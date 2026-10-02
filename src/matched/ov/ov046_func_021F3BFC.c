/*
 * function: func_021F3BFC
 * address:  0x021F3BFC
 * packet:   pkt_ov046_021F3BFC
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 3/4 selector must be a ternary inside the sum with the ternary
 * first: an if-assigned local or `a0 * 5 + (...)` gets other registers.
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
 *   func_020122C0  0x020122C0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021F3DE8  0x021F3DE8  thumb  ov046
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q {
    int a0;
    int a4;
    int *a8;
    u8 c;
    u8 d;
    u8 e;
    u8 pad;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
} Q;

extern u32 func_020124E4(u32);
extern u32 func_0201210C(u32);
extern u32 func_02188D2C(u32);
extern Q *func_021897BC(u32, int);
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EC4(u32);
extern int func_0200B3A4(u32, u32);
extern u32 func_020122C0(u32, int, void (*)(void), int);
extern void func_02012374(u32, u32);
extern void func_021F3DE8(void);

int func_021F3BFC(u32 a, int *b)
{
    u32 h = func_020124E4(a);
    u32 x = func_0201210C(h);
    Q *q;
    int t;
    int i;

    func_02188D2C(x);
    q = func_021897BC(x, 1);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        q->c = (q->a4 == 0 ? 3 : 4) + q->a0 * 5;
        q->d = 1;
        q->p18 = 0;
        q->e = 1;
        q->p1c = 0x6d3;
        q->p20 = -1;
        func_02012374(a, func_020122C0(h, 0, func_021F3DE8, 0));
        (*b)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
