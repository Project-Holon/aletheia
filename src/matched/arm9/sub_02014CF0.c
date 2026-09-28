/*
 * function: sub_02014CF0
 * address:  0x02014CF0
 * packet:   pkt_0201394C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two consecutive word stores through the object pointer - a plain field
 * pair setter with no prologue, so no label, attested by the pool word
 * 0x02014CF1.  The stores are in source order.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014CF0.c \
 *       --func sub_02014CF0 --addr 0x02014CF0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct Obj02014CF0;

void sub_02014CF0(struct Obj02014CF0 *o, u32 v1, u32 v2)
{
    *(u32 *)((u8 *)o + 0x38) = v1;
    *(u32 *)((u8 *)o + 0x3c) = v2;
}

