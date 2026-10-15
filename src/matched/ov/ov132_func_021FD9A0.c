/*
 * function: STA_SLOT_GetStateByKey
 * address: 0x021FD9A0
 * packet: pkt_ov132_021FD9A0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Left-associated base plus scaled index plus byte offset keeps
 * the returned byte load after both address additions.
 * symbols:
 */
unsigned char STA_SLOT_GetStateByKey(unsigned char *p,unsigned char key) {unsigned char i;for(i=0;i<4;i++){if(p[(unsigned int)i*48+114]==key) return *(unsigned char *)((unsigned int)p+(unsigned int)i*48+113);}return 10;}
