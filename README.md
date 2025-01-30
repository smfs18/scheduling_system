**Projeto de estrutura de dados orientada ao objeto - Silas Manoel Freitas da Silva (smfs@cin.ufpe.br)**

Este código simula um sistema de agendamento de serviços em uma barbearia. O sistema permite registrar clientes, serviços, agendamentos e gerenciar uma barbearia, onde os clientes podem agendar serviços em horários disponíveis. A estrutura do código é organizada em quatro classes principais: Cliente, Servico, Agendamento e Barbearia. Vou explicar cada uma delas e como elas interagem.

**Classes e Funcionamento:**

_Classe Cliente:_
Representa um cliente da barbearia, com informações como nome e telefone.
Possui:
Atributos: nome e telefone.
Métodos:
getNome(): Retorna o nome do cliente.
getTelefone(): Retorna o telefone do cliente.
mostrarInfo(): Exibe as informações do cliente no formato nome - telefone.

_Classe Servico:_
Representa um serviço oferecido pela barbearia, como corte de cabelo ou barba.
Possui:
Atributos: nome, duracao (em minutos) e preco (preço do serviço).
Métodos:
getNome(): Retorna o nome do serviço.
getDuracao(): Retorna a duração do serviço.
getPreco(): Retorna o preço do serviço.
mostrarInfo(): Exibe as informações do serviço no formato nome - Duração: X min, Preço: R$Y.

_Classe Agendamento:_
Representa um agendamento feito por um cliente para um serviço específico em uma data e hora.
Possui:
Atributos: cliente (objeto da classe Cliente), dataHora (a data e hora do agendamento) e servico (objeto da classe Servico).
Métodos:
mostrarAgendamento(): Exibe as informações do agendamento no formato Cliente: [nome], Serviço: [nome do serviço], Data/Hora: [data e hora].
getDataHora(): Retorna a data e hora do agendamento.

_Classe Barbearia:_
Representa a barbearia, onde os agendamentos de serviços serão feitos.
Possui:
Atributos: nome (nome da barbearia), endereco (endereço da barbearia) e agendamentos (vetor de objetos Agendamento).
Métodos:
verificarDisponibilidade(dataHora): Verifica se o horário desejado já está ocupado. Retorna true se o horário estiver disponível e false caso contrário.
agendar(cliente, dataHora, servico): Realiza o agendamento se o horário estiver disponível. Caso contrário, exibe uma mensagem informando que o horário está ocupado.
listarAgendamentos(): Exibe todos os agendamentos realizados na barbearia.
~Barbearia(): Destruidor que libera a memória dos objetos Agendamento criados dinamicamente.

**Funcionamento Geral do Sistema:**

_Criação de Objetos:_
Clientes são criados com seus respectivos nomes e telefones.
Serviços são criados, cada um com nome, duração e preço.
A Barbearia é criada, recebendo um nome e um endereço.

_Agendamento de Serviços:_
A barbearia tenta agendar serviços para os clientes em horários específicos.

O método verificarDisponibilidade é usado para garantir que o horário desejado não esteja ocupado.
Se o horário estiver disponível, o agendamento é realizado com o método agendar, criando um objeto Agendamento e adicionando-o ao vetor de agendamentos.
Caso o horário já esteja ocupado, uma mensagem é exibida, e o agendamento não é realizado.

_Listagem de Agendamentos:_
O método listarAgendamentos exibe todos os agendamentos realizados na barbearia, mostrando o nome do cliente, o nome do serviço e a data/hora de cada agendamento.

**Exemplo de Execução do Programa:**

Criação de dois clientes: João Silva e Maria Oliveira, com seus respectivos telefones.
Criação de dois serviços: Corte de cabelo (30 minutos, R$40.00) e Barba (20 minutos, R$30.00).
Agendamento dos serviços:
João Silva agenda um corte de cabelo para o dia 20 de janeiro de 2025, às 10:00.
Maria Oliveira agenda um serviço de barba para o mesmo dia, às 10:30.
Tentativa de agendamento duplicado: João tenta agendar outro serviço de barba para o mesmo horário de corte de cabelo (10:00), mas o sistema informa que o horário já está ocupado.
Listagem de agendamentos: O sistema exibe os agendamentos realizados com detalhes sobre o cliente, serviço e horário.
