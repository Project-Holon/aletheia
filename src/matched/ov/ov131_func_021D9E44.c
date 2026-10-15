/*
 * function: P_STA_SKILL_ApplyStatsScreen
 * address: 0x021D9E44
 * packet: pkt_ov131_021D9E44
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00136.h"
#include "../include/Obj04512.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Cfg;
struct Descriptor;
struct Obj;
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
extern void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode);
extern void func_02041B6C(u32);
extern void BG_SYS_DrawTileEx(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void P_STA_SKILL_ApplyStatsScreen(u8 *a,u8 *p)
{
    u8 i;
    void *cell;
    i=0;
    BG_SYS_ClearLayerEx(4,0);
    for(;i<=7;i++) {
        cell=*(void **)(p+0x5c+i*4);
        BMP_WIN_TransferChars(cell);
        BMP_WIN_MakeScreen(cell);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(cell));
    }
    BG_SYS_DecodeTile(6,*(u8 * *)&((struct Obj04512 *)p)->f3C+12,*((u32 *)(*(u8 * *)&((struct Obj04512 *)p)->f3C+8)));
    func_02041B6C(6);
    BG_SYS_DrawTileEx(5,0,0,32,3,((struct Obj04512 *)p)->f4C+12,0,0,32,32);
    func_02041B6C(5);
    CLACT_SetActorDrawEnable(((struct Obj04512 *)p)->f90,1);
    CLACT_SetActorDrawEnable(((struct Obj04512 *)p)->f94,0);
    CLACT_SetActorDrawEnable(((struct Obj00136 *)a)->f198,0);
    CLACT_SetActorDrawEnable(((struct Obj00136 *)a)->f19C,0);
}
