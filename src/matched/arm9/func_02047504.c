/*
 * function: G3D_SYSTEM_DeleteRender
 * address:  0x02047504
 * packet:   pkt_02047400
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem      0x02146A5C  data
 *   NNS_G3dFreeRenderObj   0x0206E358  arm
 *   func_020307B0   0x020307B0  arm
 *
 * Release one tagged record: nothing at all for a null pointer, and nothing
 * for a record whose halfword tag at +0 is not 0x7A14.  Otherwise hand the
 * pointer's +4 field to NNS_G3dFreeRenderObj, drop the tag to one below its own
 * value and free the record.
 *
 * The tag is pooled once (0x7A14 is past a `mov` immediate) and reused for
 * the decrement, which is why the new value arrives as `sub r1, r4, #1`
 * rather than as a second literal; the `mov r0, r5` before the store is the
 * free call's argument being set up early.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_DeleteRender.c \
 *       --func G3D_SYSTEM_DeleteRender --addr 0x02047504 --cc 1.1p1 --arm
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
extern void NNS_G3dFreeRenderObj(struct Obj02061330 *ctx, int field);
extern u32 func_020307B0(void *p);

void G3D_SYSTEM_DeleteRender(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x7A14)
        return;

    NNS_G3dFreeRenderObj((struct Obj02061330 *)_G3dSystem, p->unk_04);
    p->tag = 0x7A14 - 1;
    func_020307B0(p);
}
