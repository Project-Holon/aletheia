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
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_02174D98(u32 p)
{
    u32 a = (u32)func_020399A8();
    return func_0203D3F8(a,255,0x1506,POKE_REGULATION_GetDataSize(),p,1,0,1);
}
