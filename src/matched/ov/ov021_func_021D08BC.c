/*
 * function: func_021D08BC
 * address:  0x021D08BC
 * packet:   pkt_ov021_021D08BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D08B0  0x021D08B0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Row {
    u32 f0;
    int f4;
    u32 f8[3];
} Row;

extern void func_021D08B0(Row *r);

void func_021D08BC(Row *r, int v)
{
    if (r->f0 != 0) {
        r->f4 += 0x1000;
        if (r->f4 > v) {
            func_021D08B0(r);
        }
    }
}
