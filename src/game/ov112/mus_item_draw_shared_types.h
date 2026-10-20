#ifndef MUS_ITEM_DRAW_SHARED_TYPES_H
#define MUS_ITEM_DRAW_SHARED_TYPES_H

struct MusItemDrawVec3;

/* An int x/y pair returned by MUSICAL_MCSS_GetOffset. */
typedef struct McssOffset {
    int x;                  /* 0x00 */
    int y;                  /* 0x04 */
} McssOffset;

/* Three int components; BILLBOARD_AddElem takes a struct MusItemDrawVec3 *. */
struct MusItemDrawVec3 { int x, y, z; };

#endif
