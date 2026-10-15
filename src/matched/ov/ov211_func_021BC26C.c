/*
 * function: ZUKAN_SEARCH_PROC_IsDone
 * address: 0x021BC26C
 * packet: pkt_ov211_021BC26C
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_SEARCH_PROC_Update 0x021BC290 thumb ov211
 */
extern int ZUKAN_SEARCH_PROC_Update(unsigned char *);
int ZUKAN_SEARCH_PROC_IsDone(int a,int b,int c,unsigned char *p){return ZUKAN_SEARCH_PROC_Update(p)==0;}
