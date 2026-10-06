/*
 * function: func_0218B0CC
 * address:  0x0218B0CC
 * packet:   pkt_ov021_0218B0CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls the unlabelled ov010 leaf func_021626EC (filed as pkt_ov010_021626EC).
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_02162598  0x02162598  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626EC  0x021626EC  thumb  ov010
 *   func_0218AEAC  0x0218AEAC  thumb
 *   func_0218B2A8  0x0218B2A8  thumb
 *   func_0218B2E8  0x0218B2E8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04982.h"

typedef unsigned short u16;

typedef unsigned char  u8;
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern void func_0219E2F4(void *o, void *out);
struct Q;
extern int func_02162598(char *p, struct Q *q);
extern void *func_021625CC(char *p, unsigned i);
extern int func_021626EC(u16 *p);
extern int func_0218AEAC(u8 *p);
extern void func_0218B2A8(char *p, int s, u16 *v);
extern int func_0218B2E8(char *p, void *x, int a, int *b);

int func_0218B0CC(char *p, void *unused, void *x)
{
    int buf[2];
    int r4;
    void *r6;

    func_0219E2F4(func_021A3074(func_02188CB4(x)), buf);
    r4 = func_02162598(((struct Obj04982 *)p)->fC, (struct Q *)buf);
    if (r4 == 0xFFFF)
        return 0;
    r6 = func_021625CC(((struct Obj04982 *)p)->fC, (u16)r4);
    if (func_021626EC(r6) == 1 || func_0218AEAC(r6) == 0)
        return 0;
    func_0218B2A8(p, r4, (u16 *)buf);
    return func_0218B2E8(p, x, r4, buf);
}
