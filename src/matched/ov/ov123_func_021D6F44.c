/*
 * unit: no
 * function: func_021D6F44
 * address: 0x021D6F44
 * packet: pkt_ov123_021D6F44
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5C0C 0x021D5C0C thumb ov123
 *   func_021D5B70 0x021D5B70 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D706C 0x021D706C thumb ov123
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern int func_021D5C0C(int);
extern void func_021D5B70(int);
extern void func_021D6EE0(u8 *,u32,int);
extern void func_021D706C(char *);
void func_021D6F44(u8 *p){if(func_021D5C0C(*(int *)(p+8))){func_021D5B70(*(int *)(p+8));*(int *)(p+8)=0;func_021D6EE0(p,(u32)func_021D706C,0x17c);}}
