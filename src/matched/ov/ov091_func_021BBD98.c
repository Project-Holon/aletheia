/*
 * function: PLIST_MENU_CreateCommandLabel
 * address:  0x021BBD98
 * packet:   pkt_ov091_021BBD98
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   gPlistMenuLabelMsgIds     0x021BEC8C  data  ov091  a4
 */
#include "../include/Obj05174.h"

typedef unsigned short u16;

extern unsigned int POKE_TOOL_GetPartyValue(void *, unsigned int, unsigned int);
typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern int gPlistMenuLabelMsgIds[];

int PLIST_MENU_CreateCommandLabel(int a, int unused, int idx)
{
    int r;
    int h;
    if (idx >= 0x10 && idx <= 0x13) {
        r = POKE_TOOL_GetPartyValue((void *)*(int *)&((struct Obj05174 *)a)->f38, idx + 0x26, 0);
        h = (int)func_02045B38(0, 2, 0xcb, ((struct Obj05174 *)a)->f0);
        r = (int)func_02045EC0((struct MsgBank *)h, r);
        MSGDATA_Delete((struct Rec *)h);
    } else {
        r = (int)func_02045EC0((struct MsgBank *)(((struct Obj05174 *)a)->f134), gPlistMenuLabelMsgIds[idx]);
    }
    return r;
}
