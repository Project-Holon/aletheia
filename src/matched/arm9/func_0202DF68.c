/*
 * unit:     no
 * function: PMS_DRAW_LoadResources
 * address:  0x0202DF68
 * packet:   pkt_0202DF68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the four handles of the pms_draw sub-object at +0x10 of its
 * owner: the three VRAM-bank queries of unit_0202DE9C are taken first
 * (off the engine word at +4), a 0x2b resource set is opened on the
 * caller's heap, and ENV_SetResourceSet / CLACT_RegisterCharacter / CLACT_RegisterCellAnim
 * fill +8, +0xc and +0x10 before the set is closed again.
 *
 * The screen-size argument to ENV_SetResourceSet is `(u16)(a1 << 5)`, the
 * unequal shift pair lsls #0x15 / lsrs #0x10 -- a narrowing cast folded
 * with the shift, not an 11-bit bitfield.
 *
 * symbols:
 *   sub_0202DE9C       0x0202DE9C  thumb
 *   sub_0202DEE0       0x0202DEE0  thumb
 *   sub_0202DF24       0x0202DF24  thumb
 *   func_020490F4      0x020490F4  arm
 *   ENV_SetResourceSet 0x0204AC18  arm
 *   CLACT_RegisterCharacter      0x0204A6C8  arm
 *   CLACT_RegisterCellAnim      0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle      0x02049238  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   sub_0202DE9C(u32 engine);
extern u32   sub_0202DEE0(u32 engine);
extern u32   sub_0202DF24(u32 engine);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32   ENV_SetResourceSet(void *h, u32 a1, u32 engine, u16 a3,
                                u32 s0, u32 s1, u32 s2);
extern u32   CLACT_RegisterCharacter(void *h, u32 a1, u32 a2, u32 engine, u32 s0);
typedef signed int     s32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void  ARC_TOOL_DeleteHandle(void *h);

void PMS_DRAW_LoadResources(u32 *o, u32 a1, u32 heap)
{
    u32 b0;
    u32 b1;
    u32 b2;
    void *h;

    b0 = sub_0202DE9C(o[1]);
    b1 = sub_0202DEE0(o[1]);
    b2 = sub_0202DF24(o[1]);
    h = func_020490F4(0x2b, heap);
    o[2] = ENV_SetResourceSet(h, 1, o[1], (u16)(a1 << 5), 0, 5, heap);
    o[3] = CLACT_RegisterCharacter(h, b2, 0, o[1], heap);
    o[4] = CLACT_RegisterCellAnim(h, b0, b1, heap);
    ARC_TOOL_DeleteHandle(h);
}
