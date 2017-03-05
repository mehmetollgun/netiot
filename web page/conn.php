<?php
try{
	
$db = new PDO("mysql:host=hostname;dbname=dbname","username","pass");
}catch(PDOException $e){

echo($e);
}
$alinan = $_POST['txt'];

$id=1;
$oncekiveri=$db->query("SELECT * FROM tablename WHERE id='{$id}'")->fetch(PDO::FETCH_ASSOC);
if($oncekiveri)
{
	$last=$oncekiveri[komut];
	
}

$guncelle = $db->prepare("UPDATE tablename SET komut=:kimlik WHERE komut=:gonderilecek");
$process=$guncelle->execute(array("kimlik"=>$alinan,"gonderilecek"=>$last));
if($process)
{
print "guncelleme basarili";	
header("Location:index.php");

}
?>
