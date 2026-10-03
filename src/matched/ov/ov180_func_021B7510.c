/*
 * function: func_021B7510
 * address: 0x021B7510
 * packet: pkt_ov180_021B7510
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_0204A8D4(u32);
void func_021B7510(char *p,int n) { if(*(u32 *)(p+0x90cc+n*4)!=~0u) { func_0204A8D4(*(u32 *)(p+0x90cc+n*4)); *(u32 *)(p+0x90cc+n*4)=~0u; } }
