/*
 * function: func_021DCC5C
 * address: 0x021DCC5C
 * packet: pkt_ov093_021DCC5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DCC80 0x021DCC80 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021DCC80(void *,void *,int,int *);
void func_021DCC5C(void *a,void *b,int c,int *d) { if(c==func_021D775C(2)) func_021DCC80(a,b,c,d); }
