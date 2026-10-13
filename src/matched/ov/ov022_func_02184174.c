/*
 * function: UNION_APP_RequestReset
 * address:  0x02184174
 * packet:   pkt_ov022_02184174
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): sets the word at
 * 0x20. Blocker of ov023 OEKAKI_Main.
 */
#include "../include/Obj20329.h"

typedef unsigned char u8;
typedef unsigned int  u32;

void UNION_APP_RequestReset(u8 *p)
{
    ((struct Obj20329 *)p)->f20 = 1;
}
