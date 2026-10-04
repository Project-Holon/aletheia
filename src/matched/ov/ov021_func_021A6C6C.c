/*
 * function: func_021A6C6C
 * address:  0x021A6C6C
 * packet:   pkt_ov021_021A6C6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_02162598  0x02162598  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01119.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern void *func_02188C80(void *p);
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern int func_0219E664(void *o, u32 k, void *buf);
struct Q;
extern int func_02162598(char *p, struct Q *q);

int func_021A6C6C(u8 *p, u32 k)
{
    u32 buf[2];
    void *o = func_021A3960(*(unsigned char * *)&((struct Obj01119 *)p)->f14);
    u32 r4;

    r4 = func_02012844(func_020120F4(func_02188C80(*(u8 * *)&((struct Obj01119 *)p)->f18)));
    func_0219E664(o, k, buf);
    return func_02162598((char *)r4, (struct Q *)buf) != 0xFFFF;
}
