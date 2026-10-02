/*
 * function: func_021F3DE8
 * address:  0x021F3DE8
 * packet:   pkt_ov046_021F3DE8
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006210  0x02006210  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern void *func_020124E4(void *p);
extern void *func_0201210C(void *p);
extern int func_02188D2C(int *a);
extern u8 *func_021897BC(char *a, int b);
extern u32 func_02188C80(unsigned char *a);
extern void *func_020120F4(const void *a);
extern void *func_02012EC4(void *a);
extern u8 *func_0200B3A4(void *a, int b);
extern void func_021BE700(u32 a, int b, u16 c, u8 d, int e);
extern u8 *func_021BE674(u32 a, int b, u16 c, u16 d);
extern void func_021BE6B0(u8 *p, int v);
extern int func_021BE6BC(u8 *p);
extern void func_021BE6CC(u32 a, int b, u16 c, u16 d, int e);
extern void func_020061E4(int a);
extern void func_02006210(void);

int func_021F3DE8(void *a, int *st)
{
    void *s;
    u32 t;
    u8 *w;
    u8 k;
    int i;
    u8 v;

    s = func_0201210C(func_020124E4(a));
    t = func_02188D2C(s);
    w = func_021897BC(s, 1) + 0xc;
    func_0200B3A4(func_02012EC4(func_020120F4((void *)func_02188C80(s))), 10);
    switch (*st) {
    case 0:
        k = w[0];
        for (i = 0; i < w[2]; i++) {
            func_021BE6B0(func_021BE674(t, 0, k, i), 1);
            func_021BE700(t, 0, k, i, 0);
        }
        for (i = 0; i < w[1]; i++) {
            v = *(int *)(w + 0xc + i * 4);
            func_021BE6B0(func_021BE674(t, 0, k, v), 0);
            func_021BE700(t, 0, k, v, 1);
            func_021BE6CC(t, 0, k, v, 0);
            func_020061E4(*(int *)(w + 0x10));
        }
        (*st)++;
        break;
    case 1:
        if (func_021BE6BC(func_021BE674(t, 0, w[0], *(int *)(w + 0xc)))) {
            func_02006210();
            if (*(int *)(w + 0x14) != -1)
                func_020061E4(*(int *)(w + 0x14));
            return 1;
        }
        break;
    }
    return 0;
}
