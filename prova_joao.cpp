#include <iostream>

using namespace std;
typedef struct day
{
	char mat[8];
	char nome[20];
	float n1;
	float n2;
	float n3;
	float media;
}D1;

D1 *contato;

D1 *alocacontato(D1 *contato){
	contato = new D1;
	return contato;
}

typedef struct Reg{
	D1 info;
	Reg *prox;
}Celula;

Celula *inicializa(void)
{
	return NULL;
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

Celula *insere(Celula *L, D1 contato){
	Celula *novo;
	novo = new Celula;
	novo->info = contato;
	novo->prox = L->prox;
	L->prox=novo;
	return L;
}
/*
void imprime(Celula *L)
{
	Celula *p;
	for (p = L; p != NULL; p = L->prox){
		cout<<p->info<<endl;
	}
}*/

int main(int argc, char const *argv[])
{
	Celula *L1;
	L1 = new Celula;
	contato = alocacontato(contato);
	L1 = inicializa();
	contato = Cadastrar(contato);
	L1 = insere(L1, contato);
	//imprime(L1);
	return 0;
}