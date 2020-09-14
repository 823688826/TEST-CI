--TEST--
helloword_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('helloword')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = helloword_test1();

var_dump($ret);
?>
--EXPECT--
The extension helloword is loaded and working!
NULL
