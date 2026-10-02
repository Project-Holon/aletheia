/*
 * function: func_021D55D8
 * address:  0x021D55D8
 * packet:   pkt_ov093_021D55D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: the index is added in each arm of the table select, so the sum is
 * formed once and shared by the halfword and byte loads.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 a; u8 b; u8 c; u8 pad[10]; } Ent;
int func_021D55D8(u8 *p, int i, int s)
{
    Ent *e;
    if (s) e = (Ent *)(p + 0x104) + i; else e = (Ent *)(p + 0x10a) + i;
    if (e->a != 0 && e->b == e->c) return 1;
    return 0;
}
