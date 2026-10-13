/*
 * function: FLDMMDL_MOVE_LookFellow
 * address:  0x0219BB08
 * packet:   pkt_ov021_0219BB08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_MOVE_UpdateFellowTracking  0x0219BC48  thumb  ov021
 *   gLookFellowStepTable  0x021D538C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern int FLDMMDL_MOVE_UpdateFellowTracking(int a, u8 *b);
extern Step gLookFellowStepTable[];

void FLDMMDL_MOVE_LookFellow(u32 a)
{
    u8 *p = FLDMMDL_GetMoveProcWork((void *)a);
    if (FLDMMDL_MOVE_UpdateFellowTracking(a, p)) {
        while (gLookFellowStepTable[p[0]](a, p) == 1) {
        }
    }
}
