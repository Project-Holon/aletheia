/*
 * function: func_021BA408
 * address: 0x021BA408
 * packet: pkt_ov213_021BA408
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_021BA2F0 0x021BA2F0 thumb ov213
 */
extern int func_021B9E50(unsigned);extern void func_021BA2F0(char *);
enum Count{CountZero,CountTwo=2,CountFour=4};void func_021BA408(char *p){int i;enum Count count;if(func_021B9E50(*(unsigned char *)(p+0x49C8)))count=CountTwo;else count=CountFour;p+=0x483C;for(i=0;i<count;i++)func_021BA2F0(p+i*84);}
