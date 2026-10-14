/*
 * function: BTLV_SCD_ShowCounterScreen
 * address:  0x0689B780
 * packet:   pkt_0689B780
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Witness leaf for ov093 BTLV_CORE_ShowCounterValue (its tail-call pool word is 0x0689B781).
 * Tail-call forwarding thunk: (*(p+0xb0), 6, q) to BTLV_INPUT_ChangeScreen (ov094).
 *
 * symbols:
 *   BTLV_INPUT_ChangeScreen  0x0220270C  thumb  ov094
 */
#include "../include/Obj21900.h"

typedef unsigned char u8;

extern void BTLV_INPUT_ChangeScreen(char *s, int mode, void *arg);

void BTLV_SCD_ShowCounterScreen(void *p, void *q)
{
    BTLV_INPUT_ChangeScreen(((struct Obj21900 *)p)->fB0, 6, q);
}
