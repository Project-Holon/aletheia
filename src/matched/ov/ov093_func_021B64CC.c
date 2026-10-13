/*
 * function: BTL_MAIN_IsRecordPlaybackDone
 * address: 0x021B64CC
 * packet: pkt_ov093_021B64CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_REC_IsChannelDone 0x021EE894 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
extern int BTL_REC_IsChannelDone(void *,u8);
int BTL_MAIN_IsRecordPlaybackDone(u8 *p) { unsigned int i; for(i=0;i<4;i++) { if(BTL_MAIN_IsClientUsed(p,i)) { if(!BTL_REC_IsChannelDone(p+0x2c8,i)) return 0; } } return 1; }
