/*
 * function: sub_02010FAC
 * address:  0x02010FAC
 * packet:   pkt_020107CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An empty function: a pool word in the image holds 0x02010FAD (Thumb), so
 * this two-byte `bx lr` is a real entry point, a placeholder callback that
 * disasm.py could not label because it saves nothing.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010FAC.c \
 *       --func sub_02010FAC --addr 0x02010FAC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


void sub_02010FAC(void)
{
}

