<?php
declare(strict_types=1);

require_once __DIR__ . '/modelos/errores.php';
require_once __DIR__ . '/controladores/controladorLibros.php';

// Obtener la acción (por defecto: 'index')
$action = $_GET['action'] ?? 'index';
$id = filter_input(INPUT_GET, 'id', FILTER_VALIDATE_INT);

$controlador = new ControladorLibros();

switch ($action) {
    case 'ver':
        if ($id !== null) {
            $controlador->ver($id);
        } else {
            mostrarError("ID de libro no válido.");
        }
        break;

    case 'crear':
        $controlador->crear();
        break;

    case 'cargar':
        $controlador->cargar();
        break;

    case 'eliminar':
        $eliminado = filter_input(INPUT_POST, 'id', FILTER_VALIDATE_INT);
        if ($eliminado !== null) {
            $controlador->eliminar($eliminado);
        } else {
            mostrarError("No se recibió un ID válido para eliminar.");
        }
        break;

    default:
        $controlador->listar();
        break;
}
