/*
 * function: func_021D4FEC
 * address: 0x021D4FEC
 * packet: pkt_ov123_021D4FEC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021D4E64 0x021D4E64 thumb ov123
 *   func_021D4D40 0x021D4D40 thumb ov123
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4440 0x021D4440 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02012DD0(void *);
extern void func_021D4E64(char *);
extern void func_021D4D40(char *,int);
extern void func_021D4244(char *,void *,int);
extern void func_021D4440(void *);
void func_021D4FEC(char *p) { if(func_02012DD0(*(void **)(p+0x260))==2) { func_021D4E64(p); func_021D4D40(p,0); func_021D4244(p,func_021D4440,0x4ea); } }
