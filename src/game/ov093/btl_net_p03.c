/*
 * file:     btl_net_p03.c
 * unit:     yes
 * function: func_021D43B8, func_021D43E0
 * address:  0x021D43B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3B88     0x021F3B88  data  ov093
 *   func_0203D3F8  0x0203D3F8  arm
 */
#include "../../matched/include/Obj12141.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S {
    u32 f00;
};

typedef struct {
    int w[8];
} S32;

extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_021D43B8(u32 a);
void func_021D43E0(int unused0, int unused1, S32 *src);
extern struct S *d_021F3B88;


u32 func_021D43B8(u32 a)
{
    return func_0203D3F8(d_021F3B88->f00, 0xff, 0x101, 0x20, a, 0, 0, 0);
}


/*
 * Unlabelled leaf (no lr prologue, hidden in the pool run after
 * func_021D43B8).  Copies a 32-byte aggregate into the object at
 * d_021F3B88+0x18 once, gated on byte +0xa.
 */
void func_021D43E0(int unused0, int unused1, S32 *src)
{
    char *p = (char *)d_021F3B88;

    if (((struct Obj12141 *)p)->fA == 0) {
        *(S32 *)(p + 0x18) = *src;
        ((struct Obj12141 *)p)->fA = 1;
    }
}
