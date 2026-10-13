/*
 * function: SCRCMD_MSGWIN_CmdBalloonWinMsgGender
 * address:  0x021B0DF0
 * packet:   pkt_ov021_021B0DF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CmdBalloonWinMsgGender  0x021B0DF0  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   func_02008550  0x02008550  thumb
 *   SCRCMD_MSGWIN_OpenBalloonWinMsg  0x021B0BAC  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_MSGWIN_WaitBalloonWin  0x021B0CEC  thumb
 */

typedef unsigned short u16;
extern u16 SCRIPT_WORK_ReadWorkValue(int, int);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern char *GAME_DATA_GetMyPlayerWork(void *);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
typedef unsigned int   u32;
extern int SCRCMD_MSGWIN_OpenBalloonWinMsg(u32 b, u16 id, u16 c, u16 d, u16 e, int f);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_MSGWIN_WaitBalloonWin(int, int);

int SCRCMD_MSGWIN_CmdBalloonWinMsgGender(int a, int b)
{
    u16 v0, v1, v2, v3, v4, v5;
    v0 = SCRIPT_WORK_ReadWorkValue(a, b);
    v1 = SCRIPT_WORK_ReadWorkValue(a, b);
    v2 = SCRIPT_WORK_ReadWorkValue(a, b);
    v3 = SCRIPT_WORK_ReadWorkValue(a, b);
    v4 = SCRIPT_WORK_ReadWorkValue(a, b);
    v5 = SCRIPT_WORK_ReadWorkValue(a, b);
    if (func_02008550((const struct Sub0200852CObj *)(GAME_DATA_GetMyPlayerWork(SCRCMD_WORK_GetGameData((void *)b)) + 0x20))) {
        v1 = v2;
    }
    if (SCRCMD_MSGWIN_OpenBalloonWinMsg(b, v3, v0, v1, v4, v5) == 1) {
        VM_SetWait((char *)a, (int)SCRCMD_MSGWIN_WaitBalloonWin);
        return 1;
    }
    return 0;
}
