/*
 * function: MUSICAL_SHOT_SYS_DrawScene
 * address: 0x021F3C50
 * packet: pkt_ov112_021F3C50
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte padding at 0x021F3CA2.
 * symbols:
 *   STA_ACT_LIGHT_UpdateBillboard 0x021F7160 thumb ov112
 *   MUSICAL_MCSS_TickAnim 0x021F51E8 thumb ov112
 *   STA_ACT_LIGHT_UpdateElemActors 0x021F6CB0 thumb ov112
 *   STA_ACT_LIGHT_NoOp 0x021F6E74 thumb ov112
 *   STA_ACT_LIGHT_UpdateElem 0x021F75A0 thumb ov112
 *   MUSICAL_MCSS_DrawRenderObj 0x021F51F4 thumb ov112
 *   STA_ACT_LIGHT_UpdateSprite 0x021F718C thumb ov112
 *   STA_ACT_LIGHT_DrawModel 0x021F6F8C thumb ov112
 *   MUSICAL_MCSS_NoOp 0x021F4280 thumb ov112
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
#include "../include/Obj02823.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Board;
struct Camera;
struct Lights;
extern void STA_ACT_LIGHT_UpdateBillboard(u8 *p);
extern void MUSICAL_MCSS_TickAnim(u8 *);
extern void STA_ACT_LIGHT_UpdateElemActors(char *p);
extern void STA_ACT_LIGHT_NoOp(u32);
extern void STA_ACT_LIGHT_UpdateElem(u8 *p);
extern void MUSICAL_MCSS_DrawRenderObj(void **p);
extern void STA_ACT_LIGHT_UpdateSprite(char *p);
extern void STA_ACT_LIGHT_DrawModel(u8 *p);
extern void MUSICAL_MCSS_NoOp(u8 *);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void G3D_SYSTEM_DrawEnd(void);
void MUSICAL_SHOT_SYS_DrawScene(u8 *p)
{
    STA_ACT_LIGHT_UpdateBillboard((u8 *)(((struct Obj02823 *)p)->f2C));
    MUSICAL_MCSS_TickAnim(*(u8 * *)&((struct Obj02823 *)p)->f20);
    STA_ACT_LIGHT_UpdateElemActors((char *)(((struct Obj02823 *)p)->f40));
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    STA_ACT_LIGHT_NoOp(((struct Obj02823 *)p)->f40);
    STA_ACT_LIGHT_UpdateElem((u8 *)(((struct Obj02823 *)p)->f2C));
    MUSICAL_MCSS_DrawRenderObj((void **)(*(u32 *)&((struct Obj02823 *)p)->f20));
    STA_ACT_LIGHT_UpdateSprite((char *)(((struct Obj02823 *)p)->f2C));
    STA_ACT_LIGHT_DrawModel((u8 *)(((struct Obj02823 *)p)->f28));
    BILLBOARD_Draw((struct Board *)(((struct Obj02823 *)p)->f1C),(struct Camera *)(((struct Obj02823 *)p)->f18),0);
    MUSICAL_MCSS_NoOp(p);
    G3D_SYSTEM_DrawEnd();
}
