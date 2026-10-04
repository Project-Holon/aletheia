/*
 * function: func_021BB380
 * address:  0x021BB380
 * packet:   pkt_ov088_021BB380
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds an 8-window bgwinfrm manager at +0x118, initialises each window
 * from a 4-byte table (height from its halfword at +2), then binds the
 * thirteen resources at +0x80..+0xe0 (stride 8) to windows 0,0,0,0,0,0,1..7.
 *
 * symbols:
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_0202CEBC  0x0202CEBC  thumb
 *   d_021BD5EC     0x021BD5EC  data  a4
 */
#include "../include/Obj00014.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u16 f0;
    u16 f2;
};

struct WinMgr;
extern const struct Ent d_021BD5EC[];

extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);

void func_021BB380(char *p)
{
    u32 i;

    ((struct Obj00014 *)p)->f118 = func_0202C9B4(0, 8, 0xb);
    for (i = 0; i < 8; i++)
        func_0202CA3C(((struct Obj00014 *)p)->f118, i, 1, 0x1a, d_021BD5EC[i].f2);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f80);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f88);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f90);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f98);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->fA0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->fA8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 1, ((struct Obj00014 *)p)->fB0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 2, ((struct Obj00014 *)p)->fB8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 3, ((struct Obj00014 *)p)->fC0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 4, ((struct Obj00014 *)p)->fC8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 5, ((struct Obj00014 *)p)->fD0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 6, ((struct Obj00014 *)p)->fD8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 7, ((struct Obj00014 *)p)->fE0);
}
