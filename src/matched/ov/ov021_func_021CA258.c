/*
 * function: BSUBWAY_SCR_SetWinCountFromRound
 * address:  0x021CA258
 * packet:   pkt_ov021_021CA258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0xe]; u16 fE; } P;
void BSUBWAY_SCR_SetWinCountFromRound(P *p, u32 a, u32 b)
{
    u32 v = a * 7;
    v += b;
    if (v > 0xffff)
        v = 0xffff;
    p->fE = v;
}
