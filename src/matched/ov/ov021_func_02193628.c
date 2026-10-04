/*
 * function: func_02193628
 * address:  0x02193628
 * packet:   pkt_ov021_02193628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02169520  0x02169520  thumb ov010
 *   func_0216959C  0x0216959C  thumb ov010
 *   func_02169530  0x02169530  thumb ov010
 *   func_021695BC  0x021695BC  thumb ov010
 *   func_02169620  0x02169620  thumb ov010
 *   func_02169528  0x02169528  thumb ov010
 *   func_02169540  0x02169540  thumb ov010
 *   func_02169580  0x02169580  thumb ov010
 *   func_02169560  0x02169560  thumb ov010
 *   func_02169578  0x02169578  thumb ov010
 *   func_02169598  0x02169598  thumb ov010
 *   func_0218DD04  0x0218DD04  thumb ov021
 *   func_0218DD08  0x0218DD08  thumb ov021
 *   func_0218DD0C  0x0218DD0C  thumb ov021
 *   func_0218DD10  0x0218DD10  thumb ov021
 *   func_0218B974  0x0218B974  thumb ov021
 *   func_0218DCF4  0x0218DCF4  thumb ov021
 *   func_0218DCFC  0x0218DCFC  thumb ov021
 *   func_02193924  0x02193924  thumb ov021
 *   func_021A7410  0x021A7410  thumb ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct S;
extern int func_02169520(int a0, int a1);
extern void func_0216959C(int o);
extern void func_02169530(unsigned char *a, int *out);
extern void func_021695BC(int o, int v);
extern int func_02169620(struct S *p);
extern void func_02169528(unsigned char *a, int *out);
extern void func_02169540(unsigned char *a, unsigned int v);
extern void func_02169580(int o);
extern int func_02169560(unsigned char *a);
extern int func_02169578(unsigned char *a);
extern int func_02169598(int o);
extern int func_0218DD04(int q);
extern int func_0218DD08(int q);
extern int func_0218DD0C(int q);
extern u16 func_0218DD10(u8 *p);
extern int func_0218B974(int a, int o, void *p, int n);
extern int func_02193924(int a, void *p, int b, int o, int prev, int x, int y, u16 c);
extern int func_0218DCF4(int q);
extern int func_0218DCFC(int q);
typedef unsigned int   u32;
extern int func_021A7410(u32 a, u32 b, u32 c, u32 d);

int func_02193628(int o, int q)
{
    u16 *st;
    int x;
    char *h;
    int boff;
    char *base;
    int j;
    int y0;
    int g;
    int id;
    u16 c;
    char *p;
    int off;
    int r;
    int n;
    int i;
    int x0;

    func_0218DD10((u8 *)q);
    func_02169520(o, (int)(&st));
    switch (*st) {
    case 1:
        func_0216959C(o);
        func_02169530((unsigned char *)o, &x);
        func_021695BC(o, x);
        *st = 2;
        break;
    case 2:
        if (func_02169620((struct S *)o) != 0)
            break;
        *(int *)((char *)st + 0x18) = 1;
        *(int *)((char *)st + 0x1c) = 1;
        *(int *)((char *)st + 0x20) = 1;
        *st = 3;
        break;
    case 3:
        func_02169528((unsigned char *)o, (int *)(&h));
        p = h;
        func_02169540((unsigned char *)o, (unsigned int)(p + *(int *)(p + 4)));
        off = *(int *)(p + 0xC);
        if (off != *(int *)(p + 0x10))
            r = func_0218B974(func_0218DD04(q), o, h + off + 4, *(int *)(h + off));
        g = func_0218DD04(q);
        base = h;
        boff = *(int *)(p + 8);
        n = func_0218DD0C(q);
        id = func_0218DD08(q);
        c = func_0218DD10((u8 *)q);
        x0 = (n % 2) * 4;
        y0 = (n / 2) * 4;
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++) {
                r = func_02193924(id, base + boff, g, o, r, x0 + i, y0 + j, c);
            }
        }
        func_02169580(o);
        if (func_0218DCF4(q))
            func_021A7410(func_0218DCFC(q), func_02169560((unsigned char *)o), func_02169578((unsigned char *)o), func_02169598(o));
        *st = 4;
        break;
    case 4:
        *st = 0;
        return 0;
    }
    return 1;
}
