/*
 * function: EL_SCOREBOARD_EventMain
 * address:  0x021876E0
 * packet:   pkt_ov020_021876E0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   EL_SCOREBOARD_OnStart  0x02187CEC  thumb  ov020
 *   EL_SCOREBOARD_UpdateFade  0x02187A10  thumb  ov020
 *   EL_SCOREBOARD_OnFinish  0x02187CFC  thumb  ov020
 *   KEY_GetTrg  0x020362DC  arm
 *   EL_SCOREBOARD_GetMode  0x02187D20  thumb  ov020
 *   EL_SCOREBOARD_RequestFinish  0x02187D28  thumb  ov020
 *   EL_SCOREBOARD_AdvanceState  0x02187CCC  thumb  ov020
 */
#include "../include/Obj12549.h"

typedef unsigned int u32;

extern void EL_SCOREBOARD_OnStart(char *o);
extern void EL_SCOREBOARD_UpdateFade(char *o, int k);
extern void EL_SCOREBOARD_OnFinish(char *o);
extern u32 KEY_GetTrg(void);
extern u32 EL_SCOREBOARD_GetMode(char *p);
extern void EL_SCOREBOARD_RequestFinish(u32 *p);
extern void EL_SCOREBOARD_AdvanceState(char *o, int *s);

int EL_SCOREBOARD_EventMain(void *unused, int *s, char *o)
{
    switch (*s) {
    case 0: EL_SCOREBOARD_OnStart(o); break;
    case 1: case 3: break;
    case 2: EL_SCOREBOARD_UpdateFade(o, *s); break;
    case 4: EL_SCOREBOARD_UpdateFade(o, *s); break;
    case 5: EL_SCOREBOARD_OnFinish(o); return 1;
    }
    if (KEY_GetTrg() & 1) { if (EL_SCOREBOARD_GetMode(o) == 0) EL_SCOREBOARD_RequestFinish((u32 *)o); }
    ((struct Obj12549 *)o)->f18 = ((struct Obj12549 *)o)->f18 + 1;
    EL_SCOREBOARD_AdvanceState(o, s);
    return 0;
}
