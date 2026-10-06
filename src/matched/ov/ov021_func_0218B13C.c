/*
 * function: func_0218B13C
 * address:  0x0218B13C
 * packet:   pkt_ov021_0218B13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_02162598  0x02162598  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626EC  0x021626EC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_0218AECC  0x0218AECC  thumb  ov021
 *   func_0218B2A8  0x0218B2A8  thumb  ov021
 *   func_0218B2E8  0x0218B2E8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04983.h"

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
extern u8 func_021626E8(u8 *p);
extern int func_0218AECC(char *a0, int a1);
extern void func_0218B2A8(char *p, int s, u16 *v);
extern int func_0218B2E8(char *p, void *x, int a, int *b);

int func_0218B13C(char *p, void *unused, void *x, int *alt)
{
    int buf[2];
    int id;
    void *o;

    func_0219E2F4(func_021A3074(func_02188CB4(x)), buf);
    id = func_02162598(((struct Obj04983 *)p)->fC, (struct Q *)buf);
    if (id != 0xFFFF) {
        o = func_021625CC(((struct Obj04983 *)p)->fC, (u16)id);
        if (func_021626EC(o) == 0 && func_0218AECC(o, ((struct Obj04983 *)p)->f24) != 0
            && func_021626E8(o) == 1) {
            func_0218B2A8(p, id, (u16 *)buf);
            return func_0218B2E8(p, x, id, buf);
        }
    }
    id = func_02162598(((struct Obj04983 *)p)->fC, (struct Q *)alt);
    if (id == 0xFFFF)
        return 0;
    o = func_021625CC(((struct Obj04983 *)p)->fC, (u16)id);
    if (func_021626EC(o) == 0 && func_0218AECC(o, ((struct Obj04983 *)p)->f24) != 0) {
        func_0218B2A8(p, id, (u16 *)buf);
        return func_0218B2E8(p, x, id, buf);
    }
    return 0;
}
