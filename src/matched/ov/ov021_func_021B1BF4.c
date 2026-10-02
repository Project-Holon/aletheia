/*
 * function: func_021B1BF4
 * address:  0x021B1BF4
 * packet:   pkt_ov021_021B1BF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021B1E74  0x021B1E74  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern u32 func_021B1E74(u32);
extern u32 func_0216D5F8(u32);
extern u32 func_021642A4(u32);
extern u32 func_02158F90(void *);
extern void func_0216D5E0(u32, u32);
extern void func_0216D674(u32, u32);

int func_021B1BF4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    u32 v = func_021642A4(func_0216D5F8(func_021B1E74(b)));
    u32 o = func_02158F90(s);

    if (o != 0) {
        func_0216D5E0(o, v);
        func_0216D674(o, 0);
    }
    return 0;
}
