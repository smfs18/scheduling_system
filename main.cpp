#include <iostream>
#include <string>
using namespace std;


class Cliente {
private:
    string nome;
    string telefone;


public:
    Cliente(string nome, string telefone) {
        this->nome = nome;
        this->telefone = telefone;
    }


    string getNome() {
        return nome;
    }


    string getTelefone() {
        return telefone;
    }


    void mostrarInfo() {
        cout << nome << " - " << telefone << endl;
    }
};


class Servico {
private:
    string nome;
    int duracao;  // Duração do serviço em minutos
    double preco;


public:
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



