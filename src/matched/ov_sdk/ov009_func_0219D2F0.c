/*
 * function: GOACryptInit
 * address:  0x0219D2F0
 * packet:   pkt_ov009_0219D2F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GOACryptInit (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
 *
 * symbols:
 *   GOAHashInit  0x0219D2A4  arm  ov009
 *   keyrand  0x0219D1F4  arm  ov009
 */

struct GOACryptState {
    unsigned char cards[256];
    unsigned char rotor;
    unsigned char ratchet;
    unsigned char avalanche;
    unsigned char last_plain;
    unsigned char last_cipher;
};

extern void GOAHashInit(struct GOACryptState *state);
extern unsigned char keyrand(struct GOACryptState *state, int limit, unsigned char *user_key,
                                   unsigned char keysize, unsigned char *rsum, unsigned int *keypos);

void GOACryptInit(struct GOACryptState *state, unsigned char *key, unsigned char keysize)
{
    unsigned int keypos;
    unsigned char rsum;
    unsigned char swaptemp;
    unsigned char toswap;
    int i;

    if (keysize < 1) {
        GOAHashInit(state);
        return;
    }
    for (i = 0; i < 256; i++)
        state->cards[i] = (unsigned char)i;
    keypos = 0;
    rsum = 0;
    for (i = 255; i >= 0; i--) {
        toswap = keyrand(state, i, key, keysize, &rsum, &keypos);
        swaptemp = state->cards[i];
        state->cards[i] = state->cards[toswap];
        state->cards[toswap] = swaptemp;
    }
    state->rotor = state->cards[1];
    state->ratchet = state->cards[3];
    state->avalanche = state->cards[5];
    state->last_plain = state->cards[7];
    state->last_cipher = state->cards[rsum];
}
