/*
 * function: func_021F3EFC
 * address:  0x021F3EFC
 * packet:   pkt_ov046_021F3EFC
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov046 token is dropped from d_021F4130 (contested hint).
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
 *   func_020061E4  0x020061E4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   d_021F4130  0x021F4130  data  a4
 */

typedef unsigned int u32;
typedef unsigned char u8;
extern void *func_020124E4(u32);
extern u32 func_0201210C(void *);
extern u32 func_02188D2C(u32);
extern int *func_021897BC(u32, int);
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EC4(u32);
extern int func_0200B3A4(u32, u32);
extern void func_020061E4(int);
extern u32 func_02188CB4(u32);
extern void func_021A3038(u32, int *);
extern void func_021A3044(u32, int *);
extern int d_021F4130[];

int func_021F3EFC(u32 a, int *b)
{
    u32 x;
    int *w;
    int r = 1;
    u32 c;
    int v[3];

    x = func_0201210C(func_020124E4(a));
    func_02188D2C(x);
    w = func_021897BC(x, 1) + 3;
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        func_020061E4(0x55e);
        (*b)++;
        break;
    case 1:
        c = func_02188CB4(x);
        func_021A3038(c, v);
        v[0] = v[0] + w[1];
        v[1] = w[2] + (d_021F4130[((u8 *)w)[3]] << 12);
        func_021A3044(c, v);
        ((u8 *)w)[3] = ((u8 *)w)[3] + 1;
        if (((u8 *)w)[3] >= 8) {
            func_020061E4(0x6d3);
            return r;
        }
        break;
    }
    return 0;
}
