/*
 * function: P_STATUS_InitWork
 * address: 0x021D4240
 * packet: pkt_ov131_021D4240
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: owner 02012BF8 reads only r1; unused legacy r2/r3 are
 *   omitted after reading its full body. It returns a complete int word.
 *   Constructors consume context and return pointers, proven by full bodies.
 *   Raw addresses and callback/payload casts retain all 32 bits.
 * lever: explicit case 0 plus default keeps the original switch branch.
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   POKE_TOOL_CreateFromBoxParam 0x0201747C thumb
 *   P_STATUS_InitGraphics 0x021D46EC thumb ov131
 *   P_STA_SUB_Create 0x021D65D8 thumb ov131
 *   P_STA_INFO_AllocWork 0x021D7B00 thumb ov131
 *   P_STA_SKILL_Create 0x021D96B0 thumb ov131
 *   P_STA_RIBBON_Create 0x021D87E0 thumb ov131
 *   P_STATUS_LoadObjResource 0x021D4964 thumb ov131
 *   P_STATUS_InitMessage 0x021D51DC thumb ov131
 *   P_STATUS_CreateButtonActors 0x021D4FBC thumb ov131
 *   P_STATUS_VBlankTask 0x021D46E4 thumb ov131
 *   func_020056A0 0x020056A0 thumb
 *   func_02082A60 0x02082A60 arm
 *   P_STATUS_LoadPokemonState 0x021D5C4C thumb ov131
 *   P_STA_SUB_InitWindows 0x021D697C thumb ov131
 *   P_STA_SKILL_InitMovesPage 0x021DA6A4 thumb ov131
 *   P_STA_RIBBON_CollectOwned 0x021D911C thumb ov131
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   P_STA_SKILL_InitStatsPage 0x021D9C3C thumb ov131
 *   P_STA_RIBBON_Init 0x021D8F50 thumb ov131
 *   P_STA_INFO_Setup 0x021D7C38 thumb ov131
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj00238.h"
#include "../include/Obj23119.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_020355C4(void);
extern void *P_STATUS_GetPokePara(u8 *);
struct Mon;
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern void P_STATUS_InitGraphics(char *);
extern void *P_STA_SUB_Create(void *);
struct Context;
extern void **P_STA_INFO_AllocWork(u16 *a);
extern u8 *P_STA_SKILL_Create(u8 *);
extern void *P_STA_RIBBON_Create(u16 *a);
extern void P_STATUS_LoadObjResource(u8 *p);
extern void P_STATUS_InitMessage(char *);
extern void P_STATUS_CreateButtonActors(struct Context *ctx);
extern void P_STATUS_VBlankTask(void);
extern void *func_020056A0(u32,u32,u32);
extern void func_02082A60(const void *,void *,u32);
extern void P_STATUS_LoadPokemonState(u8 *);
extern void P_STA_SUB_InitWindows(u8 *,int *);
extern void P_STA_SKILL_InitMovesPage(u8 *a, u8 *p);
extern void P_STA_RIBBON_CollectOwned(u8 *a, u8 *p);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);
extern void P_STA_SKILL_InitStatsPage(void *,u8 *);
extern void P_STA_RIBBON_Init(void *,u8 *);
extern void P_STA_INFO_Setup(void *,u8 *);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
int P_STATUS_InitWork(char *p)
{
    u8 i;
    ((struct Obj00238 *)p)->f18=(*(u8 **)(p+8))[15];
    ((struct Obj00238 *)p)->f1A=255;
    ((struct Obj00238 *)p)->f1B=0;
    ((struct Obj00238 *)p)->f20=*(u32 *)0x02fffc3c;
    ((struct Obj00238 *)p)->f5C=4;
    ((struct Obj00238 *)p)->f44=1;
    ((struct Obj00238 *)p)->f48=0;
    ((struct Obj00238 *)p)->f4C=0;
    ((struct Obj00238 *)p)->f54=0;
    ((struct Obj00238 *)p)->fC=1;
    ((struct Obj00238 *)p)->f25C=0;
    ((struct Obj00238 *)p)->f260=0;
    ((struct Obj00238 *)p)->f50=0;
    ((struct Obj00238 *)p)->f1A0=0;
    ((struct Obj00238 *)p)->f10=0;
    ((struct Obj00238 *)p)->f14=0;
    ((struct Obj00238 *)p)->f1C=func_020355C4();
    if ((*(u8 **)(p+8))[13]==3) {
        (*(u8 **)(p+8))[13]=2;
        ((struct Obj00238 *)p)->f14=1;
    }
    if ((*(u8 **)(p+8))[12]==2) ((struct Obj00238 *)p)->f258=POKE_TOOL_CreateFromBoxParam(P_STATUS_GetPokePara((u8 *)p),((struct Obj00238 *)p)->f0);
    else ((struct Obj00238 *)p)->f258=0;
    P_STATUS_InitGraphics(p);
    ((struct Obj00238 *)p)->f88=P_STA_SUB_Create(p);
    ((struct Obj00238 *)p)->f8C=P_STA_INFO_AllocWork((u16 *)p);
    ((struct Obj00238 *)p)->f90=P_STA_SKILL_Create((u8 *)p);
    ((struct Obj00238 *)p)->f94=P_STA_RIBBON_Create((u16 *)p);
    P_STATUS_LoadObjResource((u8 *)p);
    P_STATUS_InitMessage(p);
    P_STATUS_CreateButtonActors((struct Context *)p);
    ((struct Obj00238 *)p)->f4=func_020056A0((u32)P_STATUS_VBlankTask,(u32)p,8);
    ((struct Obj00238 *)p)->f1A4=0;
    func_02082A60((void *)0x0500026c,p+0x1a6,12);
    func_02082A60((void *)0x05000360,p+0x1b6,64);
    func_02082A60((void *)0x050003a0,p+0x216,32);
    func_02082A60((void *)0x050003a0,p+0x236,32);
    P_STATUS_LoadPokemonState((u8 *)p);
    if ((*(u8 **)(p+8))[13]==2) {
        ((struct Obj00238 *)p)->f58=3;
        P_STA_SUB_InitWindows((u8 *)p,*(int * *)&((struct Obj00238 *)p)->f88);
        P_STA_SKILL_InitMovesPage((u8 *)p,((struct Obj00238 *)p)->f90);
        P_STA_RIBBON_CollectOwned((u8 *)p,((struct Obj00238 *)p)->f94);
    } else {
        ((struct Obj00238 *)p)->f58=(*(u8 **)(p+8))[16];
        if (((struct Obj00238 *)p)->f58<3) {
            for(i=0;i<3;i++) *(int *)(p+0x60+i*4)=GAME_DATA_CheckSaveFlag((int)(((struct Obj23119 *)(*(char * *)&((struct Obj00238 *)p)->f8))->f8),i+7);
        }
        P_STA_SUB_InitWindows((u8 *)p,*(int * *)&((struct Obj00238 *)p)->f88);
        P_STA_RIBBON_CollectOwned((u8 *)p,((struct Obj00238 *)p)->f94);
        switch (((struct Obj00238 *)p)->f58) {
        case 0: P_STA_INFO_Setup(p,*(u8 * *)&((struct Obj00238 *)p)->f8C); break;
        case 1: P_STA_SKILL_InitStatsPage(p,*(u8 * *)&((struct Obj00238 *)p)->f90); break;
        case 2: P_STA_RIBBON_Init(p,*(u8 * *)&((struct Obj00238 *)p)->f94); break;
        default: ((struct Obj00238 *)p)->f58=0;
            P_STA_INFO_Setup(p,*(u8 * *)&((struct Obj00238 *)p)->f8C); break;
        }
    }
    GFL_NET_RestartWithDefaultTimeout(1,((struct Obj00238 *)p)->f0);
    return 1;
}
