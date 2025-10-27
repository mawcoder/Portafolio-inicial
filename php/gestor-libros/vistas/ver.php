<?php
declare(strict_types=1);

/**
 * Vista: ver.php
 * -------------------
 * Muestra los detalles de un libro individual.
 * 
 * Variables recibidas:
 * - Libro $libro  Objeto que contiene los datos del libro seleccionado.
 *
 * @package Vistas
 */
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Detalles del libro</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #fafafa;
            margin: 40px;
        }

        h1 {
            color: #2a75bb;
        }

        table {
            border-collapse: collapse;
            width: 100%;
            background: white;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
        }

        th, td {
            padding: 10px 15px;
            border-bottom: 1px solid #ccc;
            text-align: left;
        }

        th {
            background: #2a75bb;
            color: white;
        }

        tr:hover {
            background: #f3f3f3;
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

        a.volver {
            display: inline-block;
            margin-top: 15px;
            text-decoration: none;
            color: #2a75bb;
        }

        a.volver:hover {
            text-decoration: underline;
        }
    </style>
</head>
<body>

    <h1>Detalles del libro - <?= htmlspecialchars($libro->obtenerTitulo(), ENT_QUOTES, 'UTF-8') ?></h1>

    <?php if (!empty($libro)): ?>
        <table>
            <thead>
                <tr>
                    <th>Título</th>
                    <th>Autor</th>
                    <th>Número de páginas</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><?= htmlspecialchars($libro->obtenerTitulo(), ENT_QUOTES, 'UTF-8') ?></td>
                    <td><?= htmlspecialchars($libro->obtenerAutor(), ENT_QUOTES, 'UTF-8') ?></td>
                    <td><?= htmlspecialchars((string)$libro->obtenerPaginas(), ENT_QUOTES, 'UTF-8') ?></td>
                </tr>
            </tbody>
        </table>

        <form action="?action=eliminar" method="POST" onsubmit="return confirm('¿Seguro que deseas eliminar este libro?');">
            <input type="hidden" name="id" value="<?= (int)$libro->obtenerId() ?>">
            <button type="submit">Eliminar libro</button>
        </form>

        <a href="index.php" class="volver">← Volver al listado</a>

    <?php else: ?>
        <p>Datos del libro no encontrados.</p>
    <?php endif; ?>

</body>
</html>
