/*
 * file:     cdemo_scene.c
 * unit:     yes
 * function: CDEMO_SCENE_Create, CDEMO_SCENE_Destroy, CDEMO_SCENE_GetResult, CDEMO_SCENE_ReturnThree, CDEMO_SCENE_RunCommands, CDEMO_SCENE_Step, CDEMO_SCENE_LoadScreenBlock, CDEMO_SCENE_DispatchCommand, CDEMO_SCENE_CmdCount, CDEMO_SCENE_CmdStartWipe0, CDEMO_SCENE_CmdStartWipe1, CDEMO_SCENE_CmdStartWipe2, CDEMO_SCENE_CmdStartWipe3, CDEMO_SCENE_CmdSetDone, CDEMO_SCENE_CmdLoadBg, CDEMO_SCENE_CmdSetVram, CDEMO_SCENE_CmdSetBg, CDEMO_SCENE_CmdSetBlend, CDEMO_SCENE_CmdSetBlend2, CDEMO_SCENE_CmdResetBlend, CDEMO_SCENE_CmdNoop0, CDEMO_SCENE_CmdStopBgm, CDEMO_SCENE_CmdPlayFanfare, CDEMO_SCENE_CmdNoop1, CDEMO_SCENE_CmdNoop2, CDEMO_SCENE_CmdNoop3, CDEMO_SCENE_CmdReset, CDEMO_SCENE_CmdNoop4
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
 *   func_020490F4 0x020490F4 arm
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
 *   func_020870D0  0x020870D0  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   data_021B6A1C  0x021B6A1C  data  ov179
 *   _ull_mul       0x0209C054  arm
 *   _ll_udiv       0x0209C00C  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   func_0207ECF0  0x0207ECF0  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021B6A40 0x021B6A40 data a4
 *   d_021B6A90 0x021B6A90 data a4
 *   CDEMO_WIPE_StartFadeIn  0x021B62B8  thumb  ov179
 *   CDEMO_WIPE_StartFadeOutWhite  0x021B62E0  thumb  ov179
 *   CDEMO_WIPE_StartFadeInWhite  0x021B630C  thumb  ov179
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   CDEMO_WIPE_LoadPalette 0x021B6338 thumb ov179
 *   func_02040588  0x02040588  arm
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb  arm9
 */
#include "cdemo_types.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {unsigned short value;char pad[10];} CdemoEntry;

typedef unsigned char u8;

typedef unsigned long long u64;

typedef struct {
    u16 unk0;
    u16 count;
    int a;
    int b;
} Entry_021B64E0;

extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void CDEMO_MAIN_SetupVram(void);
extern void CDEMO_MAIN_SetupScreen(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern void CDEMO_MAIN_SetScript(char *);
extern void CDEMO_MAIN_StartTask(int *);
extern void CDEMO_WIPE_StartFadeOut(char *,unsigned,unsigned,unsigned);
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void CDEMO_MAIN_StopTask(char *);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CDEMO_MAIN_Noop(char *);
extern void CDEMO_MAIN_HidePlane(void);
extern u64 func_020870D0(void);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern void DWCi_ScreenDC_FlushRange(int, int);
extern void GX_LoadBG2Scr(int, int, int);
extern void func_0207ECF0(int, int, int);
extern u32 func_020307B0(void *p);
extern void CDEMO_WIPE_StartFadeIn(char *p, u32 a, u32 b, u32 c);
extern void CDEMO_WIPE_StartFadeOutWhite(char *p, u32 a, u32 b, u32 c);
extern void CDEMO_WIPE_StartFadeInWhite(char *p, u32 a, u32 b, u32 c);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void CDEMO_WIPE_LoadPalette(void *,int,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GFL_USE_PlayFanfare(void *arg);
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
int CDEMO_SCENE_CmdSetVram(int a, int *q);
int CDEMO_SCENE_CmdSetBg(int a, int *q);
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
extern const Entry_021B64E0 data_021B6A1C[];
extern const unsigned d_021B6A90[];


int CDEMO_SCENE_Create(char *p)
{
 BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 BG_SYS_SetLcdSwap(1);CDEMO_MAIN_SetupVram();CDEMO_MAIN_SetupScreen(p);
 ((struct CdemoState *)p)->arcHandle=func_020490F4(d_021B6A1C[((struct CdemoState *)p)->script->index].value,0x7F);
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
 * const: that is what lets the e->b load schedule ahead of the count store.
 */
int CDEMO_SCENE_Step(char *p)
{
    const Entry_021B64E0 *e = &data_021B6A1C[((struct CdemoState *)p)->script->index];

    if (((struct CdemoState *)p)->tick == 0) {
        ((struct CdemoState *)p)->tick = func_020870D0();
    } else {
        u64 now = func_020870D0();
        ((struct CdemoState *)p)->accum += (now - ((struct CdemoState *)p)->tick) * 64000 / 33514;
        ((struct CdemoState *)p)->tick = now;
        if (((struct CdemoState *)p)->accum < 66667)
            return 4;
        ((struct CdemoState *)p)->accum -= 66667;
    }

    switch (((struct CdemoState *)p)->state) {
    case 0:
        CDEMO_SCENE_LoadScreenBlock(((struct CdemoState *)p)->arcHandle, ((struct CdemoState *)p)->step, e->b, e->a, 0);
        (((struct CdemoState *)p)->step)++;
        CDEMO_SCENE_LoadScreenBlock(((struct CdemoState *)p)->arcHandle, ((struct CdemoState *)p)->step, e->b, e->a, 1);
        (((struct CdemoState *)p)->step)++;
        BG_SYS_SetVisibleLayer((u8)2, (u8)0);
        BG_SYS_SetVisibleLayer((u8)3, (u8)1);
        ((struct CdemoState *)p)->state = 1;
        break;
    case 1:
        BG_SYS_SetVisibleLayer((u8)((((struct CdemoState *)p)->flip ^ 1) + 2), (u8)0);
        BG_SYS_SetVisibleLayer((u8)(((struct CdemoState *)p)->flip + 2), (u8)1);
        CDEMO_SCENE_LoadScreenBlock(((struct CdemoState *)p)->arcHandle, ((struct CdemoState *)p)->step, e->b, e->a, ((struct CdemoState *)p)->flip);
        (((struct CdemoState *)p)->step)++;
        if (((struct CdemoState *)p)->step >= e->count) {
            ((struct CdemoState *)p)->state = 2;
        } else {
            ((struct CdemoState *)p)->flip ^= 1;
        }
        break;
    case 2:
        BG_SYS_SetVisibleLayer((u8)(((struct CdemoState *)p)->flip + 2), (u8)0);
        BG_SYS_SetVisibleLayer((u8)((((struct CdemoState *)p)->flip ^ 1) + 2), (u8)1);
        ((struct CdemoState *)p)->state = 3;
        break;
    case 3:
        return 5;
    }
    return 4;
}



void CDEMO_SCENE_LoadScreenBlock(void *a, int b, int c, int d, int e)
{
    int t = (int)ARC_UTIL_LoadHandleMember(a, b, 1, 0x807f);

    DWCi_ScreenDC_FlushRange(t, d);
    if (e == 0) {
        GX_LoadBG2Scr(t, c, d);
    } else {
        func_0207ECF0(t, c, d);
    }
    func_020307B0((void *)t);
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
 func_02049658(((struct CdemoState *)p)->arcHandle,q[2],q[1],0,0,1,127);
 if(q[2]==0) func_020498F4(((struct CdemoState *)p)->arcHandle,q[2],q[1],0,0,0,127);
 CDEMO_WIPE_LoadPalette(p,q[1],q[2]); return 1;
}



int CDEMO_SCENE_CmdSetVram(int a, int *q)
{
    func_02040588((unsigned char)q[1],
                  (unsigned char)q[2]);
    return 1;
}



int CDEMO_SCENE_CmdSetBg(int a, int *q)
{
    BG_SYS_SetVisibleLayer((unsigned char)q[1],
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
    ((struct CdemoState *)p)->field6034 = q[1];
    ((struct CdemoState *)p)->field6038 = q[2];
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
    GFL_USE_PlayFanfare((void *)rec[1]);
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
