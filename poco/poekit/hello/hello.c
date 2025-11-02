/*****************************************************************************
 * hello.c - A simple hello world POE module demonstrating the new library
 *           loading system.
 ****************************************************************************/

/*----------------------------------------------------------------------------
 * include the usual header files...
 *--------------------------------------------------------------------------*/

#include "pocorex.h"    /* required header file, also includes pocolib.h */
#include "errcodes.h"   /* most POE programs will need error codes info  */
#include <stdio.h>      /* for printf */

/*----------------------------------------------------------------------------
 * your data and code goes here...
 *--------------------------------------------------------------------------*/

static void hello_func(void)
{
	printf("Hello from POE!\n");
}

/*----------------------------------------------------------------------------
 * Setup pocorex interface structures...
 *--------------------------------------------------------------------------*/

static Lib_proto poe_calls[] = {
	{ hello_func, "void HelloFunc(void);" },
};

Setup_Pocorex(NOFUNC, NOFUNC, "Hello POE", poe_calls);

/*----------------------------------------------------------------------------
 * Entry point function - must be exported as a public symbol
 *--------------------------------------------------------------------------*/

POCO_EXPORT Pocorex* poco_rexlib_get(void)
{
	return &rexlib_header;
}

