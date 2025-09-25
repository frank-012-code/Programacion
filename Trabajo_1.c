#include <stdio.h>

int main()
{
    int cantidad_stock = 0, continuador = 1, id = 0, opcion, cantidad_de_venta, aumento_a_stock = -1;
    float precio_unitario = 0.0, ganancias;
    char nombre_producto;

    while (continuador == 1)
    {
        printf("------* Programa de gestion de un único producto *------");
        printf("\n1. Registro.");
        printf("\n2. Vender producto.");
        printf("\n3. Consulta stock.");
        printf("\n4. Agregar productos.");
        printf("\n5. Ganancias.");
        printf("\n6. Salir.");
        printf("\nOpción: ");
        scanf("%d", &opcion);  

        if (opcion < 1 || opcion > 6)
        {
            printf("\nOpción no válida.");
        }

        if (opcion == 1)
        {
            while ( id < 10000000 || id > 99999999)
            {
                printf("\nID del producto (8 digitos): ");
                scanf("%d", &id);
                if (id < 10000000 || id > 99999999)
                {
                    printf("\nDato no válido.");
                }
            }

            while (cantidad_stock <= 0)
            {
                printf("Cantidad en stock: ");
                scanf("%d", &cantidad_stock);
                
                if (cantidad_stock <= 0)
                {
                    printf("\nDato no válido.");
                }
            }

            while (precio_unitario <= 0.0)
            {
                printf("Ingrese valor del producto por unidad: ");
                scanf("%f", &precio_unitario);

                if(precio_unitario <= 0.0)
                {
                    printf("\nDato no válido.");
                } 
            }

            printf("Nombre del producto: ");
            scanf("%s", &nombre_producto);
        }

        if (opcion == 2)
        {
            if (id == 0)
            {
                printf("\nPrimero se debe resgistrar el producto.");
            }
            else
            {
                cantidad_de_venta = cantidad_stock + 1;
                while (cantidad_de_venta > cantidad_stock)
                {
                    cantidad_de_venta = 0;
                    printf("Cantidad de unidades a vender: ");
                    scanf("%d", &cantidad_de_venta);

                    if (cantidad_de_venta > cantidad_stock)
                    {
                        printf("\nCantidad insuficiente en stock.");
                    }
                }
                cantidad_stock = cantidad_stock - cantidad_de_venta;
            }
        }

        if(opcion ==3)
        {
            if (id == 0)
            {
                printf("\nPrimero se debe resgistrar el producto.");
            }
            else
            {
                printf("\nTotal en stock: %d", cantidad_stock);
            }
        }

        if (opcion == 4)
        {
            while(aumento_a_stock <= 0)
            {
                printf("\nCantidad de producto a agregar: ");
                scanf("%d", &aumento_a_stock);

                if(aumento_a_stock <= 0)
                {
                    printf("Cantidad no válida.");
                }
            }
            cantidad_stock = cantidad_stock + aumento_a_stock;
            aumento_a_stock = 0;
        }

        if (opcion == 5)
        {
            if(id <= 0 || cantidad_de_venta <= 0)
            {
                printf("\nAún no se ha registrado el producto o no se ha vendido.");
            }
            else
            {
                ganancias = cantidad_de_venta * precio_unitario;
                printf("\nEl total de ganancias generadas son: %.2f", ganancias);
            }
        }

        if (opcion == 6)
        {
            printf("\nFin del programa. :)");
            continuador = 0;
        }

        opcion = 0;
        printf("\n");
    }  

    return 0;
}