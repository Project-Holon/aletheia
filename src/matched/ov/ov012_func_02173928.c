/*
 * function: UNION_MAIN_IsExitStarted
 * address:  0x02173928
 * packet:   pkt_ov012_02173928
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov012 listing): reads the word at
 * +0x356C.  Callee of ov021 func_0218A0E4.
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19241.h"

typedef unsigned char u8;

int UNION_MAIN_IsExitStarted(u8 *p)
{
    return ((struct Obj19241 *)p)->f356C;
}
