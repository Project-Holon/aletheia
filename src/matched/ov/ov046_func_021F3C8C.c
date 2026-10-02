/*
 * function: func_021F3C8C
 * address:  0x021F3C8C
 * packet:   pkt_ov046_021F3C8C
 * region:   ov046
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

extern void *func_020124E4(void *);
extern void *func_0201210C(void *p);
extern int func_02188D2C(int *);
extern Q *func_021897BC(char *, int);
extern u32 func_02188C80(unsigned char *);
extern void *func_020120F4(const void *);
extern void *func_02012EC4(void *);
extern int *func_0200B3A4(void *, int);
extern void *func_020122C0(void *, int, void (*)(void), int);
extern void func_02012374(void *, void *);
extern void func_021F3DE8(void);

int func_021F3C8C(u32 a, int *b)
{
    void *h = func_020124E4((void *)a);
    void *x = func_0201210C(h);
    Q *q;
    int r;

    func_02188D2C(x);
    r = 1;
    q = func_021897BC(x, 1);
    func_0200B3A4(func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        if ((q->a8 + q->a4)[1] != 0)
            r = 0;
        q->c = (q->a4 == 0 ? 1 : 2) + q->a0 * 5;
        q->d = 1;
        q->p18 = r;
        q->e = 2;
        q->p1c = 0x6fc;
        q->p20 = 0x6fd;
        func_02012374((void *)a, func_020122C0(h, 0, func_021F3DE8, 0));
        (q->a8 + q->a4)[1] = r;
        (*b)++;
        break;
    case 1:
        return r;
    }
    return 0;
}
