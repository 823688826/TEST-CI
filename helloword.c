/* helloword extension for PHP */


#include "php.h"
#include "ext/standard/info.h"
#include "php_helloword.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
    ZEND_PARSE_PARAMETERS_START(0, 0) \
    ZEND_PARSE_PARAMETERS_END()
#endif
zend_class_entry *test_ce;
PHP_METHOD(Hello, getFoo)
{
    zval *obj, *foo_value,*aa;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    obj = getThis();

//    foo_value = zend_read_property(test_ce, obj, "foo", sizeof("foo") - 1, 1 ,TSRMLS_CC);
    foo_value = zend_read_property(test_ce,obj,"foo", sizeof("foo")-1,1,aa);
    RETURN_ZVAL(foo_value, 1, 0);
}

PHP_METHOD(Hello, setFoo)
{
    zval *obj, *new_foo_value;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &new_foo_value) == FAILURE) {
        return;
    }

    obj = getThis();

    zend_update_property(test_ce, obj, "foo", sizeof("foo") - 1, new_foo_value TSRMLS_CC);
}
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(helloword)
{
#if defined(ZTS) && defined(COMPILE_DL_HELLOWORD)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(helloword)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "helloword support", "enabled");
    php_info_print_table_end();
}
/* {{{ arginfo
 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_helloword_test1, 0, 0, 0)
ZEND_END_ARG_INFO(  )

ZEND_BEGIN_ARG_INFO_EX(arginfo_helloword_test2, 0, 0, 1)
                ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ helloword_functions[]
*/
const zend_function_entry helloword_functions[] = {
        PHP_ME(Hello,getFoo, arginfo_helloword_test1,ZEND_ACC_PUBLIC)
        PHP_ME(Hello,setFoo, arginfo_helloword_test2,ZEND_ACC_PUBLIC)
        PHP_FE_END
};
/* }}} */

/* {{{ helloword_module_entry
 */
zend_module_entry helloword_module_entry = {
        STANDARD_MODULE_HEADER,
        "helloword",                    /* Extension name */
        helloword_functions,            /* zend_function_entry */
        NULL,                            /* PHP_MINIT - Module initialization */
        NULL,                            /* PHP_MSHUTDOWN - Module shutdown */
        PHP_RINIT(helloword),            /* PHP_RINIT - Request initialization */
        NULL,                            /* PHP_RSHUTDOWN - Request shutdown */
        PHP_MINFO(helloword),            /* PHP_MINFO - Module info */
        PHP_HELLOWORD_VERSION,        /* Version */
        STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HELLOWORD
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(helloword)
#endif

