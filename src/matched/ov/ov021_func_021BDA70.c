/*
 * function: func_021BDA70
 * address:  0x021BDA70
 * packet:   pkt_ov021_021BDA70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A7B20  0x021A7B20  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021BDC80  0x021BDC80  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
struct Args;
struct Evt;
extern void *func_021A7B20(struct Args *a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_021BDC80(u32 *);
u32 func_021BDA70(u32 a, u32 *st, u32 *p)
{
    u32 v = p[0];
    switch (st[0]) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7B20((struct Args *)v));
        st[0]++;
        break;
    case 1:
        func_021BDC80(p);
        return 1;
    }
    return 0;
}
