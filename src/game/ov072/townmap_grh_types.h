/*
 * Types private to the town map graphics file (ov072). The objects shared
 * with the screen code (scroll, text box, label, touch, graphics set) are in
 * townmap_types.h.
 */
#ifndef TOWNMAP_GRH_TYPES_H
#define TOWNMAP_GRH_TYPES_H

#include "townmap_types.h"

/* Opaque library objects. */
struct Bitmap;
struct DispConfig;
struct DispVram;
struct BgTemplate;

/* One display layer setup entry, 0x28 bytes. */
typedef struct TownMapBgEntry {
    u32 bgId;
    u32 templ[8];
    u32 mode;
} TownMapBgEntry;

/* Sprite system init block. */
typedef struct TownMapClactInit {
    u32 word[7];
} TownMapClactInit;

/* One row of the town info table (member 0x56 of the town map archive). */
typedef struct TownMapInfoRow {
    u16 value[27];
} TownMapInfoRow;

#endif
