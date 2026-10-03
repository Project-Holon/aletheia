/*
 * function: func_021C46F8
 * address:  0x021C46F8
 * packet:   pkt_ov021_021C46F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   abs_id_3f      0x0000003F  data
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A305C  0x021A305C  thumb  ov021
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   func_021C4788  0x021C4788  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_020122C0(u32 a, u32 b, void (*fn)(void), u32 size);
extern u32 *func_020124E8(u32 t);
extern int func_02034AC4(int a);
extern unsigned char abs_id_3f[];
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern void func_021A305C(char *p, u32 b);
extern u32 func_021F36C0(u32 a, u32 b, void *c, u32 d);
extern void func_021C4788(void);

u32 func_021C46F8(u32 a, u32 b, u32 c)
{
    u32 t = func_020122C0(a, 0, func_021C4788, 4);
    u32 *w = func_020124E8(t);
    void *x;
    void *y;

    func_02034AC4((int)abs_id_3f);
    x = func_02188CB4((void *)b);
    y = func_021A3074((void *)x);
    func_021A305C(x, c);
    *w = func_021F36C0(a, b, y, 1);
    return t;
}
