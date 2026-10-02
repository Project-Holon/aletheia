/*
 * function: func_021C6BD8
 * address:  0x021C6BD8
 * packet:   pkt_ov136_021C6BD8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C7D78 0x021C7D78 data a4
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct StateEnt {
    void (*fn)(u8 *);
    u32 a;
    u32 b;
};
extern const struct StateEnt d_021C7D78[];
int func_021C6BD8(u8 *p)
{
    d_021C7D78[*(u32 *)(p + 0x14)].fn(p);
    return 7;
}
