#include <iostream>
#include <string>
#include <list>

using namespace std;
// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor
int vetNum[3];

int converteSensor(float val_Mim, float val_Max, float medida)
{
    float position = medida/(val_Max+val_Mim);
    position=position*100;
    return position;
}


// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor
int leituraSensor()
{
    int num;
    cout<<"digite um número entre o intervalo citado"<<endl;
    cin>>num;
    return num;
}


// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor
int armazenaVetor(int *ponteiroVetor, int tamanhoVetor, int posArmazenamento, int medida)
{
	*(ponteiroVetor+posArmazenamento-1) = medida;
    if (posArmazenamento == tamanhoVetor) {
        // avisa que chegou no limite ou retorna a posicao atual
        cout<<"o vetor já está em sua última posicao";
    }
    return posArmazenamento + 1;
}


// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.
int direcaoMenorCaminho(int *ponteiroVetor,int *variavel ){
	int aux = 0;
	for (int i=0; i<4;i++){
		if (*(ponteiroVetor + i ) > aux);
			aux = *(ponteiroVetor + i );
	}
	*variavel=aux;
	return aux;
}


// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso

int leComando(){
	string resposta;
	cout<<"voce deseja continuar?";
	cin>>resposta;
	if (resposta=="sim"){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int vetor2[50]={1,2,3,4,5,6,7};
	int *pnt2=vetor2;
	int maior;
	int *pnt3=&maior;
    int vetor[10]={1,2,3,4,5,6,7,8,8,10};
	int *pnt=vetor;
	//saída exercicio 1
    cout<<"digite o numero de valor minimo, valor maximo e a medida desejada(nessa ordem)"<<endl;
    cin>>vetNum[0];
    cin>>vetNum[1];
    cout<<"o numero representa "<<converteSensor(vetNum[0],vetNum[1],vetNum[2])<<"%"<<" do intervalo";

	//saida exercicio 2
    vetNum[2]=leituraSensor();

	//saida exercicio 3
	armazenaVetor(pnt,10,8,15);
	for(int element:vetor){
		cout<<element<<" ";
	}
	//saida exercicio 4
	cout<<	direcaoMenorCaminho(pnt2,pnt3 );

//saida exercicio 5
	cout<<leComando();

	return 0;

}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas


/*
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
		int medida = /// .. Chame a função de de leitura da medida para a "Direita"
		medida = converteSensor(medida,0,830);
		posAtualVetor = // Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		dirigindo = leComando();		
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}
*/