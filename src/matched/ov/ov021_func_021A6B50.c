/*
 * function: func_021A6B50
 * address:  0x021A6B50
 * packet:   pkt_ov021_021A6B50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5D8  0x0216D5D8  thumb
 *   d_021D8AB0  0x021D8AB0  data  ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    short h2;
} P;

extern void func_0216D5D8(int a, int b);
extern const u8 d_021D8AB0[][4];

void func_021A6B50(P *p, int a)
{
    if (p->b0) {
        p->h2 = (p->h2 + 1) % 4;
        func_0216D5D8(a, d_021D8AB0[p->b1][p->h2]);
    }
}
