#ifndef POKE_TOOL_SHARED_TYPES_H
#define POKE_TOOL_SHARED_TYPES_H

#include "../types.h"

/* The accessors take an integer that is a pointer for string and mail parameters.
 * The DS passes it as u32; the host needs the full pointer width. */
#ifdef __MWERKS__
typedef u32 PokeToolArg;
#else
typedef uptr PokeToolArg;
#endif


struct MsgBank;

struct Pokemon;

#include "../types.h"

#endif
