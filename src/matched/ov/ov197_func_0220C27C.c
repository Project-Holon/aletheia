/*
 * function: B_BAG_MAIN_RegisterCursorGraphics
 * address: 0x0220C27C
 * packet: pkt_ov197_0220C27C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00315.h"
#include "../include/Obj25022.h"
#include "../include/Obj25023.h"
#include "../include/Obj25024.h"
#include "../include/Obj25025.h"
#include "../include/Obj25026.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
extern int CLACT_RegisterPalette(void *,unsigned,unsigned,unsigned,u16);
extern int CLACT_RegisterCellAnim(void *,unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void ARC_TOOL_DeleteHandle(void *);
void B_BAG_MAIN_RegisterCursorGraphics(char *p)
{
    void *arc = func_020490F4(99,(u16)((((struct Obj25022 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    ((struct Obj00315 *)p)->f560=CLACT_RegisterCharacter(arc,13,1,1,((struct Obj25023 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f584=CLACT_RegisterPalette(arc,14,1,224,((struct Obj25024 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f590=CLACT_RegisterCellAnim(arc,15,16,((struct Obj25025 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    PALANM_LoadHandlePaletteToSlot(((struct Obj00315 *)p)->f8,(void *)((unsigned)arc),14,((struct Obj25026 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC,3,32,112);
    ARC_TOOL_DeleteHandle(arc);
}
