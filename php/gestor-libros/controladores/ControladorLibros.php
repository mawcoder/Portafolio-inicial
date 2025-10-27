<?php
declare(strict_types=1);

require_once __DIR__ . '../../modelos/database.php';
require_once __DIR__ . '../../modelos/libro.php';

/**
 * ControladorLibros
 *
 * Controlador principal para gestionar las operaciones relacionadas con los libros.
 * Se encarga de comunicarse con el modelo Database, crear objetos Libro y cargar las vistas correspondientes.
 */
class ControladorLibros
{
    /**
     * Muestra el listado completo de libros almacenados en la base de datos.
     *
     * @return void
     */
    public function listar(): void
    {
        $basedatos = new Database('libros');
        $registros = $basedatos->obtenerTodos('libros');
        $libros = [];

        foreach ($registros as $fila) {
            $libros[] = new Libro(
                $fila['id'],
                $fila['titulo'],
                $fila['autor'],
                $fila['paginas']
            );
        }

        $basedatos->cerrar();

        require_once __DIR__ . '../../vistas/listado.php';
    }

    /**
     * Muestra la información detallada de un libro específico según su ID.
     *
     * @param int $id  Identificador único del libro.
     * @return void
     */
    public function ver(int $id): void
    {
        $basedatos = new Database('libros');
        $registro = $basedatos->buscarPorId('libros', $id);

        $libro = new Libro(
            $registro[0]['id'],
            $registro[0]['titulo'],
            $registro[0]['autor'],
            $registro[0]['paginas']
        );

        $basedatos->cerrar();

        require_once __DIR__ . '../../vistas/ver.php';
    }

    /**
     * Carga la vista con el formulario para crear un nuevo libro.
     *
     * @return void
     */
    public function crear(): void
    {
        require_once __DIR__ . '../../vistas/crear.php';
    }

    /**
     * Procesa los datos enviados desde el formulario y guarda un nuevo libro en la base de datos.
     *
     * @return void
     */
    public function cargar(): void
    {
        $basedatos = new Database('libros');

        // Sanitizar y validar datos recibidos desde POST
        $libro = [
            'titulo'  => filter_input(INPUT_POST, 'titulo', FILTER_SANITIZE_SPECIAL_CHARS),
            'autor'   => filter_input(INPUT_POST, 'autor', FILTER_SANITIZE_SPECIAL_CHARS),
            'paginas' => filter_input(INPUT_POST, 'paginas', FILTER_VALIDATE_INT)
        ];

        $basedatos->insertar('libros', $libro);
        $basedatos->cerrar();

        // Redirigir al inicio después de guardar
        header('Location: index.php');
        exit;
    }

    /**
     * Elimina un libro según su ID y redirige al listado principal.
     *
     * @param int $id  Identificador único del libro a eliminar.
     * @return void
     */
    public function eliminar(int $id): void
    {
        $basedatos = new Database('libros');
        $basedatos->eliminar('libros', $id);
        $basedatos->cerrar();

        header('Location: ./');
        exit;
    }
}
