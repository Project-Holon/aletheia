/*
 * function: WIFIBATTLEMATCH_NET_GdbUpdateRecord
 * address: 0x021DBDAC
 * packet: pkt_ov175_021DBDAC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: PC-relative slot audit binds error/cancel/timeout lines to 0x11a0,0x11be,0x11ca; fixing source constants removes three pool-byte mismatches.
 * extent: existing matched WIFIBATTLEMATCH_NET_GdbClearRecord.c covers the final16 bytes; keep this504-byte lead alone.
 * symbols:
 *   DWC_GdbInitialize 0x021E10CC arm ov175
 *   DWC_GdbUpdateRecordAsync 0x021E1540 arm ov175
 *   DWC_GdbProcess 0x021E1414 arm ov175
 *   DWC_GdbGetState 0x021E1434 arm ov175
 *   DWC_GdbGetAsyncResult 0x021E1454 arm ov175
 *   DWC_GdbCancelRequest 0x021E11F0 arm ov175
 *   WIFIBATTLEMATCH_NET_SetResultA 0x021DCE40 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetErrorA 0x021DCE08 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetResultB 0x021DCE48 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetResultC 0x021DCE50 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbShutdown 0x021DB6A0 thumb ov175
 *   func_02034714 0x02034714 arm
 *   d_021E2EF8 0x021E2EF8 data a4
 *   d_021E2F1C 0x021E2F1C data a4
 * prototype: Setters retain caller-loaded line in r2; shutdown receives live entry r0 in case 4 despite its unused parameter.
 */
#include "../include/Obj00999.h"
typedef unsigned long u32;
typedef struct DWCstAccUserData DWCstAccUserData;
extern int DWC_GdbInitialize(int,DWCstAccUserData *,int);
extern int DWC_GdbUpdateRecordAsync(char *,int,void *,int);
extern void DWC_GdbProcess(void);
extern int DWC_GdbGetState(void);
extern u32 DWC_GdbGetAsyncResult(void);
extern int DWC_GdbCancelRequest(void);
extern void WIFIBATTLEMATCH_NET_SetResultA(char *,u32,int);
extern void WIFIBATTLEMATCH_NET_SetErrorA(char *,u32,int);
extern void WIFIBATTLEMATCH_NET_SetResultB(char *,u32,int);
extern void WIFIBATTLEMATCH_NET_SetResultC(char *,u32,int);
extern void WIFIBATTLEMATCH_NET_GdbShutdown(char *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021E2EF8[],d_021E2F1C[];
int WIFIBATTLEMATCH_NET_GdbUpdateRecord(char *p)
{
    long r;
    switch(((struct Obj00999 *)p)->f12C) {
    case 0:
        r=DWC_GdbInitialize(0xb5f,*(DWCstAccUserData * *)&((struct Obj00999 *)p)->f0,0);
        if(r!=0) {WIFIBATTLEMATCH_NET_SetResultA(p+0x18,r,0x1161);WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;}
        ((struct Obj00999 *)p)->f12C=1;break;
    case 1:
        if(((struct Obj00999 *)p)->f198>=0x26)func_02034714(d_021E2EF8,0,d_021E2EF8);
        r=DWC_GdbUpdateRecordAsync((char *)d_021E2F1C,**(int * *)&((struct Obj00999 *)p)->f1464,((struct Obj00999 *)p)->f190,((struct Obj00999 *)p)->f198);
        if(r!=0) {WIFIBATTLEMATCH_NET_SetResultA(p+0x18,r,0x116e);WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;}
        ((struct Obj00999 *)p)->f1A0=0;((struct Obj00999 *)p)->f12C=2;break;
    case 2:
        if((((struct Obj00999 *)p)->f1A0)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(p+0x18,1,0x117b);((struct Obj00999 *)p)->f12C=6;break;}
        DWC_GdbProcess();r=DWC_GdbGetState();
        if(r==0||r==4) {WIFIBATTLEMATCH_NET_SetResultB(p+0x18,r,0x1186);((struct Obj00999 *)p)->f12C=6;}
        else if(r==1)((struct Obj00999 *)p)->f12C=3;
        break;
    case 3:
        r=DWC_GdbGetAsyncResult();
        if(r==0) {WIFIBATTLEMATCH_NET_SetResultC(p+0x18,r,0x1199);((struct Obj00999 *)p)->f12C=6;}
        else if(r!=1) {WIFIBATTLEMATCH_NET_GdbShutdown(p);WIFIBATTLEMATCH_NET_SetResultC(p+0x18,r,0x11a0);return 2;}
        else ((struct Obj00999 *)p)->f12C=4;
        break;
    case 4:
        WIFIBATTLEMATCH_NET_GdbShutdown(p);((struct Obj00999 *)p)->f12C=5;
    case 5:return 1;
    case 6:
        r=DWC_GdbCancelRequest();
        if(r==0) {((struct Obj00999 *)p)->f1A0=0;((struct Obj00999 *)p)->f12C=7;}
        else {WIFIBATTLEMATCH_NET_SetResultA(p+0x18,r,0x11be);WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;}
        break;
    case 7:
        if((((struct Obj00999 *)p)->f1A0)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(p+0x18,1,0x11ca);WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;}
        DWC_GdbProcess();r=DWC_GdbGetState();
        if(r==0||r==4) {WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;}
        if(r==1)((struct Obj00999 *)p)->f12C=8;
        break;
    case 8:WIFIBATTLEMATCH_NET_GdbShutdown(p);return 2;
    }
    return 0;
}
