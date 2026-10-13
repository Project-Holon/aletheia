/*
 * function: P_STATUS_ExitWork
 * address: 0x021D4418
 * packet: pkt_ov131_021D4418
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 0x021D44C6.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   P_STATUS_DeleteButtonActors 0x021D5180 thumb ov131
 *   P_STATUS_ExitMessage 0x021D5258 thumb ov131
 *   P_STATUS_DeleteObjResource 0x021D4F24 thumb ov131
 *   P_STA_RIBBON_Noop 0x021D91EC thumb ov131
 *   P_STA_RIBBON_Delete 0x021D881C thumb ov131
 *   P_STA_SKILL_Delete 0x021D9734 thumb ov131
 *   P_STA_INFO_FreeWork 0x021D7B34 thumb ov131
 *   P_STA_SUB_Delete 0x021D6608 thumb ov131
 *   P_STATUS_ExitGraphics 0x021D48E4 thumb ov131
 *   GAME_DATA_SetSaveFlag 0x02012BE0 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01255.h"
#include "../include/Obj23120.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void P_STATUS_DeleteButtonActors(char *);
extern void P_STATUS_ExitMessage(char *);
extern void P_STATUS_DeleteObjResource(char *);
extern void P_STA_RIBBON_Noop(void *,void *);
extern void P_STA_RIBBON_Delete(void *,u8 *);
extern void P_STA_SKILL_Delete(u8 *a, u8 *p);
extern void P_STA_INFO_FreeWork(int,char *);
extern void P_STA_SUB_Delete(void *,void *);
extern void P_STATUS_ExitGraphics(char *);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);
extern void func_020355D8(u8);
extern u32 func_020307B0(void *p);
int P_STATUS_ExitWork(char *p)
{
    u8 i;
    func_02030EAC(((struct Obj01255 *)p)->f4);
    (*(u8 **)(p+8))[15]=((struct Obj01255 *)p)->f18;
    P_STATUS_DeleteButtonActors(p);
    P_STATUS_ExitMessage(p);
    P_STATUS_DeleteObjResource(p);
    P_STA_RIBBON_Noop(p,((struct Obj01255 *)p)->f94);
    P_STA_RIBBON_Delete(p,*(u8 * *)&((struct Obj01255 *)p)->f94);
    P_STA_SKILL_Delete((u8 *)p,((struct Obj01255 *)p)->f90);
    P_STA_INFO_FreeWork((int)p,*(char * *)&((struct Obj01255 *)p)->f8C);
    P_STA_SUB_Delete(p,((struct Obj01255 *)p)->f88);
    P_STATUS_ExitGraphics(p);
    if(((struct Obj01255 *)p)->f58<3){
        for(i=0;i<3;i++) GAME_DATA_SetSaveFlag(((struct Obj23120 *)(*(char * *)&((struct Obj01255 *)p)->f8))->f8,i+7,*(int *)(p+i*4+0x60));
    }
    if(((struct Obj01255 *)p)->f14==1){
        (*(u8 **)(p+8))[13]=3;
        ((struct Obj01255 *)p)->f14=0;
    }
    func_020355D8(((struct Obj01255 *)p)->f1C);
    if(((struct Obj01255 *)p)->f258) func_020307B0(((struct Obj01255 *)p)->f258);
    return 1;
}
