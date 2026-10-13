/*
 * function: UNION_MAIN_GetFieldRequest
 * address:  0x0217391C
 * packet:   pkt_ov012_0217391C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov012 listing): reads the word at
 * +0x3568.  Callee of ov021 func_0218A0E4.
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19240.h"

typedef unsigned char u8;

int UNION_MAIN_GetFieldRequest(u8 *p)
{
    return ((struct Obj19240 *)p)->f3568;
}
