/*
 * function: GTSNEGO_DISP_BlendPalette
 * address: 0x021D6328
 * packet: pkt_ov120_021D6328
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D63F2.
 * lever: declaring the counter before the context places it at sp+0x10.
 * interface: PALANM_Delete forwards the supplied context to its free target.
 * symbols:
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   DC_FlushRange 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 */
#include "../include/Obj13934.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *PALANM_Create(u32);
struct Chan02021FD8;
struct PalAnmSlot;
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *,int);
extern void DC_FlushRange(void *,unsigned long);
extern void func_0207E5D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
void GTSNEGO_DISP_BlendPalette(u8 *p,int bank,int *offset,int *size,int count)
{
    int i;
    void *obj;
    u8 *buffer;
    obj=PALANM_Create(((struct Obj13934 *)p)->fF4);
    PALANM_AllocSlotBuffers(obj,bank,0x200,((struct Obj13934 *)p)->fF4);
    PALANM_CopyHwPaletteToSlot(obj,bank,0,0x200);
    PALANM_BlendChannel(obj,bank,0,0x100,6,0);
    buffer=(u8 *)PALANM_GetTransWork(obj,bank);
    for(i=0;i<count;i++) {
        switch(bank) {
        case 3:
            DC_FlushRange(buffer+offset[i]*32,size[i]*32);
            func_0207E5D0(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        case 1:
            DC_FlushRange(buffer+offset[i]*32,size[i]*32);
            func_0207E468(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        }
    }
    PALANM_FreeSlotBuffers(obj,bank);
    PALANM_Delete(obj);
}
