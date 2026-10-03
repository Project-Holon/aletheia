/*
 * function: func_021DA090
 * address: 0x021DA090
 * packet: pkt_ov123_021DA090
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D95F0 0x021D95F0 thumb ov123
 *   func_020362DC 0x020362DC arm
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA054 0x021DA054 thumb ov123
 */
extern int func_021D95F0(char *);
extern unsigned int func_020362DC(void);
extern void func_021DA034(char *,int,int);
extern void func_021DA054(char *p);
void func_021DA090(char *p) { if(func_021D95F0(*(char **)(p+0x10)) && func_020362DC()!=0) func_021DA034(p,(int)func_021DA054,0xf1); }
