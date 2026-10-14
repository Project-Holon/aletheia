/*
 * function: MAILVIEW_LoadGraphics
 * address: 0x021C4EEC
 * packet: pkt_ov136_021C4EEC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): byte-correct; only the ABS32 word for MAILSYS_OnKeyModeNoOp (an unlabelled
 *   ov136 leaf "return 0", not in any lane) lacks a witness. File that leaf, then re-verify.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   func_0201F548 0x0201F548 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   MAILSYS_OnKeyModeNoOp 0x021C4534 thumb ov136
 *   MAILSYS_OnTouchMode 0x021C4528 thumb ov136
 */
#include "../include/Obj00540.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern u8 func_0201F548(int i);
extern void GF_FONT_SetDefaultTextColor(void);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_02041300(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);
extern void func_02041B6C(u32 layer);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern int MAILSYS_OnKeyModeNoOp(void);
extern int MAILSYS_OnTouchMode(void *a);

void MAILVIEW_LoadGraphics(u8 *p)
{
    u32 k = (*(u8 **)(p + 0x1C))[0xB];
    void *h = func_020490F4(0x9B, (u16)((struct Obj00540 *)p)->f0);
    u32 sz;
    u32 pal;
    u32 chr;

    func_0201F5BC(0, 1, 4, 0, (u16)((struct Obj00540 *)p)->f0);
    func_0201F5BC(0, 0xD, 6, 0, (u16)((struct Obj00540 *)p)->f0);
    pal = k + 0xC;
    func_02049658(h, pal, 3, 0, 0, 1, (u16)((struct Obj00540 *)p)->f0);
    func_02049658(h, pal, 4, 0, 0, 1, (u16)((struct Obj00540 *)p)->f0);
    chr = k + 0x18;
    sz = 0x800;
    func_020498F4(h, chr, 3, 0, sz, 1, (u16)((struct Obj00540 *)p)->f0);
    func_020498F4(h, chr, 4, 0, sz, 1, (u16)((struct Obj00540 *)p)->f0);
    func_02049B68(h, k, 4, 0, 0, (u16)((struct Obj00540 *)p)->f0);
    func_02049B40(0x17, 5, 0, 0xA0, 0x20, (u16)((struct Obj00540 *)p)->f0);
    ((struct Obj00540 *)p)->f38 = (u32)PALANM_Create(((struct Obj00540 *)p)->f0);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 0, 0xE0, (u16)((struct Obj00540 *)p)->f0);
    PALANM_LoadHandlePaletteToSlot((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), h, k, (u16)((struct Obj00540 *)p)->f0, 0, 0x60, 0);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 0x17, 7, (u16)((struct Obj00540 *)p)->f0, 0, 0x20, 0x30);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 0x17, 5, (u16)((struct Obj00540 *)p)->f0, 0, 0x20, 0x50);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 5, func_0201F548(0), (u16)((struct Obj00540 *)p)->f0, 0, 0x20, 0x40);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 5, func_0201F548(1), (u16)((struct Obj00540 *)p)->f0, 0, 0x20, 0x60);
    GF_FONT_SetDefaultTextColor();
    ARC_TOOL_DeleteHandle(h);
    func_02041300(4, 0x2001, 0, 0, 0x20, 0x20, 0x11);
    func_02041B6C(4);
    BG_SYS_SetMainPlaneVisible(1, 1);
    BG_SYS_SetMainPlaneVisible(2, 1);
    BG_SYS_SetMainPlaneVisible(8, 1);
    if (p[0xB] != 0) {
        h = func_020490F4(0x9B, (u16)((struct Obj00540 *)p)->f0);
        func_020498F4(h, 0x24, 2, 0, sz, 1, (u16)((struct Obj00540 *)p)->f0);
        ARC_TOOL_DeleteHandle(h);
        ((struct Obj00540 *)p)->f3C = (void *)MAILSYS_OnKeyModeNoOp;
        ((struct Obj00540 *)p)->f40 = (void *)MAILSYS_OnTouchMode;
        BG_SYS_SetMainPlaneVisible(4, 1);
    }
}
