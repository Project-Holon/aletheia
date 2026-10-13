/*
 * function: P_STA_SUB_DeleteMcss
 * address: 0x021D797C
 * packet: pkt_ov131_021D797C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_Del 0x02015BA4 thumb
 */
#include "../include/Obj14069.h"
extern void MCSS_SetVanishFlag(void *);
extern void MCSS_Del(void *,void *);
void P_STA_SUB_DeleteMcss(unsigned char *p,void **q) {
 MCSS_SetVanishFlag(q[0]);
 MCSS_SetVanishFlag(q[1]);
 MCSS_Del(((struct Obj14069 *)p)->f78,q[0]);
 MCSS_Del(((struct Obj14069 *)p)->f78,q[1]);
 q[0]=0;
 q[1]=0;
}
