/*
 * function: MONOLITH_TOOL_LoadGraphics
 * address:  0x021B6644
 * packet:   pkt_ov071_021B6644
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_LoadHandlePaletteToSlotAt  0x02021660  thumb
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   PALANM_LoadHandlePaletteToSlot  0x020216B4  thumb
 *   func_020498F4  0x020498F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020490F4  0x020490F4  arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   func_02027634  0x02027634  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj02419.h"
#include "../include/Obj09885.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct PalAnmSlot;
extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
struct PalAnmSlot;
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);
extern void func_02027634(void *arc, int id, u32 heap, int base, u32 pal);
extern void ARC_TOOL_DeleteHandle(void *a);
extern void func_020409B4(u32 a);

void MONOLITH_TOOL_LoadGraphics(void *a, void *b)
{
    char *d = (char *)a;
    char *r5 = (char *)b;
    void *h;

    PALANM_LoadHandlePaletteToSlotAt(((struct Obj02419 *)r5)->f0, (void *)(*(u32 *)&((struct Obj02419 *)r5)->f30), 0x10, 0x61, 0, 0x1c0, 0, 0);
    PALANM_LoadHandlePaletteToSlotAt(((struct Obj02419 *)r5)->f0, (void *)(*(u32 *)&((struct Obj02419 *)r5)->f30), 0x11, 0x61, 1, 0x1c0, 0, 0);
    func_02049658(((struct Obj02419 *)r5)->f30, 0xf, 3, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj02419 *)r5)->f30, 0xa, 3, 0, 0, 1, 0x61);
    func_02049658(((struct Obj02419 *)r5)->f30, 0xe, 7, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj02419 *)r5)->f30, 4, 7, 0, 0, 1, 0x61);
    PALANM_LoadArcPaletteToSlotAt(((struct Obj02419 *)r5)->f0, 0x17, 5, 0x61, 0, 0, 0xd0, 0);
    PALANM_LoadArcPaletteToSlotAt(((struct Obj02419 *)r5)->f0, 0x17, 5, 0x61, 1, 0, 0xd0, 0);
    h = func_020490F4(0x53, 0x61);
    ((struct Obj09885 *)d)->f138 = (void *)BG_SYS_CreateRun(7, 0x80, 1);
    func_02049658(h, 0x1c, 7, (u32)(((struct Obj09885 *)d)->f138), 0x80, 0, 0x61);
    func_02027634(h, 7, 0x61, (int)(((struct Obj09885 *)d)->f138), 0xc);
    PALANM_LoadHandlePaletteToSlot(((struct Obj02419 *)r5)->f0, h, 0x1b, 0x61, 1, 0x20, 0xc0);
    ARC_TOOL_DeleteHandle(h);
    func_020409B4(7);
    func_020409B4(3);
    func_020409B4(7);
}
