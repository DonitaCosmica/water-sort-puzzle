# Nombre del ejecutable
TARGET = app

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall

# Directorios de inclusión
INCLUDE_DIRS = -I./include

# Archivos fuente
SOURCES = main.c ./src/stack.c ./src/listColors.c

# Archivos de encabezado
HEADERS = ./include/stack.h ./include/listColors.h

# Regla para construir el ejecutable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $(TARGET) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)

