/*
 * function: POKETRADE_SAVE_CreateTypeIconActor
 * address: 0x021E0DBC
 * packet: pkt_ov119_021E0DBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
#include "../include/Obj13909.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Descriptor {int a,b,c,d,e,f,g;u8 h,i,j,k;} Descriptor;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetTouchBarFileId(void);
extern u32 APP_ICON_GetTypeCellFileId(u32);
extern u32 APP_ICON_GetTypePaletteFileId(u32);
extern u32 APP_ICON_GetTypeAnimFileId(u32);
extern u8 APP_ICON_GetTypePaletteOffset(int i);
extern void UI_SCENE_LoadActorGfx(void *,Descriptor *,int,u16);
extern int UI_SCENE_CreateActor(void *,int,u8,u8,u8,u16);
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void POKETRADE_SAVE_CreateTypeIconActor(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b) {Descriptor d;u8 v;int z=0;v=POKE_TOOL_GetPartyValue(mon,index+174,0);d.a=a;d.b=z;d.c=APP_ICON_GetArchiveId();d.d=APP_ICON_GetTouchBarFileId();d.e=APP_ICON_GetTypeCellFileId(v);d.f=APP_ICON_GetTypePaletteFileId(2);d.g=APP_ICON_GetTypeAnimFileId(2);d.h=8;d.i=z;d.j=3;UI_SCENE_LoadActorGfx(p,&d,slot,b);((struct Obj13909 *)p)->f10=UI_SCENE_CreateActor(p,slot,x,y,z,b);CLACT_SetActorPaletteOffset((struct Obj *)(((struct Obj13909 *)p)->f10),APP_ICON_GetTypePaletteOffset(v),1);}
