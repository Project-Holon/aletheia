/*
 * function: GOAHashInit
 * address:  0x0219D2A4
 * packet:   pkt_ov009_0219D2A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GOAHashInit (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
 *
 * symbols:
 */

struct GOACryptState {
    unsigned char cards[256];
    unsigned char rotor;
    unsigned char ratchet;
    unsigned char avalanche;
    unsigned char last_plain;
    unsigned char last_cipher;
};

void GOAHashInit(struct GOACryptState *state)
{
    int i, j;

    state->rotor = 1;
    state->ratchet = 3;
    state->avalanche = 5;
    state->last_plain = 7;
    state->last_cipher = 11;
    for (i = 0, j = 255; i < 256; i++, j--)
        state->cards[i] = (unsigned char)j;
}
