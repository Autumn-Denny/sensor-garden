<?php
// Process the registration form data
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  $username = $_POST['username'];
  $password = $_POST['password'];

  // Perform validation and data sanitization as per your requirements
  // ...

  // Store the credentials in the database (Example: using MySQLi)
  $dbHost = 'your_database_host';
  $dbName = 'your_database_name';
  $dbUser = 'your_database_username';
  $dbPass = 'your_database_password';

  $conn = new mysqli($dbHost, $dbUser, $dbPass, $dbName);
  if ($conn->connect_error) {
    die('Connection failed: ' . $conn->connect_error);
  }

  // Store the username and password in the users table
  $sql = "INSERT INTO users (username, password) VALUES ('$username', '$password')";
  if ($conn->query($sql) === true) {
    echo 'Registration successful!';
  } else {
    echo 'Error: ' . $sql . '<br>' . $conn->error;
  }

  $conn->close();
}
?>
