/*
 * function: FLD_VREQ_SetBgVisible
 * address:  0x021D3244
 * packet:   pkt_ov021_021D3244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct St021D3244 {
    u8 pad0[0x2c];
    u8 v[8];
} St021D3244;

void FLD_VREQ_SetBgVisible(St021D3244 *p, int i, u8 v)
{
    p->v[i] = v;
}
