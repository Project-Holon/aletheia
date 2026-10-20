/*
 * file:     cdemo_scene.c
 * unit:     yes
 * function: CDEMO_SCENE_Create, CDEMO_SCENE_Destroy, CDEMO_SCENE_GetResult, CDEMO_SCENE_ReturnThree, CDEMO_SCENE_RunCommands, CDEMO_SCENE_Step, CDEMO_SCENE_LoadScreenBlock, CDEMO_SCENE_DispatchCommand, CDEMO_SCENE_CmdCount, CDEMO_SCENE_CmdStartWipe0, CDEMO_SCENE_CmdStartWipe1, CDEMO_SCENE_CmdStartWipe2, CDEMO_SCENE_CmdStartWipe3, CDEMO_SCENE_CmdSetDone, CDEMO_SCENE_CmdLoadBg, CDEMO_SCENE_CmdSetPlaneVisible, CDEMO_SCENE_CmdSetLayerVisible, CDEMO_SCENE_CmdSetBlend, CDEMO_SCENE_CmdSetBlend2, CDEMO_SCENE_CmdResetBlend, CDEMO_SCENE_CmdNoop0, CDEMO_SCENE_CmdStopBgm, CDEMO_SCENE_CmdPlayFanfare, CDEMO_SCENE_CmdNoop1, CDEMO_SCENE_CmdNoop2, CDEMO_SCENE_CmdNoop3, CDEMO_SCENE_CmdReset, CDEMO_SCENE_CmdNoop4
 * address:  0x021B63D4
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
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   CDEMO_MAIN_SetupVram 0x021B615C thumb ov179
 *   CDEMO_MAIN_SetupScreen 0x021B616C thumb ov179
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CDEMO_MAIN_SetScript 0x021B622C thumb ov179
 *   CDEMO_MAIN_StartTask 0x021B624C thumb ov179
 *   CDEMO_WIPE_StartFadeOut 0x021B6290 thumb ov179
 *   d_021B6A1C 0x021B6A1C data a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   CDEMO_MAIN_StopTask 0x021B6268 thumb ov179
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CDEMO_MAIN_Noop 0x021B6248 thumb ov179
 *   CDEMO_MAIN_HidePlane 0x021B6220 thumb ov179
 *   OS_GetTick  0x020870D0  arm
 *   BG_SYS_SetPriority  0x0204047C  arm
 *   data_021B6A1C  0x021B6A1C  data  ov179
 *   _ull_mul       0x0209C054  arm
 *   _ll_udiv       0x0209C00C  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   GX_LoadBG3Scr  0x0207ECF0  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   d_021B6A40 0x021B6A40 data a4
 *   d_021B6A90 0x021B6A90 data a4
 *   CDEMO_WIPE_StartFadeIn  0x021B62B8  thumb  ov179
 *   CDEMO_WIPE_StartFadeOutWhite  0x021B62E0  thumb  ov179
 *   CDEMO_WIPE_StartFadeInWhite  0x021B630C  thumb  ov179
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   CDEMO_WIPE_LoadPalette 0x021B6338 thumb ov179
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb  arm9
 */
#include "cdemo_types.h"

#include "../types.h"

typedef struct {unsigned short value;char pad[10];} CdemoEntry;

typedef struct {
    u16 unused0;
    u16 blockCount;
    int size;
    int destOffset;
} CdemoScriptStep;

