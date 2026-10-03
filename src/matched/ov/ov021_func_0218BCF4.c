/*
 * function: func_0218BCF4
 * address:  0x0218BCF4
 * packet:   pkt_ov021_0218BCF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020113D8  0x020113D8  thumb
 *   d_021D3D50     0x021D3D50  data  a4
 */

typedef struct {
    int cur;
    int prev;
    int changed;
    unsigned char val;
    unsigned char id;
} S;

extern unsigned char d_021D3D50[];
typedef unsigned int   u32;
u32 func_020113D8(u32 row);

void func_0218BCF4(S *p)
{
    p->prev = p->cur;
    p->cur = func_020113D8(p->id);
    p->changed = p->cur != p->prev;
    p->val = d_021D3D50[p->cur];
}
