/*
 * function: WIFI_BSUBWAY_PollHttpRequest
 * address: 0x021D6EC4
 * packet: pkt_ov116_021D6EC4
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D700E follow the epilogue.
 * evidence: ov114 labelled 97F4/99F0/99F4/9A14 bodies read the
 * declared pointer/index inputs; 99F4 reconstructs a full32-bit value.
 * Original keeps field loads and repeated per-call object reloads.
 * symbols:
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   WIFI_BSUBWAY_SetHttpError 0x021D7250 thumb ov116
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   WIFI_BSUBWAY_TickUploadTimeout 0x021D7260 thumb ov116
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_RecordList_GetCount 0x021B99F0 thumb ov114
 *   NHTTP_RAP_RecordList_GetRecord 0x021B9A14 thumb ov114
 *   MI_CpuCopy8 0x02082D44 arm
 *   NHTTP_RAP_RecordList_GetValue 0x021B99F4 thumb ov114
 *   WIFI_BSUBWAY_SetDownloadResult 0x021D724C thumb ov116
 *   WIFI_BSUBWAY_ReadRecordUnits 0x021D7010 thumb ov116
 */
#include "../include/Obj01925.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int NHTTP_RAP_GetResultCode(u8 *);
extern int NHTTP_RAP_PollConnection(u8 *);
extern void WIFI_BSUBWAY_SetHttpError(u8 *, u32);
extern void NHTTP_RAP_DeleteConnection(u8 *);
extern void NHTTP_RAP_FreePostData(u8 *);
extern void NHTTP_RAP_Destroy(u8 *);
extern void DWC_RAP_SetErrorCallback(int, int);
extern void WIFI_BSUBWAY_TickUploadTimeout(u8 *);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *);
extern int NHTTP_RAP_RecordList_GetCount(u8 *p);
extern u8 *NHTTP_RAP_RecordList_GetRecord(u8 *p, u32 i);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 NHTTP_RAP_RecordList_GetValue(u32 p, u32 i);
extern void WIFI_BSUBWAY_SetDownloadResult(u8 *, u32);
extern void WIFI_BSUBWAY_ReadRecordUnits(unsigned int a, unsigned int b);
int WIFI_BSUBWAY_PollHttpRequest(u8 *p, u8 *q, int flag)
{
    int result = 0;
    int code, status, all, i;
    u8 *x;
    code = NHTTP_RAP_GetResultCode(*(u8 * *)&((struct Obj01925 *)p)->f168);
    status = NHTTP_RAP_PollConnection(*(u8 * *)&((struct Obj01925 *)p)->f168);
    if (code != 200 && status == 0) {
        WIFI_BSUBWAY_SetHttpError(q, code);
        NHTTP_RAP_DeleteConnection(*(u8 * *)&((struct Obj01925 *)p)->f168);
        NHTTP_RAP_FreePostData(*(u8 * *)&((struct Obj01925 *)p)->f168);
        NHTTP_RAP_Destroy(*(u8 * *)&((struct Obj01925 *)p)->f168);
        *(u8 * *)&((struct Obj01925 *)p)->f168 = 0;
        DWC_RAP_SetErrorCallback(0, 0);
        return 2;
    }
    if (status != 0) {
        WIFI_BSUBWAY_TickUploadTimeout(q);
    } else {
        x = NHTTP_RAP_GetRecvBuffer(*(u8 * *)&((struct Obj01925 *)p)->f168);
        if (NHTTP_RAP_RecordList_GetCount(x) == 0) {
            all = 1;
            MI_CpuCopy8(NHTTP_RAP_RecordList_GetRecord(x, ((struct Obj01925 *)p)->f16C), p + 0x16e, 128);
            for (i = 0; i < ((struct Obj01925 *)p)->f16C; i++) {
                if (NHTTP_RAP_RecordList_GetValue((u32)x, i) != 0) {
                    all = 0;
                    if (flag != 0) WIFI_BSUBWAY_SetDownloadResult(q, 1);
                    else WIFI_BSUBWAY_ReadRecordUnits((unsigned int)p, i);
                }
            }
            if (all != 0) result = 1;
            else result = 2;
        } else {
            if (flag != 0) WIFI_BSUBWAY_SetDownloadResult(q, 2);
            result = 2;
            for (i = 0; i < ((struct Obj01925 *)p)->f16C; i++) {
                if (NHTTP_RAP_RecordList_GetValue((u32)x, i) != 0) WIFI_BSUBWAY_ReadRecordUnits((unsigned int)p, i);
            }
        }
        NHTTP_RAP_FreePostData(*(u8 * *)&((struct Obj01925 *)p)->f168);
        NHTTP_RAP_Destroy(*(u8 * *)&((struct Obj01925 *)p)->f168);
        *(u8 * *)&((struct Obj01925 *)p)->f168 = 0;
        DWC_RAP_SetErrorCallback(0, 0);
    }
    return result;
}
