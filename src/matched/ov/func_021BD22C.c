/*
 * function: PLACE_NAME_LETTER_FreeWork
 * address:  0x021BD22C
 * packet:   pkt_021BD1CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020307B0(void *p);

u32 PLACE_NAME_LETTER_FreeWork(void *a0)
{
    return func_020307B0(a0);
}
