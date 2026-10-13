/*
 * unit:     no
 * address:  0x02030EE8
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: TCBL_IsDeletePending
 *
 * A plain word accessor at offset 0x10. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_IsDeletePending.c \
 *       --func TCBL_IsDeletePending --addr 0x02030EE8 --cc 1.1p1
 */

typedef unsigned int u32;

struct S02030EE8 {
    char pad[0x10];
    u32  field10;
};

u32 TCBL_IsDeletePending(struct S02030EE8 *p)
{
    return p->field10;
}
