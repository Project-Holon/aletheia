/*
 * function: func_02189BBC
 * address:  0x02189BBC
 * packet:   pkt_ov021_02189BBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02189B28  0x02189B28  thumb  ov021
 *   d_021D373C     0x021D373C  data  a4
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    unsigned char pad[0x3C];
} Ent;

extern Ent d_021D373C[];
unsigned int func_02189B28(unsigned int x);

int func_02189BBC(int x)
{
    return d_021D373C[(int)func_02189B28((unsigned int)x)].f8;
}
