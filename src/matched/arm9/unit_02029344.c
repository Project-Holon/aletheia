/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02029344
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02029344, sub_02029348
 *
 * Two leaf helpers on the same object as the six checker/trampoline pairs of
 * pkt_0202918C's neighbour packets: sub_02029344 is a plain word setter at
 * offset 4, and sub_02029348 clears four fields (two words at +0xc/+0x1c,
 * two halfwords at +0x18/+0x1a) that the checker wrappers elsewhere test and
 * arm. Neither function has a relocation of any kind.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029344.c \
 *       --addr 0x02029344 --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

void sub_02029344(void *obj, u32 value)
{
    *(u32 *)((char *)obj + 4) = value;
}

void sub_02029348(void *obj)
{
    *(u32 *)((char *)obj + 0x1c) = 0;
    *(u32 *)((char *)obj + 0xc) = 0;
    *(u16 *)((char *)obj + 0x18) = 0;
    *(u16 *)((char *)obj + 0x1a) = 0;
}
