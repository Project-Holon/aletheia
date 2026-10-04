/*
 * function: func_0215EFCC
 * address: 0x0215EFCC
 * packet: pkt_ov010_0215EFCC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_0215EF60 0x0215EF60 thumb ov010
 */
#include "../include/Obj02057.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct C;
struct Desc;
struct Obj;
struct Pair;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215F0E8(u32 *out, const struct Pair *in, u32 *ctx);
extern int func_0215EF60(void *a, int *st, struct C *c);
void *func_0215EFCC(void *p, void *ctx)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EF60, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}
