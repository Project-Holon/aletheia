/*
 * function: POKETRADE_NEGO_StepPollMonCheck
 * address: 0x021DEF1C
 * packet: pkt_ov119_021DEF1C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Nested success tests share the normal callback after the inner
 * guards. The bank allocation reads p+0x5f4 directly; the name allocation
 * reads the saved heap pointer, reproducing the original two load forms.
 * interface: 02019B58 receives the visibly loaded record pointer: its
 * empty 020185F0 call preserves r0 for 02019B64, which reads that input.
 * symbols:
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_RecordList_GetCount 0x021B99F0 thumb ov114
 *   NHTTP_RAP_RecordList_GetValue 0x021B99F4 thumb ov114
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   POKETRADE_PROC_IsMonValid 0x021D89EC thumb ov119
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   MAIL_Create 0x02008F08 thumb
 *   func_02008F88 0x02008F88 thumb
 *   func_02019B58 0x02019B58 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepStartMonCheck 0x021DF0B8 thumb ov119
 *   POKETRADE_NEGO_StepSendCheckResult 0x021DEEA8 thumb ov119
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb ov009
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 */
#include "../include/Obj01927.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int NHTTP_RAP_GetResultCode(u8 *);
extern int NHTTP_RAP_PollConnection(u8 *);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *);
extern int NHTTP_RAP_RecordList_GetCount(u8 *p);
extern u32 NHTTP_RAP_RecordList_GetValue(u32 p, u32 i);
extern void NHTTP_RAP_DeleteConnection(u8 *);
extern void NHTTP_RAP_FreePostData(u8 *);
extern void NHTTP_RAP_Destroy(u8 *);
struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
extern int POKETRADE_PROC_IsMonValid(const u8 *p);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern u32 FILE_UTIL_Check136C(u16);
extern void *MAIL_Create(int);
extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
extern void func_02019B58(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepStartMonCheck(char *p);
extern void POKETRADE_NEGO_StepSendCheckResult(void *);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern void DWC_RAP_SetErrorCallback(int a0, int a1);
void POKETRADE_NEGO_StepPollMonCheck(u8 *p)
{
    int status, result, i, off1, off2;
    u8 n=0, error;
    u8 *data;
    const u16 *heap;
    void *mon, *bank, *text, *name;
    u32 value;
    status=NHTTP_RAP_GetResultCode(*(u8 * *)&((struct Obj01927 *)p)->f0);
    result=NHTTP_RAP_PollConnection(*(u8 * *)&((struct Obj01927 *)p)->f0);
    if(result==0) {
    if(status==200) {
        data=NHTTP_RAP_GetRecvBuffer(*(u8 * *)&((struct Obj01927 *)p)->f0);
        p[0x11e6]=NHTTP_RAP_RecordList_GetCount(data);
        if(p[0x11e6]==1) {
            off1=0x109a;
            if(*(u16 *)(p+off1)==0) {
                i=n;
                heap=(const u16 *)(p+0x5f4);
                off2=off1;
                off2-=0xb6;
                off1-=0xb6;
                do {
                    if(POKETRADE_PROC_IsMonValid(*(void **)(p+i*4+off1))) {
                        mon=*(void **)(p+i*4+off2);
                        if(NHTTP_RAP_RecordList_GetValue((u32)data,n)) {
                            value=POKE_TOOL_GetPartyValue(mon,6,0);
                            bank=func_02045B38(0,2,81,((struct Obj01927 *)p)->f5F4);
                            text=func_02045EC0(bank,15);
                            MSGDATA_Delete(bank);
                            if(FILE_UTIL_Check136C(value)) {
                                name=MAIL_Create(*heap);
                                POKE_TOOL_GetPartyValue(mon,167,(u32)name);
                                func_02008F88(name,STRBUF_GetChars(text));
                                POKE_TOOL_SetPartyValue(mon,167,(u32)name);
                                func_020307B0(name);
                            }
                            func_02019B58(mon);
                            POKE_TOOL_SetPartyValue(mon,142,(u32)STRBUF_GetChars(text));
                            STRBUF_Delete(text);
                        }
                        n++;
                    }
                    i++;
                } while(i<3);
                ((struct Obj01927 *)p)->f109A=1;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepStartMonCheck);
                goto cleanup;
            }
        }
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendCheckResult);
    } else goto failed;
    } else goto failed;
    goto cleanup;
failed:
    {
        if(result==15 || status==200) return;
        switch(status) {
        case 400: error=240; break;
        case 401: error=241; break;
        case 408: error=242; break;
        default: error=255; break;
        }
        p[0x11e6]=error;
        NHTTP_RAP_DeleteConnection(*(u8 * *)&((struct Obj01927 *)p)->f0);
    }
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendCheckResult);
cleanup:
    if(*(u8 * *)&((struct Obj01927 *)p)->f0) {
        NHTTP_RAP_FreePostData(*(u8 * *)&((struct Obj01927 *)p)->f0);
        NHTTP_RAP_Destroy(*(u8 * *)&((struct Obj01927 *)p)->f0);
        *(u8 * *)&((struct Obj01927 *)p)->f0=0;
        DWC_RAPCOMMON_DestroySubHeap();
        DWC_RAP_SetErrorCallback(0,0);
    }
}
