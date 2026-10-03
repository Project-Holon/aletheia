/*
 * function: func_021BA444
 * address: 0x021BA444
 * packet: pkt_ov213_021BA444
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_021BA30C 0x021BA30C thumb ov213
 */
extern int func_021B9E50(unsigned);extern void func_021BA30C(char *);
enum Count{CountZero,CountTwo=2,CountFour=4};void func_021BA444(char *p){int i;enum Count count;if(func_021B9E50(*(unsigned char *)(p+0x49C8)))count=CountTwo;else count=CountFour;p+=0x483C;for(i=0;i<count;i++)func_021BA30C(p+i*84);}
