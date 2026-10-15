/*
 * function: PSEL_GRAPHIC_SetRecordState
 * address: 0x021BB974
 * packet: pkt_ov223_021BB974
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
void PSEL_GRAPHIC_SetRecordState(unsigned char *p,unsigned index,int cmd){switch(cmd){case 0:if(*(unsigned short *)((unsigned)p+212+index*148)!=0)*(unsigned short *)((unsigned)p+212+index*148)=3;break;case 2:if(*(unsigned short *)((unsigned)p+212+index*148)!=2)*(unsigned short *)((unsigned)p+212+index*148)=1;break;}}
