/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2013 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Felipe Pena <felipe@php.net>                                |
   | Authors: Joe Watkins <joe.watkins@live.co.uk>                        |
   +----------------------------------------------------------------------+
*/

#ifndef PHPDBG_INFO_H
#define PHPDBG_INFO_H

#include "TSRM.h"
#include "phpdbg.h"
#include "phpdbg_prompt.h"
#include "phpdbg_utils.h"

/**
 * Command Declarators
 */
#define PHPDBG_INFO_HANDLER(name) phpdbg_do_info_##name
#define PHPDBG_INFO_D(name, tip) \
	{PHPDBG_STRL(#name), tip, sizeof(tip)-1, 0, PHPDBG_INFO_HANDLER(name), NULL}
#define PHPDBG_INFO_EX_D(name, tip, alias) \
	{PHPDBG_STRL(#name), tip, sizeof(tip)-1, alias, PHPDBG_INFO_HANDLER(name), NULL}
#define PHPDBG_INFO(name) \
	int PHPDBG_INFO_HANDLER(name)(phpdbg_param_t *param TSRMLS_DC)

PHPDBG_INFO(files);
PHPDBG_INFO(classes);
PHPDBG_INFO(funcs);
PHPDBG_INFO(error);
PHPDBG_INFO(vars);

static const phpdbg_command_t phpdbg_info_commands[] = {
    PHPDBG_INFO_EX_D(files,     "lists included files",  'F'),
    PHPDBG_INFO_EX_D(classes,   "lists loaded classes",  'c'),
    PHPDBG_INFO_EX_D(funcs,   	"lists loaded classes",  'f'),
    PHPDBG_INFO_EX_D(error,     "show the last error",   'e'),
    PHPDBG_INFO_EX_D(vars,      "show active variables", 'v'),
    PHPDBG_END_COMAND
};

#endif /* PHPDBG_INFO_H */
