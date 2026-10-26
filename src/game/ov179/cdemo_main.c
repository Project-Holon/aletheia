/*
 * file:     cdemo_main.c
 * unit:     yes
 * function: CDEMO_MAIN_Create, CDEMO_MAIN_Update, CDEMO_MAIN_Destroy, CDEMO_MAIN_SetupVram, CDEMO_MAIN_SetupScreen, CDEMO_MAIN_HidePlane, CDEMO_MAIN_SetScript, CDEMO_MAIN_Noop, CDEMO_MAIN_StartTask, CDEMO_MAIN_StopTask
 * address:  0x021B6100
 * region:   ov179
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   CDEMO_WIPE_RunScript  0x021B6380  thumb  ov179
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   GX_SetGraphicsMode 0x0207D4B0 arm
 *   BUTTON_MAN_RotScaleMtx22 0x02051E74 arm
 *   G2x_SetBGyAffine_ 0x0207D59C arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GX_LoadBG2Scr 0x0207EB78 arm
 *   GX_LoadBG3Scr 0x0207ECF0 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   d_021B6B00 0x021B6B00 data a4
 *   d_021B68E4  0x021B68E4  data  a4
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCB_DeleteTask  0x02030EAC  arm
 */
#include "cdemo_types.h"
#include "../sdk_ioreg.h"

struct ProcSystem;
struct Proc;
struct DispVram;
struct Mtx22;
struct Node;
#include "../types.h"

typedef struct {int m[4];} Mtx;
union MtxFx22;

#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "cdemo_wipe.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/bg_sys.h"
#include "../arm9/gx.h"
#include "../arm9/button_man.h"
#include "../arm9/g2.h"
#include "../arm9/gx_load2d.h"
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
int CDEMO_MAIN_Create(struct ProcSystem *p, u32 b, struct CdemoScript *c);
int CDEMO_MAIN_Update(int a, int b, int c, char *d);
int CDEMO_MAIN_Destroy(void *p);
void CDEMO_MAIN_SetupVram(void);
void CDEMO_MAIN_SetupScreen(char *unused);
void CDEMO_MAIN_HidePlane(void);
void CDEMO_MAIN_SetScript(char *p);
void CDEMO_MAIN_Noop(char *p);
void CDEMO_MAIN_StartTask(int *p);
void CDEMO_MAIN_StopTask(char *p);
extern unsigned char d_021B6B00[];
extern int d_021B68E4[];

int CDEMO_MAIN_Create(struct ProcSystem *p, u32 b, struct CdemoScript *c)
{
    struct CdemoState *r;

    GFL_HEAP_CreateChildHeap(1, 0x7f, 0x80000);
    r = PROCSYS_AllocProcWork((struct Proc *)p, 0x605c, 0x7f);
    MI_CpuFill8(r, 0, sizeof(*r));
    r->script = (struct CdemoScript *)c;
    r->finish = 0;
    return 1;
}

int CDEMO_MAIN_Update(int a, int b, int c, char *d)
{
    if (CDEMO_WIPE_RunScript(d))
        return 0;
    return 1;
}

int CDEMO_MAIN_Destroy(void *p)
{
    PROCSYS_FreeProcWork(p);
    GFL_HEAP_DeleteChecked(0x7f);
    return 1;
}

void CDEMO_MAIN_SetupVram(void)
{
    BG_SYS_SetVramBanks((void *)0x021B68F0);
}

void CDEMO_MAIN_SetupScreen(char *unused)
{
 Mtx m;
 void *p;
 GX_SetGraphicsMode(1,5,0);
 *(volatile unsigned short *)0x0400000C=(*(volatile unsigned short *)0x0400000C&0x43)|0x4084;
 *(volatile unsigned short *)0x0400000E=(*(volatile unsigned short *)0x0400000E&0x43)|0x4884;
 BUTTON_MAN_RotScaleMtx22((union MtxFx22 *)(&m),0,(s32)0x1000,0x1000,0);
 G2x_SetBGyAffine_(REG_BG2PA_ADDR,(union MtxFx22 *)(&m),0,0,0,0);
 G2x_SetBGyAffine_(REG_BG3PA_ADDR,(union MtxFx22 *)(&m),0,0,0,0);
 p=GFL_HEAP_Alloc(0x807F,0x18000,1,(const char *)d_021B6B00,0x5B);
 GX_LoadBG2Scr(p,0,0x18000);GX_LoadBG3Scr(p,0,0x18000);GFL_HEAP_Free(p);
 BG_SYS_SetMainPlaneVisible(0x13,0);BG_SYS_SetMainPlaneVisible(0xC,1);
}

void CDEMO_MAIN_HidePlane(void)
{
    BG_SYS_SetMainPlaneVisible(12, 0);
}

void CDEMO_MAIN_SetScript(char *p)
{
    unsigned short idx = ((struct CdemoState *)p)->script->index;
    int v = d_021B68E4[idx];

    ((struct CdemoState *)p)->scriptStart = v;
    ((struct CdemoState *)p)->scriptCursor = v;
}

void CDEMO_MAIN_Noop(char *p)
{
}

void CDEMO_MAIN_StartTask(int *p)
{
    ((struct CdemoState *)p)->task = (void *)GFL_USE_AddMainTask((void *)0x021B6279, p, 0);
}

void CDEMO_MAIN_StopTask(char *p)
{
    TCB_DeleteTask(((struct CdemoState *)p)->task);
}
