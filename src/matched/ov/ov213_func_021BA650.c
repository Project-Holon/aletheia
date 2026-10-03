/*
 * function: func_021BA650
 * address: 0x021BA650
 * packet: pkt_ov213_021BA650
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
extern int func_021B9E50(unsigned);extern void func_0204B3DC(void *,unsigned),func_0204B92C(void *,unsigned);
void func_021BA650(char *p){func_021B9E50(*(unsigned char *)(p+38));if(*(unsigned short *)(p+36)==30){func_0204B3DC(*(void **)(p+16),1);func_0204B92C(*(void **)(p+16),1);func_0204B3DC(*(void **)(p+20),1);func_0204B92C(*(void **)(p+20),1);}(*(unsigned short *)(p+36))++;}
