/*
   imprimir um menu.
   */

  #include <stdio.h>

  void imprimir_menu()
  {
       int opcao = 0;

       do
       {
        printf("1 - visualizar o cronograma.\n");
        printf("2 - marcar ocupaçôes.\n");
        printf("3 - atividades de monitorização.\n");
        printf("4 - atividades de mediação.\n");
        printf("5 - sair.\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("opcao 1.\n");
            break;

        case 2:
            printf("opcao 2.\n");
            break;

        case 3:
            printf("opcao 3.\n");
            break;

        case 4:
            printf("opcao 4.\n");
            break;

        case 5:
            printf("opcao 5 - sair.\n");
            break;

        default:
            printf("opcao inexistente.\n");
            break;
        }

       } while (opcao != 5);
  }

  int main()
  {
      imprimir_menu();

      return 0;
  }



       
          
    
