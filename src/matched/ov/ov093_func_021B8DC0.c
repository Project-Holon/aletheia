/*
 * function: BTL_MAIN_GetViewPosOfPoke
 * address: 0x021B8DC0
 * packet: pkt_ov093_021B8DC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_MAIN_GetViewPosOfSlot 0x021B8E70 thumb ov093
 */
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *,void *,unsigned int);
extern unsigned char BTL_MAIN_GetViewPosOfSlot(unsigned char *,unsigned int);
unsigned char BTL_MAIN_GetViewPosOfPoke(unsigned char *p,void *a,unsigned int b) { int k=BTL_MAIN_GetTrainerSlotOfPoke(p,a,b); if(k!=6) return BTL_MAIN_GetViewPosOfSlot(p,k); return 255; }
