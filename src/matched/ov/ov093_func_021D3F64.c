/*
 * function: BTL_CLIENT_StartCounterReplay
 * address: 0x021D3F64
 * packet: pkt_ov093_021D3F64
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: object is the same 14-byte record as BTL_CLIENT_ResetCounter (bit flags in byte 2).
 *   Sets h8 = v, bit0 = 1, h12 = 0, clears bits 1 and 2. Source order h12 = 0 before h8 = v:
 *   the scheduler hoists the strh, and r1 (v) stays live so the zero takes r2.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    u8 b0;
    u8 b1;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 h10;
    u16 h12;
} S;
void BTL_CLIENT_StartCounterReplay(S *p, u16 v)
{
    p->f0 = 1;
    p->h12 = 0;
    p->h8 = v;
    p->f1 = 0;
    p->f2 = 0;
}
