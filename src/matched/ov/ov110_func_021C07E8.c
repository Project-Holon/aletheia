/*
 * function: func_021C07E8
 * address: 0x021C07E8
 * packet: pkt_ov110_021C07E8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_020452E8(void *);
extern void func_0203FB44(u32,u16,u16);
extern void func_020307B0(void *);
void func_021C07E8(u8 *p) { func_020452E8(*(void **)(p+0x24)); func_0203FB44(3,*(u32 *)p,*(u32 *)p>>16); func_020307B0(*(void **)(p+4)); }
