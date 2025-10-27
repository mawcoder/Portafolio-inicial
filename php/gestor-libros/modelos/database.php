<?php
declare(strict_types=1);

/**
 * Clase Database
 * -----------------
 * Gestiona la conexión a una base de datos SQLite y operaciones CRUD básicas.
 *
 * @package Modelos
 * @author  
 * @version 1.0
 */
class Database
{
    /** @var PDO|null Conexión PDO activa */
    private ?PDO $conexion = null;

    /**
     * Constructor: crea la conexión a la base de datos SQLite.
     * Si la base no existe, la crea junto con la tabla 'libros'.
     *
     * @param string $archivo Nombre del archivo de base de datos (sin extensión)
     * @throws RuntimeException Si ocurre un error al conectar con la base de datos.
     */
    public function __construct(string $archivo)
    {
        try {
            $ruta = __DIR__ . '../../database/' . $archivo . '.db';
            $this->conexion = new PDO('sqlite:' . $ruta);
            $this->conexion->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            // Crear tabla si no existe
            $this->conexion->exec("
                CREATE TABLE IF NOT EXISTS libros (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    titulo TEXT NOT NULL,
                    autor TEXT NOT NULL,
                    paginas INTEGER NOT NULL
                )
            ");
        } catch (PDOException $e) {
            throw new RuntimeException("Error de conexión: " . $e->getMessage());
        }
    }

    /**
     * Inserta un nuevo registro en una tabla utilizando una consulta preparada.
     *
     * @param string $tabla  Nombre de la tabla destino.
     * @param array  $datos  Arreglo asociativo con los nombres de columna y valores.
     */
    public function insertar(string $tabla, array $datos): void
    {
        $columnas = implode(", ", array_keys($datos));
        $placeholders = ":" . implode(", :", array_keys($datos));

        $sql = "INSERT INTO $tabla ($columnas) VALUES ($placeholders)";
        $stmt = $this->conexion->prepare($sql);

        // Asignar cada valor con su tipo de dato correcto
        foreach ($datos as $clave => $valor) {
            if (is_int($valor)) {
                $tipo = PDO::PARAM_INT;
            } elseif (is_bool($valor)) {
                $tipo = PDO::PARAM_BOOL;
            } elseif (is_null($valor)) {
                $tipo = PDO::PARAM_NULL;
            } else {
                $tipo = PDO::PARAM_STR;
            }

            $stmt->bindValue(":$clave", $valor, $tipo);
        }

        $stmt->execute();
    }

    /**
     * Obtiene todos los registros de una tabla.
     *
     * @param string $tabla Nombre de la tabla.
     * @return array Lista de registros como arreglos asociativos.
     */
    public function obtenerTodos(string $tabla): array
    {
        $stmt = $this->conexion->query("SELECT * FROM $tabla");
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    /**
     * Busca un registro por su ID.
     *
     * @param string $tabla Nombre de la tabla.
     * @param int    $valor Valor del ID a buscar.
     * @return array Resultado de la consulta (puede ser vacío si no se encuentra).
     */
    public function buscarPorId(string $tabla, int $id): array
    {
        $sql = "SELECT * FROM $tabla WHERE id = :id";
        $stmt = $this->conexion->prepare($sql);
        $stmt->bindValue(':id', $id, PDO::PARAM_INT);
        $stmt->execute();
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    /**
     * Elimina un registro por su ID.
     *
     * @param string $tabla Nombre de la tabla.
     * @param int    $id    ID del registro a eliminar.
     */
    public function eliminar(string $tabla, int $id): void
    {
        $sql = "DELETE FROM $tabla WHERE id = :id";
        $stmt = $this->conexion->prepare($sql);
        $stmt->bindValue(':id', $id, PDO::PARAM_INT);
        $stmt->execute();
    }

    /**
     * Devuelve la cantidad total de registros en una tabla.
     *
     * @param string $tabla Nombre de la tabla.
     * @return int Número total de registros.
     */
    public function contarRegistros(string $tabla): int
    {
        $stmt = $this->conexion->query("SELECT COUNT(*) AS total FROM $tabla");
        $resultado = $stmt->fetch(PDO::FETCH_ASSOC);
        return (int)$resultado['total'];
    }

    /**
     * Cierra la conexión con la base de datos.
     */
    public function cerrar(): void
    {
        $this->conexion = null;
    }
}
