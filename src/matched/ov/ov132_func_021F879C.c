/*
 * function: STA_ACTING_Update,STA_ACTING_VBlankCallback
 * unit: yes
 * address: 0x021F879C
 * packet: pkt_ov132_021F879C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead followed by 021F8994 tail-call stub.
 * note: 021F6E74 retains the explicitly loaded pointer despite own void prototype.
 * symbols:
 *   STA_ACTING_UpdateCamera 0x021F8EA8 thumb ov132
 *   STA_ACT_BUTTON_Update 0x021FA6CC thumb ov132
 *   STA_ACTING_ProcessRecords 0x021F9794 thumb ov132
 *   STA_ACT_SCRIPT_Update 0x021FABD8 thumb ov132
 *   STA_ACT_EFFECT_Update 0x021F9ECC thumb ov132
 *   STA_ACTING_UpdateText 0x021F9374 thumb ov132
 *   STA_ACTING_UpdateSelection 0x021F94F8 thumb ov132
 *   STA_ACT_AUDIENCE_Update 0x021FA064 thumb ov132
 *   STA_ACTING_FadePalette 0x021F91CC thumb ov132
 *   STA_ACT_EFFECT_Draw 0x021F9ED4 thumb ov132
 *   STA_ACT_EFFECT_Noop 0x021F9E4C thumb ov132
 *   STA_ACTING_LoadCharAnims 0x021F90E0 thumb ov132
 *   STA_ACT_SCRIPT_CountScripts 0x021FAD7C thumb ov132
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 *   MUS_COMM_FUNC_CheckTimingSync 0x021FCE00 thumb ov132
 *   STA_ACT_LIGHT_StepModelAnim 0x021F6F64 thumb ov112
 *   STA_ACT_LIGHT_UpdateBillboard 0x021F7160 thumb ov112
 *   STA_ACT_OBJ_Update 0x021F6A58 thumb ov112
 *   MUSICAL_MCSS_TickAnim 0x021F51E8 thumb ov112
 *   STA_ACT_LIGHT_UpdateElemActors 0x021F6CB0 thumb ov112
 *   STA_ACT_LIGHT_NoOp 0x021F6E74 thumb ov112
 *   STA_ACT_LIGHT_UpdateElem 0x021F75A0 thumb ov112
 *   MUSICAL_MCSS_DrawRenderObj 0x021F51F4 thumb ov112
 *   STA_ACT_LIGHT_UpdateSprite 0x021F718C thumb ov112
 *   STA_ACT_LIGHT_DrawModel 0x021F6F8C thumb ov112
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   d_021FDE80 0x021FDE80 data a4
 */
