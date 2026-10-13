/*
 * function: FLDMMDL_MOVE_IsWallAtOffsetA
 * address:  0x0219C180
 * packet:   pkt_ov021_0219C180
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb  ov010
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   gWallCheckOffsetAX  0x021D53B4  data  a4
 *   gWallCheckOffsetAZ  0x021D53D4  data  a4
 *
 * r = 0 is the first statement: its early live range pushes a to a stack
 * spill and leaves ip for &t.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern int FLDMMDL_MOVE_GetMapAttr(u32, Vec *, u32 *);
extern int MAP_ATTR_IsBlocked(u32 attr);
extern int gWallCheckOffsetAX[][2];
extern int gWallCheckOffsetAZ[][2];

int FLDMMDL_MOVE_IsWallAtOffsetA(u32 a, Vec *p, int b, int c)
{
    int r;
    s16 x;
    s16 z;
    Vec t;
    u32 out;

    r = 0;
    t = *p;
    x = (p->x >> 4) / 4096;
    z = (p->z >> 4) / 4096;
    x += (s16)gWallCheckOffsetAX[b][c];
    z += (s16)gWallCheckOffsetAZ[b][c];
    t.x = x << 16;
    t.z = z << 16;
    if (FLDMMDL_MOVE_GetMapAttr(a, &t, &out) == 1 && MAP_ATTR_IsBlocked(out) != 0) {
        r = 1;
    }
    return r;
}
