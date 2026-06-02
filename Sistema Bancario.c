/*INTRODUÇÃO A ALGORITIMOS E ESTRUTURA DE DADOS
  PROFESSOR: MURILO
  ALUNOS: ENZO BORGES MOURA, THAISSA DIAS MIRANDA, JOÃO VICTOR
  TURMA: PRIMEIRO SEMESTRE
  DATA: 02/06/2026
  
  DESCRIÇÃO: 
  ESTE PROGRAMA FOI CRIADO PARA SIMULAR UM SISTEMA BANCARIO COMPLETO. COM CADASTRO DE CONTAS
  DEPOSITOS, SAQUES, TRÂNSFERENCIAS ENTRE CONTAS, APLICAÇÃO DE RENDIMENTOS MENSAIS, EXIBIÇÃO DE EXTRATOS E RELATORIOS.
  ALÉM DE TER UM CERTO NÍVEL DE DIFICULDADE, POIS TODAS AS CONTAS SÃO UNICAS E NECESSITARAM CADA UMA DE SEU PROPIO TIPO
  DE SISTEMA PARA SER FEITO.                                                                                            */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    #define NUM_CONTAS               5
    #define SALARIO_MINIMO           1412.00
    #define LIMITE_NEGATIVO_SALARIO  500.00
    #define JUROS_CHEQUE_ESPECIAL    0.085
    #define JUROS_MORA               0.03
    #define RENDIMENTO_POUPANCA      0.005
    #define TAXA_CORRENTE            0.015
    #define TAXA_SALARIO             0.008

// Variáveis globais
        int    numeroConta1 =1001; int    codTitular1; int    tipoConta1;
        double saldo1;       double saldoInicial1; double limiteCheque1;
        
        int    numeroConta2 =1002; int    codTitular2; int    tipoConta2;
        double saldo2;       double saldoInicial2; double limiteCheque2;
        
        int    numeroConta3 =1003; int    codTitular3; int    tipoConta3;
        double saldo3;       double saldoInicial3; double limiteCheque3;
        
        int    numeroConta4 =1004; int    codTitular4; int    tipoConta4;
        double saldo4;       double saldoInicial4; double limiteCheque4;
        
        int    numeroConta5 =1005; int    codTitular5; int    tipoConta5;
        double saldo5;       double saldoInicial5; double limiteCheque5;

//Variaveis para o relatorio final
        int totalOperacoes = 0.0; 
        double totalDepositado =0.0; double totalSacado = 0.0; double limite_corrente = 500.00;
        
        //auxiliar
        int opcao_menu; int num_conta_escolhida;    
        double deposito; double saque; double Valor_liquido; 

        //deposito
        double saldo1_antes, saldo2_antes, saldo3_antes, saldo4_antes, saldo5_antes;

