<?php
declare(strict_types=1);

/**
 * Vista: listado.php
 * -------------------
 * Muestra el listado completo de libros existentes en la base de datos.
 * 
 * Variables recibidas:
 * - array<Libro> $libros  Lista de objetos Libro obtenidos desde el controlador.
 *
 * @package Vistas
 */
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Lista de Libros</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #fafafa;
            margin: 40px;
        }

        h1 {
            color: #2a75bb;
        }

        ul {
            list-style-type: none;
            padding: 0;
        }

        li {
            background: #ffffff;
            border: 1px solid #ddd;
            border-radius: 5px;
            padding: 10px 15px;
            margin-bottom: 8px;
            transition: background 0.2s;
        }

        li:hover {
            background: #f0f8ff;
        }

        a {
            text-decoration: none;
            color: #333;
        }

        a:hover {
            color: #2a75bb;
        }

        form {
            margin-top: 20px;
        }

        button {
            background-color: #2a75bb;
            color: white;
            border: none;
            padding: 10px 15px;
            border-radius: 5px;
            cursor: pointer;
            font-size: 14px;
        }

        button:hover {
            background-color: #1d5c96;
        }
    </style>
</head>
<body>

    <h1>Listado de libros</h1>

    <?php if (!empty($libros)): ?>
        <ul>
            <?php foreach ($libros as $libro): ?>
                <li>
                    <a href="?action=ver&id=<?= htmlspecialchars((string)$libro->obtenerId(), ENT_QUOTES, 'UTF-8') ?>">
                        <?= htmlspecialchars($libro->obtenerTitulo(), ENT_QUOTES, 'UTF-8') ?>
                    </a>
                </li>
            <?php endforeach; ?>
        </ul>
    <?php else: ?>
        <p>No hay libros cargados.</p>
    <?php endif; ?>

    <form action="?action=crear" method="POST">
        <button type="submit">Cargar nuevo libro</button>
    </form>

</body>
</html>
