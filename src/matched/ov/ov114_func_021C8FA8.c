/*
 * function: DPW_BT_Main
 * address: 0x021C8FA8
 * packet: pkt_ov114_021C8FA8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * lang: c99
 * status: EXACT
 * residual: none (EXACT in --lang c99 and --lang c, 1044 bytes).
 * pass 2 2026-10-06 P2L56: EXACT without the fixed-address cast. Same shape as the sibling
 *   021C7C1C: no Ctx pointer local, every access names the global (gDpwBtWork.state, .result,
 *   .hdr.code, .buf), and each 2-byte header copy is memcpy(&gDpwBtWork.hdr,
 *   DWCi_EncSessionGetResponse(&len), 2). The member address gets its own pool word (the
 *   d_021D421C label, which is gDpwBtWork + 0x198). memcpy into the separate d_021D421C object
 *   with direct access elsewhere is also EXACT; the member form is kept as it names one object.
 * History: G7L2 (2026-10-05) matched only with ctx = (Ctx *)0x021D4084 (not accepted: a link
 *   address in source); memcpy with a ctx pointer to gDpwBtWork was 52 B / 32 B off because the
 *   hdr.code read was hoisted above the byte stores.
 * DWC encryption-session poll: even states 2..10 run DWCi_EncSessionProcess; on 1 (error) or
 *   8 (done) move to state 12 and map the response to a result; odd states 3..11 cancel (-4).
 * symbols:
 *   gDpwBtWork 0x021D4084 data a4
 *   DWCi_EncSessionProcess 0x021CA0A0 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 *   DWCi_EncSessionGetResponse 0x021CA228 arm ov114
 *   DWC_GetLastErrorEx 0x02059E38 arm
 *   DPW_BT_ConvertDwcError 0x021C97E0 arm ov114
 *   func_02092344 0x02092344 arm
 */
#include "../../matched/arm9_sdk/libc/string.h"
typedef unsigned char u8;
typedef unsigned long u32;
typedef struct { u8 code,sub; } Hdr;
typedef struct { Hdr h[4]; } Payload;
typedef enum { STATE_IDLE=0,STATE_END=12 } State;
typedef struct {
    State state;
    int result;
    u8 pad[0x198-8];
    Hdr hdr;
    u8 pad19a[2];
    u8 *buf;
} Ctx;
extern Ctx gDpwBtWork;
extern int DWCi_EncSessionProcess(void);
extern void DWCi_EncSessionShutdown(void);
extern const void *DWCi_EncSessionGetResponse(u32 *);
extern int DWC_GetLastErrorEx(int *,int *);
extern int DPW_BT_ConvertDwcError(unsigned);
extern void *func_02092344(void *,const void *,unsigned int);
void DPW_BT_Main(void)
{
    u32 len;
    int code,type;
    const u8 *resp;
    switch(gDpwBtWork.state) {
    case 2:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            gDpwBtWork.state=12;
            DWC_GetLastErrorEx(&code,&type);
            gDpwBtWork.result=DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            gDpwBtWork.state=12;
            memcpy(&gDpwBtWork.hdr,DWCi_EncSessionGetResponse(&len),2);
            if(len!=0) gDpwBtWork.result=gDpwBtWork.hdr.code;
            else gDpwBtWork.result=-2;
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 4:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            gDpwBtWork.state=12;
            DWC_GetLastErrorEx(&code,&type);
            gDpwBtWork.result=DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            gDpwBtWork.state=12;
            resp=(const u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(gDpwBtWork.buf,resp,0xa8c);
            if(len==0xa8c) gDpwBtWork.result=0;
            else {
                switch(gDpwBtWork.buf[0]) {
                case 2: gDpwBtWork.result=-3; break;
                case 5: gDpwBtWork.result=-2; break;
                default: gDpwBtWork.result=-5; break;
                }
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 6:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            gDpwBtWork.state=12;
            DWC_GetLastErrorEx(&code,&type);
            gDpwBtWork.result=DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            gDpwBtWork.state=12;
            memcpy(&gDpwBtWork.hdr,DWCi_EncSessionGetResponse(&len),2);
            switch(gDpwBtWork.hdr.code) {
            case 1: gDpwBtWork.result=0; break;
            case 2: gDpwBtWork.result=-3; break;
            case 4: gDpwBtWork.result=-1; break;
            case 5: gDpwBtWork.result=-2; break;
            default: gDpwBtWork.result=-5; break;
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 8:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            gDpwBtWork.state=12;
            DWC_GetLastErrorEx(&code,&type);
            gDpwBtWork.result=DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            gDpwBtWork.state=12;
            memcpy(&gDpwBtWork.hdr,DWCi_EncSessionGetResponse(&len),2);
            switch(gDpwBtWork.hdr.code) {
            case 1: gDpwBtWork.result=0; break;
            case 3: gDpwBtWork.result=1; break;
            case 4: gDpwBtWork.result=2; break;
            case 5: gDpwBtWork.result=-2; break;
            default: gDpwBtWork.result=-5; break;
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 10:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            gDpwBtWork.state=12;
            DWC_GetLastErrorEx(&code,&type);
            gDpwBtWork.result=DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            gDpwBtWork.state=12;
            resp=(const u8 *)DWCi_EncSessionGetResponse(&len);
            *(Payload *)gDpwBtWork.buf=*(Payload *)resp;
            if(len==8) gDpwBtWork.result=0;
            else {
                switch(gDpwBtWork.buf[0]) {
                case 1: gDpwBtWork.result=0; break;
                case 3: gDpwBtWork.result=1; break;
                case 4: gDpwBtWork.result=2; break;
                case 5: gDpwBtWork.result=-2; break;
                default: gDpwBtWork.result=-5; break;
                }
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 3: case 5: case 7: case 9: case 11:
        gDpwBtWork.state=12; gDpwBtWork.result=-4;
        DWCi_EncSessionShutdown(); return;
    case 0: case 1: case 12: break;
    }
}
