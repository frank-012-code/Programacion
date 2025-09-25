#include <stdio.h>

main()
{
    int cantidad_stock, unidades, continuador = 1, id = 9, opcion, cantidad_de_venta, añadir, aumento_a_stock;
    float precio_unitario = 0.0;
    char nombre = ' ';

    while (continuador == 1)
    {
        printf("1. Registro.");
        printf("2. Vender producto.");
        printf("3. Consulta stock.");
        printf("4. Ganancias.");
        printf("5. Salir.");
        printf("Opción: ");
        scanf("%d", &opcion);  

        if (opcion < 1 || opcion > 5)
        {
            printf("Opción no válida.");
        }

        if (opcion == 1)
        {
            while ( id < 10000000 || id > 99999999)
            {
                printf("ID del producto (8 digitos): ");
                scanf("%d", &id);
                if (id < 10000000 || id > 99999999)
                {
                    printf("\nDato no válido.");
                }
            }

            while (nombre == ' ')
            {
                printf("Nombre del producto: ");
                scanf("%c", &nombre);

                if (nombre == ' ')
                {
                    printf("\nIngresar nombre del producto.");
                }
            }

            while (cantidad_stock == 0)
            {
                printf("Cantidad en stock: ");
                scanf("%d", &cantidad_stock);
                if (cantidad_stock == 0)
                {
                    printf("\nDato no válido.");
                }
            }

            cantidad_de_venta = cantidad_stock + 1;
           

            while (precio_unitario = 0.0)
            {
                printf("Ingrese valor del producto: ");
                scanf("%f", &precio_unitario);
               
                if(precio_unitario == 0.0)
                {
                    printf("\nDato no válido.");
                }
            }
           
        }

        if (opcion == 2)
        {
            while (cantidad_de_venta > cantidad_stock)
            {
                printf("Cantidad de unidades a vender: ");
                scanf("%d", &cantidad_de_venta);

                if (cantidad_de_venta > cantidad_stock)
                {
                    printf("\nCantidad insuficiente en stock.");
                }
            }
        }


        if (opcion == 3)
        {
            printf("Total en stock: %d", cantidad_stock);
            while (añadir < 0 || añadir > 1)
            {
                printf("\n¿Desea añadir más unidades al stock? (1 -> Si | 0 -> No): ");
                scanf("%d", &añadir);

                if(añadir < 0 || añadir > 1 )
                {
                    printf("\nDato no válido.");
                }
            }
            if (añadir == 1)
            {
                while (añadir < 0)
                {
                    printf("Unidades a añadir: ");
                    scanf("%d", &aumento_a_stock);

                    if (añadir < 0)
                    {
                        printf("");
                    }
                }
            }
        }
    }  
}