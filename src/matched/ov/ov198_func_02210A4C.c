/*
 * function: B_PLIST_MAIN_HandleCursorInput
 * address: 0x02210A4C
 * packet: pkt_ov198_02210A4C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_PLIST_MAIN_GetSlotState 0x02210B00 thumb ov198
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 */
#include "../include/Obj25266.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern int B_PLIST_MAIN_GetSlotState(u8 *p, int i);
extern void B_PLIST_MAIN_PlaySe(u8 **,u32);
int B_PLIST_MAIN_HandleCursorInput(u8 *p)
{
    u32 sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj25266 *)p)->f2184);
    switch(sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if(B_PLIST_MAIN_GetSlotState(p,sel)) {
            (*(u8 **)p)[32]=sel;
            return 1;
        }
        break;
    case 6:
        (*(u8 **)p)[32]=6;
        return 1;
    case (u32)-2:
        (*(u8 **)p)[32]=6;
        return 1;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 0;
}
