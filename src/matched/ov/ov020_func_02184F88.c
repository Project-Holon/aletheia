/*
 * function: func_02184F88
 * address:  0x02184F88
 * packet:   pkt_02184F88
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator + base init, copies a seven-word record fetched through the node's
 * fourth word, then fills status fields.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02184A14  0x02184A14  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct BigObj;
struct Rec1C;
struct Rec1C *func_02012894(const struct BigObj *p);
int func_02184A14(int ctx, int *state, u8 *p);
void func_02184CEC(void *obj, void *p);

void *func_02184F88(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184A14, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC(r4, p);
    src = (S7 *)func_02012894((const struct BigObj *)(*(int *)&((struct Obj00248 *)r4)->f4));
    *(S7 *)(r4 + 0x10) = *src;
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f18 = 2;
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}
