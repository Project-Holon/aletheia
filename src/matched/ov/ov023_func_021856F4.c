/*
 * function: OEKAKI_StepWaitThenFadeOut
 * address: 0x021856F4
 * packet: pkt_ov023_021856F4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   OEKAKI_ApplyRemoteStrokes 0x02185354 thumb ov023
 */
#include "../include/Obj20351.h"
extern void WIPE_SYS_Start(void *, unsigned int, unsigned int, unsigned int,
                        unsigned int, unsigned int, unsigned int);
extern void OEKAKI_ApplyRemoteStrokes(char *);
int OEKAKI_StepWaitThenFadeOut(char *p, int a)
{
    if (++((struct Obj20351 *)p)->f1A4 > 60) {
        WIPE_SYS_Start(0, 8, 8, 0, 0x10, 1, 0x28);
        a = 3;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return a;
}
