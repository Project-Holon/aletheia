/*
 * function: WIFIBATTLEMATCH_NET_GdbCreateRecord
 * address: 0x021DBFB4
 * packet: pkt_ov175_021DBFB4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: PC-relative pool audit binds source-line constants 125c/126f/127b to the success/cancel-error/timeout calls, fixing the prior three concrete pool bytes.
 * symbols:
 *   DWC_GdbInitialize 0x021E10CC arm ov175
 *   DWC_GdbCreateRecordAsync 0x021E1464 arm ov175
 *   DWC_GdbProcess 0x021E1414 arm ov175
 *   DWC_GdbGetState 0x021E1434 arm ov175
 *   DWC_GdbGetAsyncResult 0x021E1454 arm ov175
 *   DWC_GdbCancelRequest 0x021E11F0 arm ov175
 *   WIFIBATTLEMATCH_NET_SetResultA 0x021DCE40 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetErrorA 0x021DCE08 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetResultB 0x021DCE48 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetResultC 0x021DCE50 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbShutdown 0x021DB6A0 thumb ov175
 *   d_021E2F1C 0x021E2F1C data a4
 * prototype: Setters retain caller-loaded line in r2; shutdown receives p where the caller visibly prepares r0.
 */
#include "../include/Obj00629.h"
typedef unsigned long u32;
typedef struct DWCstAccUserData DWCstAccUserData;
extern int DWC_GdbInitialize(int,DWCstAccUserData *,int);
extern int DWC_GdbCreateRecordAsync(char *,void *,int,int *);
extern void DWC_GdbProcess(void);
extern int DWC_GdbGetState(void);
extern u32 DWC_GdbGetAsyncResult(void);
extern int DWC_GdbCancelRequest(void);
extern void WIFIBATTLEMATCH_NET_SetResultA(char *,u32,int);
extern void WIFIBATTLEMATCH_NET_SetErrorA(char *,u32,int);
extern void WIFIBATTLEMATCH_NET_SetResultB(char *,u32,int);
extern void WIFIBATTLEMATCH_NET_SetResultC(char *,u32,int);
extern void WIFIBATTLEMATCH_NET_GdbShutdown(char *);
extern const char d_021E2F1C[];
int WIFIBATTLEMATCH_NET_GdbCreateRecord(char *p)
{
    long r;
    switch(((struct Obj00629 *)p)->f12C) {
    case 0:
        r=DWC_GdbInitialize(0xb5f,*(DWCstAccUserData * *)&((struct Obj00629 *)p)->f0,0);
        if(r!=0) {WIFIBATTLEMATCH_NET_SetResultA(p+0x18,r,0x1215);return 2;}
        ((struct Obj00629 *)p)->f12C=1;break;
    case 1:
        r=DWC_GdbCreateRecordAsync((char *)d_021E2F1C,((struct Obj00629 *)p)->f190,((struct Obj00629 *)p)->f198,*(int * *)&((struct Obj00629 *)p)->f1464);
        if(r!=0) {WIFIBATTLEMATCH_NET_SetResultA(p+0x18,r,0x1223);return 2;}
        ((struct Obj00629 *)p)->f1A0=0;((struct Obj00629 *)p)->f12C=2;break;
    case 2:
        if((((struct Obj00629 *)p)->f1A0)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(p+0x18,1,0x122f);((struct Obj00629 *)p)->f12C=4;break;}
        DWC_GdbProcess();r=DWC_GdbGetState();
        if(r==0||r==4) {WIFIBATTLEMATCH_NET_SetResultB(p+0x18,r,0x123b);((struct Obj00629 *)p)->f12C=4;}
        else if(r==1)((struct Obj00629 *)p)->f12C=3;
        break;
    case 3:
        r=DWC_GdbGetAsyncResult();
        if(r==0) {WIFIBATTLEMATCH_NET_SetResultC(p+0x18,r,0x124f);((struct Obj00629 *)p)->f12C=4;}
        else if(r!=1) {WIFIBATTLEMATCH_NET_GdbShutdown(p);WIFIBATTLEMATCH_NET_SetResultC(p+0x18,r,0x1256);return 2;}
        else {
            if(**(u32 * *)&((struct Obj00629 *)p)->f1464==0)WIFIBATTLEMATCH_NET_SetErrorA(p+0x18,2,0x125c);
            WIFIBATTLEMATCH_NET_GdbShutdown(p);return 1;
        }
        break;
    case 4:
        r=DWC_GdbCancelRequest();
        if(r==0) {((struct Obj00629 *)p)->f1A0=0;((struct Obj00629 *)p)->f12C=5;}
        else {WIFIBATTLEMATCH_NET_SetResultA(p+0x18,r,0x126f);WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;}
        break;
    case 5:
        if((((struct Obj00629 *)p)->f1A0)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(p+0x18,1,0x127b);WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;}
        DWC_GdbProcess();r=DWC_GdbGetState();
        if(r==0||r==4) {WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;}
        if(r==1)((struct Obj00629 *)p)->f12C=6;
        break;
    case 6:WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;
    }
    return 0;
}
