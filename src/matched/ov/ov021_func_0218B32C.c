/*
 * function: func_0218B32C
 * address:  0x0218B32C
 * packet:   pkt_ov021_0218B32C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3098  0x021A3098  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb
 *   func_021ACBB8  0x021ACBB8  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_021A2F60  0x021A2F60  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021A2FD0  0x021A2FD0  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021A35A0  0x021A35A0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05974.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3098(u8 *p);
extern void *func_021A3074(u8 *p);
extern void *func_0216D67C(void *o);
extern void func_0216D9A0(void *o);
extern void func_0216D5E0(int a0, int a1);
extern void *func_021A2F98(void *a);
extern void func_021ACBB8(u32 a, u8 v);
extern void func_021A2F48(u8 *p, u32 a1);
extern void func_021A2F60(int *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, int a);
extern int func_0216D454(void *o);
extern int func_021A2FD0(void *a);
extern void func_0216D9E4(void *o);
extern void func_021A35A0(u32 *p, int a);

int func_0218B32C(void *unused, int *st, char *ctx)
{
    void *a = func_02188CB4(((struct Obj05974 *)ctx)->fC);
    void *o;
    int r1;

    func_021A3098(a);
    o = func_021A3074(a);
    switch (*st) {
    case 0:
        func_0216D9A0(func_0216D67C(o));
        func_0216D5E0((int)o, ((struct Obj05974 *)ctx)->f4);
        *st = *st + 1;
        break;
    case 1:
        func_021ACBB8((u32)func_021A2F98(a), 0);
        func_021A2F48(a, 1);
        func_021A2F60(a);
        r1 = func_02197E7C(((struct Obj05974 *)ctx)->f4, 0x34);
        if (((struct Obj05974 *)ctx)->f6 == 1)
            r1 = func_02197E7C(((struct Obj05974 *)ctx)->f4, 0x38);
        func_0216D410(o, r1);
        *st = *st + 1;
        break;
    case 2:
        if (func_0216D454(o) == 1) {
            func_021A2FD0(a);
            *st = *st + 1;
        }
        break;
    case 3:
        func_0216D9E4(func_0216D67C(o));
        func_021A35A0(a, 1);
        return 1;
    }
    return 0;
}
