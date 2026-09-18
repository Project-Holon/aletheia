/*
 * function: sub_02016380
 * address:  0x02016380
 * packet:   pkt_0201394C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set bit 0 of the word at +0x144: read, clear, set, write back.  The two
 * `movs r1, #1` are the two separate constants of the `& ~1` / `| 1` pair
 * (Thumb has no ORR immediate, so both go through r1).  Entry attested by
 * the pool word 0x02016381 in sub_020173C8's own pool.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02016380.c \
 *       --func sub_02016380 --addr 0x02016380 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


void sub_02016380(void *o)
{
    u32 v = *(u32 *)((u8 *)o + 0x144);

    v = v & ~1u;
    v = v | 1u;
    *(u32 *)((u8 *)o + 0x144) = v;
}

