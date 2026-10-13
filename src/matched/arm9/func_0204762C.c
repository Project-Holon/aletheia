/*
 * function: G3D_SYSTEM_DeleteAnime
 * address:  0x0204762C
 * packet:   pkt_02047564
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem      0x02146A5C  data
 *   NNS_G3dFreeAnmObj   0x0206E388  arm
 *   func_020307B0   0x020307B0  arm
 *
 * The sibling of G3D_SYSTEM_DeleteRender for the other record tag: 0x59D1 instead of
 * 0x7A14 and NNS_G3dFreeAnmObj instead of NNS_G3dFreeRenderObj.  Everything else,
 * including the register allocation and the reuse of the pooled tag for the
 * decrement, is identical.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_DeleteAnime.c \
 *       --func G3D_SYSTEM_DeleteAnime --addr 0x0204762C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 tag;
    u16 unk_02;
    u32 unk_04;
};

extern u32 _G3dSystem;
struct Obj02061330;
extern void NNS_G3dFreeAnmObj(struct Obj02061330 *ctx, int field);
extern u32 func_020307B0(void *p);

void G3D_SYSTEM_DeleteAnime(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x59D1)
        return;

    NNS_G3dFreeAnmObj((struct Obj02061330 *)_G3dSystem, p->unk_04);
    p->tag = 0x59D1 - 1;
    func_020307B0(p);
}