#include "../arm9/bg_sys.h"
#include "cdemo_main.h"
#include "../arm9/arc_tool.h"
#include "cdemo_wipe.h"
#include "../arm9/wipe.h"
#include "../arm9/gfl_use.h"
#include "../arm9/os_tick.h"
#include "../arm9/arc_util.h"
extern void DC_FlushRange(int, int);
#include "../arm9/gx_load2d.h"
#include "../arm9/gfl_heap_wrap.h"
int CDEMO_SCENE_Create(char *p);
int CDEMO_SCENE_Destroy(char *p);
u32 CDEMO_SCENE_GetResult(char *p);
int CDEMO_SCENE_ReturnThree(void);
u32 CDEMO_SCENE_RunCommands(char *p);
int CDEMO_SCENE_Step(char *p);
void CDEMO_SCENE_LoadScreenBlock(void *a, int b, int c, int d, int e);
int CDEMO_SCENE_DispatchCommand(char *p);
int CDEMO_SCENE_CmdCount(char *p,int *q);
int CDEMO_SCENE_CmdStartWipe0(int a, int *q);
int CDEMO_SCENE_CmdStartWipe1(int a, int *q);
int CDEMO_SCENE_CmdStartWipe2(int a, int *q);
int CDEMO_SCENE_CmdStartWipe3(int a, int *q);
int CDEMO_SCENE_CmdSetDone(char *p);
int CDEMO_SCENE_CmdLoadBg(char *p,const int *q);
int CDEMO_SCENE_CmdSetPlaneVisible(int a, int *q);
int CDEMO_SCENE_CmdSetLayerVisible(int a, int *q);
int CDEMO_SCENE_CmdSetBlend(char *p, int *q);
int CDEMO_SCENE_CmdSetBlend2(char *p, int *q);
int CDEMO_SCENE_CmdResetBlend(char *p);
int CDEMO_SCENE_CmdNoop0(void);
int CDEMO_SCENE_CmdStopBgm(void);
int CDEMO_SCENE_CmdPlayFanfare(void *ctx, unsigned int *rec);
int CDEMO_SCENE_CmdNoop1(void);
int CDEMO_SCENE_CmdNoop2(void);
int CDEMO_SCENE_CmdNoop3(void);
int CDEMO_SCENE_CmdReset(char *p);
int CDEMO_SCENE_CmdNoop4(void);
extern const CdemoEntry d_021B6A1C[];
extern const CdemoScriptStep data_021B6A1C[];
extern const unsigned d_021B6A90[];

int CDEMO_SCENE_Create(char *p)
{
 BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 BG_SYS_SetLcdSwap(1);CDEMO_MAIN_SetupVram();CDEMO_MAIN_SetupScreen(p);
 ((struct CdemoState *)p)->arcHandle=ARC_TOOL_CreateHandle(d_021B6A1C[((struct CdemoState *)p)->script->index].value,0x7F);
 CDEMO_MAIN_SetScript(p);CDEMO_MAIN_StartTask((int *)p);CDEMO_WIPE_StartFadeOut(p,1,1,5);
 ((struct CdemoState *)p)->finish=1;
 return 2;
}

int CDEMO_SCENE_Destroy(char *p) {
 if(WIPE_SYS_EndCheck()==0) return 1;
 if(GFL_USE_IsBgmFading()==1) return 1;
 GFL_USE_CancelChangeAndStopBgm();
 if(((struct CdemoState *)p)->finish==1) { CDEMO_MAIN_StopTask(p); ARC_TOOL_DeleteHandle(((struct CdemoState *)p)->arcHandle); CDEMO_MAIN_Noop(p); CDEMO_MAIN_HidePlane(); }
 return 6;
}

u32 CDEMO_SCENE_GetResult(char *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct CdemoState *)p)->fade;
    return 2;
}

int CDEMO_SCENE_ReturnThree(void)
{
    return 3;
}

u32 CDEMO_SCENE_RunCommands(char *p)
{
    do {
        if (**(int * *)&((struct CdemoState *)p)->scriptCursor == 20) {
            ((struct CdemoState *)p)->script->flag = 0;
            return 1;
        }
    } while (CDEMO_SCENE_DispatchCommand(p) == 1);
    return ((struct CdemoState *)p)->result;
}

/*
 * Frame-paced step: accumulates OS_GetTick deltas in microseconds and
 * advances one 66,667 us (15 Hz) step at a time. The entry table must be
 * const: that is what lets the e->destOffset load schedule ahead of the count store.
 */
