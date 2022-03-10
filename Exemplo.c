//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <locale.h>
//#include <stdlib.h>
//#include <math.h>
//
//struct node
//{
//    int cenario; // Segundos
//    float velocidade; // m/s , m  
//    struct node* next;
//    struct node* prev;
//}*head, * tail;
//
//// Protótipos
//int Menu();
//void createDCLL(int cenario, float velocidade);
//void Read();
//void display();
//void save();
//void deletepos();
//void deletebegin();
//void Substitute();
//int getlength();
//void Search();
//void Simulate();
//int Same(int cenario);
//void ListCres();
//
//
//
//// Implementações
//int Menu()
//{
//    int opcao;
//    printf("\nM E N U\n");
//    printf("1 - Insercao de um novo cenario \n");
//    printf("2 - Pesquisar um cenario pelo codigo\n");
//    printf("3 - Listagem dos cenarios por ordem crescente\n");
//    printf("4 - Alterar um cenario\n");
//    printf("5 - Remover um cenario\n");
//    printf("6 - Simular um cenario\n");
//    printf("7 - Armazenar os cenarios\n");
//    printf("8 - Carregar os cenarios\n");
//    printf("O - SAIR\n");
//
//    do
//    {
//        scanf("%d", &opcao);
//    } while ((opcao < 0) || (opcao > 8));
//    return(opcao);
//
//
//}
//void createDCLL(int cenario, float velocidade)
//{
//
//    struct node* newnode;
//
//
//    newnode = (struct node*)malloc(sizeof(struct node));
//
//
//    newnode->cenario = cenario;
//    newnode->velocidade = velocidade;
//
//
//    if (head == 0)
//    {
//        head = tail = newnode;
//        head->next = head;
//        head->prev = head;
//    }
//    else {
//
//
//
//        tail->next = newnode;
//        newnode->prev = tail;
//        head->prev = newnode;
//        tail = newnode;
//    }
//
//}
//
//void Read()
//{
//    FILE* fp;
//    int cenario, flag;
//    float velocidade;
//    fp = fopen("dados.txt", "r");
//
//
//
//    if (fp != NULL)
//    {
//        while (!feof(fp))
//
//        {
//            fscanf(fp, "Cenario -> %d  Velocicade->%f\n", &cenario, &velocidade);
//
//            flag = Same(cenario);
//
//            if (flag == 0)
//            {
//                createDCLL(cenario, velocidade);
//            }
//            else {
//
//                printf("Código do Cenario ja existe!!\n");
//            }
//        }
//
//        printf("Dados Carregados com sucesso\n");
//    }
//    else {
//        printf("Ficheiro Vazio\n");
//    }
//
//}
//void display()
//{
//    struct node* temp;
//    temp = head;
//    if (head == 0)
//    {
//        printf("Lista Vazia\n");
//    }
//    else {
//        while (temp != tail)
//        {
//            printf("Cenario -> %d  Velocicade->%f\n", temp->cenario, temp->velocidade);
//            temp = temp->next;
//
//        }
//        printf("Cenario -> %d  Velocicade->%f\n", temp->cenario, temp->velocidade);
//    }
//}
//void save()
//{
//    FILE* fp;
//    fp = fopen("dados.txt", "w");
//
//    struct node* temp;
//    temp = head;
//    if (head == 0)
//    {
//        printf("Lista Vazia\n");
//    }
//    else
//    {
//
//        if (fp != NULL)
//        {
//            while (temp != tail)
//            {
//                fprintf(fp, "Cenario -> %d  Velocicade->%f\n", temp->cenario, temp->velocidade);
//                temp = temp->next;
//
//            }
//            fprintf(fp, "Cenario -> %d  Velocicade->%f\n", temp->cenario, temp->velocidade);
//            fclose(fp);
//        }
//
//
//        printf("Dados Guardados com sucesso\n");
//
//    }
//}
//void deletepos()
//{
//    struct node* temp;
//    int pos, i = 1, l;
//
//    temp = head;
//    printf("Qual a posicao que deseja eliminar ?\n");
//    scanf("%d", &pos);
//    l = getlength();
//
//    if (pos<1 || pos>l)
//    {
//        printf("Posição inválida");
//    }
//
//    if (pos == 1)
//    {
//        deletebegin();
//    }
//    else
//    {
//        while (i < pos)
//        {
//            temp = temp->next;
//            i++;
//
//        }
//
//
//
//
//
//        if (temp == tail)
//        {
//            tail = tail->prev;
//            tail->next = head;
//            head->prev = tail;
//            free(temp);
//        }
//        else {
//            temp->prev->next = temp->next;
//            temp->next->prev = temp->prev;
//
//            free(temp);
//        }
//
//
//    }
//
//
//}
//void deletebegin()
//{
//    struct node* temp;
//    temp = head;
//
//    if (head->next == head)
//    {
//        head = tail = 0;
//        free(temp);
//
//
//
//    }
//    else {
//        head = head->next;
//        head->prev = tail;
//        tail->next = head;
//        free(temp);
//    }
//}
//int getlength()
//{
//    int count = 0;
//    struct node* temp;
//    temp = head;
//    while (temp != tail)
//    {
//        count++;
//        temp = temp->next;
//    }
//    count++;
//
//    //printf("A lista tem %d nodos\n", count);
//    return(count);
//}
//void Substitute()
//{
//    struct node* temp;
//    int cenario, flag;
//    float velocidade;
//
//    temp = head;
//
//    printf("Qual o numero do cenário que deseja substituir\n");
//    scanf("%d", &cenario);
//
//    if (temp == 0)
//    {
//        printf("Lista Vazia\n");
//    }
//    else {
//
//
//        while (temp != tail)
//        {
//
//            if (temp->cenario == cenario)
//            {
//                printf("A sua pesquisa -------- >>>   Cenario -> %d  Velocicade->%f\n", temp->cenario, temp->velocidade);
//                flag = 1;
//                printf("Qual e a velocidade que deseja inserir\n");
//                scanf("%f", &velocidade);
//                temp->velocidade = velocidade;
//                temp = temp->next;
//            }
//            else
//            {
//                temp = temp->next;
//                flag = 0;
//            }
//
//
//        }
//
//        if (((temp == tail) && (temp->cenario == cenario)) || ((temp == head) && (temp->cenario == cenario))) // no caso de o cenario pesquisado for tambem o ou o primeiro ultimo da lista
//        {
//            printf("A sua pesquisa -------- >>>   Cenario -> %d  Velocicade->%f\n", temp->cenario, temp->velocidade);
//            flag = 1;
//            printf("Qual e a velocidade que deseja inserir\n");
//            scanf("%f", &velocidade);
//            temp->velocidade = velocidade;
//        }
//
//        if ((temp == tail) && (flag == 0))
//        {
//            printf("Nao existe esse cenario\n");
//        }
//
//    }
//}
//void Search()
//{
//
//    struct node* temp;
//    int  cenario;
//    temp = head;
//    int flag = 0;
//
//
//    printf("Qual o numero de cenario\n");
//    scanf("%d", &cenario);
//    if (temp == 0)
//    {
//        printf("Lista Vazia\n");
//    }
//    else {
//
//        while (temp != tail)
//        {
//
//            if (temp->cenario == cenario)
//            {
//                printf("A sua pesquisa -------- >>>   Cenario -> %d  Velocicade->%f\n", temp->cenario, temp->velocidade);
//                flag = 1;
//                temp = temp->next;
//            }
//            else
//            {
//                temp = temp->next;
//
//            }
//
//
//
//        }
//
//        if (((temp == tail) && (temp->cenario == cenario)) || ((temp == head) && (temp->cenario == cenario))) // no caso de o cenario pesquisado for tambem o ultimo da lista
//        {
//            printf("A sua pesquisa -------- >>>   Cenario -> %d  Velocicade->%f\n", temp->cenario, temp->velocidade);
//            flag = 1;
//        }
//
//
//        if ((temp == tail) && (flag == 0))
//        {
//            printf("Nao existe esse cenario\n");
//        }
//
//
//    }
//}
//void Simulate()
//{
//
//
//    struct node* temp;
//    int  cenario, flag = 0, i = 0;
//    temp = head;
//    float velocidade, distancia, espaco, tempo = 0;
//
//    printf("Qual o numero de cenario que quer simular\n");
//    scanf("%d", &cenario);
//
//    if (temp == 0)
//    {
//        printf("Lista Vazia\n");
//    }
//    else
//    {
//        while (temp != tail)
//        {
//
//            if (temp->cenario == cenario)
//            {
//                printf("A sua pesquisa -------- >>>   Cenario -> %d   Velocicade->%.2f m/s \n", temp->cenario, temp->velocidade);
//
//                velocidade = temp->velocidade;
//                printf("Qual o intervalo entre tempos que deseja?\n");
//                scanf("%f", &espaco);
//
//                while (i != 5)
//                {
//                    tempo += espaco;
//                    distancia = velocidade * tempo;
//                    printf("distancia= %.2f m tempo=%.2f s\n", distancia, tempo);
//                    i++;
//                }
//
//                flag = 1;
//                temp = temp->next;
//            }
//            else
//            {
//                temp = temp->next;
//
//            }
//
//        }
//
//
//
//
//        if (((temp == tail) && (temp->cenario == cenario)) || ((temp == head) && (temp->cenario == cenario))) // no caso de o cenario pesquisado for tambem o ultimo da lista ou o primeiro
//        {
//            printf("A sua pesquisa -------- >>>   Cenario -> %d  Velocicade->%.2f\n", temp->cenario, temp->velocidade);
//            flag = 1;
//            velocidade = temp->velocidade;
//            printf("Qual o intervalo entre tempos que deseja?\n");
//            scanf("%f", &espaco);
//
//            while (i != 5)
//            {
//                tempo += espaco;
//                distancia = velocidade * tempo;
//                printf("distancia= %.2f  tempo=%.2f\n", distancia, tempo);
//                i++;
//            }
//        }
//
//        if ((temp == tail) && (flag == 0))
//        {
//            printf("Nao existe esse cenario");
//        }
//
//
//
//
//
//    }
//
//
//}
//int Same(int cenario)
//{
//    struct node* temp;
//    temp = head;
//    int flag = 0;
//
//
//
//
//    while (temp != tail)
//    {
//
//        if (temp->cenario == cenario)
//        {
//
//            flag = 1;
//            temp = temp->next;
//            return(flag);
//        }
//        else
//        {
//            temp = temp->next;
//
//        }
//
//        if ((temp == tail) && (temp->cenario == cenario)) // no caso de o cenario pesquisado for tambem o ultimo da lista
//        {
//
//            flag = 1;
//            return(flag);
//
//        }
//
//
//    }
//
//
//    if ((temp == tail) && (flag == 0))
//    {
//        return(flag);
//    }
//
//
//
//
//}
//void ListCres()
//{
//    struct node* temp;
//    temp = head;
//    int  i, count, t, flag = 0;
//    float velocidade;
//
//    count = getlength();
//
//    if (head == tail && head == NULL) {
//        printf("The List is empty, nothing to sort");
//        return;
//    }
//
//
//
//    for (i = 0; i < count; i++) {
//
//        temp = head;
//
//        while (temp != tail)
//        {
//            t = temp->next->cenario;
//            velocidade = temp->next->velocidade;
//
//            if (temp->cenario > t)
//            {
//
//                temp->next->cenario = temp->cenario;
//                temp->next->velocidade = temp->velocidade;
//                temp->cenario = t;
//                temp->velocidade = velocidade;
//
//
//            }
//
//            temp = temp->next;
//        }
//
//
//
//    }
//
//
//
//
//
//    display();
//
//
//}
//
//int main()
//{
//
//    head = 0;
//    int opcao, criar, cenario, flag;
//    float velocidade;
//
//    do
//    {
//        opcao = Menu();
//
//        switch (opcao)
//        {
//
//        case 1:
//
//            criar = opcao;
//
//            while (criar == 1)
//            {
//
//
//                printf("Código do Cenário\n");
//                scanf("%d", &cenario);
//
//                flag = Same(cenario);
//
//                if (flag == 0)
//                {
//                    printf("Velocidade\n");
//                    scanf("%f", &velocidade);
//                    createDCLL(cenario, velocidade);
//                }
//                else {
//
//                    printf("Código do Cenario ja existe!!\n");
//                }
//
//
//                printf("Continuar a Inserir ?\n");
//                printf("1-Sim 0-Nao\n");
//                scanf("%d", &criar);
//
//            }
//
//
//            break;
//
//
//        case 2:
//            Search();
//            break;
//
//        case 3:
//
//            ListCres();
//
//            break;
//
//        case 4:
//            Substitute();
//            break;
//
//        case 5:
//            deletepos();
//            break;
//
//        case 6:
//            Simulate();
//            break;
//
//        case 7:
//            save();
//
//            break;
//
//        case 8:
//            Read();
//            break;
//
//        default:
//
//            break;
//
//        }
//    } while (opcao != 0);
//
//}