#include "../include/Obj00191.h"
#include "../include/Obj23177.h"
#include "../include/Obj23178.h"
typedef unsigned u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 d_02FFFC3C,d_021FDE80;
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void),func_0200FB24(void);
extern int GFL_USE_IsAnySeBusy(void);
extern void MUS_COMM_FUNC_SetTimingSync(int,int);
struct Board;
struct Camera;
struct Lights;
extern int MUS_COMM_FUNC_CheckTimingSync(char *p, int id);
extern u8 STA_ACT_SCRIPT_CountScripts(char *);
extern void STA_ACTING_UpdateCamera(u8 *);
extern void STA_ACT_BUTTON_Update(char *p);
extern void STA_ACTING_ProcessRecords(char *p);
extern void STA_ACT_SCRIPT_Update(char *p);
extern int STA_ACT_EFFECT_Update(u8 *a0);
extern void STA_ACTING_UpdateText(u8 *);
extern void STA_ACTING_UpdateSelection(char *p);
extern void STA_ACT_AUDIENCE_Update(char *p);
extern void STA_ACTING_FadePalette(u8 *);
extern int STA_ACT_EFFECT_Draw(u8 *a0);
extern void STA_ACT_EFFECT_Noop(u8 *);
extern void STA_ACTING_LoadCharAnims(u8 *);
extern void STA_ACT_LIGHT_StepModelAnim(u8 *);
extern void STA_ACT_LIGHT_UpdateBillboard(u8 *);
extern void STA_ACT_OBJ_Update(char *p);
extern void MUSICAL_MCSS_TickAnim(u8 *);
extern void STA_ACT_LIGHT_UpdateElemActors(char *p);
extern void STA_ACT_LIGHT_NoOp(u8 *);
extern void STA_ACT_LIGHT_UpdateElem(u8 *);
extern void MUSICAL_MCSS_DrawRenderObj(void **p);
extern void STA_ACT_LIGHT_UpdateSprite(char *p);
extern void STA_ACT_LIGHT_DrawModel(u8 *);
extern void G3D_SYSTEM_DrawStart(void),G3D_SYSTEM_ApplyLookAt(void),G3D_SYSTEM_DrawEnd(void),CLACT_DrawSystem(void),CLACT_VBlankSystem(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
int STA_ACTING_Update(u8 *p)
{
    u32 tick;
    tick=d_02FFFC3C;
    ((struct Obj00191 *)p)->f1E8=tick-((struct Obj00191 *)p)->f1EC;
    ((struct Obj00191 *)p)->f1EC=tick;
    switch(((struct Obj00191 *)p)->f1C) {
    case 0:
        WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj00191 *)p)->f0);
        ((struct Obj00191 *)p)->f1C=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()==1) {
            if(**(u32 * *)&((struct Obj00191 *)p)->f30!=0) {
                ((struct Obj00191 *)p)->f1C=7;
                MUS_COMM_FUNC_SetTimingSync(**(int * *)&((struct Obj00191 *)p)->f30,200);
            } else ((struct Obj00191 *)p)->f1C=4;
        }
        break;
    case 2:
        if(GFL_USE_IsAnySeBusy()==0) {
            WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj00191 *)p)->f0);
            ((struct Obj00191 *)p)->f1C=3;
        }
        break;
    case 3:
        if(WIPE_SYS_EndCheck()==1) return 1;
        break;
    case 4:
        if((((struct Obj00191 *)p)->f2)++ >=60) ((struct Obj00191 *)p)->f1C=5;
        break;
    case 5:
        if(((struct Obj00191 *)p)->f164==0) {
            ((struct Obj00191 *)p)->fB4=((struct Obj23178 *)(*(u8 * *)&((struct Obj23177 *)(*(u8 * *)&((struct Obj00191 *)p)->f30))->f18))->fC;
            STA_ACTING_LoadCharAnims(p);
            ((struct Obj00191 *)p)->f1C=6;
        }
        break;
    case 6:
        if(STA_ACT_SCRIPT_CountScripts(*(char * *)&((struct Obj00191 *)p)->fB0)==0) {
            ((struct Obj00191 *)p)->fB4=0;
            if(((struct Obj00191 *)p)->f164==0) ((struct Obj00191 *)p)->f1C=2;
            else ((struct Obj00191 *)p)->f1C=255;
        }
        break;
    case 7:
        if(MUS_COMM_FUNC_CheckTimingSync(*(void **)*(u8 * *)&((struct Obj00191 *)p)->f30,200)==1)
            ((struct Obj00191 *)p)->f1C=4;
        break;
    }
    STA_ACTING_UpdateCamera(p);
    STA_ACT_BUTTON_Update((char *)(*(u8 * *)&((struct Obj00191 *)p)->fA4));
    STA_ACTING_ProcessRecords((char *)p);
    if(d_021FDE80==0) STA_ACT_SCRIPT_Update((char *)(*(u8 * *)&((struct Obj00191 *)p)->fB0));
    STA_ACT_LIGHT_StepModelAnim(*(u8 * *)&((struct Obj00191 *)p)->f3C);
    STA_ACT_LIGHT_UpdateBillboard(*(u8 * *)&((struct Obj00191 *)p)->f40);
    STA_ACT_OBJ_Update((char *)(*(u8 * *)&((struct Obj00191 *)p)->f54));
    STA_ACT_EFFECT_Update(*(u8 * *)&((struct Obj00191 *)p)->f6C);
    STA_ACTING_UpdateText(p);
    MUSICAL_MCSS_TickAnim(*(u8 * *)&((struct Obj00191 *)p)->f34);
    STA_ACT_LIGHT_UpdateElemActors((char *)(*(u8 * *)&((struct Obj00191 *)p)->f90));
    STA_ACTING_UpdateSelection((char *)p);
    STA_ACT_AUDIENCE_Update((char *)(*(u8 * *)&((struct Obj00191 *)p)->fB8));
    STA_ACTING_FadePalette(p);
    G3D_SYSTEM_DrawStart(); G3D_SYSTEM_ApplyLookAt();
    STA_ACT_LIGHT_NoOp(*(u8 * *)&((struct Obj00191 *)p)->f90);
    STA_ACT_LIGHT_UpdateElem(*(u8 * *)&((struct Obj00191 *)p)->f40);
    MUSICAL_MCSS_DrawRenderObj((void **)(*(u8 * *)&((struct Obj00191 *)p)->f34));
    STA_ACT_LIGHT_UpdateSprite((char *)(*(u8 * *)&((struct Obj00191 *)p)->f40));
    STA_ACT_LIGHT_DrawModel(*(u8 * *)&((struct Obj00191 *)p)->f3C);
    BILLBOARD_Draw(((struct Obj00191 *)p)->fAC,((struct Obj00191 *)p)->fA8,0);
    STA_ACT_EFFECT_Draw(*(u8 * *)&((struct Obj00191 *)p)->f6C);
    STA_ACT_EFFECT_Noop(p);
    G3D_SYSTEM_DrawEnd(); CLACT_DrawSystem();
    if(**(u32 * *)&((struct Obj00191 *)p)->f30!=0 && ((struct Obj00191 *)p)->f1C!=0 &&
       ((struct Obj00191 *)p)->f1C!=1 && ((struct Obj00191 *)p)->f1C!=2 &&
       ((struct Obj00191 *)p)->f1C!=3 && func_0200FB24()!=0)
        ((struct Obj00191 *)p)->f1C=2;
    return 0;
}
void STA_ACTING_VBlankCallback(void) { CLACT_VBlankSystem(); }
