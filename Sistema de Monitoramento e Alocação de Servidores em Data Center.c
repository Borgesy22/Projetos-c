#include <stdio.h>
#include <locale.h>


#define MAX_SERVIDORES 100
#define OFF 2
#define ON 1
#define RESFRIAMENTO 3

int idServidor[MAX_SERVIDORES]; int status[MAX_SERVIDORES]; 

double cargaUso[MAX_SERVIDORES]; double temperatura[MAX_SERVIDORES]; double capacidadeMemoria[MAX_SERVIDORES]; 

int contadorServidores = 0;



//Function 1 registrar novo servidor
void registrarNovoServidor() {

    printf("\n||==============================================================================||\n");
    if (contadorServidores >= MAX_SERVIDORES) {
        printf("Limite de servidores atingido. Não é possível registrar mais servidores.\n");
        return;
    }

    printf("Digite o ID do servidor: ");
    scanf("%d", &idServidor[contadorServidores]);

    for (int i = 0; i < contadorServidores; i++) {
        if (idServidor[i] == idServidor[contadorServidores]) {
            printf("Erro: ID do servidor já existe. Tente novamente.\n");
            return;
        }
    }

    printf("Digite a capacidade de memória do servidor (em GB): ");
    scanf("%lf", &capacidadeMemoria[contadorServidores]);

    status[contadorServidores] = OFF; // Servidor off
    cargaUso[contadorServidores] = 0.0; // Carga de uso inicial
    temperatura[contadorServidores] = 20; // Temperatura inicial

    contadorServidores++;

    }

void alocarCargaProcessamento() {

            printf("\n||==============================================================================||\n");
            double novaCarga;
            int id;
            int encontrado = 0; // Flag para saber se achamos o servidor

            printf("||====================================================||\n");
            printf("Digite o ID do servidor para alocar carga de processamento: ");
            scanf("%d", &id);

            for (int i = 0; i < contadorServidores; i++) {
                
                if (idServidor[i] == id) {
                    encontrado = 1; 

                    if (status[i] == OFF) {
                        printf("Aviso: O servidor estava desligado. Ele foi ligado para alocar a carga.\n");
                        status[i] = ON; 
                    }
                    else if (status[i] == RESFRIAMENTO) {  
                        printf("Erro: Servidor está em processo de resfriamento. Não é possível alocar carga.\n");
                        return; 
                    }

                    printf("Digite a carga de processamento a ser adicionada (em %%): ");
                    scanf("%lf", &novaCarga);

                    while (novaCarga <= 0 || novaCarga > 100) {
                        printf("Erro: Valor inválido. Digite um valor maior que 0 e até 100.\n");
                        scanf("%lf", &novaCarga);
                    }
                  
                    if (cargaUso[i] + novaCarga > 100.0) {
                        printf("Erro: A operação excede o limite do servidor. Carga atual: %.2lf%%\n", cargaUso[i]);
                        return;
                    } else {
                        cargaUso[i] += novaCarga; 
                        printf("Carga alocada com sucesso! Carga atual do servidor: %.2lf%%\n", cargaUso[i]);
                    }
                    
                    return; 
                }
            }
            
            if (!encontrado) {
                printf("Erro: Nenhum servidor encontrado com o ID %d.\n", id);
            }
        }

void liberarCargaProcessamento() {


    printf("\n||==============================================================================||\n");
    int idBusca;
    int encontrado = 0;

     if (contadorServidores == 0)
        {
            printf("Nenhum servidor registrado. Retornando ao menu...\n");
            return;
        }

    printf("Digite o ID do servidor: ");
    scanf("%d", &idBusca);  

    for (int i = 0; i < contadorServidores; i++)
    {
        
        if (idServidor[i] == idBusca) {
            encontrado = 1;
            double cargaALiberar;
            
            printf("Digite a carga de processamento a ser liberada (em %%): ");
            scanf("%lf", &cargaALiberar);

            while (cargaALiberar <= 0 || cargaALiberar > 100) {
                printf("Erro: Valor inválido. Digite um valor maior que 0 e até 100.\n");
                scanf("%lf", &cargaALiberar);
            }

            if (cargaUso[i] - cargaALiberar < 0.0) {
                printf("Erro: A operação resultaria em carga negativa. Carga atual: %.2lf%%\n", cargaUso[i]);
                return;
            }

            else
             {
                cargaUso[i] -= cargaALiberar; 
                printf("Carga liberada com sucesso! Carga atual do servidor: %.2lf%%\n", cargaUso[i]);
            }
            
            return;
        }
    }
        if (!encontrado) {
            printf("Erro: Nenhum servidor encontrado com o ID %d.\n", idBusca);
        }

}

