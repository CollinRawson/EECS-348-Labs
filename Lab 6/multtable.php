<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Practice 4</title>
</head>
<body>
    <?php
        $size = $_POST['size'];
        echo "<table><tr><th></th>";
        for ($i = 1; $i <= $size; $i++) {
            echo "<th>$i</th>";
        }
        echo "</th>";
        for ($i = 1; $i <= $size; $i++) {
            echo "<tr><th>$i</th>";
            for ($j = 1; $j <= $size; $j++) {
                $product = $i * $j;
                echo "<td>$product</td>";
            }
            echo "</tr>";
        }
        echo "</table>";
    ?>
</body>
</html>

