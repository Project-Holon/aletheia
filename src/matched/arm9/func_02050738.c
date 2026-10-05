/*
 * function: func_02050738
 * address:  0x02050738
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020473EC   0x020473EC  arm
 *   func_0204F2CC   0x0204F2CC  arm
 *
 * An 88-byte ARM function in the 0x02050000 block.  It reads a record index
 * out of the object at +4, resolves it through func_020473EC, then calls
 * func_0204F2CC with the object's word at +4, the halfword at q[0] and a
 * stack scratch slot; when the hook pointer at p+8 is non-null it calls the
 * hook with the scratch value and the resolved record.  The null case returns
 * the func_0204F2CC result, which is why the `cmp ip, #0` sits after the
 * second call with r0 still live.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050738.c \
 *       --func func_02050738 --addr 0x02050738 --cc 1.1p1 --arm
 */
#include "../include/Obj06992.h"
#include "../include/Obj11453.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020473EC(u32 v);
extern u32 func_0204F2CC(u32 a, u16 b, u32 *out);

u32 func_02050738(void *p, void *q)
{
    u32 v = func_020473EC(((struct Obj06992 *)q)->f4);
    u32 t;
    u32 r = func_0204F2CC(((struct Obj11453 *)p)->f4, ((struct Obj06992 *)q)->f0, &t);
    u32 (*hook)(u32, u32, u32, u32) = *(u32 (**)(u32, u32, u32, u32))((char *)p + 8);

    if (hook == 0)
        return r;
    return hook(1, t, v, 0x20);
}
