/*
 * function: func_021D4CBC
 * address: 0x021D4CBC
 * packet: pkt_ov123_021D4CBC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D4D3E before next labelled function.
 * symbols:
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 */
#include "../include/Obj13970.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
typedef unsigned char  u8;
struct Chan02021FD8;
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *p, int i);
extern void DWCi_ScreenDC_FlushRange(void *, int);
extern void func_0207E5D0(void *, int, int);
extern void func_0207E468(void *, int, int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
void func_021D4CBC(char *p, int n, int count)
{
    void *obj;
    void *buffer;
    int bytes;
    obj = PALANM_Create(((struct Obj13970 *)p)->fC);
    PALANM_AllocSlotBuffers(obj, n, 0x200, ((struct Obj13970 *)p)->fC);
    bytes = count * 32;
    PALANM_CopyHwPaletteToSlot(obj, n, 0, bytes);
    PALANM_BlendChannel(obj, (int)n, (int)0, (u16)(count * 16), (int)6, (int)0);
    buffer = (void *)PALANM_GetTransWork(obj, n);
    DWCi_ScreenDC_FlushRange(buffer, bytes);
    switch (n) {
    case 3: func_0207E5D0(buffer, 0, bytes); break;
    case 1: func_0207E468(buffer, 0, bytes); break;
    }
    PALANM_FreeSlotBuffers(obj, n);
    PALANM_Delete(obj);
}
