/*
 * function: sub_020173C8
 * address:  0x020173C8
 * packet:   pkt_0201394C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02016380  0x02016380  thumb
 *
 * A four-byte tail call: the pool word 0x02016381 (Thumb) is loaded and
 * `bx r3` jumps with the incoming r0 untouched, i.e. sub_02016380 itself.
 * Its witness is the EXACT entry for 0x02016380 in this same shard - the
 * `matched` class - which is what makes the pool word resolve.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020173C8.c \
 *       --func sub_020173C8 --addr 0x020173C8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void sub_02016380(void *o);

void sub_020173C8(void *o)
{
    sub_02016380(o);
}

