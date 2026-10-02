/*
 * function: func_02173840
 * address: 0x02173840
 * packet: pkt_ov012_02173840
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012114 0x02012114 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188BE8 0x02188BE8 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Ctx;
extern u32 func_02012114(const struct Ctx *p);
extern u32 func_0201210C(const struct Ctx *p);
extern int func_02188BE8(u32 p);
int func_02173840(u8 *p) { if(p[0x282a]==1 && func_02012114(*(const struct Ctx **)(*(u8 **)p+0xc))==1 && func_02188BE8(func_0201210C(*(const struct Ctx **)(*(u8 **)p+0xc)))==1) return 1; return 0; }
