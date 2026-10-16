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
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   GX_SetGraphicsMode 0x0207D4B0 arm
 *   BUTTON_MAN_RotScaleMtx22 0x02051E74 arm
 *   G2x_SetBGyAffine_ 0x0207D59C arm
 *   func_02030734 0x02030734 arm
 *   GX_LoadBG2Scr 0x0207EB78 arm
 *   func_0207ECF0 0x0207ECF0 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   d_021B6B00 0x021B6B00 data a4
 *   d_021B68E4  0x021B68E4  data  a4
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 */
#include "cdemo_types.h"

struct ProcSystem;
struct Proc;
struct DispVram;
struct Mtx22;
struct Node;
typedef unsigned int u32;

typedef struct {int m[4];} Mtx;

typedef unsigned char  u8;

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct ProcSystem *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern int CDEMO_WIPE_RunScript(char *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void GX_SetGraphicsMode(int,int,int);
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, unsigned int ang, const void *v1, const void *v2, u8 mode);
extern void G2x_SetBGyAffine_(void *,const Mtx *,int,int,int,int);
extern void *func_02030734(unsigned int,unsigned int,int,const char *,unsigned short);
extern void GX_LoadBG2Scr(void *,int,int);
extern void func_0207ECF0(void *,int,int);
extern unsigned int func_020307B0(void *p);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern int func_020056A0(void *, int *, int);
extern void func_02030EAC(struct Node *n);
int CDEMO_MAIN_Create(struct ProcSystem *p, u32 b, u32 c);
int CDEMO_MAIN_Update(int a, int b, int c, int d);
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


int CDEMO_MAIN_Create(struct ProcSystem *p, u32 b, u32 c)
{
    struct CdemoState *r;

    GFL_HEAP_CreateChildHeap(1, 0x7f, 0x80000);
    r = PROCSYS_AllocProcWork(p, (u32)((void *)0x605c), 0x7f);
    MI_CpuFill8(r, 0, 0x605c);
    r->script = (struct CdemoScript *)c;
    r->finish = 0;
    return 1;
}


int CDEMO_MAIN_Update(int a, int b, int c, int d)
{
    if (CDEMO_WIPE_RunScript((char *)d))
        return 0;
    return 1;
}


int CDEMO_MAIN_Destroy(void *p)
{
    func_020315D4(p);
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
 BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&m),0,(void *)0x1000,(void *)0x1000,0);
 G2x_SetBGyAffine_((void *)0x04000020,&m,0,0,0,0);
 G2x_SetBGyAffine_((void *)0x04000030,&m,0,0,0,0);
 p=func_02030734(0x807F,0x18000,1,(const char *)d_021B6B00,0x5B);
 GX_LoadBG2Scr(p,0,0x18000);func_0207ECF0(p,0,0x18000);func_020307B0(p);
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
    ((struct CdemoState *)p)->task = (void *)func_020056A0((void *)0x021B6279, p, 0);
}


void CDEMO_MAIN_StopTask(char *p)
{
    func_02030EAC(((struct CdemoState *)p)->task);
}
