/*
 * function: func_021D4504
 * address: 0x021D4504
 * packet: pkt_ov124_021D4504
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
extern void func_0204B1CC(struct Bank *);
extern void func_0204A5AC(void);
extern void func_020403F4(u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
void func_021D4504(char *p) {func_0204B1CC(*(struct Bank **)(p+0x4c));func_0204A5AC();func_020403F4(4);func_020403F4(5);func_020403F4(6);func_020403F4(7);func_020450C8();func_0203F9B4();}
