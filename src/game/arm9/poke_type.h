#ifndef GAME_ARM9_POKE_TYPE_H
#define GAME_ARM9_POKE_TYPE_H

#include "../port_limits.h"

/* Highest valid type id: 17 types, 0..16. */
#define POKETYPE_LAST BW_LIMIT(TYPE_LAST, 16)
#define POKETYPE_COUNT (POKETYPE_LAST + 1)

/*
 * "No type".  The DS uses 17, one past the last type.  The port uses 31,
 * past every type a mod can add: the item record's 5-bit Natural Gift type
 * already means "none" with 31 (543 of the 627 items).
 */
#ifdef __MWERKS__
#define POKETYPE_NONE 17
#else
#define POKETYPE_NONE 31
#endif

#endif
