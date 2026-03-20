0
<?php
include("../config/db.php");

if(isset($_POST['register'])){
    $name = $_POST['name'];
    $email = $_POST['email'];
    $password = password_hash($_POST['password'], PASSWORD_DEFAULT);
    $department = $_POST['department'];

    $sql = "INSERT INTO users (name,email,password,department) 
            VALUES ('$name','$email','$password','$department')";
    $conn->query($sql);

    header("Location: login.php");
}
?>

<form method="POST">
<input name="name" placeholder="Name" required>
<input name="email" placeholder="Email" required>
<input type="password" name="password" placeholder="Password" required>
<input name="department" placeholder="Department">
<button name="register">Register</button>
</form>
0
0

