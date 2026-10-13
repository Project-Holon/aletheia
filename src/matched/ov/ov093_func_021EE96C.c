/*
 * function: BTL_REC_FinishPacket
 * address:  0x021EE96C
 * packet:   pkt_ov093_021EE96C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Header-bit packer: stores b at d[0], builds the header byte d[1] from
 * the flag bit, the low 3 bits of x and the low 4 bits of cnt, returns
 * p->d and the length, or 0 if g is set. The `d[1] = 0` store is dead
 * and the compiler removes it, but it blocks copy propagation of
 * `type`, so x stays in its own temporary read after the d[0] store.
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

u8 *BTL_REC_FinishPacket(B *p, u8 b, u32 *out)
{
    u8 type;

    if (p->g == 0) {
        p->d[0] = b;
        type = p->x;
        p->d[1] = 0;
        p->d[1] = ((p->f & 1) << 7) | ((type & 7) << 4) | (p->cnt & 0xf);
        *out = p->len;
        return p->d;
    }
    return 0;
}
