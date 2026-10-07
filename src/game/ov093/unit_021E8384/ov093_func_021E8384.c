/*
 * function: func_021E8384
 * address:  0x021E8384
 * packet:   pkt_ov093_021E8384
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F2CF0  0x021F2CF0  data  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct { u16 a; u16 b; int v; } Ent;
extern Ent d_021F2CF0[3];

int func_021E8384(u32 x, u32 y)
{
    u32 i;
    for (i = 0; i < 3; i++) {
        if ((x == d_021F2CF0[i].a && y == d_021F2CF0[i].b) ||
            (y == d_021F2CF0[i].a && x == d_021F2CF0[i].b))
            return d_021F2CF0[i].v;
    }
    return 0;
}