int CDEMO_SCENE_Step(char *p)
{
    const CdemoScriptStep *e = &data_021B6A1C[((struct CdemoState *)p)->script->index];

    if (((struct CdemoState *)p)->tick == 0) {
        ((struct CdemoState *)p)->tick = OS_GetTick();
    } else {
        u64 now = OS_GetTick();
        ((struct CdemoState *)p)->accum += (now - ((struct CdemoState *)p)->tick) * 64000 / 33514;
        ((struct CdemoState *)p)->tick = now;
        if (((struct CdemoState *)p)->accum < 66667)
            return 4;
        ((struct CdemoState *)p)->accum -= 66667;
    }

    switch (((struct CdemoState *)p)->state) {
    case 0:
        CDEMO_SCENE_LoadScreenBlock(((struct CdemoState *)p)->arcHandle, ((struct CdemoState *)p)->step, e->destOffset, e->size, 0);
        (((struct CdemoState *)p)->step)++;
        CDEMO_SCENE_LoadScreenBlock(((struct CdemoState *)p)->arcHandle, ((struct CdemoState *)p)->step, e->destOffset, e->size, 1);
        (((struct CdemoState *)p)->step)++;
        BG_SYS_SetPriority((u8)2, (u8)0);
        BG_SYS_SetPriority((u8)3, (u8)1);
        ((struct CdemoState *)p)->state = 1;
        break;
    case 1:
        BG_SYS_SetPriority((u8)((((struct CdemoState *)p)->flip ^ 1) + 2), (u8)0);
        BG_SYS_SetPriority((u8)(((struct CdemoState *)p)->flip + 2), (u8)1);
        CDEMO_SCENE_LoadScreenBlock(((struct CdemoState *)p)->arcHandle, ((struct CdemoState *)p)->step, e->destOffset, e->size, ((struct CdemoState *)p)->flip);
        (((struct CdemoState *)p)->step)++;
        if (((struct CdemoState *)p)->step >= e->blockCount) {
            ((struct CdemoState *)p)->state = 2;
        } else {
            ((struct CdemoState *)p)->flip ^= 1;
        }
        break;
    case 2:
        BG_SYS_SetPriority((u8)(((struct CdemoState *)p)->flip + 2), (u8)0);
        BG_SYS_SetPriority((u8)((((struct CdemoState *)p)->flip ^ 1) + 2), (u8)1);
        ((struct CdemoState *)p)->state = 3;
        break;
    case 3:
        return 5;
    }
    return 4;
}

void CDEMO_SCENE_LoadScreenBlock(void *a, int b, int c, int d, int e)
{
    int t = (sptr)ARC_UTIL_LoadHandleMember(a, b, 1, 0x807f);

    DC_FlushRange(t, d);
    if (e == 0) {
        GX_LoadBG2Scr((void *)t, c, d);
    } else {
        GX_LoadBG3Scr((void *)t, c, d);
    }
    GFL_HEAP_Free((void *)t);
}

extern int (*d_021B6A40[])(char *,int *);

int CDEMO_SCENE_DispatchCommand(char *p) {
 int *q; int result; q=*(int * *)&((struct CdemoState *)p)->scriptCursor;
 result=d_021B6A40[q[0]](p,q);
 if(result) {
  q=*(int * *)&((struct CdemoState *)p)->scriptCursor;
  *(int * *)&((struct CdemoState *)p)->scriptCursor=q+d_021B6A90[q[0]];
 }
 return result;
}

int CDEMO_SCENE_CmdCount(char *p,int *q) {
 if(((struct CdemoState *)p)->count==q[1]) { ((struct CdemoState *)p)->count=0; return 2; }
 ((struct CdemoState *)p)->count=((struct CdemoState *)p)->count+1; return 0;
}

int CDEMO_SCENE_CmdStartWipe0(int a, int *q)
{
    CDEMO_WIPE_StartFadeOut((char *)a, q[1], q[2], 5);
    return 1;
}

int CDEMO_SCENE_CmdStartWipe1(int a, int *q)
{
    CDEMO_WIPE_StartFadeIn((char *)a, q[1], q[2], 5);
    return 1;
}

int CDEMO_SCENE_CmdStartWipe2(int a, int *q)
{
    CDEMO_WIPE_StartFadeOutWhite((char *)a, q[1], q[2], 5);
    return 1;
}

