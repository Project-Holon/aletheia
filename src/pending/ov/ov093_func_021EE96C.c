/*
 * function: func_021EE96C
 * address:  0x021EE96C
 * packet:   pkt_ov093_021EE96C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02: DIFF, 14 bytes. Header-bit packer: byte5 = (cnt & 0xf) |
 * (bit6 of byte3 << 7) | ((low 3 of x) << 4), returns p+4 and the length,
 * or 0 if bit7 of byte3 is set. Shift-pair spellings ((u32)f << 31) >> 24
 * and ((u32)x << 29) >> 25 reproduce the instructions; remaining diff is
 * the or-chain order and which register holds x (original x in r3, 0xf mask
 * in r1). Tried term orders, parenthesisation, local H struct (stack spill,
 * worse), temp locals.
 *
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 len;
    u8 mask;
    u8 cnt;
    u8 x : 6;
    u8 f : 1;
    u8 g : 1;
    u8 d[60];
} B;

u8 *func_021EE96C(B *p, u8 b, u32 *out)
{
    if (p->g == 0) {
        p->d[0] = b;
        p->d[1] = (p->cnt & 0xf) | (((u32)p->f << 31) >> 24) | (((u32)p->x << 29) >> 25);
        *out = p->len;
        return p->d;
    }
    return 0;
}
