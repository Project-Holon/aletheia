/*
 * function: func_021933C0
 * address:  0x021933C0
 * packet:   pkt_ov021_021933C0
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
#include "../include/Obj04211.h"
#include "../include/Obj09478.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct S;
extern int func_02169520(int a0, int a1);
extern void func_0216959C(u8 *p);
extern void func_02169530(unsigned char *a, int *out);
extern void func_021695BC(struct S *p, int b);
extern int func_02169620(struct S *p);
extern void func_02169528(unsigned char *a, int *out);
extern void func_02169540(unsigned char *a, unsigned int v);
extern void func_02169580(int o);
extern int func_02169560(unsigned char *a);
extern int func_02169578(unsigned char *a);
extern int func_02169598(int o);
extern int func_0218DD04(u8 *p);
extern void func_0218B974(int a, int o, void *p, int n);
extern int func_0218DCF4(int q);
extern int func_0218DCFC(int q);
typedef unsigned int   u32;
extern int func_021A7410(u32 a, u32 b, u32 c, u32 d);

int func_021933C0(int o, int q)
{
    u16 *st;
    int x;
    char *h;
    char *p;
    int off;

    func_02169520(o, (int)(&st));
    switch (*st) {
    case 1:
        func_0216959C((u8 *)o);
        func_02169530((unsigned char *)o, &x);
        func_021695BC((struct S *)o, x);
        *st = 2;
        break;
    case 2:
        if (func_02169620((struct S *)o) != 0)
            break;
        ((struct Obj04211 *)st)->f18 = 1;
        ((struct Obj04211 *)st)->f1C = 1;
        ((struct Obj04211 *)st)->f20 = 1;
        *st = 3;
    case 3:
        func_02169528((unsigned char *)o, (int *)(&h));
        p = h;
        func_02169540((unsigned char *)o, (unsigned int)(p + ((struct Obj09478 *)p)->f4));
        off = ((struct Obj09478 *)p)->f10;
        if (off != ((struct Obj09478 *)p)->f14)
            func_0218B974(func_0218DD04((u8 *)q), o, h + off + 4, *(int *)(h + off));
        func_02169580(o);
        if (func_0218DCF4(q))
            func_021A7410(func_0218DCFC(q), func_02169560((unsigned char *)o), func_02169578((unsigned char *)o), func_02169598(o));
        *st = 0;
        return 0;
    }
    return 1;
}
