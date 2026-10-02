/*
 * function: func_021F381C
 * address:  0x021F381C
 * packet:   pkt_ov040_021F381C
 * region:   ov040
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
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern void *func_020124E4(void *p);
extern u32 func_0201210C(void *p);
extern u32 func_02188D2C(u32 a);
extern u16 *func_021897BC(u32 a, int b);
extern u32 func_02188C80(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
extern u8 *func_0200B3A4(u32 a, u32 b);
extern void func_021BE700(u32 a, int b, u16 c, u16 d, int e);
extern u8 *func_021BE674(u32 a, int b, u16 c, u16 d);
extern void func_021BE6B0(u8 *p, int v);
extern int func_021BE6BC(u8 *p);
extern void func_021BE6CC(u32 a, int b, u16 c, u16 d, int e);

int func_021F381C(void *a, int *st)
{
    u32 s;
    u32 t;
    u16 *p;
    u8 *q;
    u8 *e;
    u8 x;
    int z;

    s = func_0201210C(func_020124E4(a));
    t = func_02188D2C(s);
    p = func_021897BC(s, 1);
    q = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(s))), 3);
    switch (*st) {
    case 0:
        x = *p;
        z = 0;
        func_021BE700(t, 0, x, 0, 1);
        func_021BE6B0(func_021BE674(t, 0, x, 0), 0);
        func_021BE6CC(t, 0, x, 0, z);
        (*st)++;
        break;
    case 1:
        e = func_021BE674(t, 0, (u8)*p, 0);
        if (func_021BE6BC(e) && func_021BE6BC(e)) {
            (q + *p)[4] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
