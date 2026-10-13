/*
 * function: FLDMMDL_MOVE_Hide
 * address:  0x0219BE3C
 * packet:   pkt_ov021_0219BE3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   gHideStepTable  0x021D537C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern Step gHideStepTable[];

void FLDMMDL_MOVE_Hide(u32 a)
{
    u8 *p = FLDMMDL_GetMoveProcWork((void *)a);
    while (gHideStepTable[p[0]](a, p) == 1) {
    }
}
