/*
 * function: func_021F8BBC
 * address: 0x021F8BBC
 * packet: pkt_ov135_021F8BBC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9B00 0x021B9B00 thumb ov114
 *   func_021C8E18 0x021C8E18 arm ov114
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021B9B00(u8 *,int);
extern void func_021C8E18(u8 *,u32);
int func_021F8BBC(u8 *p) { func_021B9B00(p+0xf18,*(int *)(*(u8 **)p+28));func_021C8E18(p+0xf18,(u32)(p+0xf7c));*(u32 *)(p+0xf8c)=0;return 1; }
