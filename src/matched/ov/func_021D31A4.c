/*
 * function: FLD_VREQ_Delete
 * address:  0x021D31A4
 * packet:   pkt_021D31A4
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

void FLD_VREQ_Delete(u32 a)
{
    func_020307B0((void *)a);
}
