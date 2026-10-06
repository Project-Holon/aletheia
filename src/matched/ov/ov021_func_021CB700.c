/*
 * function: func_021CB700
 * address:  0x021CB700
 * packet:   pkt_ov021_021CB700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED8  0x02012ED8  thumb
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02167B34  0x02167B34  thumb  ov010
 */
#include "../include/Obj12971.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_02158F54(void *a);
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012ED8(struct Big *p);
extern u16 *func_02158FE0(void *a, void *b, unsigned int id);
extern u32 func_0200FB24(void);
extern int func_02167B34(int a0);

int func_021CB700(u32 unused, u32 a)
{
    void *t;
    u8 *p;
    void *s;
    u16 *q;

    s = func_0215A5F4((void *)a);
    t = func_020120F4(func_02158F54(s));
    p = func_02012ED8(t);
    q = func_02158FE0(s, t, ((struct Obj12971 *)p)->f72A);
    if (func_0200FB24() != 0) {
        *q = 0;
        return 1;
    }
    if (func_02167B34(p[0x727]) == 1) {
        *q = 1;
        return 1;
    }
    return 0;
}
