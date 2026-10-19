/*
 * function: BR_PROC_SYS_Init
 * address: 0x021F90C0
 * packet: pkt_ov186_021F90C0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: name the zero after allocation; initialise the second flag before FC3BC, not at entry (first spelling DIFF 46 bytes).
 * abi: caller consumes 0203159C's live r0 at 021F90E0, overriding its void matched signature.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_GRAPHIC_Create 0x021FC3BC thumb ov186
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   MISC_GetRecorderFlag 0x0200C3E0 thumb
 *   BR_RES_Create 0x021FB884 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_PROC_SYS_Create 0x021F99CC thumb ov186
 *   BR_FADE_Create 0x021FE6C0 thumb ov186
 *   BR_FADE_CaptureHwPalettes 0x021FE7B4 thumb ov186
 *   BR_RES_GetCurrentSetParam 0x021FC224 thumb ov186
 *   BR_FADE_SetBlendColor 0x021FE7F4 thumb ov186
 *   BR_FADE_BlendFull 0x021FE7F8 thumb ov186
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BR_SIDEBAR_Create 0x021FED50 thumb ov186
 *   BR_PROC_SYS_LoadRecords 0x021F98F8 thumb ov186
 *   BR_NET_Create 0x021FF408 thumb ov186
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   func_02028A58 0x02028A58 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BR_SIDEBAR_ResetPositions 0x021FEE9C thumb ov186
 *   BR_SIDEBAR_StartWobble 0x021FEE4C thumb ov186
 *   BR_FADE_SetBlendLevel 0x021FE840 thumb ov186
 *   d_02200254 0x02200254 data a4
 *   ov125_id 0x0000007D data
 */