int CDEMO_SCENE_CmdStartWipe3(int a, int *q)
{
    CDEMO_WIPE_StartFadeInWhite((char *)a, q[1], q[2], 5);
    return 1;
}

int CDEMO_SCENE_CmdSetDone(char *p)
{
    ((struct CdemoState *)p)->result = 2;
    ((struct CdemoState *)p)->fade = 5;
    return 2;
}

int CDEMO_SCENE_CmdLoadBg(char *p,const int *q) {
 ARC_UTIL_UploadBgCharFromHandle(((struct CdemoState *)p)->arcHandle,q[2],q[1],0,0,1,127);
 if(q[2]==0) ARC_UTIL_UploadBgPaletteFromHandle(((struct CdemoState *)p)->arcHandle,q[2],q[1],0,0,0,127);
 CDEMO_WIPE_LoadPalette(p,q[1],q[2]); return 1;
}

int CDEMO_SCENE_CmdSetPlaneVisible(int a, int *q)
{
    BG_SYS_SetPlaneVisible((unsigned char)q[1],
                  (unsigned char)q[2]);
    return 1;
}

int CDEMO_SCENE_CmdSetLayerVisible(int a, int *q)
{
    BG_SYS_SetPriority((unsigned char)q[1],
                  (unsigned char)q[2]);
    return 1;
}

int CDEMO_SCENE_CmdSetBlend(char *p, int *q)
{
    if (q[1] == 0) {
        ((struct CdemoState *)p)->blendA0 = q[2];
        ((struct CdemoState *)p)->blendA1 = q[3];
    } else {
        ((struct CdemoState *)p)->blendB0 = q[2];
        ((struct CdemoState *)p)->blendB1 = q[3];
    }
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6831 at 0x021B6A68).
 */
int CDEMO_SCENE_CmdSetBlend2(char *p, int *q)
{
    ((struct CdemoState *)p)->blend2Param0 = q[1];
    ((struct CdemoState *)p)->blend2Param1 = q[2];
    ((struct CdemoState *)p)->result = 3;
    ((struct CdemoState *)p)->fade = 5;
    return 2;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6855 at 0x021B6A6C).
 * volatile: 0x04000050 is a hardware register (REG_BLDCNT).
 */
int CDEMO_SCENE_CmdResetBlend(char *p)
{
    *(volatile unsigned short *)0x04000050 = 0;
    ((struct CdemoState *)p)->blendA0 = 0;
    ((struct CdemoState *)p)->blendA1 = 0;
    ((struct CdemoState *)p)->blendB0 = 0;
    ((struct CdemoState *)p)->blendB1 = 0;
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6879 at 0x021B6A70).
 */
int CDEMO_SCENE_CmdNoop0(void)
{
    return 1;
}

int CDEMO_SCENE_CmdStopBgm(void)
{
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}

/*
 * 12-byte leaf: forwards the second word of the record to GFL_USE_PlayFanfare and
 * returns 1.  The lane enumerator reports 664 bytes because this is the last
 * func_ label in ov179; the disassembly ends at the pop and the rest is data.
 */
int CDEMO_SCENE_CmdPlayFanfare(void *ctx, unsigned int *rec)
{
    GFL_USE_PlayFanfare((unsigned int)rec[1]);
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6895 at 0x021B6A7C).
 */
int CDEMO_SCENE_CmdNoop1(void)
{
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6899 at 0x021B6A80).
 */
int CDEMO_SCENE_CmdNoop2(void)
{
    return 1;
}

/*
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B689D at 0x021B6A84).
 */
int CDEMO_SCENE_CmdNoop3(void)
{
    return 1;
}

int CDEMO_SCENE_CmdReset(char *p)
{
    ((struct CdemoState *)p)->step = 0;
    ((struct CdemoState *)p)->flip = 0;
    ((struct CdemoState *)p)->state = 0;
    ((struct CdemoState *)p)->tick = 0;
    ((struct CdemoState *)p)->accum = 0;
    ((struct CdemoState *)p)->result = 4;
    return 2;
}

int CDEMO_SCENE_CmdNoop4(void)
{
    return 1;
}
