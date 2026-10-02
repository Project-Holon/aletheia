/*
 * function: func_021B9750
 * address: 0x021B9750
 * packet: pkt_ov091_021B9750
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB8FC 0x021BB8FC thumb ov091
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 */
extern int func_021BB8FC(unsigned,unsigned);
extern unsigned func_020362DC(void);
extern int func_02035C60(void);
void func_021B9750(unsigned p) { if(func_021BB8FC(p,*(unsigned *)(p+336))==1) { if(func_020362DC()&1) *(unsigned *)(p+8)=0; if(func_02035C60()==1) *(unsigned *)(p+8)=1; (*(void (**)(unsigned))(p+328))(p); } }
