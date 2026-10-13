/*
 * function: EVENT_COMM_COMMON_ExitSyncEventMain
 * address:  0x0217F6A0
 * packet:   pkt_ov018_0217F6A0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   INTRUDE_COMM_ClearSessionEntries  0x021757A8  thumb  ov011
 *   INTRUDE_FIELD_InitStartParam  0x0217BF1C  thumb  ov018
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomMsgWin  0x021907A8  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb  ov010
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   INTRUDE_CMD_SendEntryIndex  0x02173D2C  thumb  ov011
 *   INTRUDE_COMM_GetMemberNameNetId  0x02175FB4  thumb  ov011
 *   INTRUDE_COMM_SendReady  0x02173C6C  thumb  ov011
 *   INTRUDE_FIELD_GetStartKind  0x0217BF28  thumb  ov018
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fC;
} Ctx;

struct BigObj;
struct Ctx;
struct Obj;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct Ctx;
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
int INTRUDE_COMM_GetWorkIfRunning(int a0);
u32 func_0200FB24(void);
u8 GAME_DATA_GetIntrudeId(const struct BigObj *p);
u8 GAME_DATA_GetExitMode(const struct BigObj *p);
void INTRUDE_COMM_ClearSessionEntries(u8 *p);
void INTRUDE_FIELD_InitStartParam(void *p);
u32 FIELDMAP_GetMsgBg(u8 *p);
int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
int FIELD_MSGBG_CreateBottomMsgWin(void *a0, int a1);
struct WordSet *func_0201EC64(u32 heap);
void GFL_USE_PlaySeDefaultVolume(u32 a);
u8 GAME_DATA_GetIntrudeIdByte(void *p);
int FIELD_MSGBG_MsgWinPrintMsg(u32 a, u32 b, u32 c, u32 d);
struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
void *func_02045EC0(struct MsgBank *bank, u32 index);
int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
int FIELD_MSGBG_MsgWinPrintStr(u32 a, u32 b, u32 c, u32 d);
void STRBUF_Delete(struct U16Vec *vec);
int GFL_NET_GetNegotiationNum(void);
int INTRUDE_CMD_SendEntryIndex(int a0, int a1);
int INTRUDE_COMM_GetMemberNameNetId(u8 *p);
int INTRUDE_COMM_SendReady(int a, int b);
u8 INTRUDE_FIELD_GetStartKind(u8 *p);
int FIELD_MSGBG_IsMsgWinTransDone(u8 *p);
u32 KEY_GetTrg(void);
u32 func_0201ED04(struct WordSet *p);
int FIELD_MSGBG_DeleteMsgWin(void *a);
u32 MSGDATA_Delete(struct Rec *rec);

int EVENT_COMM_COMMON_ExitSyncEventMain(void *a0, int *state, Ctx *c)
{
    void *h;
    void *s;
    u32 k;
    u8 *w;
    void *t;
    int flag;

    h = GAME_EVENT_GetGameSystem(a0);
    s = GAMESYSTEM_GetGameData(h);
    k = GAMESYSTEM_GetGameComm(h);
    t = GAMESYSTEM_GetFieldMap(h);
    flag = 0;
    w = (u8 *)INTRUDE_COMM_GetWorkIfRunning(k);
    if (w == 0 && *state > 0 && *state < 5) {
        *state = 5;
    }
    switch (*state) {
    case 0: {
        void *g;
        int a;
        int b;

        if (func_0200FB24() != 0 || (w == 0 && GAME_DATA_GetIntrudeId(s) != GAME_DATA_GetExitMode(s))) {
            *state = 7;
            break;
        }
        if (w != 0) {
            INTRUDE_COMM_ClearSessionEntries(w + 0x1AC);
            INTRUDE_FIELD_InitStartParam(w + 0x914);
        }
        g = (void *)FIELDMAP_GetMsgBg(t);
        c->f0 = FIELD_MSGBG_CreateMsgData((int)g, 0x2D);
        c->f4 = FIELD_MSGBG_CreateBottomMsgWin(g, c->f0);
        c->f8 = (int)func_0201EC64(4);
        GFL_USE_PlaySeDefaultVolume(0x547);
        if (w == 0 || GAME_DATA_GetIntrudeIdByte(s) == GAME_DATA_GetExitMode(s)) {
            FIELD_MSGBG_MsgWinPrintMsg(c->f4, 0, 0, 0x49);
            flag = 1;
        } else {
            a = (int)STRBUF_Create(0x100, 0x15);
            b = (int)func_02045EC0((struct MsgBank *)c->f0, 0x4A);
            func_0201F02C((struct WordSet *)c->f8, 0, (void *)GAME_DATA_GetMyStatusByNetId(s, GAME_DATA_GetIntrudeIdByte(s)));
            func_0201F250((struct WordSet *)c->f8, (void *)a, (void *)b);
            FIELD_MSGBG_MsgWinPrintStr(c->f4, 0, 0, a);
            STRBUF_Delete((struct U16Vec *)b);
            STRBUF_Delete((struct U16Vec *)a);
        }
        if (GFL_NET_GetNegotiationNum() <= 1) {
            if (flag == 0) {
                *c->fC = 0;
            } else {
                *c->fC = 1;
            }
            *state = 5;
            break;
        }
        (*state)++;
    }
    case 1:
        if (INTRUDE_CMD_SendEntryIndex((int)w, GAME_DATA_GetIntrudeIdByte(s)) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (INTRUDE_COMM_GetMemberNameNetId(w + 0x1AC + GAME_DATA_GetIntrudeIdByte(s) * 0x28) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (INTRUDE_COMM_SendReady((int)w, GAME_DATA_GetIntrudeIdByte(s)) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (INTRUDE_FIELD_GetStartKind(w + 0x914) == 1) {
            *c->fC = 1;
            *state = 5;
        }
        break;
    case 5:
        if (FIELD_MSGBG_IsMsgWinTransDone((u8 *)c->f4) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (KEY_GetTrg() & 0xF3) {
            func_0201ED04((struct WordSet *)c->f8);
            FIELD_MSGBG_DeleteMsgWin((void *)c->f4);
            MSGDATA_Delete((struct Rec *)c->f0);
            (*state)++;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}
