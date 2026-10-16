/*
 * function: P_STA_INFO_ShowPage
 * address: 0x021D7CAC
 * packet: pkt_ov131_021D7CAC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: the byte loop counter is declared before the per-cell pointer to
 *   reproduce the r4/r5 allocation. first/second keep the complete word
 *   returned by 02017E88. Extent tail 021D7E82..021D7E84 is zero padding.
 * symbols:
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj01407.h"
#include "../include/Obj05391.h"
#include "../include/Obj23144.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Rec { u32 w[9]; };
struct Point { s16 x,y; };
extern void *P_STATUS_GetPokePara(u8 *);
extern void BG_SYS_DrawTileEx(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02041B6C(u32);
struct Cfg;
struct Descriptor;
struct Obj;
extern void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
extern u32 POKE_TOOL_GetBoxValue(void *,u32,u32);
extern void CLACT_GetCharacterProxy(u32,struct Rec *);
struct Struct36;
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
extern u8 APP_ICON_GetTypePaletteOffset(int i);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorBgPriority(void *,u32);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void P_STA_INFO_ShowPage(u8 *a,u8 *p)
{
    struct Rec r1,r2;
    struct Point point;
    u8 i;
    void *object;
    void *cell;
    u32 first,second;
    object=P_STATUS_GetPokePara(a);
    if(((struct Obj01407 *)a)->f38==0) BG_SYS_DrawTileEx(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f4C+12),0,0,32,32);
    else BG_SYS_DrawTileEx(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f54+12),0,0,32,32);
    func_02041B6C(2);
    BG_SYS_DecodeTile(6,*(u8 * *)&((struct Obj05391 *)p)->f5C+12,((struct Obj23144 *)(*(u8 * *)&((struct Obj05391 *)p)->f5C))->f8);
    func_02041B6C(6);
    BG_SYS_DrawTileEx(5,0,0,32,3,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f64+12),0,0,32,32);
    func_02041B6C(5);
    for(i=0;i<10;i++) {
        cell=*(void **)((p+i*4)+0xc);
        BMP_WIN_TransferChars(cell);
        BMP_WIN_MakeScreen(cell);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(cell));
    }
    cell=((struct Obj05391 *)p)->f34;
    BMP_WIN_TransferChars(cell);
    BMP_WIN_MakeScreen(cell);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(cell));
    if(((struct Obj01407 *)a)->f38==0) {
        first=POKE_TOOL_GetBoxValue(object,174,0);
        second=POKE_TOOL_GetBoxValue(object,175,0);
        CLACT_GetCharacterProxy(*(u32 *)((u32)a+first*4u+0x130u),&r1);
        CLACT_SetActorImageProxy(((struct Obj01407 *)a)->f198,(const struct Struct36 *)(&r1));
        CLACT_SetActorPaletteOffset(((struct Obj01407 *)a)->f198,APP_ICON_GetTypePaletteOffset((u8)first),1);
        point.x=96;
        point.y=48;
        CLACT_AddActorSurfacePos(((struct Obj01407 *)a)->f198,(const struct Vec2 *)(&point),0);
        CLACT_SetActorDrawEnable(((struct Obj01407 *)a)->f198,1);
        CLACT_SetActorBgPriority(((struct Obj01407 *)a)->f198,1);
        if(first!=second) {
            CLACT_GetCharacterProxy(*(u32 *)((u32)a+second*4u+0x130u),&r2);
            CLACT_SetActorImageProxy(((struct Obj01407 *)a)->f19C,(const struct Struct36 *)(&r2));
            CLACT_SetActorPaletteOffset(((struct Obj01407 *)a)->f19C,APP_ICON_GetTypePaletteOffset((u8)second),1);
            point.x=130;
            point.y=48;
            CLACT_AddActorSurfacePos(((struct Obj01407 *)a)->f19C,(const struct Vec2 *)(&point),0);
            CLACT_SetActorDrawEnable(((struct Obj01407 *)a)->f19C,1);
            CLACT_SetActorBgPriority(((struct Obj01407 *)a)->f19C,1);
        } else CLACT_SetActorDrawEnable(((struct Obj01407 *)a)->f19C,0);
    } else {
        CLACT_SetActorDrawEnable(((struct Obj01407 *)a)->f198,0);
        CLACT_SetActorDrawEnable(((struct Obj01407 *)a)->f19C,0);
    }
    CLACT_SetActorAnimSeq(((struct Obj01407 *)a)->f178,3);
}
