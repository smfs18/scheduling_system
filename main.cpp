#include <iostream> // Inclusão da Biblioteca iostream para receber input's e enviar output's.
#include <string> // Inclusão da biblioteca que permite utilizar as strings.
using namespace std; // Apenas uma forma de dizer que quero chamar a bibioteca com o nome std.

//DEFINIÇÃO DAS CLASSES;
class Cliente { //Classe cliente;
private: // Atributos privados - significa que só podem ser acessador dentro da classe, nesse caso os atributos irão utilizá-los.
    string nome; //Nome do cliente;
    string telefone; //Telefone do cliente;


public: //Atributos públicos - podem ser utilizados fora da classe;
    Cliente(string nome, string telefone) { //Aqui temos a utilização de um construtor que basicamente vai inicializar os atributos da classe com os valores passados como argumento.
        this->nome = nome; //Utilizamos o "this" para dize que o "nome" do construtor é diferente do atributo privado "nome".
        this->telefone = telefone; 
    }


    string getNome() { // O método get é um método público usado para retornar o valor do atributo, nesse caso, o atributo "nome".
        return nome; //Obs: ele serve no encapsulammento do código, pois você só pode acessar o atributo privado por meio dele.
    }


    string getTelefone() { //Nesse caso, a função foi utilizada para retornar o valor do atributo "telefone"
        return telefone;
    }


    void mostrarInfo() { //Função que serve apenas para imprimir na tela o nome do cliente e o número de telefone.
        cout << nome << " - " << telefone << endl;
    }
};//Encerramento da classe Cliente.

class Servico { //Classe Serviço.
private: //membros privados.
    string nome; // Nome do Cliente.
    int duracao;  // Duração do serviço em minutos.
    double preco; // Valor do corte.


public: // membros públicos.
    Servico(string nome, int duracao, double preco) {
        this->nome = nome;
        this->duracao = duracao;
        this->preco = preco;
    }


    string getNome() {
        return nome;
    }


    int getDuracao() {
        return duracao;
    }


    double getPreco() {
        return preco;
    }


    void mostrarInfo() {
        cout << nome << " - Duração: " << duracao << " min, Preço: R$" << preco << endl;
    }
};


class Agendamento {
private:
    Cliente cliente;
    string dataHora;
    Servico servico;


public:
    Agendamento(Cliente cliente, string dataHora, Servico servico) : cliente(cliente), dataHora(dataHora), servico(servico) {}


    void mostrarAgendamento() {
        cout << "Cliente: " << cliente.getNome() << ", Serviço: " << servico.getNome() << ", Data/Hora: " << dataHora << endl;
    }


    string getDataHora() {
        return dataHora;
    }
};


class Barbearia {
private:
    string nome;
    string endereco;
    Agendamento* agendamentos[10];  // Limite de 10 agendamentos (exemplo simples)
    int quantidadeAgendamentos;


public:
    Barbearia(string nome, string endereco) {
        this->nome = nome;
        this->endereco = endereco;
        quantidadeAgendamentos = 0;
    }


    bool verificarDisponibilidade(string dataHora) {
        for (int i = 0; i < quantidadeAgendamentos; i++) {
            if (agendamentos[i]->getDataHora() == dataHora) {
                return false;  // Já existe um agendamento nesse horário
            }
        }
        return true;
    }


    void agendar(Cliente cliente, string dataHora, Servico servico) {
        if (!verificarDisponibilidade(dataHora)) {
            cout << "Horário " << dataHora << " já ocupado. Por favor, escolha outro horário." << endl;
            return;
        }


        Agendamento* agendamento = new Agendamento(cliente, dataHora, servico);
        agendamentos[quantidadeAgendamentos++] = agendamento;
        cout << "Agendamento realizado para " << cliente.getNome() << " no horário " << dataHora << " para o serviço de " << servico.getNome() << "." << endl;
    }


    void listarAgendamentos() {
        for (int i = 0; i < quantidadeAgendamentos; i++) {
            agendamentos[i]->mostrarAgendamento();
        }
    }
};


int main() {
    // Criando clientes
    Cliente cliente1("João Silva", "1234-5678");
    Cliente cliente2("Maria Oliveira", "8765-4321");


    // Criando serviços
    Servico corteCabelo("Corte de Cabelo", 30, 40.00);
    Servico barba("Barba", 20, 30.00);


    // Criando barbearia
    Barbearia barbearia("Barbearia do João", "Rua das Flores, 123");


    // Agendando serviços
    barbearia.agendar(cliente1, "2025-01-20 10:00", corteCabelo);
    barbearia.agendar(cliente2, "2025-01-20 10:30", barba);


    // Tentando agendar para o mesmo horário
    barbearia.agendar(cliente1, "2025-01-20 10:00", barba);  // Deve avisar que o horário está ocupado


    // Listando agendamentos
    cout << "\nAgendamentos realizados:" << endl;
    barbearia.listarAgendamentos();


    return 0;
}



