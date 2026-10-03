/*
 * function: func_021D7088
 * address: 0x021D7088
 * packet: pkt_ov123_021D7088
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D580C 0x021D580C thumb ov123
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D706C 0x021D706C thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D580C(char *);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021D6EE0(char *,int,int);
extern void func_021D706C(void);
void func_021D7088(char *p) { if(func_021D580C(*(char **)(p+24)) && (func_020362DC() || func_02035C60())) func_021D6EE0(p,(int)func_021D706C,0x1d9); }
