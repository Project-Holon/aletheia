/*
 * function: func_0217E1C0
 * address: 0x0217E1C0
 * packet: pkt_ov176_0217E1C0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CDBC 0x0203CDBC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203A5E4(int);
extern void func_0203CEAC(int);
extern int func_0203CDBC(void);
int func_0217E1C0(int *p) {switch(*p) {case 0:func_0203A5E4(0x1f00);func_0203CEAC(0);*p=1;break;case 1:if(func_0203CDBC())*p=2;break;case 2:return 1;}return 0;}
