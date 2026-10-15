/*
 * function: LOCAL_TVT_SYS_CreateGraphics
 * address: 0x021B6594
 * packet: pkt_ov174_021B6594
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj00545.h"
#include "../include/Obj24199.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u16 x,y,z; u8 a,b; } Spec;
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
typedef signed int     s32;
struct Obj;
struct Sub0200852CObj;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPaletteCompressed(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_PushTile(u32);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
void LOCAL_TVT_SYS_CreateGraphics(u8 *p)
{
    int id=37;
    void *save;
    void *arc;
    Spec s;
    if(((struct Obj00545 *)p)->f8!=2) id=38;
    func_020498F4(((struct Obj00545 *)p)->f18,id,2,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(((struct Obj00545 *)p)->f18,id,3,0,0,0,((struct Obj00545 *)p)->f0);
    save=GAME_DATA_GetMyStatus(((struct Obj24199 *)(*(u8 * *)&((struct Obj00545 *)p)->f30))->f4);
    arc=func_020490F4(172,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f44=CLACT_RegisterPaletteCompressed(arc,3,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f48=CLACT_RegisterCharacter(arc,24,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f4C=CLACT_RegisterCellAnim(arc,20,22,((struct Obj00545 *)p)->f0);
    if(func_02008550(save)==0) func_02049B68(arc,7,4,0,0x60,((struct Obj00545 *)p)->f0);
    else func_02049B68(arc,6,4,0,0x60,((struct Obj00545 *)p)->f0);
    func_02049658(arc,11,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,14,7,0,0,0,((struct Obj00545 *)p)->f0);
    BG_SYS_PushTile(7);
    func_02049B68(arc,0,0,0x160,0x20,((struct Obj00545 *)p)->f0);
    func_02049658(arc,8,1,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,13,1,0,0,0,((struct Obj00545 *)p)->f0);
    BG_SYS_FillTileMap(1,0,0,32,32,11);
    BG_SYS_PushTile(1);
    ARC_TOOL_DeleteHandle(arc);
    s.a=10; s.b=1; s.x=0;s.y=0;s.z=0;
    ((struct Obj00545 *)p)->f54=CLACT_CreateActor((void *)((struct Obj00545 *)p)->f50,((struct Obj00545 *)p)->f48,((struct Obj00545 *)p)->f44,((struct Obj00545 *)p)->f4C,&s,0,((struct Obj00545 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00545 *)p)->f54,0);
    CLACT_SetActorAutoAnim(((struct Obj00545 *)p)->f54,1);
}
