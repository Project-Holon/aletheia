/*
 * function: UNION_APP_IsResetDone
 * address:  0x0218417C
 * packet:   pkt_ov022_0218417C
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): returns the word
 * at 0x28. Blocker of ov023 OEKAKI_Main.
 */
#include "../include/Obj20330.h"

typedef unsigned char u8;
typedef unsigned int  u32;

u32 UNION_APP_IsResetDone(u8 *p)
{
    return ((struct Obj20330 *)p)->f28;
}
