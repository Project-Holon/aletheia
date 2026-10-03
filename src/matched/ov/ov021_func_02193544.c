/*
 * function: func_02193544
 * address:  0x02193544
 * packet:   pkt_ov021_02193544
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
 *   func_0218B974  0x0218B974  thumb ov021
 *   func_0218DCF4  0x0218DCF4  thumb ov021
 *   func_0218DCFC  0x0218DCFC  thumb ov021
 *   func_021A7410  0x021A7410  thumb ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_02169520(int o, u16 **out);
extern void func_0216959C(int o);
extern void func_02169530(int o, int *out);
extern void func_021695BC(int o, int v);
extern int func_02169620(int o);
extern void func_02169528(int o, char **out);
extern void func_02169540(int o, void *p);
extern void func_02169580(int o);
extern int func_02169560(int o);
extern int func_02169578(int o);
extern int func_02169598(int o);
extern int func_0218DD04(int q);
extern void func_0218B974(int a, int o, void *p, int n);
extern int func_0218DCF4(int q);
extern int func_0218DCFC(int q);
typedef unsigned int   u32;
extern int func_021A7410(u32 a, u32 b, u32 c, u32 d);

int func_02193544(int o, int q)
{
    u16 *st;
    int x;
    char *h;
    char *p;
    int off;

    func_02169520(o, &st);
    switch (*st) {
    case 1:
        func_0216959C(o);
        func_02169530(o, &x);
        func_021695BC(o, x);
        *st = 2;
        break;
    case 2:
        if (func_02169620(o) != 0)
            break;
        *(int *)((char *)st + 0x18) = 1;
        *(int *)((char *)st + 0x1c) = 1;
        *(int *)((char *)st + 0x20) = 1;
        *st = 3;
    case 3:
        func_02169528(o, &h);
        p = h;
        func_02169540(o, p + *(int *)(p + 4));
        off = *(int *)(p + 0x8);
        if (off != *(int *)(p + 0xc))
            func_0218B974(func_0218DD04(q), o, h + off + 4, *(int *)(h + off));
        func_02169580(o);
        if (func_0218DCF4(q))
            func_021A7410(func_0218DCFC(q), func_02169560(o), func_02169578(o), func_02169598(o));
        *st = 0;
        return 0;
    }
    return 1;
}
