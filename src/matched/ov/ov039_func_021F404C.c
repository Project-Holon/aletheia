/*
 * function: func_021F404C
 * address:  0x021F404C
 * packet:   pkt_ov039_021F404C
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     func_021BE674's third parameter is u8 here (the caller truncates
 *           the int local before the bl); the 0x02188D2C result bound to a
 *           named local keeps `k` computed before that call.
 *
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021897BC 0x021897BC thumb
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3050 0x021A3050 thumb ov021
 *   func_021A3038 0x021A3038 thumb ov021
 *   func_021F36C0 0x021F36C0 thumb ov039
 *   func_021F3DB8 0x021F3DB8 thumb ov039
 *   func_021F3DAC 0x021F3DAC thumb ov039
 *   func_021F3D98 0x021F3D98 thumb ov039
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021F4158 0x021F4158 thumb ov039
 *   func_020122C0 0x020122C0 thumb
 *   func_021F4610 0x021F4610 thumb ov039
 *   func_021F41A8 0x021F41A8 thumb ov039
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

extern void *func_0201210C(void);
extern u32 func_02188C80(void *p);
extern unsigned int func_020120F4(unsigned int);
extern unsigned int func_02012EC4(unsigned int);
extern void *func_0200B3A4(unsigned int, unsigned int);
extern u8 *func_021897BC(void *p, int idx);
extern u32 func_02188CB4(void *p);
extern int func_021A3050(u32 a);
extern void func_021A3038(u32 a, Vec *v);
extern u8 func_021F36C0(int x, int z);
extern int func_021F3DB8(u8 *s, int n);
extern u8 func_021F3DAC(int n);
extern u8 func_021F3D98(u8 *s, int n);
extern int func_02188D2C(void *p);
extern void *func_021BE674(char *base, int i, u8 j, u16 k);
extern int func_021BE6B0(void *s, int b);
extern int func_021F4158(void *p, int c);
extern int func_020122C0(void *owner, int a, void (*fn)(void), int size);
extern void func_021F4610(void);
extern void func_021F41A8(void);

int func_021F404C(void *a0)
{
    void *sys;
    void *p;
    u8 *s;
    u32 x;
    Vec v;
    u8 n;
    int c;
    u8 k;
    int h;

    sys = func_0201210C();
    p = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(sys))), 2);
    s = func_021897BC(sys, 1);
    x = func_02188CB4(sys);
    if (func_021A3050(x)) {
        return 0;
    }
    func_021A3038(x, &v);
    n = func_021F36C0(v.x / 0x10000, v.z / 0x10000);
    if (n == 0xff) {
        return 0;
    }
    if (func_021F3DB8(s, n)) {
        c = func_021F3DAC(n);
        s[4] = func_021F3D98(s, n);
        k = s[4] + 1;
        h = func_02188D2C(sys);
        func_021BE6B0(func_021BE674((char *)h, 0, c, k), 1);
        s[7] = c;
        if (func_021F4158(p, c)) {
            return func_020122C0(a0, 0, func_021F4610, 0);
        }
        return func_020122C0(a0, 0, func_021F41A8, 0);
    }
    return 0;
}
