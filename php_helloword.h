/* helloword extension for PHP */

#ifndef PHP_HELLOWORD_H
# define PHP_HELLOWORD_H

extern zend_module_entry helloword_module_entry;
# define phpext_helloword_ptr &helloword_module_entry

# define PHP_HELLOWORD_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_HELLOWORD)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_HELLOWORD_H */