// Funções de cadastro

        void cadastrarConta1(){

            // código do titular
                    printf("Digite qual sera o seu Codigo do Titular: \n");
                    scanf("%d", &codTitular1);
        
              for (codTitular1 ; codTitular1<1000 || codTitular1>9999;)
              {
                    printf("\nCodigo do Titular invalido! Digite um numero entre 1000 e 9999: : ");
                    scanf("%d", &codTitular1);
              }
                    printf("\nCodigo do Titular cadastrado com sucesso! Seu codigo de titular: %d.\n", codTitular1);
                    printf("Codigo da sua conta: %d\n", numeroConta1);

            // Solicitar o tipo da conta
                    printf("\nDigite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): \n");
                    scanf("%d", &tipoConta1);

              for ( tipoConta1; tipoConta1<1 || tipoConta1>3; )
              {
                    printf("\n Numero invalido! Digite qual sera o tipo da sua conta: \n");
                    scanf("%d", &tipoConta1);
              }
                    printf("Tipo de conta cadastrado com sucesso!\n\n");

            // Limite de cheque especial
                if (tipoConta1 == 1) {
                    limiteCheque1 = limite_corrente;
                } else if (tipoConta1 == 2) {
                    limiteCheque1 = 0.0;
                } else if (tipoConta1 == 3) {
                    limiteCheque1 = 0.0;
                }

            //saldo inicial da conta (Valor vai ser atribuido a saldo depois do cadastro)
                printf("Digite o saldo da sua conta: \n");
                scanf("%lf", &saldoInicial1);

            while (saldoInicial1 < 0)
            {
                printf("Saldo inicial negativo! Digite um valor positivo: \n");
                scanf("%lf", &saldoInicial1);
            }
                printf("Saldo cadastrado com sucesso! O saldo da sua conta: %.2lf\n", saldoInicial1);
                saldo1 = saldoInicial1;
            }
            
        void cadastrarConta2(){

            // código do titular
           printf("\nDigite qual sera o seu Codigo do Titular: \n");
            scanf("%d", &codTitular2);

            
            for (codTitular2; (codTitular2<1000 || codTitular2>9999) || (codTitular2==codTitular1);)
            {
                printf("\nCodigo do Titular invalido! Digite um numero entre 1000 e 9999: : \n");
                scanf("%d", &codTitular2);      
            }
                printf("\nCodigo do Titular cadastrado com sucesso! Seu codigo de titular: %d.\n", codTitular2);
                printf("Codigo da sua conta: %d\n", numeroConta2);

            // Solicitar o tipo da conta
               printf("\nDigite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): \n");
                scanf("%d", &tipoConta2);

            for (tipoConta2; tipoConta2<1 || tipoConta2>3;){

            printf("\n Numero invalido! Digite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): ");
            scanf("%d", &tipoConta2);
            }
                printf("\nTipo de conta cadastrado com sucesso!\n");
        
            // Limite de cheque especial
                if (tipoConta2 == 1) {
                    limiteCheque2 = limite_corrente;
                } else if (tipoConta2 == 2) {
                    limiteCheque2 = 0.0;
                } else if (tipoConta2 == 3) {
                    limiteCheque2 = 0.0;
                }


            //saldo inicial da conta (Valor vai ser atribuido a saldo depois do cadastro)
                printf("\nDigite o saldo da sua conta: \n");
                scanf("%lf", &saldoInicial2);

            while (saldoInicial2 < 0)
            {
                printf("\nSaldo inicial negativo! Digite um valor positivo: \n");
                scanf("%lf", &saldoInicial2);
            }

                printf("\n Saldo cadastrado com sucesso! O saldo da sua conta: %.2lf\n", saldoInicial2);
                saldo2 = saldoInicial2;
            }

        void cadastrarConta3(){

            // código do titular
           printf("\nDigite qual sera o seu Codigo do Titular: \n");
            scanf("%d", &codTitular3);

            
            for (codTitular3; (codTitular3<1000 || codTitular3>9999) || (codTitular3 == codTitular1||codTitular3==codTitular2);)
            {
                printf("\nCodigo do Titular invalido! Digite um numero entre 1000 e 9999: \n");
                scanf("%d", &codTitular3);
            }
                printf("\nCodigo do Titular cadastrado com sucesso! Seu codigo de titular:  %d.\n", codTitular3);
                printf("Codigo da sua conta e: %d\n", numeroConta3);

            // Solicitar o tipo da conta
               printf("\nDigite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): \n");
                scanf("%d", &tipoConta3);

            for (tipoConta3; tipoConta3<1 || tipoConta3>3;){

            printf("\n Numero invalido! Digite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): \n");
            scanf("%d", &tipoConta3);
            }
                printf("\nTipo de conta cadastrado com sucesso!\n");
            
            // Limite de cheque especial
                if (tipoConta3 == 1) {
                    limiteCheque3 = limite_corrente;
                } else if (tipoConta3 == 2) {
                    limiteCheque3 = 0.0;
                } else if (tipoConta3 == 3) {
                    limiteCheque3 = 0.0;
                }

            //saldo inicial da conta (Valor vai ser atribuido a saldo depois do cadastro)
                printf("\nDigite o saldo da sua conta: \n");
                scanf("%lf", &saldoInicial3);

            while (saldoInicial3 < 0)
            {
                printf("\nSaldo inicial negativo! Digite um valor positivo: \n");
                scanf("%lf", &saldoInicial3);
            }
                printf("\nSaldo cadastrado com sucesso! O saldo da sua conta:  %.2lf\n", saldoInicial3);
                saldo3 = saldoInicial3;
        }

        void cadastrarConta4(){

            // código do titular
           printf("\nDigite qual sera o seu Codigo do Titular: \n");
            scanf("%d", &codTitular4);
  
            for (codTitular4; (codTitular4<1000 || codTitular4>9999) || (codTitular4 == codTitular1 || codTitular4==codTitular2 || codTitular4==codTitular3);)
            {
                printf("\nCodigo do Titular invalido! Digite um numero entre 1000 e 9999: \n");
                scanf("%d", &codTitular4);      
            }
                printf("\nCodigo do Titular cadastrado com sucesso! Seu codigo de titular:  %d.\n", codTitular4);
                printf("Codigo da sua conta e: %d\n", numeroConta4);

            // Solicitar o tipo da conta
               printf("\nDigite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): \n");
                scanf("%d", &tipoConta4);

            for (tipoConta4; tipoConta4<1 || tipoConta4>3;){

            printf("\n Numero invalido! Digite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): \n");
            scanf("%d", &tipoConta4);
            }
                printf("\nTipo de conta cadastrado com sucesso!");
            
            // Limite de cheque especial
                if (tipoConta4 == 1) {
                    limiteCheque4 = limite_corrente;
                } else if (tipoConta4 == 2) {
                    limiteCheque4 = 0.0;
                } else if (tipoConta4 == 3) {
                    limiteCheque4 = 0.0;
                }

            //saldo inicial da conta (Valor vai ser atribuido a saldo depois do cadastro)
                printf("\nDigite o saldo da sua conta: \n");
                scanf("%lf", &saldoInicial4);

            while (saldoInicial4 < 0)
            {
                printf("\nSaldo inicial negativo! Digite um valor positivo: \n");
                scanf("%lf", &saldoInicial4);
            }

                printf("\nSaldo cadastrado com sucesso! O saldo da sua conta:  %.2lf\n", saldoInicial4);
                saldo4 = saldoInicial4;
            }

        void cadastrarConta5(){

            // código do titular
           printf("\nDigite qual sera o seu Codigo do Titular: \n");
            scanf("%d", &codTitular5);

            
            for (codTitular5; (codTitular5<1000 || codTitular5>9999) || (codTitular5 == codTitular1||codTitular5==codTitular2||codTitular5==codTitular3||codTitular5==codTitular4);)
            {
                printf("\nCodigo do Titular invalido! Digite um numero entre 1000 e 9999: \n");
                scanf("%d", &codTitular5);  
            }
                printf("\nCodigo do Titular cadastrado com sucesso! Seu codigo de titular:  %d.\n", codTitular5);
                printf("Codigo da sua conta e: %d\n", numeroConta5);

            // Solicitar o tipo da conta
               printf("\nDigite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): \n");
                scanf("%d", &tipoConta5);

            for (tipoConta5; tipoConta5<1 || tipoConta5>3;){

            printf("\n Numero invalido! Digite qual sera o tipo da sua conta (1 para Corrente, 2 para Poupanca ou 3 para Salario): \n");
            scanf("%d", &tipoConta5);
            }
                printf("\nTipo de conta cadastrado com sucesso!");
            
            // Limite de cheque especial
                if (tipoConta5 == 1) {
                    limiteCheque5 = limite_corrente;
                } else if (tipoConta5 == 2) {
                    limiteCheque5 = 0.0;
                } else if (tipoConta5 == 3) {
                    limiteCheque5 = 0.0;
                }

            //saldo inicial da conta (Valor vai ser atribuido a saldo depois do cadastro)
                printf("\nDigite o saldo da sua conta: \n");
                scanf("%lf", &saldoInicial5);

            while (saldoInicial5 < 0)
            {
                printf("\nSaldo inicial negativo! Digite um valor positivo: \n");
                scanf("%lf", &saldoInicial5);
            }

                printf("\nSaldo cadastrado com sucesso! O saldo da sua conta:  %.2lf\n", saldoInicial5);
                saldo5 = saldoInicial5;
            }

        void depositar(){

            printf("||=============================================================================||\n\n");          
            printf("Digite qual o numero da conta!\n");
            scanf("%d",&num_conta_escolhida);

            if (num_conta_escolhida <1001 || num_conta_escolhida > 1005)
            {
                printf("Erro 1! retornando ao menu...\n"); 
                return;        
            }
            
             printf("Qual o valor do deposito?\n");
             scanf("%lf", &deposito);
          
            
             while (deposito <= 0)
             {
                printf("Deposito invalido! Valor negativo ou nulo.\n");
                scanf("%lf", &deposito);
             }

             // Conta 1
            if (num_conta_escolhida == numeroConta1)
            {
                
                if (tipoConta1 == 1)
                {
                    
                     Valor_liquido = deposito - (deposito * TAXA_CORRENTE);
                     saldo1 = saldo1 + Valor_liquido;
                   printf("\n         ||==============Relatorio simples===============||\n");
                   printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo1 - Valor_liquido);
                   printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_CORRENTE * 100);
                   printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                   printf("        Saldo atual apos operacao: %.2lf\n",saldo1);

                }
                else if (tipoConta1 == 2)
                {
                    Valor_liquido = deposito;
                    saldo1 = saldo1 + Valor_liquido;
                    printf("\n         ||==============Relatorio simples===============||\n");
                    printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo1 - Valor_liquido);
                    printf("        Valor da taxa aplicada: Isento\n");
                    printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                    printf("        Saldo atual apos operacao: %.2lf\n",saldo1);
                }
                else if (tipoConta1 == 3){
                    if (deposito <= SALARIO_MINIMO)
                    {
                        Valor_liquido = deposito;
                        saldo1 = saldo1 + Valor_liquido;
                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo1 - Valor_liquido);
                            printf("        Valor da taxa aplicada: Isento\n");
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo1);     
                    }
                    else{

                        Valor_liquido = deposito - (deposito * TAXA_SALARIO);
                        saldo1 = saldo1 + Valor_liquido;

                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo1 - Valor_liquido);
                            printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_SALARIO * 100);
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo1);     
                    }   
                              
                }

                    totalDepositado += Valor_liquido;
                    totalOperacoes++;                 
            }

            //Conta 2

                else if (num_conta_escolhida == numeroConta2)
            {             
                if (tipoConta2 == 1)
                {
                    
                    Valor_liquido = deposito - (deposito * TAXA_CORRENTE);
                    saldo2 = saldo2 + Valor_liquido;
                   printf("\n         ||==============Relatorio simples===============||\n");
                   printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo2 - Valor_liquido);
                   printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_CORRENTE * 100);
                   printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                   printf("        Saldo atual apos operacao: %.2lf\n",saldo2);

                }
                else if (tipoConta2 == 2)
                {
                    Valor_liquido = deposito;
                    saldo2 = saldo2 + Valor_liquido;
                    printf("\n         ||==============Relatorio simples===============||\n");
                    printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo2 - Valor_liquido);
                    printf("        Valor da taxa aplicada: Isento\n");
                    printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                    printf("        Saldo atual apos operacao: %.2lf\n",saldo2);
                }
                else if (tipoConta2 == 3){
                    if (deposito <= SALARIO_MINIMO)
                    {
                        Valor_liquido = deposito;
                        saldo2 = saldo2 + Valor_liquido;
                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo2 - Valor_liquido);
                            printf("        Valor da taxa aplicada: Isento\n");
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo2);     
                    }
                    else{

                        Valor_liquido = deposito - (deposito * TAXA_SALARIO);
                        saldo2 = saldo2 + Valor_liquido;

                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo2 - Valor_liquido);
                            printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_SALARIO * 100);
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo2);     
                    }   
                              
                }

                    totalDepositado += Valor_liquido;
                    totalOperacoes++;                  
            }

            //Conta 3
             if (num_conta_escolhida == numeroConta3)
            {
                
                if (tipoConta3 == 1)
                {
                    
                     Valor_liquido = deposito - (deposito * TAXA_CORRENTE);
                     saldo3 = saldo3 + Valor_liquido;
                   printf("\n         ||==============Relatorio simples===============||\n");
                   printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo3 - Valor_liquido);
                   printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_CORRENTE * 100);
                   printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                   printf("        Saldo atual apos operacao: %.2lf\n",saldo3);

                }
                else if (tipoConta3 == 2)
                {
                    Valor_liquido = deposito;
                    saldo3 = saldo3 + Valor_liquido;
                    printf("\n         ||==============Relatorio simples===============||\n");
                    printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo3 - Valor_liquido);
                    printf("        Valor da taxa aplicada: Isento\n");
                    printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                    printf("        Saldo atual apos operacao: %.2lf\n",saldo3);
                }
                else if (tipoConta3 == 3){
                    if (deposito <= SALARIO_MINIMO)
                    {
                        Valor_liquido = deposito;
                        saldo3 = saldo3 + Valor_liquido;
                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo3 - Valor_liquido);
                            printf("        Valor da taxa aplicada: Isento\n");
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo3);     
                    }
                    else{

                        Valor_liquido = deposito - (TAXA_SALARIO * deposito);
                        saldo3 = saldo3 + Valor_liquido;

                            printf("\n         ||==============Relatorio simples===============||");
                            printf("\n        Valor Bruto da conta antes do deposito %.2lf\n", saldo3 - Valor_liquido);
                            printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_SALARIO * 100);
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo3);     
                    }   
                              
                }

                    totalDepositado += Valor_liquido;
                    totalOperacoes++;
            }
            //Conta 4
                 if (num_conta_escolhida == numeroConta4)
            {
                
                if (tipoConta4 == 1)
                {
                    
                     Valor_liquido = deposito - (deposito * TAXA_CORRENTE);
                     saldo4 = saldo4 + Valor_liquido;
                   printf("\n         ||==============Relatorio simples===============||\n");
                   printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo4 - Valor_liquido);
                   printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_CORRENTE * 100);
                   printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                   printf("        Saldo atual apos operacao: %.2lf\n",saldo4);

                }
                else if (tipoConta4 == 2)
                {
                    Valor_liquido = deposito;
                    saldo4 = saldo4 + Valor_liquido;
                    printf("\n         ||==============Relatorio simples===============||\n");
                    printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo4 - Valor_liquido);
                    printf("        Valor da taxa aplicada: Isento\n");
                    printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                    printf("        Saldo atual apos operacao: %.2lf\n",saldo4);
                }
                else if (tipoConta4 == 3){
                    if (deposito <= SALARIO_MINIMO)
                    {
                        Valor_liquido = deposito;
                        saldo4 = saldo4 + Valor_liquido;
                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo4 - Valor_liquido);
                            printf("        Valor da taxa aplicada: Isento\n");
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo4);     
                    }
                    else{

                        Valor_liquido = deposito - (deposito * TAXA_SALARIO);
                        saldo4 = saldo4 + Valor_liquido;

                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo4 - Valor_liquido);
                            printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_SALARIO * 100);
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo4);     
                    }   
                              
                }

                    totalDepositado += Valor_liquido;
                    totalOperacoes++;
            }
                //Conta 5

             if (num_conta_escolhida == numeroConta5)
            {
                
                if (tipoConta5 == 1)
                {
                    
                     Valor_liquido = deposito - (deposito * TAXA_CORRENTE);
                     saldo5 = saldo5 + Valor_liquido;
                   printf("\n         ||==============Relatorio simples===============||\n");
                   printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo5 - Valor_liquido);
                   printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_CORRENTE * 100);
                   printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                   printf("        Saldo atual apos operacao: %.2lf\n",saldo5);

                }
                else if (tipoConta5 == 2)
                {
                    Valor_liquido = deposito;
                    saldo5 = saldo5 + Valor_liquido;
                    printf("\n         ||==============Relatorio simples===============||\n");
                    printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo5 - Valor_liquido);
                    printf("        Valor da taxa aplicada: Isento\n");
                    printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                    printf("        Saldo atual apos operacao: %.2lf\n",saldo5);
                }
                else if (tipoConta5 == 3){
                    if (deposito <= SALARIO_MINIMO)
                    {
                        Valor_liquido = deposito;   
                        saldo5 = saldo5 + Valor_liquido;
                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo5 - Valor_liquido);
                            printf("        Valor da taxa aplicada: Isento\n");
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo5);     
                    }
                    else{

                        Valor_liquido = deposito - (deposito * TAXA_SALARIO);
                        saldo5 = saldo5 + Valor_liquido;

                            printf("\n         ||==============Relatorio simples===============||\n");
                            printf("        Valor Bruto da conta antes do deposito %.2lf\n", saldo5 - Valor_liquido);
                            printf("        Valor da taxa aplicada: %.1lf%%\n", TAXA_SALARIO * 100);
                            printf("        Valor liquido creditado: %.2lf\n",Valor_liquido);
                            printf("        Saldo atual apos operacao: %.2lf\n",saldo5);     
                    }   
                              
                }

                    totalDepositado += Valor_liquido;
                    totalOperacoes++;
            }
                     printf("\n\n||=============================================================================||\n\n");

        }
            
        void sacar(){

            printf("||=============================================================================||\n\n");
            printf("Digite qual o numero da conta!\n");
            scanf("%d", &num_conta_escolhida);

            if (num_conta_escolhida < 1001 || num_conta_escolhida > 1005)
            {
                printf("Erro 1! Conta invalida.\n");
                return;
            }

            printf("Digite o valor a sacar:\n");
            scanf("%lf", &saque);

            if (saque <= 0.0)
            {
                printf("Erro 2! Valor de saque invalido.\n");
                return;
            }

            //definindo as variaveis
            int tipoContaSelecionada = 0;
            double saldoAtual = 0.0;
            double limiteChequeSelecionado = 0.0;
            int contaValida = 0;

            if (num_conta_escolhida == numeroConta1)
            {
                contaValida = 1;
                tipoContaSelecionada = tipoConta1;
                saldoAtual = saldo1;
                limiteChequeSelecionado = limiteCheque1;
            }
            else if (num_conta_escolhida == numeroConta2)
            {
                contaValida = 2;
                tipoContaSelecionada = tipoConta2;
                saldoAtual = saldo2;
                limiteChequeSelecionado = limiteCheque2;
            }
            else if (num_conta_escolhida == numeroConta3)
            {
                contaValida = 3;
                tipoContaSelecionada = tipoConta3;
                saldoAtual = saldo3;
                limiteChequeSelecionado = limiteCheque3;
            }
            else if (num_conta_escolhida == numeroConta4)
            {
                contaValida = 4;
                tipoContaSelecionada = tipoConta4;
                saldoAtual = saldo4;
                limiteChequeSelecionado = limiteCheque4;
            }
            else if (num_conta_escolhida == numeroConta5)
            {
                contaValida = 5;
                tipoContaSelecionada = tipoConta5;
                saldoAtual = saldo5;
                limiteChequeSelecionado = limiteCheque5;
            }

            if (contaValida == 0)
            {
                printf("Erro 1! Conta invalida.\n");
                return;
            }

            //tratamento do saque bb
            if (tipoContaSelecionada == 1)
            {
                if (saque > saldoAtual + limiteChequeSelecionado)
                {
                    printf("Erro 3! Saldo insuficiente.\n");
                    return;
                }

                saldoAtual -= saque;

                if (saldoAtual < 0.0)
                {
                    double valorChequeEspecial = -saldoAtual;
                    double juros = valorChequeEspecial * JUROS_CHEQUE_ESPECIAL;
                    saldoAtual -= juros;
                }
            }
            else if (tipoContaSelecionada == 2)
            {
                if (saque > saldoAtual)
                {
                    printf("Erro 3! Saldo insuficiente.\n");
                    return;
                }

                saldoAtual -= saque;
            }
            else if (tipoContaSelecionada == 3)
            {
                if (saldoAtual - saque < -LIMITE_NEGATIVO_SALARIO)
                {
                    printf("Erro 3! Saldo insuficiente.\n");
                    return;
                }

                saldoAtual -= saque;
            }
            else
            {
                printf("3\n");
                return;
            }

            if (contaValida == 1)
            {
                saldo1 = saldoAtual;
            }
            else if (contaValida == 2)
            {
                saldo2 = saldoAtual;
            }
            else if (contaValida == 3)
            {
                saldo3 = saldoAtual;
            }
            else if (contaValida == 4)
            {
                saldo4 = saldoAtual;
            }
            else if (contaValida == 5)
            {
                saldo5 = saldoAtual;
            }

            totalSacado += saque;
            totalOperacoes++;
            printf("\n         ||==============Relatorio simples===============||\n");
            printf("         Valor sacado: %.2lf\n", saque);
            printf("         Novo saldo: %.2lf", saldoAtual);

             printf("\n\n||=============================================================================||\n\n"); 
        }
                          
        void transferir()
        {
            int contaOrigem, contaDestino; int tipoOrigem;  int tipoDestino;
            double valorTransferencia; double valor_liquido_transferencia;  double saldoOrigem;
            double saldoDestino; double limiteOrigem;
            
             printf("||=============================================================================||\n\n");
            printf("Digite o numero da conta de origem:\n");
            scanf("%d", &contaOrigem);

            //validacao da conta de origem
            if (contaOrigem < 1001 || contaOrigem > 1005)
            {
                printf("Erro 1! Conta invalida.\n");
                return;
            }

            printf("Digite o numero da conta de destino:\n");
            scanf("%d", &contaDestino);

            //validacao da conta de destino
            if (contaDestino < 1001 || contaDestino > 1005)
            {
                printf("Erro 1! Conta invalida.\n");
                return;
            }
            else if (contaDestino == contaOrigem)
            {
                printf("Erro 2! Conta de destino nao pode ser igual a conta de origem.\n");
                return;
            }

            //validacao do valor da transferencia
            printf("Digite o valor da transferencia:\n");
            scanf("%lf", &valorTransferencia);

            if (valorTransferencia <= 0.0)
            {
                printf("Erro 3! Valor de transferencia invalido.\n");
                return;
            }

            //definindo as variaveis de origem e destino bb
            if (contaOrigem == numeroConta1)
            {
                tipoOrigem = tipoConta1;
                saldoOrigem = saldo1;
                limiteOrigem = limiteCheque1;
            }
            else if (contaOrigem == numeroConta2)
            {
                tipoOrigem = tipoConta2;
                saldoOrigem = saldo2;
                limiteOrigem = limiteCheque2;
            }
            else if (contaOrigem == numeroConta3)
            {
                tipoOrigem = tipoConta3;
                saldoOrigem = saldo3;
                limiteOrigem = limiteCheque3;
            }
            else if (contaOrigem == numeroConta4)
            {
                tipoOrigem = tipoConta4;
                saldoOrigem = saldo4;
                limiteOrigem = limiteCheque4;
            }
            else
            {
                tipoOrigem = tipoConta5;
                saldoOrigem = saldo5;
                limiteOrigem = limiteCheque5;
            }

            //definindo as variaveis de destino bb
            if (contaDestino == numeroConta1)
            {
                tipoDestino = tipoConta1;
                saldoDestino = saldo1;
            }
            else if (contaDestino == numeroConta2)
            {
                tipoDestino = tipoConta2;
                saldoDestino = saldo2;
            }
            else if (contaDestino == numeroConta3)
            {
                tipoDestino = tipoConta3;
                saldoDestino = saldo3;
            }
            else if (contaDestino == numeroConta4)
            {
                tipoDestino = tipoConta4;
                saldoDestino = saldo4;
            }
            else
            {
                tipoDestino = tipoConta5;
                saldoDestino = saldo5;
            }

            //validacao do saldo da conta de origem considerando o tipo de conta e limite
            if (tipoOrigem == 1)
            {
                if (valorTransferencia > saldoOrigem + limiteOrigem)
                {
                    printf("Erro 4! Saldo insuficiente.\n");
                    return;
                }
            }
            else if (tipoOrigem == 2)
            {
                if (valorTransferencia > saldoOrigem)
                {
                    printf("Erro 4! Saldo insuficiente.\n");
                    return;
                }
            }
            else if (tipoOrigem == 3)
            {
                if (saldoOrigem - valorTransferencia < -LIMITE_NEGATIVO_SALARIO)
                {
                    printf("Erro 4! Saldo insuficiente.\n");
                    return;
                }
            }
            else
            {
                printf("Erro 5! Tipo de conta de origem invalido.\n");
                return;
            }

            //calculo do valor liquido da transferencia 
            if (tipoDestino == 1)
            {
                valor_liquido_transferencia = valorTransferencia - (valorTransferencia * TAXA_CORRENTE);
            }
            else if (tipoDestino == 2)
            {
                valor_liquido_transferencia = valorTransferencia;
            }
            else if (tipoDestino == 3)
            {
                if (valorTransferencia <= SALARIO_MINIMO)
                {
                    valor_liquido_transferencia = valorTransferencia;
                }
                else
                {
                    valor_liquido_transferencia = valorTransferencia - (valorTransferencia * TAXA_SALARIO);
                }
            }
            else
            {
                printf("Erro 5! Tipo de conta de destino invalido.\n");
                return;
            }

            if (contaOrigem == numeroConta1)
            {
                saldo1 = saldoOrigem - valorTransferencia;
            }
            else if (contaOrigem == numeroConta2)
            {
                saldo2 = saldoOrigem - valorTransferencia;
            }
            else if (contaOrigem == numeroConta3)
            {
                saldo3 = saldoOrigem - valorTransferencia;
            }
            else if (contaOrigem == numeroConta4)
            {
                saldo4 = saldoOrigem - valorTransferencia;
            }
            else if (contaOrigem == numeroConta5)
            {
                saldo5 = saldoOrigem - valorTransferencia;
            }

            if (contaDestino == numeroConta1)
            {
                saldo1 = saldoDestino + valor_liquido_transferencia;
            }
            else if (contaDestino == numeroConta2)
            {
                saldo2 = saldoDestino + valor_liquido_transferencia;
            }
            else if (contaDestino == numeroConta3)
            {
                saldo3 = saldoDestino + valor_liquido_transferencia;
            }
            else if (contaDestino == numeroConta4)
            {
                saldo4 = saldoDestino + valor_liquido_transferencia;
            }
            else if (contaDestino == numeroConta5)
            {
                saldo5 = saldoDestino + valor_liquido_transferencia;
            }

            printf("\n         ||==============Relatorio simples===============||\n");
            printf("Conta de origem: %d\n", contaOrigem);
            printf("Conta de destino: %d\n", contaDestino);
            printf("Valor bruto da transferencia: %.2lf\n", valorTransferencia);

            if (tipoDestino == 1)
            {
                printf("Valor liquido da transferencia com taxas de 1,5%%: %.2lf\n", valor_liquido_transferencia);
            }
            else if (tipoDestino == 2)
            {
                printf("Valor liquido da transferencia com taxas de 0%%: %.2lf\n", valor_liquido_transferencia);
            }
            else
            {
                double taxa = (valorTransferencia <= SALARIO_MINIMO) ? 0.0 : TAXA_SALARIO;
                printf("Valor liquido da transferencia com taxas de %.1lf%%: %.2lf\n", taxa * 100, valor_liquido_transferencia);
            }

            if (contaOrigem == numeroConta1)
            {
                printf("Novo saldo da conta de origem: %.2lf\n", saldo1);
            }
            else if (contaOrigem == numeroConta2)
            {
                printf("Novo saldo da conta de origem: %.2lf\n", saldo2);
            }
            else if (contaOrigem == numeroConta3)
            {
                printf("Novo saldo da conta de origem: %.2lf\n", saldo3);
            }
            else if (contaOrigem == numeroConta4)
            {
                printf("Novo saldo da conta de origem: %.2lf\n", saldo4);
            }
            else
            {
                printf("Novo saldo da conta de origem: %.2lf\n", saldo5);
            }

            if (contaDestino == numeroConta1)
            {
                printf("Novo saldo da conta de destino: %.2lf\n", saldo1);
            }
            else if (contaDestino == numeroConta2)
            {
                printf("Novo saldo da conta de destino: %.2lf\n", saldo2);
            }
            else if (contaDestino == numeroConta3)
            {
                printf("Novo saldo da conta de destino: %.2lf\n", saldo3);
            }
            else if (contaDestino == numeroConta4)
            {
                printf("Novo saldo da conta de destino: %.2lf\n", saldo4);
            }
            else
            {
                printf("Novo saldo da conta de destino: %.2lf\n", saldo5);
            }

            totalSacado += valorTransferencia;
            totalDepositado += valor_liquido_transferencia;
            totalOperacoes += 2;
             printf("\n\n||=============================================================================||\n\n");
        }
        
        void aplicarRendimentoConta(void){


            double saldoAnterior;
            double saldoFinal;
            double valorAplicado;

             printf("||=============================================================================||\n\n");
            printf("Aplicando rendimento mensal em todas as contas...\n\n");

            // Conta 1
            saldoAnterior = saldo1;
            if (saldoAnterior < 0)
            {
                saldoFinal = saldoAnterior * 1.03;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo1 = saldoFinal;
            }
            else if (tipoConta1 == 2)
            {
                saldoFinal = saldoAnterior * 1.005;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo1 = saldoFinal;
            }
            else
            {
                saldoFinal = saldoAnterior;
                valorAplicado = 0.0;
            }
            printf("Conta: %d\n", numeroConta1);
            printf("Tipo de conta: %d\n", tipoConta1);
            printf("Saldo anterior: %.2lf\n", saldoAnterior);
            printf("Valor aplicado: %.2lf\n", valorAplicado);
            printf("Saldo final: %.2lf\n\n", saldoFinal);
            printf("=================================================================\n");

            // Conta 2
            saldoAnterior = saldo2;
            if (saldoAnterior < 0)
            {
                saldoFinal = saldoAnterior * 1.03;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo2 = saldoFinal;
            }
            else if (tipoConta2 == 2)
            {
                saldoFinal = saldoAnterior * 1.005;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo2 = saldoFinal;
            }
            else
            {
                saldoFinal = saldoAnterior;
                valorAplicado = 0.0;
            }
            printf("Conta: %d\n", numeroConta2);
            printf("Tipo de conta: %d\n", tipoConta2);
            printf("Saldo anterior: %.2lf\n", saldoAnterior);
            printf("Valor aplicado: %.2lf\n", valorAplicado);
            printf("Saldo final: %.2lf\n\n", saldoFinal);
            printf("=================================================================\n");

            // Conta 3
            saldoAnterior = saldo3;
            if (saldoAnterior < 0)
            {
                saldoFinal = saldoAnterior * 1.03;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo3 = saldoFinal;
            }
            else if (tipoConta3 == 2)
            {
                saldoFinal = saldoAnterior * 1.005;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo3 = saldoFinal;
            }
            else
            {
                saldoFinal = saldoAnterior;
                valorAplicado = 0.0;
            }
            printf("Conta: %d\n", numeroConta3);
            printf("Tipo de conta: %d\n", tipoConta3);
            printf("Saldo anterior: %.2lf\n", saldoAnterior);
            printf("Valor aplicado: %.2lf\n", valorAplicado);
            printf("Saldo final: %.2lf\n\n", saldoFinal);
            printf("=================================================================\n");

            // Conta 4
            saldoAnterior = saldo4;
            if (saldoAnterior < 0)
            {
                saldoFinal = saldoAnterior * 1.03;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo4 = saldoFinal;
            }
            else if (tipoConta4 == 2)
            {
                saldoFinal = saldoAnterior * 1.005;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo4 = saldoFinal;
            }
            else
            {
                saldoFinal = saldoAnterior;
                valorAplicado = 0.0;
            }
            printf("Conta: %d\n", numeroConta4);
            printf("Tipo de conta: %d\n", tipoConta4);
            printf("Saldo anterior: %.2lf\n", saldoAnterior);
            printf("Valor aplicado: %.2lf\n", valorAplicado);
            printf("Saldo final: %.2lf\n\n", saldoFinal);
            printf("=================================================================\n");

            // Conta 5
            saldoAnterior = saldo5;
            if (saldoAnterior < 0)
            {
                saldoFinal = saldoAnterior * 1.03;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo5 = saldoFinal;
            }
            else if (tipoConta5 == 2)
            {
                saldoFinal = saldoAnterior * 1.005;
                valorAplicado = saldoFinal - saldoAnterior;
                saldo5 = saldoFinal;
            }
            else
            {
                saldoFinal = saldoAnterior;
                valorAplicado = 0.0;
            }
            printf("Conta: %d\n", numeroConta5);
            printf("Tipo de conta: %d\n", tipoConta5);
            printf("Saldo anterior: %.2lf\n", saldoAnterior);
            printf("Valor aplicado: %.2lf\n", valorAplicado);
            printf("Saldo final: %.2lf\n\n", saldoFinal);
            printf("=================================================================\n");
             printf("\n\n||=============================================================================||\n\n");
        }
      
        void  exibirExtrato(){

            // Exibição de todas as contas
            printf("||=============================================================================||\n\n");
            printf("Digite o numero da conta para exibir o extrato:\n");
            scanf("%d", &num_conta_escolhida);

            if (num_conta_escolhida < 1001 || num_conta_escolhida > 1005)
            {
                printf("Erro 1! Conta invalida.\n");
                return;
            }
            
            if(num_conta_escolhida == numeroConta1){
                printf("Extrato da Conta %d:\n", numeroConta1);
                printf("Numero da conta: %d\n", numeroConta1);
                printf("Codigo do titular: %d\n", codTitular1);
                printf("Tipo de conta: %d\n", tipoConta1);               
                printf("Saldo atual: %.2lf\n", saldo1);
                printf("Limite de cheque especial: %.2lf\n", limiteCheque1);

                        if (saldo1>= 10 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Excelente (Codigo 4)\n");
                    }
                    else if (saldo1 >= 3 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Boa (Codigo 3)\n");
                    }
                    else if (saldo1 >= 0)
                    {
                        printf("Saude financeira: Regular (Codigo 2)\n");
                    }
                    else
                    {
                        printf("Saude financeira: Ruim (Codigo 1)\n");
                    }
                printf("=================================================================\n");
            }
            else if(num_conta_escolhida == numeroConta2){
                printf("Extrato da Conta %d:\n", numeroConta2);
                printf("Numero da conta: %d\n", numeroConta2);
                printf("Codigo do titular: %d\n", codTitular2);
                printf("Tipo de conta: %d\n", tipoConta2);              
                printf("Saldo atual: %.2lf\n", saldo2);
                printf("Limite de cheque especial: %.2lf\n", limiteCheque2);

                        if (saldo2>= 10 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Excelente (Codigo 4)\n");
                    }
                    else if (saldo2 >= 3 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Boa (Codigo 3)\n");
                    }
                    else if (saldo2 >= 0)
                    {
                        printf("Saude financeira: Regular (Codigo 2)\n");
                    }
                    else
                    {
                        printf("Saude financeira: Ruim (Codigo 1)\n");
                    }
                printf("=================================================================\n");
            }
            else if(num_conta_escolhida == numeroConta3){
                printf("Extrato da Conta %d:\n", numeroConta3);
                printf("Numero da conta: %d\n", numeroConta3);
                printf("Codigo do titular: %d\n", codTitular3);
                printf("Tipo de conta: %d\n", tipoConta3);               
                printf("Saldo atual: %.2lf\n", saldo3);
                printf("Limite de cheque especial: %.2lf\n", limiteCheque3);

                        if (saldo3>= 10 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Excelente (Codigo 4)\n");
                    }
                    else if (saldo3 >= 3 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Boa (Codigo 3)\n");
                    }
                    else if (saldo3 >= 0)
                    {
                        printf("Saude financeira: Regular (Codigo 2)\n");
                    }
                    else
                    {
                        printf("Saude financeira: Ruim (Codigo 1)\n");
                    }
                printf("=================================================================\n");
            }
            else if(num_conta_escolhida == numeroConta4){
                printf("Extrato da Conta %d:\n", numeroConta4);
                printf("Numero da conta: %d\n", numeroConta4);
                printf("Codigo do titular: %d\n", codTitular4);
                printf("Tipo de conta: %d\n", tipoConta4);               
                printf("Saldo atual: %.2lf\n", saldo4);
                printf("Limite de cheque especial: %.2lf\n", limiteCheque4);

                        if (saldo4>= 10 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Excelente (Codigo 4)\n");
                    }
                    else if (saldo4 >= 3 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Boa (Codigo 3)\n");
                    }
                    else if (saldo4 >= 0)
                    {
                        printf("Saude financeira: Regular (Codigo 2)\n");
                    }
                    else
                    {
                        printf("Saude financeira: Ruim (Codigo 1)\n");
                    }
                printf("=================================================================\n");
            }
            else if(num_conta_escolhida == numeroConta5){
                printf("Extrato da Conta %d:\n", numeroConta5);
                printf("Numero da conta: %d\n", numeroConta5);
                printf("Tipo de conta: %d\n", tipoConta5);
                printf("Codigo do titular: %d\n", codTitular5);
                printf("Saldo atual: %.2lf\n", saldo5);
                printf("Limite de cheque especial: %.2lf\n", limiteCheque5);

                        if (saldo5>= 10 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Excelente (Codigo 4)\n");
                    }
                    else if (saldo5 >= 3 * SALARIO_MINIMO)
                    {
                        printf("Saude financeira: Boa (Codigo 3)\n");
                    }
                    else if (saldo5 >= 0)
                    {
                        printf("Saude financeira: Regular (Codigo 2)\n");
                    }
                    else
                    {
                        printf("Saude financeira: Ruim (Codigo 1)\n");
                    }
                printf("=================================================================\n");
                
            }
             printf("||=============================================================================||\n\n");
        }

        void  relatorioGeral(){

             //exibição
            printf("||=============================================================================||\n\n");
            printf("                  Gerando relatorio geral...   \n\n");
            printf("||=============================================================================||\n\n");

            printf("Numero da conta: %d\n", numeroConta1);
            printf("Codigo do titular: %d\n", codTitular1);
            printf("Tipo de conta: %d\n", tipoConta1);               
            printf("Saldo atual: %.2lf\n", saldo1);

            printf("||=============================================================================||\n\n");
            printf("Numero da conta: %d\n", numeroConta2);
            printf("Codigo do titular: %d\n", codTitular2);
            printf("Tipo de conta: %d\n", tipoConta2);               
            printf("Saldo atual: %.2lf\n", saldo2);

            printf("||=============================================================================||\n\n");
            printf("Numero da conta: %d\n", numeroConta3);
            printf("Codigo do titular: %d\n", codTitular3);
            printf("Tipo de conta: %d\n", tipoConta3);               
            printf("Saldo atual: %.2lf\n", saldo3);

            printf("||=============================================================================||\n\n");
            printf("Numero da conta: %d\n", numeroConta4);
            printf("Codigo do titular: %d\n", codTitular4);
            printf("Tipo de conta: %d\n", tipoConta4);               
            printf("Saldo atual: %.2lf\n", saldo4);

            printf("||=============================================================================||\n\n");
            printf("Numero da conta: %d\n", numeroConta5);
            printf("Codigo do titular: %d\n", codTitular5);
            printf("Tipo de conta: %d\n", tipoConta5);           
            printf("Saldo atual: %.2lf\n", saldo5);
            printf("||=============================================================================||\n\n");

            // Media dos saldos
            printf("=========================\nMedia dos saldos: %.2lf\n", (saldo1 + saldo2 + saldo3 + saldo4 + saldo5) / 5);

            // Maior saldo
            {
                double maiorSaldo = saldo1;
                int contaMaior = numeroConta1;
                int titularMaior = codTitular1;

                if (saldo2 > maiorSaldo) { maiorSaldo = saldo2; contaMaior = numeroConta2; titularMaior = codTitular2; }
                if (saldo3 > maiorSaldo) { maiorSaldo = saldo3; contaMaior = numeroConta3; titularMaior = codTitular3; }
                if (saldo4 > maiorSaldo) { maiorSaldo = saldo4; contaMaior = numeroConta4; titularMaior = codTitular4; }
                if (saldo5 > maiorSaldo) { maiorSaldo = saldo5; contaMaior = numeroConta5; titularMaior = codTitular5; }

                printf("Maior saldo: %.2lf da conta %d do titular %d\n", maiorSaldo, contaMaior, titularMaior);
            }
            
            // Menor saldo
            {
                double menorSaldo = saldo1;
                int contaMenor = numeroConta1;
                int titularMenor = codTitular1;

                if (saldo2 < menorSaldo) { menorSaldo = saldo2; contaMenor = numeroConta2; titularMenor = codTitular2; }
                if (saldo3 < menorSaldo) { menorSaldo = saldo3; contaMenor = numeroConta3; titularMenor = codTitular3; }
                if (saldo4 < menorSaldo) { menorSaldo = saldo4; contaMenor = numeroConta4; titularMenor = codTitular4; }
                if (saldo5 < menorSaldo) { menorSaldo = saldo5; contaMenor = numeroConta5; titularMenor = codTitular5; }

                printf("Menor saldo: %.2lf da conta %d do titular %d\n", menorSaldo, contaMenor, titularMenor);
            }

            printf("Soma total dos saldos: %.2lf\n", saldo1 + saldo2 + saldo3 + saldo4 + saldo5);

            //saldo negativo usando contador
            printf("Quantitade de contas com saldo negativo:");
            int contasNegativas = 0;
                if (saldo1 < 0)            {
                    contasNegativas++;
                }
                if (saldo2 < 0)            {
                    contasNegativas++;
                }
                if (saldo3 < 0)            {
                    contasNegativas++;
                }
                if (saldo4 < 0)            {
                    contasNegativas++;
                }
                if (saldo5 < 0)            {
                    contasNegativas++;
                }
                printf(" %d\n", contasNegativas);

                //Total de contas corrente, poupanca e salario usando contador
                printf("Total de contas do tipo corrente:");
                int contasCorrente = 0;
                if (tipoConta1 == 1)            {
                    contasCorrente++;
                }
                if (tipoConta2 == 1)            {
                    contasCorrente++;
                }
                if (tipoConta3 == 1)            {
                    contasCorrente++;
                }
                if (tipoConta4 == 1)            {
                    contasCorrente++;
                }
                if (tipoConta5 == 1)            {
                    contasCorrente++;
                }
                printf(" %d\n", contasCorrente);

                //Poupanca
                 printf("Total de contas do tipo poupanca:");
                int contasPoupanca = 0;
                if (tipoConta1 == 2)            {
                    contasPoupanca++;
                }
                if (tipoConta2 == 2)            {
                    contasPoupanca++;
                }
                if (tipoConta3 == 2)            {
                    contasPoupanca++;
                }
                if (tipoConta4 == 2)            {
                    contasPoupanca++;
                }
                if (tipoConta5 == 2)            {
                    contasPoupanca++;
                }
                printf(" %d\n", contasPoupanca);

                //Salario
                 printf("Total de contas do tipo salario:");
                int contasSalario = 0;
                if (tipoConta1 == 3)            {
                    contasSalario++;
                }
                if (tipoConta2 == 3)            {
                    contasSalario++;
                }
                if (tipoConta3 == 3)            {
                    contasSalario++;
                }
                if (tipoConta4 == 3)            {
                    contasSalario++;
                }
                if (tipoConta5 == 3)            {
                    contasSalario++;
                }
                printf(" %d\n", contasSalario);
                printf("\n\n||=============================================================================||\n\n");
        }
        
        void   relatorioFinal(){

            printf("||=============================================================================||\n\n"); 
            printf("Gerando Relatorio Final...\n\n");

            // Media dos saldos
            printf("=========================\nMedia dos saldos: %.2lf\n", (saldo1 + saldo2 + saldo3 + saldo4 + saldo5) / 5);

            // Maior saldo
            {
                double maiorSaldo = saldo1;
                int contaMaior = numeroConta1;
                int titularMaior = codTitular1;

                if (saldo2 > maiorSaldo) { maiorSaldo = saldo2; contaMaior = numeroConta2; titularMaior = codTitular2; }
                if (saldo3 > maiorSaldo) { maiorSaldo = saldo3; contaMaior = numeroConta3; titularMaior = codTitular3; }
                if (saldo4 > maiorSaldo) { maiorSaldo = saldo4; contaMaior = numeroConta4; titularMaior = codTitular4; }
                if (saldo5 > maiorSaldo) { maiorSaldo = saldo5; contaMaior = numeroConta5; titularMaior = codTitular5; }

                printf("Maior saldo: %.2lf da conta %d do titular %d\n", maiorSaldo, contaMaior, titularMaior);
            }
            
            // Menor saldo
            {
                double menorSaldo = saldo1;
                int contaMenor = numeroConta1;
                int titularMenor = codTitular1;

                if (saldo2 < menorSaldo) { menorSaldo = saldo2; contaMenor = numeroConta2; titularMenor = codTitular2; }
                if (saldo3 < menorSaldo) { menorSaldo = saldo3; contaMenor = numeroConta3; titularMenor = codTitular3; }
                if (saldo4 < menorSaldo) { menorSaldo = saldo4; contaMenor = numeroConta4; titularMenor = codTitular4; }
                if (saldo5 < menorSaldo) { menorSaldo = saldo5; contaMenor = numeroConta5; titularMenor = codTitular5; }

                printf("Menor saldo: %.2lf da conta %d do titular %d\n", menorSaldo, contaMenor, titularMenor);
            }

            printf("Soma total dos saldos: %.2lf\n", saldo1 + saldo2 + saldo3 + saldo4 + saldo5);

            //saldo negativo usando contador
            printf("Quantitade de contas com saldo negativo:");
            int contasNegativas = 0;
                if (saldo1 < 0)            {
                    contasNegativas++;
                }
                if (saldo2 < 0)            {
                    contasNegativas++;
                }
                if (saldo3 < 0)            {
                    contasNegativas++;
                }
                if (saldo4 < 0)            {
                    contasNegativas++;
                }
                if (saldo5 < 0)            {
                    contasNegativas++;
                }
                printf(" %d\n", contasNegativas);

                //Total de contas corrente, poupanca e salario usando contador
                printf("Total de contas do tipo corrente:");
                int contasCorrente = 0;
                if (tipoConta1 == 1)            {
                    contasCorrente++;
                }
                if (tipoConta2 == 1)            {
                    contasCorrente++;
                }
                if (tipoConta3 == 1)            {
                    contasCorrente++;
                }
                if (tipoConta4 == 1)            {
                    contasCorrente++;
                }
                if (tipoConta5 == 1)            {
                    contasCorrente++;
                }
                printf(" %d\n", contasCorrente);

                //Poupanca
                 printf("Total de contas do tipo poupanca:");
                int contasPoupanca = 0;
                if (tipoConta1 == 2)            {
                    contasPoupanca++;
                }
                if (tipoConta2 == 2)            {
                    contasPoupanca++;
                }
                if (tipoConta3 == 2)            {
                    contasPoupanca++;
                }
                if (tipoConta4 == 2)            {
                    contasPoupanca++;
                }
                if (tipoConta5 == 2)            {
                    contasPoupanca++;
                }
                printf(" %d\n", contasPoupanca);

                //Salario
                 printf("Total de contas do tipo salario:");
                int contasSalario = 0;
                if (tipoConta1 == 3)            {
                    contasSalario++;
                }
                if (tipoConta2 == 3)            {
                    contasSalario++;
                }
                if (tipoConta3 == 3)            {
                    contasSalario++;
                }
                if (tipoConta4 == 3)            {
                    contasSalario++;
                }
                if (tipoConta5 == 3)            {
                    contasSalario++;
                }
                printf(" %d\n", contasSalario);

                printf("===========================================================\n\n");
                
            
                printf("Extrato da Conta %d:\n", numeroConta1);
                printf("Numero da conta: %d\n", numeroConta1);
                printf("Codigo do titular: %d\n", codTitular1);
                printf("Saldo inicial: %f\n",saldoInicial1);               
                printf("Saldo atual: %.2lf\n", saldo1);
                printf("=================================================================\n");
            
            
                printf("Extrato da Conta %d:\n", numeroConta2);
                printf("Numero da conta: %d\n", numeroConta2);
                printf("Codigo do titular: %d\n", codTitular2);
                printf("Saldo inicial: %f\n",saldoInicial2);              
                printf("Saldo atual: %.2lf\n", saldo2);
                printf("=================================================================\n");
            
            
                printf("Extrato da Conta %d:\n", numeroConta3);
                printf("Numero da conta: %d\n", numeroConta3);
                printf("Codigo do titular: %d\n", codTitular3);
                printf("Saldo inicial: %f\n",saldoInicial3);         
                printf("Saldo atual: %.2lf\n", saldo3);
                printf("=================================================================\n");
            
           
                printf("Extrato da Conta %d:\n", numeroConta4);
                printf("Numero da conta: %d\n", numeroConta4);
                printf("Codigo do titular: %d\n", codTitular4);
                printf("Saldo inicial: %f\n",saldoInicial4);               
                printf("Saldo atual: %.2lf\n", saldo4);
                printf("=================================================================\n");
            
            
                printf("Extrato da Conta %d:\n", numeroConta5);
                printf("Numero da conta: %d\n", numeroConta5);
                printf("Saldo inicial: %f\n",saldoInicial5);
                printf("Codigo do titular: %d\n", codTitular5);
                printf("Saldo atual: %.2lf\n", saldo5);
                printf("=================================================================\n");

                 double variancia;
                
                //Calculo das variancias
                    variancia = ((saldo1 - saldoInicial1)/saldoInicial1) * 100;
                    printf("Variacao percentual da conta 1001:%f", variancia);
                
                    variancia = ((saldo2 - saldoInicial2)/saldoInicial2) * 100;
                     printf("Variacao percentual da conta 1002:%f", variancia);
               
                    variancia = ((saldo3 - saldoInicial3)/saldoInicial3) * 100;
                     printf("Variacao percentual da conta 1003:%f", variancia);
               
                    variancia = ((saldo4 - saldoInicial4)/saldoInicial4) * 100;
                     printf("Variacao percentual da conta 1004:%f", variancia);
                
                    variancia = ((saldo5 - saldoInicial5)/saldoInicial5) * 100;
                     printf("Variacao percentual da conta 1005:%f", variancia);
                     
        
         printf("\n\n||=============================================================================||\n\n");
    }

        
    int main() {    
        
    printf("\n||=====Bem-vindo ao Sistema de Simulacao de Banco!=====||\n");
    printf("||=====Vamos comecar cadastrando as contas!=====||\n");

        //Cadastro
                printf("\nCadastro da Conta 1\n");
                cadastrarConta1();
                printf("||=============================================================================||\n\n");
                printf("\nCadastro da Conta 2\n");
                cadastrarConta2();
                printf("||=============================================================================||\n\n");
                printf("\nCadastro da Conta 3\n");
                cadastrarConta3();
                printf("||=============================================================================||\n\n");
                printf("\nCadastro da Conta 4\n");
                cadastrarConta4();
                printf("||=============================================================================||\n\n");
                printf("\nCadastro da Conta 5\n");
                cadastrarConta5();
                printf("||=============================================================================||\n\n");
        //Menu

        do {
            printf("           || =================================================== ||\n                 BEM-VINDO AO SISTEMA BANCARIO - MENU PRINCIPAL \n           || =================================================== ||");
            printf("\n             [1] Depositar\n             [2] Saque\n             [3] Transferir entre contas\n             [4] Aplicar rendimento mensal\n             [5] Exibir extrato de uma conta\n             [6] Exibir relatorio geral\n             [0] Encerrar e gerar relatorio\n \n");         
            
            printf("           Digite sua opcao: ==>  ");
            scanf("%d",&opcao_menu);  printf("\n");
           
            printf("           ||====================================================||\n");

                switch (opcao_menu)
                {
                       case 0:
                        relatorioFinal();
                        break;
                    case 1:
                        depositar();
                        break;
                    case 2:
                        sacar();
                        break;
                    case 3:
                        transferir();
                        break;
                    case 4:
                        aplicarRendimentoConta();
                        break;
                    case 5:
                        exibirExtrato();
                        break;
                    case 6:
                        relatorioGeral();
                        break;
                    
                }
            }

            while (opcao_menu != 0);
                 
    return 0;
    }


