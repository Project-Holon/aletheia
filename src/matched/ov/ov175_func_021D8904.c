/*
 * function: WIFIBATTLEMATCH_NET_CompStepG
 * address: 0x021D8904
 * packet: pkt_ov175_021D8904
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_021E8AC0 0x021E8AC0 thumb ov177
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepH 0x021D8BC4 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepI 0x021D8CF0 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompCleanup 0x021D9064 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupMatchReport 0x021DA5B0 thumb ov175
 *   WIFIBATTLEMATCH_NET_ScProcess 0x021DA6B8 thumb ov175
 *   WIFIBATTLEMATCH_NET_GetReportState 0x021DADAC thumb ov175
 *   WIFIBATTLEMATCH_NET_DisconnectWifi 0x021DA36C thumb ov175
 *   WIFIBATTLEMATCH_NET_ClearCancelFlag 0x021DA384 thumb ov175
 *   WIFIBATTLEMATCH_NET_StopMatchmaking 0x021DA390 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupGdbUpload 0x021DBC04 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbUpdateRecord 0x021DBDAC thumb ov175
 *   DWC_RAPCOMMON_CreateSubHeap 0x02156E30 thumb ov009
 *   DWC_RAPCOMMON_SetHeapTag 0x02156F50 thumb ov009
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb ov009
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   MISC_SAVEDATA_InsertRecentValue 0x0200ED54 thumb
 *   func_02008530 0x02008530 thumb
 */
