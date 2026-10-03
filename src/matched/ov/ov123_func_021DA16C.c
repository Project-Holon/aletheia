/*
 * function: func_021DA16C
 * address: 0x021DA16C
 * packet: pkt_ov123_021DA16C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021D9844 0x021D9844 thumb ov123
 *   func_021D9730 0x021D9730 thumb ov123
 *   func_021DA138 0x021DA138 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
typedef unsigned char u8;
extern unsigned int func_020362DC(void);
extern void func_021D9844(char *,int,int);
extern void func_021D9730(char *,int);
extern void func_021DA138(char *);
extern void func_021DA034(char *,int,int);
void func_021DA16C(char *p) { if(func_020362DC()) { func_021D9844(*(char **)(p+0x10),*(int *)(p+0x28),*(int *)(p+0x28)); func_021D9730(*(char **)(p+0x10),9); func_021DA034(p,(int)func_021DA138,0x12a); } }
