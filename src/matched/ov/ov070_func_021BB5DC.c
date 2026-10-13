/*
 * function: func_021BB5DC
 * address:  0x021BB5DC
 * packet:   pkt_ov070_021BB5DC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB368  0x021BB368  thumb  ov070
 *   func_021BB5A4  0x021BB5A4  thumb  ov070
 *   GAME_DATA_CheckSaveFlag  0x02012BF8  thumb
 *   func_0204B878  0x0204B878  arm
 */
#include "../include/Obj00002.h"

extern int func_021BB368(int);
typedef unsigned short u16;
struct Obj;
extern void func_021BB5A4(char *p);
extern int GAME_DATA_CheckSaveFlag(int, int);
extern void func_0204B878(struct Obj *p, u16 value);

void func_021BB5DC(int p, int mode)
{
    int r = GAME_DATA_CheckSaveFlag(*(int *)&((struct Obj00002 *)p)->f0, func_021BB368(((struct Obj00002 *)p)->f80C));

    if (mode == 1) {
        func_021BB5A4((char *)p);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f710), 4);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f714), 5);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f71C), 0);
        if (r == 1) {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 7);
        } else {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 6);
        }
    } else {
        func_0204B878((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C), 4);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f710), 0x12);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f714), 0x13);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f71C), 0xE);
        if (r == 1) {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 0x16);
        } else {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 0x15);
        }
    }
}
