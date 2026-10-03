/*
 * function: func_021BBA28
 * address: 0x021BBA28
 * packet: pkt_ov091_021BBA28
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
extern unsigned int func_02045770(unsigned int);
extern void func_02043B5C(int,int);
extern void func_02045334(unsigned int);
extern void func_02045374(unsigned int);
extern unsigned char func_02045730(unsigned int);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021BBA28(int a,int b) {unsigned int q; func_02043B5C(func_02045770(*(unsigned int *)(b+4)),15); q=*(unsigned int *)(b+4); func_02045334(q);func_02045374(q);func_02041B6C(func_02045730(q));}
