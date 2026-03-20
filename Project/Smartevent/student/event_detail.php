<?php
include("../config/db.php");

$id = $_GET['id'];
$event = $conn->query("SELECT * FROM events WHERE id=$id")->fetch_assoc();
?>

<h2><?= $event['title'] ?></h2>
<img src="../uploads/<?= $event['image'] ?>" width="300">
<p><?= $event['description'] ?></p>
<p><?= $event['location'] ?></p>

<a href="rsvp.php?id=<?= $event['id'] ?>">RSVP</a>
<a href="bookmark.php?id=<?= $event['id'] ?>">Bookmark</a>
0

