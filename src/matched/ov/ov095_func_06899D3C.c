/*
 * function: BTLV_SCD_CloseInputIfOpen
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
 *   BTLV_SCD_CloseInput 0x06899D64 thumb ov095
 */
typedef unsigned int u32;
extern int func_06899D54(u32);
extern void BTLV_SCD_CloseInput(u32);
void BTLV_SCD_CloseInputIfOpen(u32 p)
{
    if (func_06899D54(*(u32 *)(p + 0xB0)) != 0) BTLV_SCD_CloseInput(p);
}
