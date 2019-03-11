#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <windows.h> 
 
struct obra
{
    char codigo[5];
	char nome[150];
	char endereco[50];
    float valor;
	char responsavel[20];	
    char data[10];    
};
 
int  exibirMenu(void);
void adicionarObra(void);
void consultarObra(void);
void alterarObra(void);
void excluirObra(void);
void listarObrasOrdemAlfabetica(void);
void listarObrasValorTotal(void);
void listarObrasDataPrevista(void);
void listarObrasGeral(void);


 
int main(void)


{
    int opcao;
 
    do
    {
        opcao = exibirMenu();
 
        switch (opcao)
        {
        case 1:
            adicionarObra();
            break;
        case 2:
            consultarObra();
            break;
        case 3:
            alterarObra();
            break;
        case 4:
            excluirObra();
            break;
        case 5:
            printf("\n Encerrando...");
            break;
        case 6:
            listarObrasValorTotal();
            break;    
        case 7:
            listarObrasDataPrevista();
            break;        
        case 8:
            listarObrasGeral();
            break;            
        default:
            printf("\n Opcao invalida!");
        }
        Sleep(1000); 
    } while (opcao != 5);
 
    return 0;
}
 
int exibirMenu(void)
{
    int opcao;
 
    system("cls"); // Se estiver usando Linux, é system("clear");
 
    printf("\tCONTROLE DE OBRAS \n\n");
    printf(" 1. Cadastrar Obra\n");
    printf(" 2. Consultar Obra\n");
    printf(" 3. Alterar Obra\n");
    printf(" 4. Excluir Obra\n");
    printf(" 5. Encerrar\n");
    printf(" 6. Listar valor total das Obras\n");
    printf(" 7. Listar Obras por data\n");    
    printf(" 8. Listar Obras \n\n");    
    printf(" Digite a opcao desejada: ");
    scanf("%d", &opcao);
 
    return opcao;
}
 
void adicionarObra(void)
{
    struct obra minhaObra;
    FILE *arquivo;
 
    system("cls"); // Se estiver usando Linux, é system("clear");
 
    printf("\tCONTROLE DE OBRAS - CADASTRAR OBRA\n\n");
    
	printf(" Código: ");    
	fflush(stdin);        
    gets(minhaObra.codigo);
	
	printf(" Nome: ");
    fflush(stdin);        
    gets(minhaObra.nome);
    
    
	printf(" Endereço: ");
    fflush(stdin);        
    gets(minhaObra.endereco);
    
    
    printf(" Valor: ");    
    fflush(stdin);        
    scanf("%f",&minhaObra.valor);
    
	printf(" Engenheiro(a) Responsável: ");
    fflush(stdin);        
	gets(minhaObra.responsavel);
    
    
    printf(" Previsão de entregra: ");
    fflush(stdin);        
    gets(minhaObra.data);
    
 
    arquivo = fopen("obras.txt", "ab");
    if (!arquivo)
    {
        arquivo = fopen("obra.txt", "wb");
    }
 
    fwrite(&minhaObra, 1, sizeof(struct obra), arquivo);
 
    fclose(arquivo);
}
 
void consultarObra(void)
{
    int encontrado = 0;
    char busca[100];
    struct obra minhaObra;
    FILE *arquivo;
 	
 
    system("cls");    
    
    
 
    printf("\tCONTROLE DE OBRAS - BUSCAR OBRA\n\n");
    
    printf(" Código da obra: ");
    fflush(stdin);
    gets(busca);
 
    arquivo = fopen("obras.txt", "rb");
 
    if (arquivo)
    {
        fread(&minhaObra, 1, sizeof(struct obra), arquivo);
        while (!feof(arquivo))
        {
            if (strcmp(busca, minhaObra.codigo) == 0)
            {
                
                printf("\n Código: %s\n", minhaObra.codigo);
				printf(" Nome: %s\n", minhaObra.nome);
				printf(" Endereco: %s\n", minhaObra.endereco);
                printf(" Valor: %.2f\n", minhaObra.valor);
                printf(" Engenheiro(a) Responsável: %s\n", minhaObra.responsavel);
                printf(" Previsão de Entrega: %s\n", minhaObra.data);                
				encontrado = 1;                
            }
            fread(&minhaObra, 1, sizeof(struct obra), arquivo);
        }		
 		
 
        if (!encontrado)
        {
            printf("\n Obra não encontrada!\n");
            
        }
        fclose(arquivo);
    }
    else
    {
        printf("\n Nada encontrado no arquivo!\n");
        
    }
    
    system("PAUSE");
}

