#include <stdio.h>

int main()
{
    //Declaracion de variables
    int cantidad_stock = 0, continuador = 1, id = 0, opcion, cantidad_de_venta, aumento_a_stock = -1, descuento;
    float precio_unitario, ganancias = 0.0, precio_con_descuento;
    char nombre_producto [30];

    while (continuador == 1) //Bucle principal del menú
    {
        //Despliegue del menú
        printf("\n------* Programa de gestion de un único producto *------");
        printf("\n1. Registro.");
        printf("\n2. Vender producto.");
        printf("\n3. Consulta stock.");
        printf("\n4. Agregar productos.");
        printf("\n5. Ganancias.");
        printf("\n6. Salir.");
        printf("\nOpción: ");
        scanf("%d", &opcion);  //Entrada de dato de la variable 'opcion'

        if (opcion < 1 || opcion > 6) //Condicional para determinar la opcion
        {
            printf("\nOpción no válida."); //Mensaje de dato no válido para la variable
        }

        if (opcion == 1) //Opcion de resgistro del producto
        {
            id = 0, cantidad_stock = 0, precio_unitario = 0; //Reinicio de las variables
            while ( id < 10000000 || id > 99999999)  //Control de ingreso de variable con 8 digitos
            {
                printf("ID del producto (8 digitos): ");
                scanf("%d", &id);               //Ingreso del ID del producto
                if (id < 10000000 || id > 99999999)
                {
                    printf("Dato no válido.\n"); //Mensaje de dato no válido para la variable
                }
            }

            while (cantidad_stock <= 0) //Control de ingreso de cantidad del producto en stock
            {
                printf("Cantidad en stock: ");
                scanf("%d", &cantidad_stock);   //Ingreso de la cantidad que hay en stock
                
                if (cantidad_stock <= 0)
                {
                    printf("Dato no válido.\n"); //Mensaje de dato no aceptable
                }
            }

            while (precio_unitario <= 0.0)  //Control de ingreso del precio por unidad
            {
                printf("Ingrese valor del producto por unidad: ");
                scanf("%f", &precio_unitario);           //Ingreso del precio por unidad

                if(precio_unitario <= 0.0)
                {
                    printf("Dato no válido.\n"); //Mensaje de dato no válido para la variable
                } 
            }

            printf("Nombre del producto: "); //Ingreso del nombre del producto
            scanf("%s", nombre_producto);
        }

        if (opcion == 2) //Opcion de venta del producto
        {
            descuento = -1;
            if (id == 0) //Controlador para hacer que el usuario evite saltarse pasos
            {
                printf("\nPrimero se debe resgistrar el producto.");  //Mensaje de que aun no se ha registrado
            }
            else
            {
                cantidad_de_venta = 0;  //Reinicio de variable
                cantidad_de_venta = cantidad_stock + 1; //Forzar a la variable entrar al bucle
                while (cantidad_de_venta <= 0 || cantidad_de_venta > cantidad_stock)   //Control de entrada correcta de la variable
                {
                    cantidad_de_venta = 0;
                    printf("Cantidad de unidades a vender: ");
                    scanf("%d", &cantidad_de_venta);    //Entrada de la cantidad de producto a vender

                    if (cantidad_de_venta <= 0 || cantidad_de_venta > cantidad_stock)
                    {
                        printf("Cantidad no en stock.\n");  //Mensaje de dato no válido para la variable
                    }
                }

                while (descuento < 0 || descuento > 100)
                {
                    printf("Descuento aplicado al producto: (Ej. 20%%) ");
                    scanf("%d", &descuento);

                    if(descuento < 0 || descuento > 100)
                    {
                        printf("Cantidad no válida.\n");
                    }
                }

                if(descuento == 0)
                {
                    //Proceso para calcular las ganancias por cada venta hecha
                    ganancias = ganancias + (cantidad_de_venta * precio_unitario);
                }
                else
                {
                    //Proceso para calcular las ganancias con el descuento
                    precio_con_descuento = precio_unitario * (1 - ((float)descuento / 100));
                    ganancias = ganancias + (cantidad_de_venta * precio_con_descuento);
                }

                //Proceso para quitar del stock lo que se vendio
                cantidad_stock = cantidad_stock - cantidad_de_venta;
            }
        }

        if(opcion ==3)  //Opcion para verificar la cantidad de producto en stock
        {
            if (id == 0)
            {
                printf("\nPrimero se debe resgistrar el producto.");    //Mensaje de que aun no se ha registrado
            }
            else
            {
                printf("\nTotal en stock: %d", cantidad_stock); //Salida de cantidad en stock
            }
        }

        if (opcion == 4)    //Opcion para agregar producto al stock
        {
            if (id == 0)
            {
                printf("\nAún no se a registrado el producto.");    //Mensaje de que aun no se ha registrado
            }
            else
            {
                aumento_a_stock = 0;    //Reinicio de la variable
                while(aumento_a_stock <= 0)     //Control de ingreso del aumento del stock
                {
                    printf("Cantidad de producto a agregar: ");
                    scanf("%d", &aumento_a_stock);      //Entrada del aumento al stock

                    if(aumento_a_stock <= 0)
                    {
                        printf("Cantidad no válida.\n");    //Mensaje de dato no válido para la variable
                    }
                }
                cantidad_stock = cantidad_stock + aumento_a_stock;  //Proceso de aumento al stock
            }
        }

        if (opcion == 5)    //Opcion para mostrar las ganancias
        {
            if(id <= 0 || ganancias == 0)
            {
                printf("\nAún no se ha registrado el producto o no se ha vendido.");    //Mensaje de que no se ha completado un paso anterior
            }
            else
            {
                printf("\nEl total de ganancias generadas son: %.2f", ganancias);   //Salida de las ganancias generadas
            }
        }

        if (opcion == 6)    //Opcion de salida del programa
        {
            printf("\nFin del programa. :)");
            continuador = 0; //Cierre del bucle principal
        }

        opcion = 0;  //Reinicio de la variable opcion
    }  

    return 0;
}