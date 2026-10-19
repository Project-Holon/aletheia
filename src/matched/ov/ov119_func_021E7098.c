/*
 * function: POKETRADE_2D_FadePaletteBank
 * address: 0x021E7098
 * packet: pkt_ov119_021E7098
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: 02021540 forwards live r0 to 020307B0, so caller passes s.
 * symbols:
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   DC_FlushRange 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 */
#include "../include/Obj13926.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { void *a, *b; u32 size, c, d; } Slot;
extern void *PALANM_Create(u32 heap);
struct Chan02021FD8;
struct PalAnmSlot;
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *,int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void DC_FlushRange(void *,u32);
extern void func_0207E5D0(void *,u32,u32);
extern void func_0207E468(void *,u32,u32);
extern void GX_LoadOBJPltt(void *,u32,u32);
extern void GX_LoadBGPltt(void *,u32,u32);
void POKETRADE_2D_FadePaletteBank(char *p, int bank, int mask)
{
    Slot *s;
    char *buf;
    int i;
    int off;
    s=PALANM_Create(((struct Obj13926 *)p)->f5F4);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)s,bank,0x200,((struct Obj13926 *)p)->f5F4);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)s,bank,0,0x200);
    PALANM_BlendChannel((struct Chan02021FD8 *)s,bank,0,0x100,6,0);
    buf=(char *)PALANM_GetTransWork((char *)s,bank);
    for(i=0;i<16;i++) {
        if(mask & (1<<i)) {
            off=i*32;
            DC_FlushRange(buf+off,32);
            switch(bank) {
            case 3: func_0207E5D0(buf+off,off,32); break;
            case 1: func_0207E468(buf+off,off,32); break;
            case 2: GX_LoadOBJPltt(buf+off,off,32); break;
            case 0: GX_LoadBGPltt(buf+off,off,32); break;
            }
        }
    }
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)s,bank);
    PALANM_Delete(s);
}
