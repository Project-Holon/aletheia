/*
 * function: GTSNEGO_DISP_StartMatchmaking
 * address: 0x021D4B48
 * packet: pkt_ov120_021D4B48
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GTSNEGO_MSG_CreateConfirmUi 0x021D8590 thumb ov120
 *   GTSNEGO_DISP_OnDisconnectCallback 0x021D505C thumb ov120
 *   GTSNEGO_DISP_HandleTradeKeys 0x021D4988 thumb ov120
 *   GTSNEGO_DISP_ScoreMatch 0x021D4A20 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   func_02009CA8 0x02009CA8 thumb
 *   GTSNEGO_DISP_GetEntry 0x021D4F70 thumb ov120
 *   MI_CpuCopy8 0x02082D44 arm
 *   DWC_AddMatchKeyInt 0x0216C8DC arm ov009
 *   func_0208D7E0 0x0208D7E0 arm
 *   DWC_RAP_StartMatchWithFilter 0x0215580C thumb ov009
 *   GFL_NET_STATE_WifiEnterFriendMatch 0x0203C35C arm
 *   DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   d_021D8B40 0x021D8B40 data a2
 *   d_021D8B50 0x021D8B50 data a1
 */
#include "../include/Obj01539.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 value; u8 kind; u8 pad; u16 detail; u32 tail; } Record;
struct Sub0200852CObj;
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern int GFL_NET_GetRunState(void);
extern void GTSNEGO_MSG_CreateConfirmUi(u8 *, int, int);
extern void GTSNEGO_DISP_OnDisconnectCallback(int a, int b, int *p);
extern void GTSNEGO_DISP_HandleTradeKeys(int *a);
extern int GTSNEGO_DISP_ScoreMatch(int, u8 *);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GFL_NET_SetWaitMode(int);
extern void func_02009CA8(void *account, void *out);
extern void *GTSNEGO_DISP_GetEntry(void **p, int i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u8 DWC_AddMatchKeyInt(u8 keyID, char *keyString, int *valueSrc);
extern int func_0208D7E0(char *, const char *, ...);
extern int DWC_RAP_StartMatchWithFilter(int, int, int, int);
extern u32 GFL_NET_STATE_WifiEnterFriendMatch(void);
extern void DWC_RAP_SetVchatEnabled(int);
extern void GFL_NET_STATE_SetError(int, u32, u32, u32);
extern const u16 d_021D8B40[];
extern const char d_021D8B50[];
void GTSNEGO_DISP_StartMatchmaking(u8 *p)
{
    u32 values[8];
    void *q;
    int i;
    Record *r;
    if (GTSNEGO_MSG_UpdatePrintStream(((struct Obj01539 *)p)->f40)) {
        if (GFL_NET_GetRunState() == 0) {
            GTSNEGO_MSG_CreateConfirmUi(*(u8 * *)&((struct Obj01539 *)p)->f40, (int)GTSNEGO_DISP_OnDisconnectCallback, (int)p);
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_HandleTradeKeys, 0x3ea);
            return;
        }
        GFL_NET_SetWaitMode(0);
        func_02009CA8((void *)(((struct Obj01539 *)p)->f44), values);
        values[0] = ((struct Obj01539 *)p)->f14C;
        values[1] = ((struct Obj01539 *)p)->f138;
        values[2] = ((struct Obj01539 *)p)->f144;
        values[3] = ((struct Obj01539 *)p)->f13C;
        values[4] = ((struct Obj01539 *)p)->f140;
        values[5] = 0x20015;
        values[6] = 1;
        values[7] = 0;
        if (((struct Obj01539 *)p)->f138 == 1) {
            if (((struct Obj01539 *)p)->f148 == -1)
                values[2] = 4;
            else {
                q = GTSNEGO_DISP_GetEntry(((struct Obj01539 *)p)->f2C, ((struct Obj01539 *)p)->f148);
                values[7] = func_02008530(q);
                ((struct Obj01539 *)p)->f18 = func_02008530(q);
            }
        }
        for (i = 0; i < 8; i++) {
            r = (Record *)(p + 0x58) + i;
            MI_CpuCopy8(d_021D8B40 + i, &r->detail, 2);
            r->value = values[i];
            r->kind = DWC_AddMatchKeyInt(r->kind, (char *)(&r->detail), (int *)r);
        }
        func_0208D7E0((char *)p + 0xb8, d_021D8B50, ((struct Obj01539 *)p)->f138, 1);
        if (DWC_RAP_StartMatchWithFilter((int)p + 0xb8, 2, (int)GTSNEGO_DISP_ScoreMatch, (int)p)) {
            GFL_NET_STATE_WifiEnterFriendMatch();
            DWC_RAP_SetVchatEnabled(0);
            GTSNEGO_MSG_CreateConfirmUi(*(u8 * *)&((struct Obj01539 *)p)->f40, (int)GTSNEGO_DISP_OnDisconnectCallback, (int)p);
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_HandleTradeKeys, 0x41d);
            return;
        }
        GFL_NET_STATE_SetError(0, 0, 0, 0x3f1);
    }
}
