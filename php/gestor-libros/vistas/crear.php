<?php
declare(strict_types=1);

/**
 * Vista: crear.php
 * -------------------
 * Muestra el formulario para cargar un nuevo libro en la base de datos
 * 
 * @package Vistas
 */
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Cargar nuevo libro</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #fafafa;
            margin: 40px;
        }
        h1 {
            color: #2a75bb;
        }
        form {
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
            max-width: 500px;
        }
        label {
            display: block;
            margin-bottom: 10px;
            font-weight: bold;
            color: #333;
        }
        input[type="text"],
        input[type="number"] {
            width: 100%;
            padding: 8px;
            border: 1px solid #ccc;
            border-radius: 5px;
            margin-top: 5px;
            box-sizing: border-box;
        }
        button {
            background-color: #2a75bb;
            color: white;
            border: none;
            padding: 10px 15px;
            border-radius: 5px;
            cursor: pointer;
            margin-top: 10px;
        }
        button:hover {
            background-color: #1e5f9a;
        }
        p {
            color: #555;
        }
        a {
            display: inline-block;
            margin-top: 15px;
            color: #2a75bb;
            text-decoration: none;
        }
        a:hover {
            text-decoration: underline;
        }
    </style>
</head>
<body>
    <h1>Cargar nuevo libro</h1>
    <p>En el siguiente formulario, podrás ingresar los datos para cargar un nuevo libro al sistema.</p>

    <form action="?action=cargar" method="POST">
        <label>
            Título del libro:
            <input type="text" name="titulo" required>
        </label>

        <label>
            Autor del libro:
            <input type="text" name="autor" required>
        </label>

        <label>
            Cantidad de páginas:
            <input type="number" name="paginas" min="1" max="5000" required>
        </label>

        <button type="submit">Cargar</button>
    </form>

    <a href="?action=listar">← Volver al listado</a>
</body>
</html>