void registrarLeituraTemperatura() {

    printf("\n||==============================================================================||\n");
    int idBusca;
    int encontrado = 0;

     if (contadorServidores == 0)
        {
            printf("Nenhum servidor registrado. Retornando ao menu...\n");
            return;
        }

    printf("Digite o ID do servidor: ");
    scanf("%d", &idBusca);  

    for (int i = 0; i < contadorServidores; i++)
    {
        
        if (idServidor[i] == idBusca) {
            encontrado = 1;
            double novaTemperatura;
            
            printf("Digite a nova leitura de temperatura do servidor (em °C): ");
            scanf("%lf", &novaTemperatura);

            if (novaTemperatura < -20 || novaTemperatura > 85.00) 
            {
                printf("Alerta Crítico: Temperatura fora do intervalo seguro (-20°C a 85°C).\n");
                status[i] = RESFRIAMENTO;
                cargaUso[i] = 0.0;
                printf("O servidor foi desligado para resfriamento. Carga de uso resetada\n");
                return;
            }  

            temperatura[i] = novaTemperatura; 
            printf("Leitura de temperatura registrada com sucesso! Temperatura atual do servidor: %.2lf°C\n", temperatura[i]);        
            return;
        }
    }
        if (!encontrado) {
            printf("Erro: Nenhum servidor encontrado com o ID %d.\n", idBusca);
        }

}

void consultarStatusServidor() {


    printf("\n||==============================================================================||\n");
    int idBusca;
    int encontrado = 0;

     if (contadorServidores == 0)
        {
            printf("Nenhum servidor registrado. Retornando ao menu...\n");
            return;
        }

        printf("Digite o ID do servidor: ");
        scanf("%d", &idBusca);  

            for (int i = 0; i < contadorServidores; i++)
            {
                
                if (idServidor[i] == idBusca) {
                    encontrado = 1;
                    printf("Status do Servidor ID %d:\n", idServidor[i]);
                    printf("Status: %s\n", (status[i] == ON) ? "Ligado" : (status[i] == OFF) ? "Desligado" : "Em Resfriamento");
                    printf("Carga de Uso: %.2lf%%\n", cargaUso[i]);
                    printf("Temperatura: %.2lf°C\n", temperatura[i]);
                    printf("Capacidade de Memória: %.2lf GB\n", capacidadeMemoria[i]);
                    return;
                }
            }
                if (!encontrado) {
                    printf("Erro: Nenhum servidor encontrado com o ID %d.\n", idBusca);
                }
}

void relatorioDesempenhoDataCenter() {


      printf("\n||==============================================================================||\n");
    if (contadorServidores == 0)
        {
            printf("Nenhum servidor registrado. Retornando ao menu...\n");
            return;
        }

        printf("Relatório de Desempenho do Data Center:\n");
        printf("Total de Servidores: %d\n", contadorServidores);
        printf("ID\t Status\t \tCarga de Uso \tTemperatura\tCapacidade Memória\n");
        printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < contadorServidores; i++)
    {
        printf("%d\t%s\t%.2lf%%\t\t%.2lf°C\t%.2lf GB\n", idServidor[i], 
               (status[i] == ON) ? "Ligado" : (status[i] == OFF) ? "Desligado" : "Em Resfriamento", 
               cargaUso[i], temperatura[i], capacidadeMemoria[i]);
    }
}

void setstatus(){
    
for (int i = 0; i < contadorServidores; i++)
{
    printf("Digite o status do servidor ID %d (1 para ON, 2 para OFF, 3 para RESFRIAMENTO): ", idServidor[i]);
    scanf("%d", &status[i]);
}
}


int main(){

    setlocale(LC_ALL, "Portuguese");

    int opcao_menu;
    
    do
    {
       
            printf("||==============================================================================||\n");
            printf("           BEM-VINDO AO SISTEMA DE MONITORAMENTO DE SERVIDORES - MENU PRINCIPAL \n");
            printf("||==============================================================================||\n");
            
            printf("             [1] Registrar Novo Servidor\n");
            printf("             [2] Alocar Carga de Processamento\n");
            printf("             [3] Liberar Carga de Processamento\n");
            printf("             [4] Registrar Leitura de Temperatura\n");
            printf("             [5] Setar Status de um Servidor\n");
            printf("             [6] Consultar Status de um Servidor\n");
            printf("             [7] Relatório de Desempenho do Data Center\n");
            printf("             [0] Encerrar Sistema\n");
            printf("           Digite sua opção: ==>  ");

            scanf("%d", &opcao_menu);

            switch (opcao_menu)        
            {
            case 1:
                registrarNovoServidor();
                break;
            case 2:
                alocarCargaProcessamento();
                break;
            case 3:
                liberarCargaProcessamento();
                break;
            case 4:
                registrarLeituraTemperatura();
                break;
            case 5:
                setstatus();
                break;
            case 6:
                consultarStatusServidor();
                break;
            case 7:
                relatorioDesempenhoDataCenter();
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
    }
     while (opcao_menu != 0);

    return 0;

}