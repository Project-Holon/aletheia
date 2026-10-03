/*
 * function: func_021DA244
 * address: 0x021DA244
 * packet: pkt_ov123_021DA244
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D95F0 0x021D95F0 thumb ov123
 *   func_021DA3A0 0x021DA3A0 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
typedef unsigned char u8;
extern int func_021D95F0(char *);
extern void func_021DA3A0(char *);
extern void func_021DA034(char *,int,int);
void func_021DA244(char *p) { if(func_021D95F0(*(char **)(p+0x10))) func_021DA034(p,(int)func_021DA3A0,0x172); }
