/*
 * unit: yes
 * function: GURU2_MAIN_StateWaitEffectToMessage, GURU2_MAIN_StateWaitTimerToEnd
 * address: 0x021DF56C
 * packet: pkt_ov137_021DF56C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_PopBgmWhenDone 0x021E19A4 thumb ov137
 *   GURU2_MAIN_PrintMessage 0x021E0130 thumb ov137
 */
#include "../include/Obj08219.h"
#include "../include/Obj08220.h"
typedef unsigned char u8;
extern int GURU2_MAIN_PopBgmWhenDone(void);
extern void GURU2_MAIN_PrintMessage(u8 *p, int message);
int GURU2_MAIN_StateWaitEffectToMessage(u8 *p)
{
    if (((struct Obj08219 *)p)->fC < 180) {
        ((struct Obj08219 *)p)->fC += 1;
    } else if (GURU2_MAIN_PopBgmWhenDone() == 0) {
        ((struct Obj08219 *)p)->fC = 0;
        ((struct Obj08219 *)p)->f0 = 41;
        GURU2_MAIN_PrintMessage(p, 4);
    }
    return 0;
}
int GURU2_MAIN_StateWaitTimerToEnd(u8 *p)
{
    if (((struct Obj08220 *)p)->fC < 180) {
        ((struct Obj08220 *)p)->fC += 1;
    } else {
        ((struct Obj08220 *)p)->fC = 0;
        ((struct Obj08220 *)p)->f0 = 42;
    }
    return 0;
}
