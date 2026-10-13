/*
 * function: EL_SCOREBOARD_GetNextState
 * address:  0x02187BBC
 * packet:   pkt_ov020_02187BBC
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EL_SCOREBOARD_IsStateDone  0x02187D30  thumb  ov020
 *   EL_SCOREBOARD_IsFinishRequested  0x02187D24  thumb  ov020
 */
#include "../include/Obj01207.h"

typedef unsigned char u8;

typedef unsigned int   u32;
int EL_SCOREBOARD_IsStateDone(char *p);
u32 EL_SCOREBOARD_IsFinishRequested(char *p);

int EL_SCOREBOARD_GetNextState(char *o, int st)
{
    switch (st) {
    case 0:
        st = 1;
        break;
    case 1:
        st = 2;
        break;
    case 2:
        if (EL_SCOREBOARD_IsStateDone(o) == 1)
            st = 3;
        break;
    case 3:
        if (EL_SCOREBOARD_IsStateDone(o) == 1 || EL_SCOREBOARD_IsFinishRequested(o) == 1)
            st = 4;
        break;
    case 4:
        if (EL_SCOREBOARD_IsStateDone(o) == 1) {
            st = 5;
            if (((struct Obj01207 *)o)->f14 != ((struct Obj01207 *)o)->f15)
                st = 1;
        }
        break;
    case 5:
        break;
    }
    return st;
}
