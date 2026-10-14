/*
 * function: BTLV_SCD_ShowRotateScreen
 * address: 0x0689B514
 * packet: pkt_ov095_0689B514
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled C follower after the non-C veneer at 0689B504.
 * symbols:
 *   BTLV_INPUT_ChangeScreen 0x0220270C thumb ov094
 */
#include "../include/Obj21895.h"
extern void BTLV_INPUT_ChangeScreen(char *s, int mode, void *arg);
void BTLV_SCD_ShowRotateScreen(void *p, void *q)
{
    BTLV_INPUT_ChangeScreen(((struct Obj21895 *)p)->fB0, 5, q);
}
