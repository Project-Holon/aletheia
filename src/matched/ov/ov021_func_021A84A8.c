/*
 * function: func_021A84A8
 * address:  0x021A84A8
 * packet:   pkt_ov021_021A84A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0FB4  0x021A0FB4  thumb
 */

typedef unsigned short u16;

typedef struct {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int pad[7];
    int f28;
} S;

typedef unsigned int   u32;
extern void func_021A0FB4(u32 *p, u32 a);

void func_021A84A8(S *s)
{
    if (s->f28 == 1) {
        func_021A0FB4((u32 *)s->f8, s->h0);
    }
}
