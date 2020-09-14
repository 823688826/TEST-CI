--TEST--
Check if helloword is loaded
--SKIPIF--
<?php
if (!extension_loaded('helloword')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "helloword" is available';
?>
--EXPECT--
The extension "helloword" is available
