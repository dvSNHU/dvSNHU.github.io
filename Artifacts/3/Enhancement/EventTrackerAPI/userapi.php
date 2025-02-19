<?php
include 'userdb.php';

header("Content-Type: application/json");

$method = $_SERVER['REQUEST_METHOD'];
$input = json_decode(file_get_contents('php://input'), true);

switch ($method) {
    case 'GET':
		//<h> GET </h>
        if (isset($_GET['un'])) {
            $un = $_GET['un'];
            $result = $conn->query("SELECT * FROM users WHERE username='$un'");
            $data = $result->fetch_assoc();
            echo json_encode($data);
        } else {
            $result = $conn->query("SELECT * FROM users");
            $users = [];
            while ($row = $result->fetch_assoc()) {
                $users[] = $row;
            }
            echo json_encode($users);
        }
        break;

    case 'POST':
		/*
		$un = $_GET['username'];
        $ph = $_GET['passhash'];
        $sal = $_GET['salt'];
		*/
		
        $un = $input['username'];
        $ph = $input['passhash'];
        $sal = $input['salt'];
		
        $conn->query("INSERT INTO users (username, passhash, salt) VALUES ('$un', '$ph', '$sal')");
        echo json_encode(["message" => "User added successfully"]);
        break;

    case 'PUT':
        $id = $_GET['id'];
        $name = $input['name'];
        $email = $input['email'];
        $age = $input['age'];
        $conn->query("UPDATE users SET name='$name',
                     email='$email', age=$age WHERE id=$id");
        echo json_encode(["message" => "User updated successfully"]);
        break;

    case 'DELETE':
        $id = $_GET['id'];
        $conn->query("DELETE FROM users WHERE id=$id");
        echo json_encode(["message" => "User deleted successfully"]);
        break;

    default:
        echo json_encode(["message" => "Invalid request method"]);
        break;
}

$conn->close();




?>