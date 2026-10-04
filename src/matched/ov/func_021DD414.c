/*
 * function: func_021DD414
 * address:  0x021DD414
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Forward two biased halfword coordinates.
 */

typedef unsigned int   u32;
struct Party;
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);

void func_021DD414(char **p, char *q)
{
    func_0201AB8C((struct Party *)(*(int *)(*p + 8)), *(unsigned short *)(q + 4) - 0x1e,
                  *(unsigned short *)(q + 2) - 0x1e, 0x4c);
}

