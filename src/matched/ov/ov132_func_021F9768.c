/*
 * function: STA_ACTING_GetCurrentAction
 * address: 0x021F9768
 * packet: pkt_ov132_021F9768
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACTING_GetActionByIndex 0x021F9774 thumb ov132
 */
#include "../include/Obj08155.h"
typedef unsigned char u8;
extern int STA_ACTING_GetActionByIndex(char *,unsigned int);
int STA_ACTING_GetCurrentAction(char *p){return STA_ACTING_GetActionByIndex(p,((struct Obj08155 *)p)->fA);}
