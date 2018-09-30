#include <stdlib.h>
#include <iostream>
using namespace std;

class Matrix{

	private:
		int colunas;
		int linhas;
		int **matriz;

	public:
		int getLinhas() { return linhas; }
		int getColunas() { return colunas; }
		int setLinhas(int l) { linhas = l; }
		int setColunas(int c) { colunas = c; }

        // Sobrecarga de Operador [].
		int* operator[](int const y) {
            return &matriz[0][y];

		}
		// Sobrecarga de Operador =.
		Matrix & operator=(Matrix &obj){
		    colunas=obj.colunas;
            linhas=obj.linhas;

            alocarEspacoMatriz(linhas, colunas);

            for (unsigned i=0; i < colunas; i++){
                for (unsigned j=0; j < linhas; j++){
                    matriz[i][j] = obj.matriz[i][j];
                }
            }

            return *this;
		}

		// Construtor.
		Matrix(int lin, int col) {
            colunas=col;
            linhas=lin;

            bool alocou = alocarEspacoMatriz(lin, col);
            if(!alocou) cout << "Erro ao alocar espa�o para a matriz." << endl;
		}

        // Construtor de c�pia.
        // Recebe o endere�o de um outro objeto do tipo Matrix.
		Matrix(const Matrix &outroObjeto){
		    colunas = outroObjeto.colunas;
            linhas = outroObjeto.linhas;

            bool alocou = alocarEspacoMatriz(linhas, colunas);
            if(!alocou) cout << "Erro ao alocar espa�o para a matriz." << endl;

            for (unsigned i=0; i < linhas; i++){
                for (unsigned j=0; j < colunas; j++){
                    matriz[i][j] = outroObjeto.matriz[i][j];
                }
            }
		}

        // Destrutor. ~
		~Matrix(void){
			for (unsigned i=0; i < linhas; i++) {
				delete[] matriz[i];
			}
			delete[] matriz;
		}

		// Fun��o para alocar espa�o.
		bool alocarEspacoMatriz(int lin, int col) {
            // ALOCANDO A MATRIZ.
            matriz = new int* [col];
            for (unsigned i=0; i < col; i++) {
                matriz[i] = new int[lin];
            }
            return true;
		}

        // Fun��o para preencher uma matriz de dados.
		void preencherMatriz() {
            cout << endl << "Informe os valores desejados para a Matriz!!" << endl << endl;

            for(unsigned i=0; i < linhas; i++){
                for(unsigned j=0; j < colunas; j++){
                    cout << "Matriz Lin[" << i << "] Col[" << j << "] = ";
                    cin >> matriz[i][j];
                }
            }
        }

        // Fun��o para IMPRIMIR uma matriz de dados.
        void imprimirMatriz() {
            cout << endl << "Imprimindo a Matriz!!" << endl << endl;

            for(unsigned i=0; i < linhas; i++){
                for(unsigned j=0; j < colunas; j++){
                    cout << "Matriz Lin[" << i << "] Col[" << j << "] = " << matriz[i][j] << endl;
                }
            }
        }
};



int main(){

	int row, col;

    cout << "Forneca no numeros de linhas: ";
    cin >> row;

    cout << "Forneca no numeros de colunas: ";
    cin >> col;

	Matrix mat(row, col);

	cout << "Tamanho Matriz: Linhas " << mat.getLinhas() << " e Colunas " << mat.getColunas() << "!!!" << endl;

	mat.preencherMatriz();
	cout << "----------------------------------- IMPRIMINDO -----------------------------------" << endl;
	mat.imprimirMatriz();

	cout << "Imprimindo novo objeto criado pelo construtor de copia." << endl << endl;
	// Com construtor de c�pia.
	Matrix A(mat);
	A[0][0] = 190;
	A.imprimirMatriz();

	cout << "Imprimindo novo objeto criado pelo construtor de copia." << endl << endl;
	
	Matrix B = mat;
	B[0][0] = 50;
	B.imprimirMatriz();

	cout << "Imprimindo NOVAMENTE A MATRIZ INICIAL." << endl << endl;
	mat.imprimirMatriz();

}
