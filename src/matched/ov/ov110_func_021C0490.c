/*
 * function: PMS_SELECT_GRAPHIC_Setup
 * address: 0x021C0490
 * packet: pkt_ov110_021C0490
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: test source byte +95 after copying to +94; bitfield clear and ordered In stores.
 * prototype: 021C1718 tail-forwards to the returned first-word accessor 021C1848.
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   PMS_SELECT_GRAPHIC_CreateScene 0x021C1610 thumb ov110
 *   PMS_SELECT_GRAPHIC_GetSceneActorUnit 0x021C1718 thumb ov110
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   PMS_SELECT_GRAPHIC_CreateBg 0x021C060C thumb ov110
 *   PMS_SELECT_GRAPHIC_ResetBgBlink 0x021C09E0 thumb ov110
 *   PMS_SELECT_GRAPHIC_CreateTouchBar 0x021C0A54 thumb ov110
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   PMS_SELECT_GRAPHIC_CreateRows 0x021C0B54 thumb ov110
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj00435.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u8 pad[0x99]; u8 flag:1,rest:7; } Bits;
typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;
extern u8 func_020355C4(void);
extern void *PMS_SELECT_GRAPHIC_CreateScene(unsigned,u16);
extern u32 PMS_SELECT_GRAPHIC_GetSceneActorUnit(u8 *);
extern void UI_SCENE_LoadActorGfx(void *,In *,int,u16);
extern int UI_SCENE_CreateActor(void *,int,u16,u16,u8,u16);
extern void CLACT_SetActorBgPriority(void *,u32);
struct Obj;
struct R;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void PMS_SELECT_GRAPHIC_CreateBg(u8 *p, u16 heap, u32 font, void *print, void *bank);
extern void PMS_SELECT_GRAPHIC_ResetBgBlink(u8 *);
extern void *PMS_SELECT_GRAPHIC_CreateTouchBar(int,void *,int);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void PMS_SELECT_GRAPHIC_CreateRows(char *);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
void PMS_SELECT_GRAPHIC_Setup(u8 *p)
{
    int enabled;
    u32 resource;
    In in;
    ((Bits *)p)->flag=0;
    ((struct Obj00435 *)p)->fA4=1;
    enabled=1;
    if(func_020355C4()!=1) enabled=0;
    ((struct Obj00435 *)p)->fA8=enabled;
    p[0x94]=p[0x95];
    if(p[0x95]==255) {
        if(enabled) p[0x96]=0;
        else { p[0x95]=0; p[0x96]=0; }
    } else {
        if(enabled) p[0x95]=255;
    }
    ((struct Obj00435 *)p)->f50=PMS_SELECT_GRAPHIC_CreateScene(0,((struct Obj00435 *)p)->f4);
    resource=PMS_SELECT_GRAPHIC_GetSceneActorUnit(*(u8 * *)&((struct Obj00435 *)p)->f50);
    in.f8=43; in.fC=7; in.f10=13; in.f14=35; in.f18=41;
    in.f0=0; in.f4=0;
    in.b1c=0; in.b1d=0; in.b1e=5;
    UI_SCENE_LoadActorGfx(p+12,&in,resource,((struct Obj00435 *)p)->f4);
    *(int *)&((struct Obj00435 *)p)->f8=UI_SCENE_CreateActor(p+12,resource,240,16,16,((struct Obj00435 *)p)->f4);
    CLACT_SetActorBgPriority(((struct Obj00435 *)p)->f8,1);
    CLACT_SetActorAutoAnim(((struct Obj00435 *)p)->f8,1);
    PMS_SELECT_GRAPHIC_CreateBg(p+0x24,((struct Obj00435 *)p)->f4,(u32)(((struct Obj00435 *)p)->f58),((struct Obj00435 *)p)->f5C,((struct Obj00435 *)p)->f60);
    PMS_SELECT_GRAPHIC_ResetBgBlink(p+0x24);
    p[0x44]=0;
    ((struct Obj00435 *)p)->f40=0;
    ((struct Obj00435 *)p)->f54=PMS_SELECT_GRAPHIC_CreateTouchBar((int)p,(void *)PMS_SELECT_GRAPHIC_GetSceneActorUnit(*(u8 * *)&((struct Obj00435 *)p)->f50),((struct Obj00435 *)p)->f4);
    ((struct Obj00435 *)p)->f64=APP_TASKMENU_RES_Create(0,12,*(u32 *)&((struct Obj00435 *)p)->f58,*(u32 *)&((struct Obj00435 *)p)->f5C,((struct Obj00435 *)p)->f4);
    PMS_SELECT_GRAPHIC_CreateRows((char *)p);
    GFL_NET_RestartWithDefaultTimeout(1,((struct Obj00435 *)p)->f4);
}
