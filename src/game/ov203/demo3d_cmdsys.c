/*
 * file:     demo3d_cmdsys.c
 * unit:     yes
 * function: DEMO3D_CMDSYS_Create, DEMO3D_CMDSYS_Delete, DEMO3D_CMDSYS_Update, DEMO3D_CMDSYS_Init, DEMO3D_CMDSYS_Release, DEMO3D_CMDSYS_Seek, DEMO3D_CMDSYS_Dispatch
 * address:  0x021BF7C0
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from demo3d_graphic.c, demo3d_data.c, demo3d_cmdsys.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   DEMO3D_CMDSYS_Create 0x021BF7C0 thumb ov203
 *   DEMO3D_CMDSYS_Delete 0x021BF810 thumb ov203
 *   DEMO3D_CMDSYS_Update 0x021BF858 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   DEMO3D_DATA_DeleteCapture 0x021BE9E8 thumb
 *   d_021C3D4C 0x021C3D4C data a4
 *   DEMO3D_DATA_GetExitCommandList 0x021BE9A4 thumb ov203
 *   TCBL_Main 0x020310C4 arm
 *   DEMO3D_DATA_GetCommandList 0x021BE990 thumb ov203
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   d_021C3D00 0x021C3D00 data a4
 */
#include "demo3d_graphic_shared_types.h"
#include "demo3d_data_shared_types.h"
#include "../arm9/gfl_use.h"

#include "../arm9/gfl_heap_wrap.h"

struct GfFont;

struct S02031140;

/* the owner passed to Create; struct Demo3dEngineCtx in demo3d_engine.c owns this record */
struct Demo3dOwner {
    u8 pad78[0x78];
    int config;
    u32 time;
};

typedef struct {int kind;unsigned time;int values[8];} Demo3dCmdsysRecord;



extern void DEMO3D_DATA_DeleteCapture(int);


extern u32 DEMO3D_DATA_GetExitCommandList(u32 id);

#include "../arm9/tcbl.h"

extern u32 DEMO3D_DATA_GetCommandList(u32 id);
struct TcblSystem;


#include "../arm9/gf_font.h"

#include "../arm9/arc_tool.h"

#include "../arm9/msg_speed.h"





Demo3dCmdContext *DEMO3D_CMDSYS_Create(char *owner,unsigned heap);

void DEMO3D_CMDSYS_Delete(char *p);

void DEMO3D_CMDSYS_Update(Demo3dCmdContext *p,int time,int flag);

void DEMO3D_CMDSYS_Init(char *p);

void DEMO3D_CMDSYS_Release(char *p);

int DEMO3D_CMDSYS_Seek(char *p,char *owner,int *index);

void DEMO3D_CMDSYS_Dispatch(Demo3dCmdContext *ctx,char *owner,Demo3dCmdsysRecord *r);

extern const char d_021C3D4C[];

Demo3dCmdContext *DEMO3D_CMDSYS_Create(char *owner,unsigned heap)
{
    Demo3dCmdContext *p;
    p=GFL_HEAP_Alloc(heap,0x30,1,d_021C3D4C,78);
    p->owner=owner;p->heap=heap;p->alternate=(heap&0x7FFF)|0x8000;
    p->config=((struct Demo3dOwner *)owner)->config;p->previous=-1;
    DEMO3D_CMDSYS_Init((char *)p);
    p->ended=DEMO3D_CMDSYS_Seek((char *)p,owner,&p->index);
    return p;
}

void DEMO3D_CMDSYS_Delete(char *p)
{
    Demo3dCmdsysRecord *r;
    char *owner;
    int i;
    owner=((Demo3dCmdContext *)p)->owner;r=(Demo3dCmdsysRecord *)DEMO3D_DATA_GetExitCommandList(((Demo3dCmdContext *)p)->config);
    for(i=0;i<9999;i++,r++) {
        if(r->kind==18) break;
        DEMO3D_CMDSYS_Dispatch((Demo3dCmdContext *)p,(char *)owner,r);
    }
    ((Demo3dCmdContext *)p)->done=1;
    TCBL_Main((struct TcblSystem *)(((Demo3dCmdContext *)p)->task));DEMO3D_CMDSYS_Release(p);GFL_HEAP_Free((void *)p);
}

void DEMO3D_CMDSYS_Update(Demo3dCmdContext *p,int time,int flag)
{
    Demo3dCmdsysRecord *r;
    char *owner;
    int i;
    owner=p->owner;
    p->flags[2]=flag?1:0;
    TCBL_Main((struct TcblSystem *)p->task);
    if(p->ended==0 && time!=-4096) {
        r=(Demo3dCmdsysRecord *)(uptr)DEMO3D_DATA_GetCommandList(p->config)+p->index;
        time>>=12;
        if(r->time==time && p->previous!=time) {
            i=0;
            do {
                DEMO3D_CMDSYS_Dispatch(p,owner,r);
                r++;
                p->ended=r->kind==18?1:0;
                p->index++;
                if(p->ended==1) break;
                if(r->time!=time) break;
                i++;
            } while(i<9999);
        }
        p->previous=time;
    }
}

extern void (*d_021C3D00[])(Demo3dCmdContext *, char *, int *);

void DEMO3D_CMDSYS_Init(char *p){((Demo3dCmdContext *)p)->task=(struct Tcbl *)TCBL_Create(((Demo3dCmdContext *)p)->heap,((Demo3dCmdContext *)p)->heap,16,128);((Demo3dCmdContext *)p)->text=GF_FONT_Create(23,0,0,0,((Demo3dCmdContext *)p)->heap);((Demo3dCmdContext *)p)->assets=ARC_TOOL_CreateHandle(161,((Demo3dCmdContext *)p)->heap);((Demo3dCmdContext *)p)->flags[0]=MSG_SPEED_GetWait();}

void DEMO3D_CMDSYS_Release(char *p)
{
    if(((Demo3dCmdContext *)p)->extra) DEMO3D_DATA_DeleteCapture(((Demo3dCmdContext *)p)->extra);
    TCBL_DeleteAllTasks((struct TcblSystem *)(((Demo3dCmdContext *)p)->task));
    if(((Demo3dCmdContext *)p)->flags[1]) {
        GFL_USE_PopBgm();GFL_USE_SetBgmPaused(0);GFL_USE_FadeInBgmFull(60);
    }
    ARC_TOOL_DeleteHandle(((Demo3dCmdContext *)p)->assets);GF_FONT_Delete(((Demo3dCmdContext *)p)->text);TCBL_Destroy((struct TcblSystem *)((Demo3dCmdContext *)p)->task);
}

int DEMO3D_CMDSYS_Seek(char *p,char *owner,int *index)
{
    Demo3dCmdsysRecord *r;
    int i;
    r=(Demo3dCmdsysRecord *)(uptr)DEMO3D_DATA_GetCommandList(((struct Demo3dOwner *)owner)->config);
    for(i=0;i<9999;i++) {
        if(r[i].kind==18) return 1;
        if(r[i].time==-1) DEMO3D_CMDSYS_Dispatch((Demo3dCmdContext *)p,owner,&r[i]);
        else if(r[i].time>=((struct Demo3dOwner *)owner)->time) {*index=i;return 0;}
    }
    return 0;
}

void DEMO3D_CMDSYS_Dispatch(Demo3dCmdContext *ctx,char *owner,Demo3dCmdsysRecord *r){d_021C3D00[r->kind](ctx,owner,r->values);}
