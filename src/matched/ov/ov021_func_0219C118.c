/*
 * function: FLDMMDL_MOVE_WallWalk
 * address:  0x0219C118
 * packet:   pkt_ov021_0219C118
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   gWallWalkStepTable  0x021D5394  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern Step gWallWalkStepTable[];

void FLDMMDL_MOVE_WallWalk(u32 a)
{
    u8 *p = FLDMMDL_GetMoveProcWork((void *)a);
    while (gWallWalkStepTable[p[0]](a, p) == 1) {
    }
}
