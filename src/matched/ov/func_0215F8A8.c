/*
 * function: func_0215F8A8
 * address:  0x0215F8A8
 * packet:   pkt_0215F8A8
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, three sub-init calls over the new node.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0215E580  0x0215E580  thumb  ov010
 *   func_0215F734  0x0215F734  thumb  ov010
 *   func_0215F900  0x0215F900  thumb  ov010
 *   func_0215F920  0x0215F920  thumb  ov010
 *   func_0215F948  0x0215F948  thumb  ov010
 */
#include "../include/Obj04132.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Ctx;
void *func_020120F4(const struct Ctx *p);
u8 *func_02012944(void *p);
void func_0215E580(void *a);
struct Work;
int func_0215F734(void *evt, u32 *i, struct Work *w);
void func_0215F900(void *obj);
int func_0215F920(int a0);
void func_0215F948(u8 *p);

void *func_0215F8A8(void *p, int a1)
{
    int r7 = (int)func_020120F4(p);
    void *r0v = func_020122C0(p, 0, func_0215F734, 0x7C);
    char *r4 = func_020124E8(r0v);

    ((struct Obj04132 *)r4)->f0 = (int)p;
    ((struct Obj04132 *)r4)->f4 = r7;
    ((struct Obj04132 *)r4)->f8 = a1;
    ((struct Obj04132 *)r4)->f10 = (int)func_02012944((void *)r7);
    ((struct Obj04132 *)r4)->f78 = 0;
    ((struct Obj04132 *)r4)->f14 = (int)p;
    ((struct Obj04132 *)r4)->f18 = a1;
    func_0215E580((void *)r7);
    func_0215F900(r4);
    func_0215F920((int)r4);
    func_0215F948((u8 *)r4);
    return r0v;
}