void listarObrasGeral(void)
{
    int encontrado = 0;    
    struct obra minhaObra;
    FILE *arquivo;
 
    system("cls"); 
 
    printf("\tCONTROLE DE OBRAS - RELACAO DAS OBRAS \n\n");    
 
    arquivo = fopen("obras.txt", "rb");
 
    if (arquivo)
    {
        fread(&minhaObra, 1, sizeof(struct obra), arquivo);
        while (!feof(arquivo))
        {
            
                
                printf("\n Código: %s\n", minhaObra.codigo);
				printf(" Nome: %s\n", minhaObra.nome);
				printf(" Endereco: %s\n", minhaObra.endereco);
                printf(" Valor: %.2f\n", minhaObra.valor);
                printf(" Engenheiro(a) Responsável: %s\n", minhaObra.responsavel);
                printf(" Previsão de Entrega: %s\n", minhaObra.data);                
				encontrado = 1;                
            
            fread(&minhaObra, 1, sizeof(struct obra), arquivo);
        }		
 		
 
        if (!encontrado)
        {
            printf("\n Obra não encontrada!\n");
            
        }
        fclose(arquivo);
    }
    else
    {
        printf("\n Nada encontrado no arquivo!\n");
        
    }
    
    system("PAUSE");
}

 
void alterarObra(void)
{
    int encontrado = 0;
    char nome[100], endereco[100],responsavel[100],data[10];
    char codigo[5];	
    char valor[10];	
    
    struct obra obraTemporaria;
    FILE *arquivoAntigo = NULL, *arquivoAtualizado = NULL;
 
 	listarObrasGeral();
 	
    system("cls"); // Se estiver usando Linux, é system("clear");
 
    printf("\tCONTROLE DE OBRAS - ATUALIZAR OBRA\n\n");
    printf(" Código da Obra: ");
    fflush(stdin);
    gets(codigo);
    printf(" Novo Nome: ");
    fflush(stdin);
    gets(nome);    
	printf(" Novo Endereço: ");
    fflush(stdin);
    gets(endereco);   	
    printf("Novo Responsável: ");
    fflush(stdin);
    gets(responsavel);
    printf(" Nova Data: ");
    fflush(stdin);
    gets(data);
 
    arquivoAntigo = fopen("obras.txt", "rb");
    if (arquivoAntigo)
    {
        arquivoAtualizado = fopen("temp.txt", "wb");
        if (!arquivoAtualizado)
        {
            printf("\n Falha na atualizacao da obra!");
            Sleep(1000); 
            return;
        }
 
        fread(&obraTemporaria, 1, sizeof(struct obra), arquivoAntigo);
        while (!feof(arquivoAntigo))
        {
            if (strcmp(obraTemporaria.codigo, codigo) == 0)
            {
                strcpy(obraTemporaria.nome, nome);                
				strcpy(obraTemporaria.endereco, endereco);                				
                strcpy(obraTemporaria.responsavel, responsavel);
                strcpy(obraTemporaria.data, data);                
                encontrado = 1;
            }
            fwrite(&obraTemporaria, 1, sizeof(struct obra), arquivoAtualizado);
            fread(&obraTemporaria, 1, sizeof(struct obra), arquivoAntigo);
        }
 
        fclose(arquivoAntigo);
        fclose(arquivoAtualizado);
 
        remove("obras.txt");
        rename("temp.txt", "obras.txt");
 
        if (!encontrado)
        {
            printf("\n Nao foi possivel encontrar a obra...");
        }
        else
        {
            printf("\n Atualizacao realizada com sucesso!");
        }
 
        Sleep(1000); // Se estiver usando Linux, é sleep(1);
    }
    else
    {
        printf("\n Nenhuma obra encontrada!");
        Sleep(1000); // Se estivar usando Linux, é sleep(1);
    }
}

