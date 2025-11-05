#define REXLIB_INTERNALS 1
#include "rexlib.h"

#if defined(_WIN32) || defined(__CYGWIN__)
#define ANIMHOST_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define ANIMHOST_EXPORT __attribute__((visibility("default")))
#else
#define ANIMHOST_EXPORT
#endif

/*
 * Canonical definitions of the legacy Hostlib handles.
 * These symbols must exist exactly once in the process so that
 * legacy POE modules and the Animator host share the same addresses.
 */

ANIMHOST_EXPORT Hostlib _a_a_syslib   = { NULL, AA_SYSLIB,    AA_SYSLIB_VERSION };
ANIMHOST_EXPORT Hostlib _a_a_loadpath = { NULL, AA_LOADPATH,  AA_LOADPATH_VERSION };
ANIMHOST_EXPORT Hostlib _a_a_stdiolib = { NULL, AA_STDIOLIB,  AA_STDIOLIB_VERSION };
ANIMHOST_EXPORT Hostlib _a_a_gfxlib   = { NULL, AA_GFXLIB,    AA_GFXLIB_VERSION };
ANIMHOST_EXPORT Hostlib _a_a_pocolib  = { NULL, AA_POCOLIB,   AA_POCOLIB_VERSION };
ANIMHOST_EXPORT Hostlib _a_a_mathlib  = { NULL, AA_MATHLIB,   AA_MATHLIB_VERSION };


