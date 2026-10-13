/*
 * function: BTL_CLIENT_ResetCounter
 * address:  0x021D3F04
 * packet:   pkt_ov093_021D3F04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f3 : 1;
    u8 f4 : 1;
    u8 f5 : 1;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 h10;
    u16 h12;
} S;

void BTL_CLIENT_ResetCounter(S *p)
{
    p->b1 = 0;
    p->f3 = 0;
    p->b0 = 0;
    p->f1 = 0;
    p->h6 = 0;
    p->f2 = 0;
    p->h8 = 0;
    p->f0 = 0;
    p->h10 = 0;
    p->f4 = 0;
    p->f5 = 0;
    p->h12 = 0;
    p->h4 = 0;
}
