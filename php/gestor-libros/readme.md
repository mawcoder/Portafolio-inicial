# Gestor de Libros en PHP

Este proyecto es un ejemplo sencillo de una aplicación MVC en **PHP** que permite listar, ver, crear y eliminar libros almacenados en una base de datos **SQLite**.

El objetivo es mostrar una estructura clara, separando la lógica en controladores, modelos y vistas, sin depender de frameworks externos.

---

## Características

- Listado dinámico de libros con enlaces a los detalles.
- Formulario para cargar nuevos libros.
- Eliminación de libros con confirmación.
- Validación y saneamiento de entradas mediante `filter_input` y filtros nativos de PHP.
- Conexión segura a base de datos SQLite mediante PDO.
- Configuración de errores adaptable (modo desarrollo o producción).

---

## Estructura del proyecto

gestor-libros/
├── index.php
├── modelos/
│   ├── libro.php
│   ├── database.php
│   └── errores.php
├── controladores/
│   └── controladorLibros.php
├── vistas/
│   ├── listado.php
│   ├── ver.php
│   └── crear.php
└── database/
└── libros.db (se genera automáticamente)

---

## Requisitos

- PHP 8.0 o superior  
- Extensión **PDO_SQLITE** habilitada  
- Navegador web moderno (Firefox, Chrome, Edge, etc.)

---

## Instalación y uso

1. Clonar o descargar el repositorio:
   ```bash
   git clone https://github.com/mawcoder/Portafolio-inicial
   cd Portafolio-inicial/php/gestor-libros
```

2. Iniciar el servidor embebido de PHP:

   ```bash
   php -S localhost:8000
   ```

3. Abrir el navegador y acceder a:

   ```
   http://localhost:8000
   ```

4. Funcionalidades disponibles:

   * Ver el listado de libros
   * Cargar un nuevo libro
   * Ver detalles
   * Eliminar registros

---

## Configuración de errores

El archivo [`modelos/errores.php`](modelos/errores.php) permite alternar entre dos modos:

**Desarrollo**
Muestra todos los errores en pantalla
**Producción**
Oculta los errores y los guarda en `errores.log`

Para cambiar el modo:

```php
$modoDesarrollo = false; // o true
```

---

## Estructura MVC simplificada

**modelos/**
Clases de datos (`Libro`, `Database`, `Errores`)    
**controladores/**
Lógica del flujo del programa (`ControladorLibros`) 
**vistas/**
Archivos HTML con datos dinámicos                   

---

## Base de datos

La base de datos se genera automáticamente al iniciar el proyecto (`database/libros.db`) y se crea la tabla libros por defecto.

Estructura de la tabla:

```sql
CREATE TABLE libros (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    titulo TEXT,
    autor TEXT,
    paginas INTEGER
);
```

---

## Licencia

Este proyecto es de libre uso con fines educativos.
Podés modificarlo y adaptarlo según tus necesidades.

---

## Autor

**mawcoder**

```

---
