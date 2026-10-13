/*
 * function: EVENTDATA_SYSTEM_IsBgEventGridHit
 * address:  0x02162E48
 * packet:   pkt_ov010_02162E48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Position trigger test: an entry of mode 0 matches when the grid cell of
 * pos equals (x, z) and its height is within 2 of the entry's.
 */

typedef unsigned short u16;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct TrigPos {
    s32 x;              /* 0x08 */
    s32 z;              /* 0x0C */
    s32 y;              /* 0x10 */
} TrigPos;

typedef struct Trigger {
    u16 id;             /* 0x00 */
    u16 kind2;          /* 0x02 */
    u16 kind;           /* 0x04 */
    u16 mode;           /* 0x06 */
    TrigPos pos;        /* 0x08 */
} Trigger;

int EVENTDATA_SYSTEM_IsBgEventGridHit(Trigger *t, const VecFx32 *pos)
{
    s32 gx;
    s32 gy;
    s32 gz;
    TrigPos *p;

    if (t->mode == 1)
        return 0;
    p = &t->pos;
    gz = (pos->z >> 4) / 4096;
    gy = pos->y >> 12;
    gx = (pos->x >> 4) / 4096;
    if (p->x == gx && p->z == gz && p->y - 2 <= gy && p->y + 2 > gy)
        return 1;
    return 0;
}
