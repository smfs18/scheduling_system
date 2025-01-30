#include <iostream>
#include <string>
#include <vector>  // Usamos o vetor dinâmico para armazenar os agendamentos, pois ele cresce conforme necessário.
using namespace std;

// Definindo a classe Cliente
class Cliente {
private:
    string nome;  // Nome do cliente
    string telefone;  // Telefone do cliente

public:
    // Construtor que inicializa o nome e o telefone do cliente
    Cliente(string nome, string telefone) : nome(nome), telefone(telefone) {}

    // Método para pegar o nome do cliente
    string getNome() const {
        return nome;
    }

    // Método para pegar o telefone do cliente
    string getTelefone() const {
        return telefone;
    }

    // Método para mostrar as informações do cliente
    void mostrarInfo() const {
        cout << nome << " - " << telefone << endl;
    }
};

// Definindo a classe Serviço
class Servico {
private:
    string nome;  // Nome do serviço (ex: corte de cabelo)
    int duracao;  // Duração do serviço em minutos
    double preco;  // Preço do serviço

public:
    // Construtor que inicializa os dados do serviço
    Servico(string nome, int duracao, double preco)
        : nome(nome), duracao(duracao), preco(preco) {}

    // Métodos para obter as informações do serviço
    string getNome() const {
        return nome;
    }

    int getDuracao() const {
        return duracao;
    }

    double getPreco() const {
        return preco;
    }

    // Método para mostrar as informações do serviço
    void mostrarInfo() const {
        cout << nome << " - Duração: " << duracao << " min, Preço: R$" << preco << endl;
    }
};

// Definindo a classe Agendamento
class Agendamento {
private:
    Cliente cliente;  // O cliente que fez o agendamento
    string dataHora;  // Data e hora do agendamento
    Servico servico;  // O serviço que o cliente agendou

public:
    // Construtor que inicializa o agendamento com o cliente, data/hora e o serviço
    Agendamento(Cliente cliente, string dataHora, Servico servico)
        : cliente(cliente), dataHora(dataHora), servico(servico) {}

    // Método para mostrar o agendamento
    void mostrarAgendamento() const {
        cout << "Cliente: " << cliente.getNome() << ", Serviço: " << servico.getNome() << ", Data/Hora: " << dataHora << endl;
    }

    // Método para pegar a data e hora do agendamento
    string getDataHora() const {
        return dataHora;
    }
};

// Definindo a classe Barbearia
class Barbearia {
private:
    string nome;  // Nome da barbearia
    string endereco;  // Endereço da barbearia
    vector<Agendamento*> agendamentos;  // Vetor para armazenar os agendamentos de forma dinâmica

public:
    // Construtor para inicializar a barbearia com nome e endereço
    Barbearia(string nome, string endereco) : nome(nome), endereco(endereco) {}

    // Método para verificar se o horário está disponível para agendamento
    bool verificarDisponibilidade(string dataHora) const {
        for (const Agendamento* agendamento : agendamentos) {
            if (agendamento->getDataHora() == dataHora) {
                return false;  // Se já tiver um agendamento nesse horário, retorna falso
            }
        }
        return true;  // Se não encontrar nenhum agendamento no horário, retorna verdadeiro
    }

    // Método para agendar um serviço para um cliente
    void agendar(Cliente cliente, string dataHora, Servico servico) {
        if (!verificarDisponibilidade(dataHora)) {
            cout << "Horário " << dataHora << " já ocupado. Por favor, escolha outro horário." << endl;
            return;  // Se o horário estiver ocupado, não faz o agendamento
        }

        // Se o horário estiver disponível, cria um novo agendamento e o adiciona no vetor
        Agendamento* agendamento = new Agendamento(cliente, dataHora, servico);
        agendamentos.push_back(agendamento);
        cout << "Agendamento realizado para " << cliente.getNome() << " no horário " << dataHora << " para o serviço de " << servico.getNome() << "." << endl;
    }

    // Método para listar todos os agendamentos
    void listarAgendamentos() const {
        for (const Agendamento* agendamento : agendamentos) {
            agendamento->mostrarAgendamento();  // Mostra as informações de cada agendamento
        }
    }

    // Destruidor para liberar a memória dos agendamentos criados dinamicamente
    ~Barbearia() {
        for (Agendamento* agendamento : agendamentos) {
            delete agendamento;  // Libera a memória de cada agendamento
        }
    }
};

// Função principal
int main() {
    // Criando dois clientes
    Cliente cliente1("João Silva", "1234-5678");
    Cliente cliente2("Maria Oliveira", "8765-4321");

    // Criando dois serviços
    Servico corteCabelo("Corte de Cabelo", 30, 40.00);
    Servico barba("Barba", 20, 30.00);

    // Criando a barbearia
    Barbearia barbearia("Barbearia do João", "Rua das Flores, 123");

    // Agendando os serviços para os clientes
    barbearia.agendar(cliente1, "2025-01-20 10:00", corteCabelo);  // Agendamento de corte de cabelo
    barbearia.agendar(cliente2, "2025-01-20 10:30", barba);  // Agendamento de barba

    // Tentando agendar para o mesmo horário
    barbearia.agendar(cliente1, "2025-01-20 10:00", barba);  // Vai mostrar que o horário está ocupado

    // Listando os agendamentos
    cout << "\nAgendamentos realizados:" << endl;
    barbearia.listarAgendamentos();  // Mostra todos os agendamentos realizados

    return 0;
}
