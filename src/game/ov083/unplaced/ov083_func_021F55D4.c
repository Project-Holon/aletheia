/*
 * function: GPOWER_EVENT_PrintPowerList
 * address:  0x021F55D4
 * packet:   pkt_ov083_021F55D4
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF10  0x0200BF10  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   FIELD_MSGBG_InfoMsgWinPrintStr  0x02190844  thumb  ov021
 *   GPOWER_EVENT_PrintPowerRow  0x021F556C  thumb  ov083
 *   func_02010EB4  0x02010EB4  thumb
 *   GPOWER_GetMinutesLeftByType  0x02010EC0  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include "../unit_021F5260_types.h"

struct SaveControl;
struct GPowerSave;
struct MsgData;
struct Strbuf;
struct InfoMsgWin;

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct GPowerSave *func_0200BE48(struct SaveControl *saveControl);
extern u8 func_0200BF10(struct GPowerSave *gpowerSave);
extern void MSGDATA_ReadString(struct MsgData *msgData, u32 msgId, struct Strbuf *dst);
extern void FIELD_MSGBG_InfoMsgWinPrintStr(struct InfoMsgWin *win, int x, int y, struct Strbuf *str);
extern void GPOWER_EVENT_PrintPowerRow(GPowerListWork *work, struct Strbuf *templateStr, u32 powerId, int minutes, u8 row);
extern u8 func_02010EB4(int type);
extern u32 GPOWER_GetMinutesLeftByType(u32 type);

void GPOWER_EVENT_PrintPowerList(GPowerListWork *work)
{
    u8 powerIds[13];
    u8 order[13];
    u16 minutesLeft[13];
    struct GPowerSave *gpowerSave;
    u8 powerId;
    u8 i;
    u8 j;
    u8 count;
    u8 swapTmp;

    gpowerSave = func_0200BE48(GAME_DATA_GetSaveControl(work->gameData));
    MSGDATA_ReadString(work->msgData, 4, work->templateStr);
    FIELD_MSGBG_InfoMsgWinPrintStr(work->infoMsgWin, 0, 0, work->templateStr);
    MSGDATA_ReadString(work->msgData, 6, work->templateStr);
    powerId = (int)func_0200BF10(gpowerSave);
    if (powerId != GPOWER_ID_NONE) {
        GPOWER_EVENT_PrintPowerRow(work, work->templateStr, powerId, 0, 1);
    }
    MSGDATA_ReadString(work->msgData, 5, work->templateStr);
    FIELD_MSGBG_InfoMsgWinPrintStr(work->infoMsgWin, 0, 0x30, work->templateStr);
    MSGDATA_ReadString(work->msgData, 7, work->templateStr);

    /* The `for (i = 0, count = 0; ...)` form (not `count = 0;` before the loop) keeps the constant zero in r4 across the calls and seeds i from it. */
    for (i = 0, count = 0; i < 13; i++) {
        order[i] = i;
        powerId = (int)func_02010EB4((u8)i);
        if (powerId != GPOWER_ID_NONE) {
            minutesLeft[count] = GPOWER_GetMinutesLeftByType(i);
            powerIds[count] = powerId;
            count++;
        }
    }

    for (i = 0; i < count - 1; i++) {
        for (j = count - 1; j > i; j--) {
            if (minutesLeft[order[j - 1]] > minutesLeft[order[j]]) {
                swapTmp = order[j];
                order[j] = order[j - 1];
                order[j - 1] = swapTmp;
            }
        }
    }

    for (i = 0; i < count; i++) {
        GPOWER_EVENT_PrintPowerRow(work, work->templateStr, powerIds[order[i]], minutesLeft[order[i]], i + 4);
    }
}
