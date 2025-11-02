/*****************************************************************************
 * POCOLoad.H - Header file for POE (Poco Extension) modules.
 * 
 * This header defines the entry point function signature and structure
 * definitions required for creating loadable Poco libraries.
 * 
 * POE modules should include this header to ensure compatibility with
 * the Poco library loading system.
 ****************************************************************************/

#ifndef POCOLoad_H
#define POCOLoad_H

#ifndef STDTYPES_H
	#include "stdtypes.h"
#endif

#ifndef POCOLIB_H
	#include "pocolib.h"
#endif

/*****************************************************************************
 * Forward declarations
 ****************************************************************************/

typedef struct pocorex Pocorex;

/*****************************************************************************
 * Entry point function signature for POE modules
 * 
 * Each POE module MUST export a function with this exact signature:
 * 
 *   Pocorex* poco_rexlib_get(void);
 * 
 * This function should return a pointer to a statically allocated Pocorex
 * structure that contains the library definition (see pocorex.h for details).
 * 
 * Example:
 * 
 *   Pocorex* poco_rexlib_get(void) {
 *       return &rexlib_header;
 *   }
 * 
 * IMPORTANT: This function must be exported as a public symbol:
 *   - Linux/macOS: Use __attribute__((visibility("default"))) or compile with -fvisibility=default
 *   - Windows: Use __declspec(dllexport)
 ****************************************************************************/

typedef Pocorex* (*Poco_rexlib_get_func)(void);

/*****************************************************************************
 * POE Module Requirements
 * 
 * To create a loadable Poco library (POE module), you must:
 * 
 * 1. Include the necessary headers:
 *    #include "pocoload.h"
 *    #include "pocorex.h"  (for Pocorex structure definition)
 * 
 * 2. Define your library functions and prototypes:
 *    Lib_proto lib_calls[] = {
 *        {my_function1, "void MyFunc1(void);"},
 *        {my_function2, "int MyFunc2(int x);"},
 *    };
 * 
 * 3. Set up the Pocorex structure using Setup_Pocorex macro:
 *    Setup_Pocorex(init_func, cleanup_func, "My Library Name", lib_calls);
 * 
 * 4. Export the entry point function:
 *    Pocorex* poco_rexlib_get(void) {
 *        return &rexlib_header;
 *    }
 * 
 * 5. Build as a shared library:
 *    - Linux: .so extension
 *    - macOS: .dylib extension
 *    - Windows: .dll extension
 *    - Or use .poe extension for cross-platform compatibility
 * 
 * 6. Export the poco_rexlib_get symbol:
 *    - Linux/macOS: -fvisibility=default or __attribute__((visibility("default")))
 *    - Windows: __declspec(dllexport)
 ****************************************************************************/

#endif /* POCOLoad_H */

