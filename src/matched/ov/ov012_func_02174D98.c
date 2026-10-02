/*
 * function: func_02174D98
 * address: 0x02174D98
 * packet: pkt_ov012_02174D98
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes 020399A8's live r0 despite its filed void return.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0201A918 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned int u32;
extern u32 func_020399A8(void);
extern int func_0201A918(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_02174D98(u32 p)
{
    u32 a = func_020399A8();
    return func_0203D3F8(a,255,0x1506,func_0201A918(),p,1,0,1);
}
