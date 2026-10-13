/*
 * function: MUSICAL_EVENT_TrimAllPartiesToThree
 * address:  0x02155224
 * packet:   pkt_ov010_02155224
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Trims the list at +0x38 and the four lists at +0x3c to three entries each.
 *
 * symbols:
 *   MUSICAL_EVENT_TrimPartyToThree  0x02155200  thumb  ov010
 */

typedef unsigned char u8;

struct Ctx {
    u8 pad00[0x38];
    void *f38;
    void *f3c[4];
};

extern void MUSICAL_EVENT_TrimPartyToThree(void *list);

void MUSICAL_EVENT_TrimAllPartiesToThree(struct Ctx *ctx)
{
    int i;

    MUSICAL_EVENT_TrimPartyToThree(ctx->f38);
    for (i = 0; i < 4; i++)
        MUSICAL_EVENT_TrimPartyToThree(ctx->f3c[i]);
}
