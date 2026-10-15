/*
 * function: IRCBATTLEMENU_SeqSaveYesNo
 * address:  0x02197800
 * packet:   pkt_ov021_02197800
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020071F0  0x020071F0  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   IRCBATTLEMENU_PrintMessage  0x02197644  thumb  ov021
 *   IRCBATTLEMENU_CreateTimeIcon  0x02196290  thumb  ov021
 *   IRCBATTLEMENU_SetSubPaletteActive  0x02196228  thumb  ov021
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   IRCBATTLEMENU_DeleteMsgWin  0x021962F4  thumb  ov021
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqWaitTouchExit  0x021977C0  thumb  ov021
 *   IRCBATTLEMENU_SeqSaveStart  0x02197798  thumb  ov021
 *   IRCBATTLEMENU_SeqUpdateTouchTop  0x02196A4C  thumb  ov021
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct MsgBank;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 func_020071F0(void);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void IRCBATTLEMENU_PrintMessage(u8 *, u32);
extern void IRCBATTLEMENU_CreateTimeIcon(u8 *);
extern void IRCBATTLEMENU_SetSubPaletteActive(u8 *p, int flag);
extern void BG_SYS_ClearSlot(u32);
extern void IRCBATTLEMENU_DeleteMsgWin(u8 *);
extern void IRCBATTLEMENU_SetSeq(u8 *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqWaitTouchExit(u8 *a);
extern void IRCBATTLEMENU_SeqSaveStart(u8 *a);
extern void IRCBATTLEMENU_SeqUpdateTouchTop(u8 *a);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

void IRCBATTLEMENU_SeqSaveYesNo(u8 *a)
{
    if (APP_TASKMENU_IsFinish((struct TaskMenu *)(((struct Obj00094 *)a)->f2C0)) != 0) {
        if (APP_TASKMENU_GetCursorPos((const u8 *)(((struct Obj00094 *)a)->f2C0)) == 0) {
            GAME_DATA_GetSaveControl((struct Big *)(((struct Obj00094 *)a)->f30));
            if (func_020071F0() != 0) {
                MSGDATA_ReadString((struct MsgBank *)(((struct Obj00094 *)a)->f28), 0x2d, (void *)(((struct Obj00094 *)a)->f38));
                IRCBATTLEMENU_PrintMessage(a, 0);
                IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqWaitTouchExit, 0x7b9);
            } else {
                MSGDATA_ReadString((struct MsgBank *)(((struct Obj00094 *)a)->f28), 0x1c, (void *)(((struct Obj00094 *)a)->f38));
                IRCBATTLEMENU_PrintMessage(a, 1);
                IRCBATTLEMENU_CreateTimeIcon(a);
                IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqSaveStart, 0x7bf);
            }
        } else {
            IRCBATTLEMENU_SetSubPaletteActive(a, 0);
            BG_SYS_ClearSlot(3);
            IRCBATTLEMENU_DeleteMsgWin(a);
            ((struct Obj00094 *)a)->f8 = 12;
            IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqUpdateTouchTop, 0x7c7);
        }
        APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj00094 *)a)->f2C0));
        ((struct Obj00094 *)a)->f2C0 = 0;
    }
}
