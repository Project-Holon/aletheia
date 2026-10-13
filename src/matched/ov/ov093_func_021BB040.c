/*
 * function: BTL_SERVER_CheckShiftPromptNeeded
 * address:  0x021BB040
 * packet:   pkt_ov093_021BB040
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_CheckShiftModePrompt  0x021B85A8  thumb  ov093
 *   BTL_MAIN_GetSlotClientIdThunk  0x021B8DE4  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SLOT_CountLiving  0x021B9B98  thumb  ov093
 */
#include "../include/Obj01235.h"

typedef unsigned char u8;

extern int BTL_MAIN_CheckShiftModePrompt(u8 *);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
extern u8 BTL_SLOT_CountLiving(u8 *p);

int BTL_SERVER_CheckShiftPromptNeeded(u8 *p)
{
    unsigned i;

    if (BTL_MAIN_CheckShiftModePrompt(*(u8 * *)&((struct Obj01235 *)p)->fC) != 0 && p[0xcba] != 0) {
        for (i = 0; i < p[0xcba]; i++) {
            if (BTL_MAIN_GetSlotClientIdThunk((char *)(*(u8 * *)&((struct Obj01235 *)p)->fC), p[0xcb4 + i]) == 0)
                return 0;
        }
        if (BTL_SLOT_CountLiving((u8 *)BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj01235 *)p)->f10, BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj01235 *)p)->fC))) < 2)
            return 0;
        return 1;
    }
    return 0;
}
