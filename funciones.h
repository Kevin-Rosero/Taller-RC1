int Menu();
void SaltodeLinea(char *cadena, int n);
void MostrarInventario(int *pantallas, int *baterias, int *chips, int *tarjetagrafica, int *teclados, int *mouses);
void RealizarPedido(char nombreproducto[5][50], int contador, int *pantallas, int *teclados,
                    int *mouses, int *baterias, int *chips, int *tarjetagrafica, int opcionproducto, int cantidadpedido, int respuestaRP);
void EditarProducto(int *pantallas, int *teclados, int *mouses, int *baterias, int *chips, int *tarjetagrafica, int respuestaEP);
int BuscarProducto(char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses, int *baterias, int *chips, int *tarjetagrafica, int contador);
void EliminarProducto(char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses,
                      int *baterias, int *chips, int *tarjetagrafica, int *contador, int respuestaEliminar);
void Reabastecerstock(int *pantallas, int *teclados, int *mouses, int *tarjetagrafica, int *baterias, int *chips, int respuestaR, int opcionesR);
void AgregarProducto(char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses,
                     int *baterias, int *chips, int *tarjetagrafica, int *contador);