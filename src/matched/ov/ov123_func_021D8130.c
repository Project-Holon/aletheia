/*
 * function: func_021D8130
 * address: 0x021D8130
 * packet: pkt_ov123_021D8130
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D80B8 0x021D80B8 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D580C(char *);
extern void func_021D6EE0(char *,int,int);
extern void func_021D80B8(char *p);
void func_021D8130(char *p) { if(func_021D580C(*(char **)(p+24))) func_021D6EE0(p,(int)func_021D80B8,0x5b3); }
