/*
 * function: STA_ACTING_StopBgm
 * address: 0x021F96C4
 * packet: pkt_ov132_021F96C4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 */
#include "../include/Obj23189.h"
extern void GFL_USE_CancelChangeAndStopBgm(void);
void STA_ACTING_StopBgm(char *p){((struct Obj23189 *)p)->f2C=0;GFL_USE_CancelChangeAndStopBgm();}
