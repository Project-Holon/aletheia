/*
 * function: func_022010BC
 * address:  0x022010BC
 * packet:   pkt_022010BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker: the call target 0x0200FB4C (arm9, Thumb leaf) has no label, so its
 * relocation stays wildcarded (requested in docs/sessions/2026-09-27/arm9_requests.md).
 * The four ov114 targets 0x021B97F4, 0x021B99F0, 0x021B99F4, 0x021B9A14 were seeded
 * by tree_ov135_4. Every other byte is identical. Labelling 0x0200FB4C makes this EXACT.
 *
 * symbols:
 *   NHTTP_RAP_GetResultCode  0x021B99DC  thumb  ov114
 *   NHTTP_RAP_PollConnection  0x021B9790  thumb  ov114
 *   NHTTP_RAP_GetRecvBuffer  0x021B97F4  thumb  ov114
 *   NHTTP_RAP_DeleteConnection  0x021B9774  thumb  ov114
 *   NHTTP_RAP_FreePostData  0x021B99B8  thumb  ov114
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *   NHTTP_RAP_RecordList_GetCount  0x021B99F0  thumb  ov114
 *   NHTTP_RAP_RecordList_GetValue  0x021B99F4  thumb  ov114
 *   NHTTP_RAP_RecordList_GetRecord  0x021B9A14  thumb  ov114
 *   GFL_NET_ERR_RaiseFatal  0x0200FB4C  thumb
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_0220254C  0x0220254C  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x28];
    int state;
    u8 pad2C[0x38 - 0x2C];
    int err;
    u8 pad3C[0xE4 - 0x3C];
    u8 mon[0x10E0 - 0xE4];
    void *wm;
    u8 valid;
    u8 pad10E5[3];
    u32 count;
    u8 buf[0x80];
    u8 pad116C[0x1328 - 0x116C];
    u32 done;
} Work;

extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *p);
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void NHTTP_RAP_FreePostData(u8 *p);
extern void NHTTP_RAP_Destroy(u8 *p);
extern int NHTTP_RAP_RecordList_GetCount(u8 *p);
extern u32 NHTTP_RAP_RecordList_GetValue(u32 p, u32 i);
extern u8 *NHTTP_RAP_RecordList_GetRecord(u8 *p, u32 i);
extern void GFL_NET_ERR_RaiseFatal(u32 id);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern void func_0220254C(void *mon, u32 heap);
extern u32 func_0200FBB0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_ClearErrorMode(void);

int func_022010BC(Work *p)
{
    int st;
    int r;
    void *rec;

    st = NHTTP_RAP_GetResultCode(p->wm);
    r = NHTTP_RAP_PollConnection(p->wm);
    if (r == 0) {
        rec = NHTTP_RAP_GetRecvBuffer(p->wm);
        switch (st) {
        case 400:
            GFL_NET_ERR_RaiseFatal(0x41);
            GFL_NET_ERR_ShowScreen(0);
            NHTTP_RAP_DeleteConnection(p->wm);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            p->state = 0x2C;
            return 2;
        case 401:
            GFL_NET_ERR_RaiseFatal(0x42);
            GFL_NET_ERR_ShowScreen(0);
            NHTTP_RAP_DeleteConnection(p->wm);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            p->state = 0x2C;
            return 2;
        case 408:
            GFL_NET_ERR_RaiseFatal(0x44);
            GFL_NET_ERR_ShowScreen(0);
            NHTTP_RAP_DeleteConnection(p->wm);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            p->state = 0x2C;
            return 2;
        default:
            GFL_NET_ERR_RaiseFatal(0x43);
            GFL_NET_ERR_ShowScreen(0);
            NHTTP_RAP_DeleteConnection(p->wm);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            p->state = 0x2C;
            return 2;
        case 200:
            p->valid = NHTTP_RAP_RecordList_GetCount(rec);
            p->count = NHTTP_RAP_RecordList_GetValue((u32)rec, 0);
            MI_CpuCopy8(NHTTP_RAP_RecordList_GetRecord(rec, 1), p->buf, 0x80);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            if (p->valid == 0) {
                if (p->count == 0) {
                    p->state = 4;
                } else if (p->done == 0) {
                    p->done++;
                    p->state = 2;
                    func_0220254C(p->mon, 0x48);
                } else {
                    p->err = -7;
                    p->state = 0x2D;
                }
            } else if (p->done == 0) {
                p->done++;
                p->state = 2;
                func_0220254C(p->mon, 0x48);
            } else {
                p->err = -7;
                p->state = 0x2D;
            }
            break;
        }
    } else if (r != 0xF) {
        p->err = -15;
        p->state = 0x2B;
        NHTTP_RAP_FreePostData(p->wm);
        NHTTP_RAP_Destroy(p->wm);
        func_0200FBB0();
        GFL_NET_STATE_SetWifiError();
        func_0200FBA0();
        GFL_NET_STATE_ClearErrorMode();
    }
    return 2;
}
