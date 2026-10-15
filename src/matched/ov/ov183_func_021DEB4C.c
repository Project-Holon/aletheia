/*
 * function: BR_CODEIN_StatSetup
 * address: 0x021DEB4C
 * packet: pkt_ov183_021DEB4C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   func_02034714 0x02034714 arm
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BR_CODEIN_SearchCreateList 0x021DF1DC thumb ov183
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_StatStepFadeIn 0x021DED14 thumb ov183
 *   d_021E3964 0x021E3964 data a1
 */
#include "../include/Obj00364.h"
#include "../include/Obj24587.h"
#include "../include/Obj24588.h"
#include "../include/Obj24589.h"
#include "../include/Obj24590.h"
#include "../include/Obj24591.h"
#include "../include/Obj24592.h"
#include "../include/Obj24593.h"
#include "../include/Obj24595.h"
#include "../include/Obj24596.h"
#include "../include/Obj24597.h"
#include "../include/Obj24598.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Config {u16 left,right,top;u8 flag,pad;} Config;
typedef struct Triple {u32 a,b,c;} Triple;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_UTIL_DeleteTextWin(void *,int);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void BR_RES_LoadSprite(char *,u32,u32);
extern void MI_CpuFill8(void *,int,int);
extern int BR_RES_GetSprite(void *,int,Triple *);
extern void func_02034714(const char *,u32,const char *);
extern void *BR_BTN_CreateFromMessage(void *,int,int,int,int,int,int,int,void *,u16);
extern void *BR_UTIL_Create(u16,u32,u16,u16,u8,u8,void *,u16);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,u16);
extern void BR_UTIL_SetTextLayout(u8 *p, u32 a, u32 b, u32 c);
extern void BR_CODEIN_SearchCreateList(char *,char *,char *,int,void *,void *,u16 *,u32);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_StatStepFadeIn(int *a, int *state, char *p);
extern const char d_021E3964[];
void BR_CODEIN_StatSetup(int *task,int *state,char *p)
{
    int font,bank;
    Config config;
    Triple triple;
    font=BR_RES_GetFont(*(char * *)&((struct Obj24587 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
    bank=BR_RES_GetMsgData(*(char * *)&((struct Obj24588 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
    if(((struct Obj00364 *)p)->f24) {
        BR_UTIL_DeleteTextWin(((struct Obj00364 *)p)->f24,((struct Obj24589 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
        ((struct Obj00364 *)p)->f24=0;
    }
    BR_RES_LoadBgGraphics((void *)(((struct Obj24590 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10),24,((struct Obj00364 *)p)->f18);
    BR_RES_LoadSprite(*(char * *)&((struct Obj24591 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,6,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f104=1;
    MI_CpuFill8(&config,0,8);
    config.left=80;config.right=168;config.top=0;config.flag=1;
    if(!BR_RES_GetSprite(((struct Obj24592 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,6,&triple))
        func_02034714(d_021E3964,0,d_021E3964);
    ((struct Obj00364 *)p)->f4=BR_BTN_CreateFromMessage(&config,4,96,1,((struct Obj24593 *)(*(char * *)&((struct Obj00364 *)p)->f108))->fC,((struct Obj00364 *)p)->f0,font,bank,&triple,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f8=BR_UTIL_Create(4,11,6,10,4,14,((struct Obj00364 *)p)->f14,((struct Obj00364 *)p)->f18);
    BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00364 *)p)->f8,(void *)bank,(void *)0x55,(void *)font,0x3da0);
    ((struct Obj00364 *)p)->fC=BR_UTIL_Create(1,3,3,26,4,14,((struct Obj00364 *)p)->f14,((struct Obj00364 *)p)->f18);
    BR_UTIL_SetTextLayout(((struct Obj00364 *)p)->fC,0,1,0);
    BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00364 *)p)->fC,(void *)bank,(void *)(**(int * *)&((struct Obj00364 *)p)->f108+0x57),(void *)font,0x3da0);
    BR_CODEIN_SearchCreateList(p+0x28,*(char * *)&((struct Obj24595 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f1C,*(char * *)&((struct Obj24596 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,((struct Obj24597 *)(*(char * *)&((struct Obj00364 *)p)->f108))->fC,((struct Obj00364 *)p)->f1C,((struct Obj00364 *)p)->f20,*(u16 * *)&((struct Obj24598 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f28,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f100=1;
    BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_StatStepFadeIn);
}
