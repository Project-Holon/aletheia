#ifndef GAME_OV021_FLDMMDL_RAIL_TYPES_H
#define GAME_OV021_FLDMMDL_RAIL_TYPES_H

/* fldmmdl_rail.c: a field model on a rail keeps its place as a rail
 * location. The rail move code (fldmmdl_rail_move.c) passes it around too. */

#include "../types.h"

/* A place on the rails (8 bytes). */
typedef struct {
    u16 railIndex;    /* which rail */
    u8 type;          /* 2 marks a stored location as not set yet */
    u8 key;           /* rail move key, converted from a direction (ZONEDATA_DirToRailKey) */
    s16 widthGrid;    /* grid position across the rail line, 0 at the centre */
    u16 lineGrid;     /* grid position along the rail line */
} RailLocation;

#endif
