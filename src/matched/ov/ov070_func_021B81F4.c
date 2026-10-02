/*
 * function: func_021B81F4
 * address: 0x021B81F4
 * packet: pkt_ov070_021B81F4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B81B0 0x021B81B0 thumb ov070
 *   func_02012BF8 0x02012BF8 thumb
 *   func_0204B878 0x0204B878 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B81B0(int x);
extern int func_02012BF8(int p, int a);
extern void func_0204B878(void *p, u16 v);
void func_021B81F4(u8 *p) { if (*(int *)(p+0x81C)!=1) func_0204B878(*(void **)(p+0x718),(unsigned int)func_02012BF8(*(int *)p,func_021B81B0(*(int *)(p+0x80C)))+6u); }
