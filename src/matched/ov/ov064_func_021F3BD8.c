/*
 * function: func_021F3BD8
 * address:  0x021F3BD8
 * packet:   pkt_ov064_021F3BD8
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_020124E4(void);
extern int func_0201210C(void);
extern int func_02188D2C(int a);
extern u8 *func_021BE674(int a, int b, int c, u16 d);
extern int func_021BE6BC(u8 *p);

int func_021F3BD8(void)
{
    int s;

    func_020124E4();
    s = func_02188D2C(func_0201210C());
    if (func_021BE6BC(func_021BE674(s, 0, 1, 0)) != 0) {
        return 1;
    }
    return 0;
}
