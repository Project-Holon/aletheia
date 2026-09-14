/*
 * unit:     no
 * address:  0x02030EF0
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030EF0
 *
 * Row address of a stride-`field4 + 0x18` table: `idx * (p->field4 + 0x18)
 * + p->field14`, the `mla` idiom for an index times a runtime stride plus a
 * base. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030EF0.c \
 *       --func sub_02030EF0 --addr 0x02030EF0 --cc 1.1p1
 */

typedef unsigned int u32;

struct S02030EF0 {
    char pad0[4];
    u32  field4;
    char pad1[0xc];
    u32  field14;
};

u32 sub_02030EF0(struct S02030EF0 *p, u32 idx)
{
    return idx * (p->field4 + 0x18) + p->field14;
}
