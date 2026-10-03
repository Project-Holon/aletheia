/*
 * function: func_021FC394
 * address: 0x021FC394
 * packet: pkt_ov186_021FC394
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D48 0x02200D48 data a1
 *   d_022008E0 0x022008E0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_02200D48[];
extern const u32 d_022008E0[];
extern void func_02034714(const char*,int,const char*);
u16 func_021FC394(u32 n){if(n>=8)func_02034714(d_02200D48,0,d_02200D48);return *(const u32*)((u32)d_022008E0+n*4);}
