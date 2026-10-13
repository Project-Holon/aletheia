/*
 * function: BTL_CLIENT_IsCounterFadeDone
 * address: 0x021D3F4C
 * packet: pkt_ov093_021D3F4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef struct { u8 pad[2]; unsigned char f0:2; unsigned char flag:1; unsigned char rest:5; } Flags;
int BTL_CLIENT_IsCounterFadeDone(Flags *p)
{
    return p->flag;
}
