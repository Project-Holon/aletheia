/*
 * function: func_021E5980
 * address: 0x021E5980
 * packet: pkt_ov177_021E5980
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: observed three color arrays; cached phase on wrap, compound increment reload on no-wrap.
 * symbols:
 *   func_021E5A30 0x021E5A30 thumb ov177
 */
extern void func_021E5A30(unsigned, unsigned short *, const unsigned short *, unsigned, unsigned char, unsigned char, unsigned short, unsigned short);
typedef struct { char pad[0x18]; unsigned short out[16], original[16], target[16], phase; } State;
void func_021E5980(State *p)
{
    int i;
    unsigned short phase = p->phase;
    if (phase + 0x200 >= 0x10000)
        p->phase = phase - 0xfe00;
    else
        p->phase += 0x200;
    for (i = 0; i < 16; i++) {
        func_021E5A30(15, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        func_021E5A30(31, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        func_021E5A30(14, &p->out[i], &p->phase, 0, 2, i, p->original[i], p->target[i]);
    }
}
