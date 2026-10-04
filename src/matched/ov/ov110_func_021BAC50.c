/*
 * function: func_021BAC50
 * address: 0x021BAC50
 * packet: pkt_ov110_021BAC50
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned int u32;
struct V3 { u32 a, b, c; };
void func_021BAC50(char *p, struct V3 *out, int i)
{
    *out = *(struct V3 *)(p + i * 12 + 0x3c);
}
