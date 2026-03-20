<?php
include("../config/db.php");

if(isset($_POST['login'])){
    $email = $_POST['email'];
    $password = $_POST['password'];

    $result = $conn->query("SELECT * FROM users WHERE email='$email'");
    $user = $result->fetch_assoc();

    if($user && password_verify($password,$user['password'])){
        $_SESSION['user'] = $user;
        
        if($user['role']=="admin"){
            header("Location: ../admin/dashboard.php");
        } else {
            header("Location: ../student/home.php");
        }
    }
}
?>

<form method="POST">
<input name="email" placeholder="Email">
<input type="password" name="password" placeholder="Password">
<button name="login">Login</button>
</form>
0

