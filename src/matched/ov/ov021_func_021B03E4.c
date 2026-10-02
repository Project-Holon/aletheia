/*
 * function: func_021B03E4
 * address:  0x021B03E4
 * packet:   pkt_ov021_021B03E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_0215A654  0x0215A654  thumb  ov010
 *   func_02190FA0  0x02190FA0  thumb  ov021
 *   func_0215A660  0x0215A660  thumb  ov010
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 */

typedef unsigned int u32;

extern u32 func_02159190(u32);
extern u32 func_0215A61C(u32);
extern void func_02191164(void *p);
extern void *func_0215A5F4(void *p);
extern u32 *func_02158F58(void *);
extern u32 func_0215A60C(u32);
extern u32 func_0215A654(u32);
extern u32 func_02190FA0(u32, u32, u32);
extern void func_0215A660(u32, u32);
extern void func_0215A614(u32, u32);
extern void func_02159144(u32);

void func_021B03E4(u32 a, u32 b)
{
    u32 x, r4, r5;
    u32 *p;

    r5 = 1;
    if (func_02159190(1)) {
        func_02191164((void *)func_0215A61C(a));
        return;
    }
    p = func_02158F58(func_0215A5F4((void *)a));
    x = func_0215A60C(a);
    r4 = b;
    if (b == 1) {
    } else if (b == 2) {
        r5 = 0x13;
    } else if (b == 0) {
        switch (func_0215A654(a)) {
        case 1:
        case 3:
        case 5:
            r4 = r5;
            break;
        case 2:
        case 4:
        case 6:
            r5 = 0x13;
            r4 = 2;
            break;
        case 7:
            r5 = 0x13;
            r4 = 2;
            break;
        default:
            r5 = 0x13;
            r4 = 2;
            break;
        }
    } else {
        r5 = 0x13;
        r4 = 2;
    }
    r5 = func_02190FA0(*p, x, r5);
    func_0215A660(a, r4);
    func_0215A614(a, r5);
    func_02159144(1);
}
