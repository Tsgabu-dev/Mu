<?php
include("../config/db.php");

if($_SESSION['user']['role']!="admin"){
    header("Location: ../index.php");
}

$result = $conn->query("SELECT * FROM events");
?>

<h2>Admin Dashboard</h2>
<a href="create_event.php">Create Event</a>

<?php while($row = $result->fetch_assoc()): ?>
<div>
    <h3><?= $row['title'] ?></h3>
    <a href="edit_event.php?id=<?= $row['id'] ?>">Edit</a>
    <a href="delete_event.php?id=<?= $row['id'] ?>">Delete</a>
</div>
<?php endwhile; ?>
0

