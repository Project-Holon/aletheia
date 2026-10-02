/*
 * function: func_02175C40
 * address: 0x02175C40
 * packet: pkt_ov011_02175C40
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02175C58 0x02175C58 thumb ov011
 */
typedef unsigned char u8;
typedef struct { u8 pad[0x1a5]; u8 low:5; u8 value:2; u8 high:1; } Bits;
extern void func_02175C58(void *, int);
int func_02175C40(void *p)
{
    int v;
    v = ((Bits *)p)->value;
    func_02175C58(p, 0);
    return v;
}
