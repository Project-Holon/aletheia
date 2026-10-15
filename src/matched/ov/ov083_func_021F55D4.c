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
 * `for (i = 0, n = 0; ...)` (not `n = 0;` before the loop) is what lets the
 * constant zero live in r4 across the calls and seeds `i` from it.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   INTRUDE_GetMonolithLevel  0x0200BF10  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   FIELD_MSGBG_InfoMsgWinPrintStr  0x02190844  thumb  ov021
 *   GPOWER_EVENT_PrintPowerRow  0x021F556C  thumb  ov083
 *   func_02010EB4  0x02010EB4  thumb
 *   GPOWER_GetMinutesLeftByType  0x02010EC0  thumb
 */
#include "../include/Obj00815.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *INTRUDE_GetFromSave(void *sys);
struct Rec1B0;
extern u8 INTRUDE_GetMonolithLevel(struct Rec1B0 *p);
struct MsgBank;
struct Slot;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void FIELD_MSGBG_InfoMsgWinPrintStr(struct Slot **p, int x, int y, u32 z);
extern void  GPOWER_EVENT_PrintPowerRow(char *p, u32 a1, u32 a2, int a3, u8 a4);
extern u8 func_02010EB4(int k);
extern u32 GPOWER_GetMinutesLeftByType(u32 i);

void GPOWER_EVENT_PrintPowerList(char *p)
{
    u8 vals[13];
    u8 order[13];
    u16 keys[13];
    void *x;
    u8 c;
    u8 i;
    u8 j;
    u8 n;
    u8 t;

    x = INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00815 *)p)->fC));
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj00815 *)p)->f28), 4, (void *)(((struct Obj00815 *)p)->f34));
    FIELD_MSGBG_InfoMsgWinPrintStr((struct Slot **)(((struct Obj00815 *)p)->f18), 0, 0, ((struct Obj00815 *)p)->f34);
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj00815 *)p)->f28), 6, (void *)(((struct Obj00815 *)p)->f34));
    c = (int)INTRUDE_GetMonolithLevel(x);
    if (c != 0x30) {
        GPOWER_EVENT_PrintPowerRow(p, ((struct Obj00815 *)p)->f34, c, 0, 1);
    }
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj00815 *)p)->f28), 5, (void *)(((struct Obj00815 *)p)->f34));
    FIELD_MSGBG_InfoMsgWinPrintStr((struct Slot **)(((struct Obj00815 *)p)->f18), 0, 0x30, ((struct Obj00815 *)p)->f34);
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj00815 *)p)->f28), 7, (void *)(((struct Obj00815 *)p)->f34));

    for (i = 0, n = 0; i < 13; i++) {
        order[i] = i;
        c = (int)func_02010EB4((u8)i);
        if (c != 0x30) {
            keys[n] = GPOWER_GetMinutesLeftByType(i);
            vals[n] = c;
            n++;
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (keys[order[j - 1]] > keys[order[j]]) {
                t = order[j];
                order[j] = order[j - 1];
                order[j - 1] = t;
            }
        }
    }

    for (i = 0; i < n; i++) {
        GPOWER_EVENT_PrintPowerRow(p, ((struct Obj00815 *)p)->f34, vals[order[i]], keys[order[i]], i + 4);
    }
}
