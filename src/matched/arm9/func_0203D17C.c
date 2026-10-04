/*
 * function: func_0203D17C
 * address:  0x0203D17C
 * packet:   pkt_0203D12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *
 * Vtable dispatch with the *vtable pointer* null-checked (the state object
 * itself is not): the entry at +0xC4 takes the argument, and the hook's value
 * is dropped.  Two loads separate the two tests, which is what makes this
 * shape distinct from src/matched/func_0203CF10.c and
 * src/matched/func_0203CF3C.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D17C.c \
 *       --func func_0203D17C --addr 0x0203D17C --cc 1.1p1 --arm
 */
#include "../include/Obj15981.h"
#include "../include/Obj15982.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef void (*Fn)(u32);

extern void *func_0203D788(void);

void func_0203D17C(u32 a)
{
    u8  *p;
    u32 *vt;
    Fn   f;

    p = func_0203D788();
    vt = *(u32 * *)&((struct Obj15981 *)p)->f340;
    if (vt == 0)
        return;
    f = *(Fn *)&((struct Obj15982 *)vt)->fC4;
    f(a);
}
