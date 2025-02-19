<?php
include 'eventdb.php';

header("Content-Type: application/json");

$method = $_SERVER['REQUEST_METHOD'];
$input = json_decode(file_get_contents('php://input'), true);

switch ($method) {
    case 'GET':
		//<h> GET </h>
        if (isset($_GET['un'])) {
            $un = $_GET['un'];
            $result = $conn->query("SELECT * FROM events WHERE user='$un'");
			$data = [];
			while($row = $result->fetch_assoc()) {
				$data[] = $row;
			}
            echo json_encode($data);
        } else if (isset($_GET['id'])) {
			$id = $_GET['id'];
			$result = $conn->query("SELECT * FROM events WHERE _id='$id'");
			echo json_encode($result->fetch_assoc());
		} else	{
            $result = $conn->query("SELECT * FROM events");
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
		
        $u = $input['user'];
        $n = $input['name'];
        $d = $input['date'];
		$t = $input['time'];
        $des = $input['description'];
		
        $conn->query("INSERT INTO events (user, name, date, time, description) VALUES ('$u', '$n', '$d', '$t', '$des')");
        echo json_encode(["message" => "Event added successfully"]);
        break;

    case 'PUT':
        $id = $_GET['id'];
		
        $u = $input['user'];
        $n = $input['name'];
        $d = $input['date'];
		$t = $input['time'];
        $des = $input['description'];
		
        $conn->query("UPDATE events SET user='$u',
                     name='$n', date=$d, time='$t', description=$des WHERE _id='$id'");
        echo json_encode(["message" => "Event updated successfully"]);
        break;

    case 'DELETE':
        $id = $_GET['id'];
        $conn->query("DELETE FROM events WHERE _id='$id'");
        echo json_encode(["message" => "Event deleted successfully"]);
        break;

    default:
        echo json_encode(["message" => "Invalid request method"]);
        break;
}

$conn->close();




?>