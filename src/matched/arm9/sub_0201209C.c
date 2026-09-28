/*
 * function: sub_0201209C
 * address:  0x0201209C
 * packet:   pkt_02012088
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The word pair setter that follows func_02012088's epilogue at 0x0201209A:
 * two words at +0x10 and +0x14, no prologue, no label.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201209C.c \
 *       --func sub_0201209C --addr 0x0201209C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


void sub_0201209C(void *o, u32 v1, u32 v2)
{
    *(u32 *)((u8 *)o + 0x10) = v1;
    *(u32 *)((u8 *)o + 0x14) = v2;
}

