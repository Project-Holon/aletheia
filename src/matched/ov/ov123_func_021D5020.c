/*
 * function: func_021D5020
 * address: 0x021D5020
 * packet: pkt_ov123_021D5020
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4E7C 0x021D4E7C thumb ov123
 *   func_02012DAC 0x02012DAC thumb
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4FEC 0x021D4FEC thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D4E7C(char *);
extern int func_02012DAC(int a0);
extern void func_021D4244(char *,void *,int);
extern void func_021D4FEC(char *);
void func_021D5020(char *p) { if(func_021D4E7C(p)) { func_02012DAC((int)(*(void **)(p+0x260))); func_021D4244(p,func_021D4FEC,0x4fa); } }
