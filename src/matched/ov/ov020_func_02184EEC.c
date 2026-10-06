/*
 * function: func_02184EEC
 * address:  0x02184EEC
 * packet:   pkt_ov020_02184EEC
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020128B8  0x020128B8  thumb
 *   func_02184894  0x02184894  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02185F18  0x02185F18  thumb  ov020
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
struct Rec1C *func_020128B8(const struct BigObj *p);
int func_02184894(void *a, int *state, struct Obj *o);
void func_02184CEC(void **o, void *p);
void func_02185F18(void *a, void *b);

void *func_02184EEC(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184894, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC((void **)r4, p);
    src = (S7 *)func_020128B8(((struct Obj00248 *)r4)->f4);
    *(S7 *)(r4 + 0x10) = *src;
    func_02185F18(((struct Obj00248 *)r4)->f4, r4 + 0x10);
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = 1;
    return r0v;
}
