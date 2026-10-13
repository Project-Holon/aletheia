/*
 * function: FLDMMDL_MOVE_HitCheckWallWalkDir
 * address:  0x0219C314
 * packet:   pkt_ov021_0219C314
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_GetWallWalkDir  0x0219C2E0  thumb  ov021
 *   FLDMMDL_MOVE_HitCheckMoveDir  0x021639C0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_MOVE_GetWallWalkDir(u32 a, int b, int c);
extern int FLDMMDL_MOVE_HitCheckMoveDir(u32 a, u16 v);

int FLDMMDL_MOVE_HitCheckWallWalkDir(int a, int *s, u32 c)
{
    int v = FLDMMDL_MOVE_GetWallWalkDir(a, *s, c);
    *s = v;
    if (v != 9) {
        return FLDMMDL_MOVE_HitCheckMoveDir(a, v);
    }
    return 0;
}
