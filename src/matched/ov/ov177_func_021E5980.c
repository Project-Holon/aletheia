/*
 * function: WIFIBATTLEMATCH_VIEW_UpdateAnimation
 * address: 0x021E5980
 * packet: pkt_ov177_021E5980
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: observed three color arrays; cached phase on wrap, compound increment reload on no-wrap.
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_BlendColors 0x021E5A30 thumb ov177
 */
extern void WIFIBATTLEMATCH_VIEW_BlendColors(unsigned, unsigned short *, const unsigned short *, unsigned, unsigned char, unsigned char, unsigned short, unsigned short);
typedef struct { char pad[0x18]; unsigned short out[16], original[16], target[16], phase; } State;
void WIFIBATTLEMATCH_VIEW_UpdateAnimation(State *p)
{
    int i;
    unsigned short phase = p->phase;
    if (phase + 0x200 >= 0x10000)
        p->phase = phase - 0xfe00;
    else
        p->phase += 0x200;
    for (i = 0; i < 16; i++) {
        WIFIBATTLEMATCH_VIEW_BlendColors(15, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        WIFIBATTLEMATCH_VIEW_BlendColors(31, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        WIFIBATTLEMATCH_VIEW_BlendColors(14, &p->out[i], &p->phase, 0, 2, i, p->original[i], p->target[i]);
    }
}
