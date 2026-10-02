/*
 * function: func_021F4064
 * address: 0x021F4064
 * packet: pkt_ov046_021F4064
 * region: ov046
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4020 0x021F4020 thumb ov046
 *   func_0216DAC8 0x0216DAC8 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F4020(u32,int);
extern void func_0216DAC8(u32 *,u32);
void func_021F4064(u32 a,int b,u32 c) { u32 *p; p=(u32 *)func_021F4020(a,b); if(p) func_0216DAC8(p,c); }
