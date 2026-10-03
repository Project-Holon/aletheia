/*
 * function: func_021DA110
 * address: 0x021DA110
 * packet: pkt_ov123_021DA110
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9514 0x021D9514 thumb ov123
 *   func_021D95B4 0x021D95B4 thumb ov123
 *   func_021DA0E4 0x021DA0E4 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
typedef unsigned char u8;
extern void func_021D9514(char *,int);
extern void func_021D95B4(char *);
extern void func_021DA0E4(char *);
extern void func_021DA034(char *,int,int);
void func_021DA110(char *p) { func_021D9514(*(char **)(p+0x10),6); func_021D95B4(*(char **)(p+0x10)); func_021DA034(p,(int)func_021DA0E4,0x112); }
