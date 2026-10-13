/*
 * function: FLDMMDL_MOVE_IsWallNearA
 * address:  0x0219C298
 * packet:   pkt_ov021_0219C298
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_IsWallAtOffsetA  0x0219C180  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *v);
extern int FLDMMDL_MOVE_IsWallAtOffsetA(u32 a, Vec *p, int b, int c);

int FLDMMDL_MOVE_IsWallNearA(u32 a, int b, int c)
{
    Vec v;
    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&v);
    return FLDMMDL_MOVE_IsWallAtOffsetA(a, &v, b, c);
}
