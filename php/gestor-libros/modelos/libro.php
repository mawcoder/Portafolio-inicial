<?php
declare(strict_types=1);

/**
 * Clase Libro
 * -----------------
 * Representa un libro con su ID, título, autor y cantidad de páginas.
 * 
 * Esta clase actúa como modelo de datos para la entidad "libro",
 * encapsulando sus propiedades y proporcionando métodos de acceso.
 *
 * @package Modelos
 * @author  
 * @version 1.0
 */
class Libro
{
    /** @var int Identificador único del libro */
    private int $id;

    /** @var string Título del libro */
    private string $titulo;

    /** @var string Autor del libro */
    private string $autor;

    /** @var int Cantidad de páginas del libro */
    private int $paginas;

    /**
     * Constructor de la clase Libro.
     *
     * @param int    $id      Identificador único del libro.
     * @param string $titulo  Título del libro.
     * @param string $autor   Autor del libro.
     * @param int    $paginas Cantidad total de páginas.
     */
    public function __construct(int $id, string $titulo, string $autor, int $paginas)
    {
        $this->id = $id;
        $this->titulo = $titulo;
        $this->autor = $autor;
        $this->paginas = $paginas;
    }

    /**
     * Obtiene el ID del libro.
     *
     * @return int ID del libro.
     */
    public function obtenerId(): int
    {
        return $this->id;
    }

    /**
     * Obtiene el título del libro.
     *
     * @return string Título del libro.
     */
    public function obtenerTitulo(): string
    {
        return $this->titulo;
    }

    /**
     * Obtiene el autor del libro.
     *
     * @return string Autor del libro.
     */
    public function obtenerAutor(): string
    {
        return $this->autor;
    }

    /**
     * Obtiene la cantidad de páginas del libro.
     *
     * @return int Número de páginas.
     */
    public function obtenerPaginas(): int
    {
        return $this->paginas;
    }

    /**
     * Devuelve un arreglo asociativo con los datos del libro.
     * 
     * Este método es útil para insertar registros en la base de datos.
     *
     * @return array<string, int|string> Arreglo con las propiedades del libro.
     */
    public function array(): array
    {
        return [
            'titulo' => $this->titulo,
            'autor' => $this->autor,
            'paginas' => $this->paginas,
        ];
    }
}
