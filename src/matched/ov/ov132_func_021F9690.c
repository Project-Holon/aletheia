/*
 * function: STA_ACTING_StopSeq
 * address: 0x021F9690
 * packet: pkt_ov132_021F9690
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_StopSeqAndUnload 0x02006504 thumb
 */
#include "../include/Obj23186.h"
extern void GFL_USE_StopSeqAndUnload(void);
void STA_ACTING_StopSeq(char *p){((struct Obj23186 *)p)->f28=0;GFL_USE_StopSeqAndUnload();}
