#ifndef MUS_ITEM_DRAW_SHARED_TYPES_H
#define MUS_ITEM_DRAW_SHARED_TYPES_H

struct Vec3;

/* An int x/y pair returned by MUSICAL_MCSS_GetOffset. */
typedef struct McssOffset {
    int x;                  /* 0x00 */
    int y;                  /* 0x04 */
} McssOffset;

/* Three int components; BILLBOARD_AddElem takes a struct Vec3 *. */
struct Vec3 { int x, y, z; };

#endif
