<?php
/**
 * Configuración de manejo de errores para el sistema de libros.
 * Permite alternar entre modo desarrollo y producción.
 */

// ================================
// CONFIGURACIÓN PRINCIPAL
// ================================
$modoDesarrollo = true; // Cambiar a false para modo PRODUCCIÓN

// ================================
// CONFIGURACIÓN DE ERRORES PHP
// ================================
if ($modoDesarrollo) {
    // Mostrar todos los errores en pantalla (para depurar)
    error_reporting(E_ALL);
    ini_set('display_errors', '1');
    ini_set('log_errors', '0');
} else {
    // Ocultar errores en pantalla y guardarlos en un archivo
    error_reporting(E_ALL);
    ini_set('display_errors', '0');
    ini_set('log_errors', '1');
    ini_set('error_log', __DIR__ . '/errores.log');
}

/**
 * Muestra una página de error con un formato coherente con las vistas.
 *
 * @param string $mensaje Mensaje de error para el usuario.
 * @param int $codigo Código HTTP opcional (por defecto 400).
 * @return void
 */
function mostrarError(string $mensaje, int $codigo = 400): void
{
    http_response_code($codigo);
    ?>
    <!DOCTYPE html>
    <html lang="es">
    <head>
        <meta charset="UTF-8">
        <title>Error <?= htmlspecialchars((string)$codigo) ?></title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background: #fafafa;
                margin: 40px;
            }
            h1 {
                color: #c62828;
            }
            p {
                background: #fff;
                border-left: 5px solid #c62828;
                padding: 15px;
                box-shadow: 0 0 5px rgba(0,0,0,0.1);
                max-width: 600px;
            }
            a {
                display: inline-block;
                margin-top: 15px;
                text-decoration: none;
                color: #2a75bb;
            }
            a:hover {
                text-decoration: underline;
            }
        </style>
    </head>
    <body>
        <h1>Ocurrió un error</h1>
        <p><?= htmlspecialchars($mensaje) ?></p>
        <a href="./">Volver al listado</a>
    </body>
    </html>
    <?php
    exit;
}
