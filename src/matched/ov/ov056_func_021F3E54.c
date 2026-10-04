/*
 * function: func_021F3E54
 * address:  0x021F3E54
 * packet:   pkt_ov056_021F3E54
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C6F4  0x0218C6F4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   d_021F4258  0x021F4258  data  ov056  a4
 */

typedef unsigned int u32;

extern int func_0218C6F4(u32 a, u32 b, int c);
extern int func_02188C80(int a);
extern int func_020120F4(int a);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A7C(int a, int b);
extern int d_021F4258[];

void func_021F3E54(int unused, int b, u32 *c)
{
    int r;

    if (c[2] == func_0218C6F4(c[0], c[1], 1)) {
        r = func_02012A30((const struct BigObj *)func_020120F4(func_02188C80(b)));
        c[3] = 0;
        c[2] = d_021F4258[c[3]];
        func_02028A7C(r, 0x692);
    }
}
