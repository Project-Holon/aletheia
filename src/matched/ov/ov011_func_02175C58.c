/*
 * function: func_02175C58
 * address: 0x02175C58
 * packet: pkt_ov011_02175C58
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef struct { u8 pad[0x1a5]; u8 low:5; u8 value:2; u8 high:1; } Bits;
void func_02175C58(void *p, int v)
{
    ((Bits *)p)->value = v;
}
