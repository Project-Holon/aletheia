/*
 * function: FLDMMDL_MOVE_LookPlayer
 * address:  0x0219B8E8
 * packet:   pkt_ov021_0219B8E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_MOVE_UpdatePlayerTracking  0x0219B984  thumb  ov021
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   gLookPlayerStepTable  0x021D5374  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern int FLDMMDL_MOVE_UpdatePlayerTracking(u32 a, u32 b);
extern void FLDMMDL_SetStatusBitFellowHit(unsigned int *p, unsigned int v);
extern Step gLookPlayerStepTable[];

void FLDMMDL_MOVE_LookPlayer(u32 a)
{
    u8 *p = FLDMMDL_GetMoveProcWork((void *)a);
    if (FLDMMDL_MOVE_UpdatePlayerTracking(a, (u32)p)) {
        FLDMMDL_SetStatusBitFellowHit((unsigned int *)a, 0);
        while (gLookPlayerStepTable[p[0]](a, p) == 1) {
        }
    }
}
