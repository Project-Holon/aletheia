/*
 * function: func_021BE3EC
 * address: 0x021BE3EC
 * packet: pkt_ov204_021BE3EC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 */
extern void GFL_USE_PlaySeDefaultVolume(unsigned),GFL_USE_SetSeSlotVolume(int,unsigned),GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);
extern int GFL_USE_GetSeSlot(unsigned);
int func_021BE3EC(char *p,int *state,unsigned *q){int i;GFL_USE_PlaySeDefaultVolume(q[0]);i=GFL_USE_GetSeSlot(q[0]);if(q[1])GFL_USE_SetSeSlotVolume(i,q[1]);if(q[2])GFL_USE_SetSeSlotParams(i,-1,-1,q[2]);return 1;}
