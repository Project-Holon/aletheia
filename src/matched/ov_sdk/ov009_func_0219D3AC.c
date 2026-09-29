/*
 * function: func_0219D3AC
 * address:  0x0219D3AC
 * packet:   pkt_ov009_0219D3AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GOADecryptByte (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
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

unsigned char func_0219D3AC(struct GOACryptState *state, unsigned char b)
{
    unsigned char swaptemp;

    state->ratchet = (unsigned char)(state->ratchet + state->cards[state->rotor++]);
    swaptemp = state->cards[state->last_cipher];
    state->cards[state->last_cipher] = state->cards[state->ratchet];
    state->cards[state->ratchet] = state->cards[state->last_plain];
    state->cards[state->last_plain] = state->cards[state->rotor];
    state->cards[state->rotor] = swaptemp;
    state->avalanche = (unsigned char)(state->avalanche + state->cards[swaptemp]);
    state->last_plain = (unsigned char)(b
        ^ state->cards[(state->cards[state->avalanche] + state->cards[state->rotor]) & 0xff]
        ^ state->cards[state->cards[(state->cards[state->last_plain] + state->cards[state->last_cipher] + state->cards[state->ratchet]) & 0xff]]);
    state->last_cipher = b;
    return state->last_plain;
}
