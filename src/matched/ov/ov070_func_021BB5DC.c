/*
 * function: ITEMMENU_UpdateSideButtonsForMode
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
 *   ITEMMENU_PocketToSortFlag  0x021BB368  thumb  ov070
 *   ITEMMENU_UpdateInputGuardAnim  0x021BB5A4  thumb  ov070
 *   GAME_DATA_ContainsRecentId  0x02012BF8  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */
#include "../include/Obj00002.h"

extern int ITEMMENU_PocketToSortFlag(int);
typedef unsigned short u16;
struct Obj;
extern void ITEMMENU_UpdateInputGuardAnim(char *p);
extern int GAME_DATA_ContainsRecentId(int, int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void ITEMMENU_UpdateSideButtonsForMode(int p, int mode)
{
    int r = GAME_DATA_ContainsRecentId(*(int *)&((struct Obj00002 *)p)->f0, ITEMMENU_PocketToSortFlag(((struct Obj00002 *)p)->f80C));

    if (mode == 1) {
        ITEMMENU_UpdateInputGuardAnim((char *)p);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f710), 4);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f714), 5);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f71C), 0);
        if (r == 1) {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f718), 7);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f718), 6);
        }
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C), 4);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f710), 0x12);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f714), 0x13);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f71C), 0xE);
        if (r == 1) {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f718), 0x16);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f718), 0x15);
        }
    }
}