#include "../include/Obj00387.h"
#include "../include/Obj24764.h"
#include "../include/Obj24765.h"
#include "../include/Obj24766.h"
#include "../include/Obj24768.h"
#include "../include/Obj24769.h"
#include "../include/Obj24770.h"
#include "../include/Obj24772.h"
#include "../include/Obj24773.h"
#include "../include/Obj24774.h"
#include "../include/Obj24775.h"
#include "../include/Obj24776.h"
#include "../include/Obj24777.h"
#include "../include/Obj24779.h"
#include "../include/Obj24780.h"
#include "../include/Obj24781.h"
#include "../include/Obj24782.h"
#include "../include/Obj24783.h"
#include "../include/Obj24785.h"
#include "../include/Obj24786.h"
#include "../include/Obj24787.h"
#include "../include/Obj24788.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern char ov125_id[];
extern const char d_02200254[];
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32),MI_CpuFill8(void *,int,unsigned);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
struct SoundSys;
extern void *BR_GRAPHIC_Create(unsigned mode, int setting, unsigned heap);
extern void *GAME_DATA_GetMiscSave(int *);
extern void *BR_RES_Create(unsigned,unsigned,unsigned);
struct BigObj;
struct Blk34;
extern u8 MISC_GetRecorderFlag(struct Blk34 *p);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void *BR_PROC_SYS_Create(unsigned,void *,unsigned,unsigned,unsigned *,u16);
extern int *BR_FADE_Create(unsigned);
extern void BR_FADE_CaptureHwPalettes(char *),BR_FADE_SetBlendColor(int *,int),BR_FADE_BlendFull(char *,int);
extern int BR_RES_GetCurrentSetParam(char *);
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern char *BR_SIDEBAR_Create(int,int,char *,unsigned);
extern void BR_PROC_SYS_LoadRecords(char *p, int skip, void *sys, int heap);
extern char *BR_NET_Create(void *owner, void *arg, u32 heap);
extern int func_02034AC4(int),GFL_NET_GetRunState(void);
extern void GFL_NET_RefreshWmIconAtTopRight(u32,u32);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,u16);
extern void BR_SIDEBAR_ResetPositions(char *p);
extern void BR_SIDEBAR_StartWobble(char *p);
extern void BR_FADE_SetBlendLevel(int,int,int);
int BR_PROC_SYS_Init(void *obj,int unused,char *q)
{
    char *p;
    int flag=1;
    unsigned mode;
    int enabled;
    int zero;
    GFL_HEAP_CreateChildHeap(1,0x5a,0x90000);
    p=PROCSYS_AllocProcWork(obj,0x1c,0x5a);
    zero=0;
    MI_CpuFill8(p,0,0x1c);
    *(char * *)&((struct Obj00387 *)p)->f18=q;
    ((struct Obj24765 *)(*(char * *)&((struct Obj24764 *)q)->fC))->fC=zero;
    if(**(int * *)&((struct Obj24766 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC!=2) flag=zero;
    enabled=1;
    ((struct Obj00387 *)p)->f0=BR_GRAPHIC_Create(flag,1,0x5a);
    mode=MISC_GetRecorderFlag(GAME_DATA_GetMiscSave(*(int * *)&((struct Obj24769 *)(*(char * *)&((struct Obj24768 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4));
    if(**(int * *)&((struct Obj24770 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) enabled=0;
    ((struct Obj00387 *)p)->f4=BR_RES_Create(mode,enabled,0x5a);
    BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj00387 *)p)->f4),0,0x5a);
    BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj00387 *)p)->f4),1,0x5a);
    ((struct Obj00387 *)p)->f8=BR_PROC_SYS_Create(0,(void *)d_02200254,0xd,(unsigned)p,(unsigned *)(((struct Obj24772 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f8+0x1728),0x5a);
    *(int * *)&((struct Obj00387 *)p)->fC=BR_FADE_Create(0x5a);
    BR_FADE_CaptureHwPalettes(*(char * *)&((struct Obj00387 *)p)->fC);
    BR_FADE_SetBlendColor(*(int * *)&((struct Obj00387 *)p)->fC,BR_RES_GetCurrentSetParam(*(char * *)&((struct Obj00387 *)p)->f4));
    if(!((struct Obj24773 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4) BR_FADE_BlendFull(*(char * *)&((struct Obj00387 *)p)->fC,3);
    *(char * *)&((struct Obj00387 *)p)->f10=BR_SIDEBAR_Create(BR_GRAPHIC_GetActorUnit((u8 *)(*(int *)&((struct Obj00387 *)p)->f0)),*(int *)&((struct Obj00387 *)p)->fC,*(char * *)&((struct Obj00387 *)p)->f4,0x5a);
    BR_PROC_SYS_LoadRecords((char *)(((struct Obj24774 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f8+0x1748),1,(void *)(((struct Obj24776 *)(*(char * *)&((struct Obj24775 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4),0x5a);
    if(**(int * *)&((struct Obj24777 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) {
        ((struct Obj00387 *)p)->f14=BR_NET_Create(((struct Obj24780 *)(*(char * *)&((struct Obj24779 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4,(void *)(((struct Obj24782 *)(*(char * *)&((struct Obj24781 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f8),0x5a);
    } else func_02034AC4((int)ov125_id);
    if(GFL_NET_GetRunState()) GFL_NET_RefreshWmIconAtTopRight(0,0x5a);
    if(!**(int * *)&((struct Obj24783 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) {
        if(((struct Obj24785 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4!=1) func_02028A58((void *)GAME_DATA_GetBgmInfo(((struct Obj24787 *)(*(char * *)&((struct Obj24786 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4),0x40,0);
    } else GFL_USE_CancelChangeAndPlayBgm(0x484,0xffff);
    if(((struct Obj24788 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4==1) {
        BR_SIDEBAR_ResetPositions((char *)(*(int *)&((struct Obj00387 *)p)->f10));BR_SIDEBAR_StartWobble((char *)(*(int *)&((struct Obj00387 *)p)->f10));
        BR_FADE_SetBlendLevel(*(int *)&((struct Obj00387 *)p)->fC,3,0);
    }
    return 1;
}
