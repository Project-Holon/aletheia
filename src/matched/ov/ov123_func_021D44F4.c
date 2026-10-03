/*
 * function: func_021D44F4
 * address: 0x021D44F4
 * packet: pkt_ov123_021D44F4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4E7C 0x021D4E7C thumb ov123
 *   func_021D4DA4 0x021D4DA4 thumb ov123
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D449C 0x021D449C thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D4E7C(char *);
extern void func_021D4DA4(char *);
extern void func_021D4244(char *,void *,int);
extern void func_021D449C(char *);
void func_021D44F4(char *p) { if(func_021D4E7C(p)) { func_021D4DA4(p); func_021D4244(p,func_021D449C,0x1c9); } }
