/*
 * file:     sb_crypt.c
 * unit:     yes
 * function: func_0219D1F4, func_0219D2A4, func_0219D2F0, func_0219D3AC, func_0219D478
 * address:  0x0219D1F4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */
struct GOACryptState {
    unsigned char cards[256];
    unsigned char rotor;
    unsigned char ratchet;
    unsigned char avalanche;
    unsigned char last_plain;
    unsigned char last_cipher;
};

unsigned char func_0219D1F4(struct GOACryptState *state, int limit, unsigned char *user_key, unsigned char keysize, unsigned char *rsum, unsigned int *keypos);
void func_0219D2A4(struct GOACryptState *state);
void func_0219D2F0(struct GOACryptState *state, unsigned char *key, unsigned char keysize);
unsigned char func_0219D3AC(struct GOACryptState *state, unsigned char b);
void func_0219D478(struct GOACryptState *state, unsigned char *bp, int len);


/*
 * sdk:      keyrand (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
 */
unsigned char func_0219D1F4(struct GOACryptState *state, int limit, unsigned char *user_key,
                            unsigned char keysize, unsigned char *rsum, unsigned int *keypos)
{
    unsigned int u, retry_limiter, mask;

    if (!limit)
        return 0;
    retry_limiter = 0;
    mask = 1;
    while (mask < (unsigned int)limit)
        mask = (mask << 1) + 1;
    do {
        retry_limiter++;
        *rsum = (unsigned char)(state->cards[*rsum] + user_key[(*keypos)++]);
        if (*keypos >= keysize) {
            *keypos = 0;
            *rsum = (unsigned char)(*rsum + keysize);
        }
        u = mask & *rsum;
        if (retry_limiter > 11)
            u %= limit;
    } while (u > (unsigned int)limit);
    return (unsigned char)u;
}


/*
 * sdk:      GOAHashInit (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
 */
void func_0219D2A4(struct GOACryptState *state)
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


/*
 * sdk:      GOACryptInit (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
 */
void func_0219D2F0(struct GOACryptState *state, unsigned char *key, unsigned char keysize)
{
    unsigned int keypos;
    unsigned char rsum;
    unsigned char swaptemp;
    unsigned char toswap;
    int i;

    if (keysize < 1) {
        func_0219D2A4(state);
        return;
    }
    for (i = 0; i < 256; i++)
        state->cards[i] = (unsigned char)i;
    keypos = 0;
    rsum = 0;
    for (i = 255; i >= 0; i--) {
        toswap = func_0219D1F4(state, i, key, keysize, &rsum, &keypos);
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


/*
 * sdk:      GOADecryptByte (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
 */
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


/*
 * sdk:      GOADecrypt (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
 */
void func_0219D478(struct GOACryptState *state, unsigned char *bp, int len)
{
    int i;

    for (i = 0; i < len; i++)
        bp[i] = func_0219D3AC(state, bp[i]);
}