#include "../include/Obj00477.h"
#include "../include/Obj02512.h"
#include "../include/Obj24270.h"
#include "../include/Obj24273.h"
#include "../include/Obj24274.h"
#include "../include/Obj24276.h"
typedef unsigned long u32;
typedef struct { u32 w[20]; } Rec80;
typedef struct { Rec80 data; u32 last; } Rec84;
struct L0200ED54;
typedef unsigned char  u8;
extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AB4(u32,u32);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8AB8(u32);
struct Big;
struct Record;
extern void func_021E8AA8(int a);
extern int func_021E8844(const int *p);
extern void func_021E8AC0(int,int);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *,void *,void *);
extern void WIFIBATTLEMATCH_NET_CompStepH(int *a, int *state, char *ctx);
extern void WIFIBATTLEMATCH_NET_CompStepI(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void DWC_RAPCOMMON_CreateSubHeap(u32 a, u32 b, u32 c, u32 d);
extern void DWC_RAPCOMMON_SetHeapTag(int);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern void WIFIBATTLEMATCH_NET_SetupMatchReport(char *,int,int,u32,u32 *,u32);
extern int WIFIBATTLEMATCH_NET_ScProcess(char *p, u32 *out);
extern u32 WIFIBATTLEMATCH_NET_GetReportState(u8 *p);
extern void WIFIBATTLEMATCH_NET_DisconnectWifi(char *),WIFIBATTLEMATCH_NET_ClearCancelFlag(char *);
extern int WIFIBATTLEMATCH_NET_StopMatchmaking(char *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MISC_SAVEDATA_GetBlock44(void *);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *,unsigned int);
extern void MI_CpuFill8(void *,int,unsigned);
extern void WIFIBATTLEMATCH_NET_SetupGdbUpload(u8 *p, u32 mode, struct Record *src);
extern int WIFIBATTLEMATCH_NET_GdbUpdateRecord(char *);
void WIFIBATTLEMATCH_NET_CompStepG(u32 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00477 *)p)->f104;
    Rec84 rec;
    void *list;
    int v;
    switch(*state) {
    case 0:if(((struct Obj02512 *)q)->fC==2 && ((struct Obj00477 *)p)->f100==0) func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepH);
        else {
            ((struct Obj00477 *)p)->f100=0;
            GFL_HEAP_CreateChildHeap(1,134,0x60000);
            DWC_RAPCOMMON_CreateSubHeap(9,0x60000,1000,134);
            DWC_RAPCOMMON_SetHeapTag(134);*state=1;
        }break;
    case 1:func_021E8738((int *)(((struct Obj00477 *)p)->f2C),((struct Obj00477 *)p)->f14,70,2);
        *state=13;func_021E8AB4(sys,2);break;
    case 2:WIFIBATTLEMATCH_NET_SetupMatchReport(*(char * *)&((struct Obj00477 *)p)->f34,1,0,(*(u32 **)(q+8))[1],*(u32 * *)&((struct Obj02512 *)q)->f2C,((struct Obj02512 *)q)->fC==2);
        ((struct Obj00477 *)p)->fF8=0;((struct Obj00477 *)p)->fF4=0;*state=3;break;
    case 3:
        if(((struct Obj00477 *)p)->fF8==0) {
            ((struct Obj00477 *)p)->fF8=WIFIBATTLEMATCH_NET_ScProcess(((struct Obj00477 *)p)->f34,(u32 *)(p+244));
            if(((struct Obj00477 *)p)->fF8!=0 && ((struct Obj00477 *)p)->fF4!=0)
                func_021E8AC0(**(int * *)&((struct Obj02512 *)q)->f8,**(int * *)&((struct Obj02512 *)q)->f2C);
        }
        if(((struct Obj00477 *)p)->fF8==1) {
            ((struct Obj24270 *)(*(char * *)&((struct Obj02512 *)q)->f2C))->f14=WIFIBATTLEMATCH_NET_GetReportState((u8 *)(*(char * *)&((struct Obj00477 *)p)->f34));*state=4;
        }
        if(((struct Obj00477 *)p)->fF8!=0) {
            switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00477 *)p)->f34,0,(void *)1)) {
            case 1:WIFIBATTLEMATCH_NET_DisconnectWifi(*(char * *)&((struct Obj00477 *)p)->f34);
            case 2:case 4:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);DWC_RAPCOMMON_DestroySubHeap();break;
            }
        }break;
    case 4:DWC_RAPCOMMON_DestroySubHeap();
        if(((struct Obj02512 *)q)->fC==2)func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepH);
        else *state=5;break;
    case 5:list=MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj02512 *)q)->f8));
        MISC_SAVEDATA_InsertRecentValue(list,func_02008530(((struct Obj02512 *)q)->f18));
        WIFIBATTLEMATCH_NET_ClearCancelFlag(*(char * *)&((struct Obj00477 *)p)->f34);*state=6;break;
    case 6:if(WIFIBATTLEMATCH_NET_StopMatchmaking(*(char * *)&((struct Obj00477 *)p)->f34)) *state=7;
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00477 *)p)->f34,0,(void *)1)) {
        case 1:case 4:*state=7;break;
        case 2:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 7:if(**(u32 * *)&((struct Obj02512 *)q)->f20==0) {
        MI_CpuFill8(&rec,0,84);
        rec.data=**(Rec80 * *)&((struct Obj24273 *)(*(char * *)&((struct Obj00477 *)p)->f104))->f24;
        rec.last=**(u32 * *)&((struct Obj24274 *)(*(char * *)&((struct Obj00477 *)p)->f104))->f28;
        WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)(*(char * *)&((struct Obj00477 *)p)->f34),3,(struct Record *)(&rec));*state=8;
        }break;
    case 8:v=WIFIBATTLEMATCH_NET_GdbUpdateRecord(*(char * *)&((struct Obj00477 *)p)->f34);
        if(v==1) {
            **(u32 * *)&((struct Obj24276 *)(*(char * *)&((struct Obj00477 *)p)->f104))->f20=1800;*state=9;
        }
        if(v!=0) {
            switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00477 *)p)->f34,0,0)) {
            case 1:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepI);break;
            case 2:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
            }
        }break;
    case 9:func_021E8738((int *)(((struct Obj00477 *)p)->f2C),((struct Obj00477 *)p)->f14,88,1);
        *state=13;func_021E8AB4(sys,10);break;
    case 10:((struct Obj02512 *)q)->f4=2;func_021E8AA8(sys);break;
    case 13:if(func_021E8844((const int *)(((struct Obj00477 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}
