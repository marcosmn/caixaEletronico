// AtividadeCaixaEletronico.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdexcept>

// Variaveis globais
int codigoAtual;

// Lista de usuarios
typedef struct
{
	char usuario[15];
	char senha[15];
	int saldo = 0;
} Usuario;

// Para testar
const int quantidadeContas = 3;
Usuario listaUsuarios[quantidadeContas];

// Declaração da função para acessar a conta
bool acessarConta();

// Declaração da função para verificar a senha
bool verificarSenha(char senhaAtual[15]);

// Declaração da função para verificar saldo
void verificarSaldo();

// Declaração da função para saque
void fazerSaque(int quantidadeRetirada);

// Declaração da função para deposito na propria conta
void depositoInterno(int quantidadeDepositada);

// Declaração da função para deposito em outra conta
void depositoExterno(char usuarioExterno[15], int quantidadeDepositada);

// Declaração da função para pagamento
bool fazerPagamento(int quantidadePagada);

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
	while (sucesso == false)
	{
		printf("Tente novamente,\n");
		sucesso = acessarConta();
	}

	// Operações
	while (fim == false)
	{
		printf("Lista de operações: \n");
		printf("0 - Encerrar\n");
		printf("1 - Verificar saldo \n");
		printf("2 - Fazer saque \n");
		printf("3 - Fazer deposito na propria conta \n");
		printf("4 - Fazer deposito em outra conta \n");
		printf("5 - Fazer pagamento \n");
		printf("Escolha a sua operação:");
		scanf_s("%i", &operacao);

		// Encerrar
		if (operacao == 0)
		{
			fim = true;
		}

		// Verificar Saldo
		else if (operacao == 1)
		{
			verificarSaldo();
		}

		// Fazer saque
		else if (operacao == 2)
		{
			int quantidadeRetirada = 0;
			printf("Quanto você quer sacar: ");
			scanf_s("%i", &quantidadeRetirada);
			fazerSaque(quantidadeRetirada);
		}

		// Fazer deposito na propria conta
		else if (operacao == 3)
		{
			int quantidadeDepositada = 0;
			printf("Quanto você quer depositar: ");
			scanf_s("%i", &quantidadeDepositada);
			depositoInterno(quantidadeDepositada);
		}

		// Fazer deposito em outra conta
		else if (operacao == 4)
		{
			char usuarioExterno[15];
			printf("Informe o usuario alvo: ");
			scanf_s("%s", &usuarioExterno, 15);
			int quantidadeDepositada = 0;
			printf("Quanto você quer depositar: ");
			scanf_s("%i", &quantidadeDepositada);
			depositoExterno(usuarioExterno, quantidadeDepositada);
		}

		// Fazer pagamento
		else if (operacao == 5)
		{
			int quantidadePagada = 0;
			printf("Quanto você quer pagar: ");
			scanf_s("%i", &quantidadePagada);
			fazerPagamento(quantidadePagada);
		}
	}

	// Fim do caixa
	printf("Volte sempre ao caixa eletronico!");

	return 0;
}

// Função para acessar a conta
bool acessarConta()
{
	// Para testar
	strcpy_s(listaUsuarios[1].usuario, "visitante");
	strcpy_s(listaUsuarios[1].senha, "1234");
	strcpy_s(listaUsuarios[2].usuario, "admin");
	strcpy_s(listaUsuarios[2].senha, "7777");

	// Leitura do usuario
	char usuarioAtual[15];
	printf("digite o usuario:");
	scanf_s("%s", &usuarioAtual, 15);

	// Leitura da senha
	char senhaAtual[15];
	printf("digite a senha:");
	scanf_s("%s", &senhaAtual, 15);

	// Verificar usuario
	for (codigoAtual = 0; codigoAtual < quantidadeContas; codigoAtual++)
	{
		if (strcmp(usuarioAtual, listaUsuarios[codigoAtual].usuario))
		{
			// Verificar senha correspondente
			return verificarSenha(senhaAtual);
		}
	}

	return false;
}

// Função para verificar a senha
bool verificarSenha(char senhaAtual[15])
{
	if (strcmp(senhaAtual, listaUsuarios[codigoAtual].senha))
	{
		return true;
	}

	return false;
}

// Função para verificar saldo
void verificarSaldo()
{
	printf("Saldo atual: %i", listaUsuarios[codigoAtual].saldo);
}

// Função para saque
void fazerSaque(int quantidadeRetirada)
{
	listaUsuarios[codigoAtual].saldo = listaUsuarios[codigoAtual].saldo - quantidadeRetirada;
}

// Função para deposito na propria conta
void depositoInterno(int quantidadeDepositada)
{
	listaUsuarios[codigoAtual].saldo = listaUsuarios[codigoAtual].saldo + quantidadeDepositada;
}

// Função para deposito em outra conta
void depositoExterno(char usuarioExterno[15], int quantidadeDepositada)
{
	for (int codigoExterno = 0; codigoExterno < quantidadeContas; codigoExterno++)
	{
		if (strcmp(usuarioExterno, listaUsuarios[codigoExterno].usuario))
		{
			listaUsuarios[codigoExterno].saldo = listaUsuarios[codigoExterno].saldo + quantidadeDepositada;
		}
	}
}

// Função para pagamento
bool fazerPagamento(int quantidadePagada)
{
	// Verificando se é possivel pagar a quantidade
	if (quantidadePagada < listaUsuarios[codigoAtual].saldo)
	{
		listaUsuarios[codigoAtual].saldo = listaUsuarios[codigoAtual].saldo - quantidadePagada;

		return true;
	}

	return false;
}

