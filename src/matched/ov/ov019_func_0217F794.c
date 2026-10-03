/*
 * function: func_0217F794
 * address: 0x0217F794
 * packet: pkt_ov019_0217F794
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188C54 0x02188C54 thumb ov021
 *   func_021904A8 0x021904A8 thumb ov021
 *   func_0201C6B4 0x0201C6B4 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 *func_02188C54(u32 a);
extern u32 func_021904A8(u32 *p);
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
u32 func_0217F794(char *p,u32 a) { u32 h=func_021904A8(func_02188C54(a)); if(*(void **)(p+0x3530)==0) return 1; return func_0201C6B4((void *)h); }
