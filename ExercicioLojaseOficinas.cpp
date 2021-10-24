#include <iostream>
#include <string>
using namespace std;

class motoqueiros{
 private:
 string nome;
 string marca;
 string modelo;
 string ano;

 public:
 motoqueiros(); //Construtor
~motoqueiros(); //Destrutor
void cadastro();
void imprimir();
};

//Inicia as variaveis 
motoqueiros::motoqueiros()
{
    nome.clear();
    marca.clear();
    modelo.clear();
    ano.clear();
}


motoqueiros::~motoqueiros()
{
    nome.clear();
    marca.clear();
    modelo.clear();
    ano.clear();
}

  void motoqueiros::cadastro()
{
    cout << "Nome: ";
    cin >> nome;
    cout << "Marca: ";
    cin >> marca;
    cout << "Modelo: ";
    cin >> modelo;
    cout << "Ano: ";
    cin >> ano;
    cout << endl;
 
};
//Imprime todos os documentos do sistema
void motoqueiros::imprimir()
{
    cout << "Nome: " << nome << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Ano: " << ano << endl;
    cout << endl;
}

class lojas{
 private:
 string nomeloja;
 string marcasloja;
 string beneficios;


 public:
 lojas(); //Construtor
~lojas(); //Destrutor
void cadastrolojas();
void imprimirlojas();
void buscarloja(int cont1);
};
//Inicia as variaveis 
lojas::lojas()
{
    nomeloja.clear();
    marcasloja.clear();
    beneficios.clear();

}

//Destrutor, limpa as variáveis
lojas::~lojas()
{
    nomeloja.clear();
    marcasloja.clear();
    beneficios.clear();
}

  void lojas::cadastrolojas()
{
    cout << "Nome da loja/oficina: ";
    cin >> nomeloja;
    cout << "Marca da loja(somente uma marca por loja): ";
    cin >> marcasloja;
    cout << "Beneficios(Escreva tudo junto, sem espaço): ";
    cin >> beneficios;
    cout << endl;
 
};
//Imprime todas as lojas do sistema
void lojas::imprimirlojas()
{
    cout << "Nome da loja: " << nomeloja << endl;
    cout << "Marcas: " << marcasloja << endl;
    cout << "Beneficios: " << beneficios << endl;
    cout << endl;
}

void lojas::buscarloja(int cont1){
  string x;
  cout<<"Insira a marca que deseja: ";
  cin>>x;
    if(x==marcasloja){
      cout << "Nome da loja: " << nomeloja << endl;
      cout << "Marcas: " << marcasloja << endl;
       cout << "Beneficios: " << beneficios << endl;
       cout << "DIGITE O ESTILO NOVAMENTE PARA VERIFICAR SE EXISTE MAIS ALGUM, CASO SEJA ENCAMINHADO PARA O MENU E PORQUE NAO EXISTE MAIS NENHUM DOCUMENTO COM O ESTILO DIGITADO" << endl;
    	cout << endl;
    }

}


int main(){

    string Controle, Controle2; //Controle do loop
    motoqueiros *cadastromot; //Cadastros de motoqueiros
    lojas *cadastrolojas;//Cadastro de lojas
    int aux1 = 0, aux2 = 0; //Controlam a ordem de elementos preenchidos
    int cont = 0, cont1 = 0; //cont: Conta quantos documentos ja foram cadastrados --- cont1: Conta quantos artistas ja foram cadastrados


    cadastromot = new motoqueiros [10]; //Vetor com o numero maximo de cadastros que podem ser criados
    cadastrolojas = new lojas [10]; //Vetor com o numero maximo de oficinas que podem ser criadas
  

    while (Controle != "0")
    {
        cout << "1 - Cadastrar motoqueiro" << endl;
        cout << "2 - Cadastrar loja/oficina" << endl;
        cout << "3 - Consultar motoqueiros cadastrados  " << endl;
        cout << "4 - Consultar lojas/oficinas cadastrados " << endl;
        cout << "5 - Consultar lojas/oficinas por meio da marca " << endl;
        cout << "0 - Sair " << endl;
        cout << "Opcao: ";
        cin >> Controle;

       //Cadastra um motoqueiro
        if(Controle=="1")
        {
            cout << endl;
            cadastromot[aux1].cadastro();
            aux1++;
            cont++;
            
        }

    //Cadastra uma loja/oficina 
        if(Controle=="2")
        {
            cout << endl;
            cadastrolojas[aux2].cadastrolojas();
            aux2++;	
            cont1++;
        }
       
        
        //Consulta motoqueiros cadastrados
        if(Controle=="3")
        {
            cout <<endl;
            cout <<"Motoqueiros cadastrados: "<< endl;
            for (int i=0;i<cont;i++){
                cadastromot[i].imprimir();
            }
        }

        //Consulta as oficinas/lojas cadastradas
        if (Controle=="4")
        {
            cout << endl;
            cout << "Lojas/oficinas cadastradas:" << endl;
            for (int i=0;i<cont1;i++){
                cadastrolojas[i].imprimirlojas();
            }

        }
        if(Controle=="5"){
          cout << endl;
            cout << "Buscar lojas pela marca que oferecem: " << endl<<endl;
            for (int i=0;i<cont1;i++){
                cadastrolojas[i].buscarloja(cont1);
            }
        }
    }
    
  return 0;
}