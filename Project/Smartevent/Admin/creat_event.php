<?php
include("../config/db.php");

if(isset($_POST['create'])){
    $title = $_POST['title'];
    $description = $_POST['description'];
    $date = $_POST['date'];
    $location = $_POST['location'];
    $category = $_POST['category'];

    $image = $_FILES['image']['name'];
    move_uploaded_file($_FILES['image']['tmp_name'],"../uploads/".$image);

    $conn->query("INSERT INTO events 
    (title,description,event_date,location,image,category,created_by)
    VALUES 
    ('$title','$description','$date','$location','$image','$category',
    ".$_SESSION['user']['id'].")");

    header("Location: dashboard.php");
}
?>

<form method="POST" enctype="multipart/form-data">
<input name="title" placeholder="Title">
<textarea name="description"></textarea>
<input type="datetime-local" name="date">
<input name="location" placeholder="Location">
<input name="category" placeholder="Category">
<input type="file" name="image">
<button name="create">Create</button>
</form>
0


