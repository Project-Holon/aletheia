/*
 * function: func_021840FC
 * address:  0x021840FC
 * packet:   pkt_ov022_021840FC
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): stores the two
 * callbacks and their argument at 0xf4/0xf8/0xfc (the fields
 * func_02183E48 reads). Blocker of ov023 func_02184674.
 */
#include "../include/Obj09764.h"

typedef unsigned char u8;

typedef void (*Cb)(void);

void func_021840FC(u8 *p, Cb a, Cb b, void *arg)
{
    *(Cb *)&((struct Obj09764 *)p)->fF4 = a;
    *(Cb *)&((struct Obj09764 *)p)->fF8 = b;
    ((struct Obj09764 *)p)->fFC = arg;
}
