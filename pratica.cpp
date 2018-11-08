#include <iostream>

using namespace std;
typedef struct day
{
	int mat;
	char nome[20];
	float n1;
	float n2;
	float n3;
	float media;
}D1;

/*
D1 *contato;

D1 *alocacontato(D1 *contato){
	contato = new D1;
	return contato;
}



D1 Cadastrar(D1 contato) {
	cout<<"\nCadastre um novo Conato:"<<endl;
	cout<<"Matricula: ";
	cin>>contato.mat,8;
	cout<<"NOME: ";
	cin.ignore();
	cin.getline(contato.nome,20);
	cout<<"NOTA"<<": ";
	cin>>contato.n1;
	cin>>contato.n2;
	cin>>contato.n3;
	contato.media = ((contato.n1 * 4 + contato.n2 * 5 + contato.n3 * 6)/15);
	return contato;
}
*/

typedef struct Reg{
	D1 info;
	Reg *prox;
}Celula;


Celula *inicializa(void)
{
	return NULL;
}

Celula *insere(Celula *L){
	Celula *novo;
	novo = new Celula;
	cout<<"\nCadastre um novo Aluno:"<<endl;
	cout<<"Matricula: ";
	cin>>novo->info.mat;
	cout<<"NOME: ";
	cin.ignore();
	cin.getline(novo->info.nome,20);
	cout<<"NOTA 01"<<": ";
	cin>>novo->info.n1;
	cout<<"NOTA 02"<<": ";
	cin>>novo->info.n2;
	cout<<"NOTA 03"<<": ";
	cin>>novo->info.n3;
	novo->info.media = ((novo->info.n1 * 4 + novo->info.n2 * 5 + novo->info.n3 * 6)/15);
	L = novo;
	novo->prox = NULL;
	L->prox = novo->prox;
	return L;
}

void EncontraElemento(Celula *L, int numat){
	Celula *p;
	for (p = L; p!= NULL; p = p->prox)
		if(p->info.mat == numat){
			cout<<"Dados do aluno matricula nº "<<p->info.mat<<endl;
			cout<<"Nome = "<<p->info.nome<<endl;
			cout<<"Nota 1 = "<<p->info.n1<<endl;
			cout<<"Nota 2 = "<<p->info.n2<<endl;
			cout<<"Nota 3 = "<<p->info.n3<<endl;
			cout<<"Media = "<<p->info.media<<endl;
		}
		else{
			cout<<"Sugeito nao encontrado.\nTente outra Matricula"<<endl; 
		}
}

void DeletaUm(Celula *L, int numat){
	Celula *aux, *lixo;
	aux = L;
	lixo = L->prox;
	while (lixo != NULL && (lixo->info.mat != numat)) {
		aux = lixo;
		lixo = lixo->prox;
	}
	if (lixo != NULL) {
		aux->prox = lixo->prox;
		delete lixo;
	}
}

void imprime(Celula *L)
{
	Celula *p;
	for (p = L->prox; p != NULL; p = L->prox){
			cout<<"Aluno matricula nº "<<p->info.mat<<endl;
			cout<<"Nome = "<<p->info.nome<<endl;
			cout<<"Nota 1 = "<<p->info.n1<<endl;
			cout<<"Nota 2 = "<<p->info.n2<<endl;
			cout<<"Nota 3 = "<<p->info.n3<<endl;
			cout<<"Media = "<<p->info.media<<endl;
	}
}

int main(int argc, char const *argv[])
{
	Celula *L1;
	L1 = new Celula;
	int res, numat;
	do{
		cout<<"========================================\n"<<endl;
		cout<<"\t  Menu Principal\n"<<endl;
		cout<<"========================================\n"<<endl;
		cout<<"1)Inserir um aluno\n2)Buscar um aluno\n3)Excluir um aluno\n4)Mostrar todos os alunos cadastrados\n0)Sair"<<endl;
		cin>>res;
		if (res==1)
		{
			L1 = insere(L1);
		}
		else if(res==2){
			cout<<"Informe o nº da matricula: ";
			cin>>numat;
			EncontraElemento(L1, numat);
		}
		else if(res==3){
			cout<<"Informe o nº da matricula: ";
			cin>>numat;
			DeletaUm(L1, numat);
		}
		else if(res==4){
			imprime(L1);
		}
		else if(res==0){
			break;
		}
		else{
			cout<<"ERRO: Valor invalido"<<endl;
		}
	}while(res!=0);
	return 0;
}
