/*
 * function: func_02185410
 * address:  0x02185410
 * packet:   pkt_ov020_02185410
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02162694  0x02162694  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02184410  0x02184410  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
int func_02162694(int a0, int a1, int a2);
u8 func_021626E8(u8 *p);
int func_02184410(int a, int *state, u8 *p);
void func_02184CEC(void **o, void *p);

void *func_02185410(void *p, int u, int a, int b)
{
    void *r0v;
    char *r4;

    func_020120F4(p);
    r0v = func_020122C0(p, 0, func_02184410, 0x9c);
    r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    ((struct Obj00248 *)r4)->f40 = 1;
    func_02162694(a, (int)(r4 + 0x10), b);
    ((struct Obj00248 *)r4)->f2C = func_021626E8((u8 *)a);
    return r0v;
}
