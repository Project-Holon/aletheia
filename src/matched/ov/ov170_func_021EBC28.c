/*
 * function: BOX2_SEQ_PrintIndexedMessage
 * address: 0x021EBC28
 * packet: pkt_ov170_021EBC28
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_PrintMessageMsg 0x021EBA84 thumb ov170
 */
extern void BOX2_SEQ_PrintMessageMsg(unsigned char *,int,int);
void BOX2_SEQ_PrintIndexedMessage(unsigned char *p,int n,int i){switch(n){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;case 3:n=10;break;}BOX2_SEQ_PrintMessageMsg(p,n,i);}
