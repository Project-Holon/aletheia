/*
 * function: SCRCMD_MSGWIN_CmdUpdateMoneyWin
 * address:  0x021B0730
 * packet:   pkt_ov021_021B0730
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetInfoWindow  0x02188D48  thumb  ov021
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_GetMoney  0x0200C274  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Blk34;
struct Ctx;
struct MsgBank;
struct Rec;
struct SaveBlock;
struct U16Vec;
struct WordSet;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetInfoWindow(u8 *p);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 BEACON_GetMoney(struct Blk34 *p);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void FIELD_MSGBG_ClearMsgWin(u8 *p);
extern int FIELD_MSGBG_MsgWinPrintStr(u32 a, u32 b, u32 c, u32 d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);

int SCRCMD_MSGWIN_CmdUpdateMoneyWin(u32 a, u32 b)
{
    u32 x, r5, r6, r7, r4, z;
    void *y;
    void *t;

    t = SCRCMD_WORK_GetGameSystem((void *)b);
    x = (u32)GAMESYSTEM_GetGameData(t);
    GAME_DATA_GetMyPlayerWork((struct SaveBlock *)x);
    y = GAMESYSTEM_GetFieldMap(t);
    r5 = FIELDMAP_GetInfoWindow(y);
    t = SCRCMD_WORK_GetScriptWork((void *)b);
    r6 = (u32)SCRIPT_WORK_GetWordSet(t);
    r7 = SCRIPT_WORK_GetTempBuffer(t);
    r4 = FIELDMAP_GetHeapId(y);
    z = (u32)func_02045B38(0, 3, 0x9e, r4);
    r4 = (u32)STRBUF_Create(0x80, r4);
    WORDSET_SetSlotNumber((struct WordSet *)r6, 2, BEACON_GetMoney(GAME_DATA_GetMiscSave((int *)x)), 7, 1, 1);
    MSGDATA_ReadString((struct MsgBank *)z, 1, (void *)r7);
    WORDSET_CopyTaggedText((struct WordSet *)r6, (void *)r4, (void *)r7);
    FIELD_MSGBG_ClearMsgWin((u8 *)r5);
    FIELD_MSGBG_MsgWinPrintStr(r5, 0, 0, r4);
    STRBUF_Delete((struct U16Vec *)r4);
    MSGDATA_Delete((struct Rec *)z);
    return 0;
}