void listarObrasValorTotal(void)
{
    int encontrado = 0;	
	float somatorio=0.0;
    struct obra minhaObra;
    FILE *arquivo;
    
    
 
    system("cls"); 
 
     
    arquivo = fopen("obras.txt", "rb");
 
    if (arquivo)
    {
        fread(&minhaObra, 1, sizeof(struct obra), arquivo);
        while (!feof(arquivo))
        {
            
              
                
            printf(" %s\t -> Valor: %.2f\n", minhaObra.nome, minhaObra.valor);
            somatorio += minhaObra.valor;
			encontrado = 1;                
			
            
            fread(&minhaObra, 1, sizeof(struct obra), arquivo);
        }		
 		
 		
 
        if (!encontrado)
        {
            printf("\n Obra não encontrada!\n");
            
        }
        else{
        	
        	printf("Valor total das Obras: %.2f\n",somatorio);
		}
        
        fclose(arquivo);
    }
    else
    {
        printf("\n Nada encontrado no arquivo!\n");
        
    }
    
    system("PAUSE");
}

void listarObrasDataPrevista(void)
{
    int encontrado = 0;
    char data_obra[10];
    struct obra minhaObra;
    FILE *arquivo;
 
    system("cls"); 
 
    printf("\tCONTROLE DE OBRAS - LISTAR OBRAS POR DATA\n\n");
    printf(" Data da Obra: ");
    fflush(stdin);
    gets(data_obra);
 
    arquivo = fopen("obras.txt", "rb");
 
    if (arquivo)
    {
        fread(&minhaObra, 1, sizeof(struct obra), arquivo);
        while (!feof(arquivo))
        {
            if (strcmp(data_obra, minhaObra.data) == 0)
            {
                
                printf("\n Código: %s\n", minhaObra.codigo);
				printf(" Nome: %s\n", minhaObra.nome);
				printf(" Endereco: %s\n", minhaObra.endereco);
                printf(" Valor: %.2f\n", minhaObra.valor);
                printf(" Engenheiro(a) Responsável: %s\n", minhaObra.responsavel);
                printf(" Previsão de Entrega: %s\n", minhaObra.data);                
				encontrado = 1;                
            }
            fread(&minhaObra, 1, sizeof(struct obra), arquivo);
        }		
 		
 
        if (!encontrado)
        {
            printf("\n Obra não encontrada!\n");
            
        }
        fclose(arquivo);
    }
    else
    {
        printf("\n Nada encontrado no arquivo!\n");
        
    }
    
    system("PAUSE");
}
 


 
void excluirObra(void)
{
    int encontrado = 0;    
    char codigo[5];
    int decisao;        
    struct obra obraTemporaria;
    FILE *arquivoAntigo = NULL, *arquivoAtualizado = NULL;
 	
    system("cls"); 
 
    printf("\tCONTROLE DE OBRAS - EXCLUIR OBRA\n\n");
    printf(" Código da Obra: ");
    fflush(stdin);
    gets(codigo);
 
 	printf("Tem certeza que deseja excluir ?\n");
 	printf("Digite 1.SIM ou 0.NAO\n");
 	scanf("%d",&decisao);
 	
 		
	 
 	
 	if (decisao == 1){
	    arquivoAntigo = fopen("obras.txt", "rb");
	    if (arquivoAntigo)
	    {
	        arquivoAtualizado = fopen("temp.txt", "wb");
	        if (!arquivoAtualizado)
	        {
	            printf("\n Falha na exclusao da obra!");
	            fclose(arquivoAntigo);
	            Sleep(1000); 
	            return;
	        }
	 
	        fread(&obraTemporaria, 1, sizeof(struct obra), arquivoAntigo);
	        while (!feof(arquivoAntigo))
	        {
	            if (strcmp(obraTemporaria.codigo, codigo) == 0)
	            {
	                encontrado = 1;
	            }
	            else
	            {
	                fwrite(&obraTemporaria, 1, sizeof(struct obra), arquivoAtualizado);
	            }
	            fread(&obraTemporaria, 1, sizeof(struct obra), arquivoAntigo);
	        }
	 
	        fclose(arquivoAntigo);
	        fclose(arquivoAtualizado);
	 
	        remove("obras.txt");
	        rename("temp.txt", "obras.txt");
	 
	        if (!encontrado)
	        {
	            printf("\n Nao foi possivel encontrar a obra...");
	        }
	        else
	        {
	            printf("\n Exclusao realizada com sucesso!");
	        }
	 
	        Sleep(1000); 
	    }
	    else
	    {
	        printf("\n Nenhuma obra encontrado!");
	        Sleep(1000); 
	    }
	}
}
