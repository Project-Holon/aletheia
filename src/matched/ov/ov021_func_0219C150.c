/*
 * function: FLDMMDL_MOVE_WallWalkTryStep
 * address:  0x0219C150
 * packet:   pkt_ov021_0219C150
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_WallWalkStepOnce  0x0219C338  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_MOVE_WallWalkStepOnce(char *a, u32 *s, u32 c);

int FLDMMDL_MOVE_WallWalkTryStep(char *a, u8 *s)
{
    FLDMMDL_MOVE_WallWalkStepOnce(a, (u32 *)s, 12);
    s[0]++;
    return 1;
}
