/*
 * function: func_021DFEAC
 * address:  0x021DFEAC
 * packet:   pkt_021DFC20
 * region:   ov228
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf in ov228: the address of the sub-object at +0xC of the
 * work object.  Caller: arm9 MYSTERY_DATA_Load (mystery_data.c), which passes the
 * value func_021DFC20 returned, still live in r0.  Integrator: seed ov228
 * 0x021DFEAC.
 */

typedef unsigned char u8;

void *func_021DFEAC(u8 *p)
{
    return p + 0xc;
}
