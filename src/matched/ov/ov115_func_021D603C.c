/*
 * function: WIFILOGIN_MSG_CreateWork
 * address: 0x021D603C
 * packet: pkt_ov115_021D603C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFILOGIN_DISP_CreateDisplay 0x021D4D38 thumb ov115
 *   WIFILOGIN_MSG_Create 0x021D5984 thumb ov115
 *   WIFILOGIN_MSG_RunStep 0x021D6134 thumb ov115
 *   WIFILOGIN_MSG_StepWipe 0x021D6150 thumb ov115
 *   WIFILOGIN_MSG_ShowMessage 0x021D5CCC thumb ov115
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 */
#include "../include/Obj03766.h"
#include "../include/Obj03767.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { FALSE, TRUE } BOOL;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u8 *WIFILOGIN_DISP_CreateDisplay(u16 heap, u32 mode, int a2);
extern u8 *WIFILOGIN_MSG_Create(u32 heap, u32 bank, u32 mode);
extern void WIFILOGIN_MSG_RunStep(void *a0, int a1, int a2);
extern void WIFILOGIN_MSG_StepWipe(u8 *p);
extern void WIFILOGIN_MSG_ShowMessage(u8 *p, u32 n);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
int WIFILOGIN_MSG_CreateWork(void *ctx,int unused,u8 *q) {
    u8 *p;
    BOOL flag;
    GFL_HEAP_CreateChildHeap(1,121,0x18000);
    p=PROCSYS_AllocProcWork(ctx,32,121);
    MI_CpuFill8(p,0,32);
    *(u8 * *)&((struct Obj03766 *)p)->f10=q;
    ((struct Obj03766 *)p)->f14=121;
    if(((struct Obj03767 *)q)->f10==0) ((struct Obj03767 *)q)->f10=6;
    ((struct Obj03766 *)p)->f4=WIFILOGIN_DISP_CreateDisplay(((struct Obj03766 *)p)->f14,*(int *)&((struct Obj03767 *)q)->f4,((struct Obj03767 *)q)->f8);
    ((struct Obj03766 *)p)->f8=WIFILOGIN_MSG_Create(((struct Obj03766 *)p)->f14,232,((struct Obj03767 *)q)->f8);
    WIFILOGIN_MSG_RunStep(p,(int)((void (*)(void))WIFILOGIN_MSG_StepWipe),173);
    if(((struct Obj03767 *)q)->f4==0) {
        WIFILOGIN_MSG_ShowMessage(((struct Obj03766 *)p)->f8,36);
        if(((struct Obj03767 *)q)->fC==0) GFL_USE_CancelChangeAndPlayBgm(1153,65535);
    }
    if(*(u32 *)&((struct Obj03767 *)q)->f8==0) flag=FALSE; else flag=TRUE;
    GFL_NET_RestartWithDefaultTimeout(flag,((struct Obj03766 *)p)->f14);
    return 1;
}
