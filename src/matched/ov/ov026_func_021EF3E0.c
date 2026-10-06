/*
 * function: func_021EF3E0
 * address:  0x021EF3E0
 * packet:   pkt_ov026_021EF3E0
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 */

typedef unsigned short u16;
typedef signed short   s16;

struct PtS;
extern void func_021A2640(unsigned char *, struct PtS *);
extern int func_021A26C4(unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern void func_021A21E0(u32 *p);

void func_021EF3E0(int a, s16 *b, s16 *c)
{
    s16 v[2];

    func_021A2640((unsigned char *)a, (struct PtS *)v);
    c[0] = c[0] + (s16)(c[2] + b[11]);
    c[1] = c[1] + (s16)(c[3] + b[12]);
    v[0] = c[0] / 8;
    v[1] = c[1] / 8;
    if (v[0] >= 256 || v[1] >= 160) {
        func_021A21E0((u32 *)a);
        return;
    }
    func_021A26C4(a, (unsigned int)v);
}
