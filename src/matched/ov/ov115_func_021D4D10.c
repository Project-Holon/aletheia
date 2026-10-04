/*
 * function: func_021D4D10
 * address: 0x021D4D10
 * packet: pkt_ov115_021D4D10
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_021D5A9C 0x021D5A9C thumb ov115
 *   func_021D4E04 0x021D4E04 thumb ov115
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_020403F4(u32 i);
extern void func_021D5A9C(u8 *);
extern void func_021D4E04(u8 *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021D4D10(u32 a,int b,int c,u8 *p) { func_020403F4(7); func_021D5A9C(*(u8 **)(p+56)); func_021D4E04(*(u8 **)(p+52)); func_020315D4((struct S020315D4 *)a); func_020306F0(120); return 1; }
