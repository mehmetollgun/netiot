<?php
try{
	
$db = new PDO("mysql:host=hostname;dbname=dbname","username","pass");
}
catch(PDOException $e)
{
	echo($e);
}
$al = $db->query("SELECT * FROM tablename WHERE id='1'")->fetch(PDO::FETCH_ASSOC);
if($al)
{
print($al[komut]);	
}



?>