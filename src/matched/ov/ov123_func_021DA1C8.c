/*
 * function: func_021DA1C8
 * address: 0x021DA1C8
 * packet: pkt_ov123_021DA1C8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021DA054 0x021DA054 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
typedef unsigned char u8;
extern unsigned int func_020362DC(void);
extern void func_021DA054(char *);
extern void func_021DA034(char *,int,int);
void func_021DA1C8(char *p) { if(func_020362DC() & 3) func_021DA034(p,(int)func_021DA054,0x14b); }
