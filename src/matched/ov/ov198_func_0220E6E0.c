/*
 * function: B_PLIST_DRAW_CreateActors
 * address: 0x0220E6E0
 * packet: pkt_ov198_0220E6E0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   B_PLIST_DRAW_CreateActorFromParams 0x0220E684 thumb ov198
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   B_PLIST_DRAW_ApplyActorPalettes 0x0220E7E4 thumb ov198
 *   d_02211DFC 0x02211DFC data a4
 */
#include "../include/Obj00172.h"
#include "../include/Obj25221.h"
#include "../include/Obj25222.h"
typedef unsigned short u16;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern unsigned B_PLIST_DRAW_CreateActorFromParams(char *,const int *);
typedef unsigned int   u32;
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
struct PalAnmSlot;
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void B_PLIST_DRAW_ApplyActorPalettes(void *);
extern const int d_02211DFC[][5];
void B_PLIST_DRAW_CreateActors(char *p)
{
    unsigned i;
    ((struct Obj00172 *)p)->f1EB8=(unsigned int)CLACT_CreateUnit((unsigned)45,(unsigned)0,(u16)((((struct Obj25221 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    for(i=0;i<41;i++) *(unsigned *)(p+i*4+0x1ebc)=B_PLIST_DRAW_CreateActorFromParams(p,d_02211DFC[i]);
    GFL_NET_RefreshWmIconAtTopRight(0,((struct Obj25222 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(((struct Obj00172 *)p)->f1D8),(int)3,(int)0,(int)0x1e0);
    B_PLIST_DRAW_ApplyActorPalettes(p);
}
