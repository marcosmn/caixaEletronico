// AtividadeCaixaEletronico.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdexcept>

// Lista de usuarios
typedef struct
{
	char usuario[15];
} Usuario;

// Declaração da função para acessar a conta
bool acessarConta();

// Declaração da função para verificar a senha
bool verificarSenha(int codigo, char senha[15]);

// Declaração da função para verificar saldo
bool verificarSaldo(char usuario[15]);

// Declaração da função para saque
bool fazerSaque(char usuario[15]);

// Declaração da função para deposito na propria conta
bool depositoInterno(char usuario[15]);

// Declaração da função para deposito em outra conta
bool depositoExterno(char usuario[15]);

// Declaração da função para pagamento
bool fazerPagamento(char usuario[15]);

// Loop Inicial (Menu)
int main()
{
	// Inicio do caixa
	printf("Bem vindo ao caixa eletronico!");

	// Declaração de variaveis
	bool sucesso = false;
	bool fim = false;
	int operacao = 0;

	// Acesso a conta
	printf("Acesse a sua conta,\n");
	sucesso = acessarConta();
	while(sucesso == false)
	{
		printf("Tente novamente,\n");
		sucesso = acessarConta();
	}

	// Operações
	while(fim == false)
	{
		printf("Lista de operações: \n");
		printf("0 - Encerrar\n");
		printf("1 - Verificar saldo \n");
		printf("2 - Fazer saque \n");
		printf("3 - Fazer deposito na propria conta \n");
		printf("4 - Fazer deposito em outra conta \n");
		printf("5 - Fazer pagamento \n");
		printf("Escolha a sua operação:");
		scanf("%i", &operacao);

		// Encerrar
		if(operacao == 0)
		{

		}

		// Verificar Saldo
		if(operacao == 1)
		{

		}

		// Fazer saque
		if(operacao == 2)
		{

		}

		// Fazer deposito na propria conta
		if(operacao == 3)
		{

		}

		// Fazer deposito em outra conta
		if(operacao == 4)
		{

		}

		// Fazer pagamento
		if(operacao == 5)
		{

		}
	}
}

// Função para acessar a conta
bool acessarConta()
{
	const int quantidadeContas = 3;
	Usuario listaUsuarios[quantidadeContas];
	strcpy(listaUsuarios[1].usuario,"visitante");
	strcpy(listaUsuarios[2].usuario, "admin");

	char usuario[15];
	printf("digite o usuario:");
	scanf("%s", &usuario);

	char senha[15];
	printf("digite a senha:");
	scanf("%s", &senha);

	// Verificar usuario
	for(int codigo = 0; codigo < quantidadeContas; codigo++)
	{
		if(strcmp(usuario, listaUsuarios[codigo].usuario))
		{
			// Verificar senha correspondente
			return verificarSenha(codigo, senha);
		}
	}

	return false;
}

// Função para verificar a senha
bool acessarConta()
{

}

// Função para verificar saldo
bool acessarConta()
{

}

// Função para saque
bool acessarConta()
{

}

// Função para deposito na propria conta
bool acessarConta()
{

}

// Função para deposito em outra conta
bool acessarConta()
{

}

// Função para pagamento
bool acessarConta()
{

}
