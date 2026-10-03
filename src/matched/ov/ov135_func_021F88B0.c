/*
 * function: func_021F88B0
 * address: 0x021F88B0
 * packet: pkt_ov135_021F88B0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_022030E8 0x022030E8 data a2
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern const u16 d_022030E8[];
void func_021F88B0(u8 *p,u32 n) { if(n==0){*(u32 *)(p+0xf84)=0;return;}n--;if(n<130)*(u32 *)(p+0xf84)=d_022030E8[n]; }
