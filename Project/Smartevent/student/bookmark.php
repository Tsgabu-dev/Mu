<?php
include("../config/db.php");

$user_id = $_SESSION['user']['id'];
$event_id = $_GET['id'];

$conn->query("INSERT INTO bookmarks (user_id,event_id)
VALUES ($user_id,$event_id)");

header("Location: my_events.php");
0

