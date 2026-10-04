/*
 * function: func_02199F94
 * address:  0x02199F94
 * packet:   pkt_ov021_02199F94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0219FCC0  0x0219FCC0  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D7CC  0x0216D7CC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_0216D6D4(void *p);
extern int func_0219FCC0(u32, u16 *, u16 *);
extern u16 func_0216D598(void *p);
extern void func_020061E4(u32);
extern void func_0216D7CC(u32);

int func_02199F94(u32 a)
{
    u16 *p;
    u16 v[2];
    p = func_0216D6D4((void *)a);
    if (func_0219FCC0(a, &v[1], &v[0]) != 1)
        return 0;
    p[0] = p[0] + 1;
    v[0] = v[0] - 1;
    if (func_0216D598((void *)a) == 0xDD && v[1] == 0 && *((u8 *)p + 2) != v[0]) {
        *((u8 *)p + 2) = v[0];
        switch (v[0]) {
        case 0:
            func_020061E4(0x7E5);
            break;
        case 3:
            func_020061E4(0x7E6);
            break;
        }
    }
    if (p[0] < 0x5F)
        return 0;
    func_0216D7CC(a);
    return 1;
}
