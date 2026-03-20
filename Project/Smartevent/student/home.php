<?php
include("../config/db.php");
$result = $conn->query("SELECT * FROM events ORDER BY event_date ASC");
?>

<h2>Events</h2>

<?php while($row = $result->fetch_assoc()): ?>
<div>
    <img src="../uploads/<?= $row['image'] ?>" width="150">
    <h3><?= $row['title'] ?></h3>
    <p><?= $row['category'] ?></p>
    <a href="event_detail.php?id=<?= $row['id'] ?>">View</a>
</div>
<?php endwhile; ?>
0

