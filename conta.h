//definir um tipo produto (ponteiro para o produto)
typedef struct Conta * c_conta;

//inicilizar um vetor do tamanho x de ponteiros para produtos
void inicializar(c_conta cConta[], int tamanho);

//cadastrar em uma posicao (um novo produto) e alocar nesta
//posicao do ponteiro
void inserir(c_conta cConta[], int posicao);

//listar na tela apenas os produtos cadastrados
void listar(c_conta cConta[], int tamanho);

//recebe o vetor, seu tamanho, e pede qual deseja-se alterar
void alterar(c_conta cConta[], int tamanho);

//percorre a lista somando (preco_unitario * qtd)
void saldoGeral(c_conta cConta[], int tamanho);

//percorre a lista, ao encontrar o produto solicita a qtd
//comprada ao usuario
void depositar(c_conta cConta[], int tamanho);

//percorre a lista, ao encontrar o produto solicita a qtd
//vendida ao usuario
void sacar(c_conta cConta[], int tamanho);

//listar um unico produto encontrado a partir da solicitacao
//do usuario
void procurar(c_conta cConta[], int tamanho);

//listar um unico produto encontrado a partir da solicitacao
//do usuario
void imprimir(c_conta cConta[], int tamanho);

void imprimirConta(c_conta const *cConta, int i);

//leitura para o codigo procurado
int procurarConta();
