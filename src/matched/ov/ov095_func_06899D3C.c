/*
 * function: func_06899D3C
 * address: 0x06899D3C
 * packet: pkt_ov095_06899D3C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_06899D54 0x06899D54 thumb ov095
 *   func_06899D64 0x06899D64 thumb ov095
 */
typedef unsigned int u32;
extern int func_06899D54(u32);
extern void func_06899D64(u32);
void func_06899D3C(u32 p)
{
    if (func_06899D54(*(u32 *)(p + 0xB0)) != 0) func_06899D64(p);
}
