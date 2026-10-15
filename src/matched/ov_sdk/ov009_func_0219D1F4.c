/*
 * function: keyrand
 * address:  0x0219D1F4
 * packet:   pkt_ov009_0219D1F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      keyrand (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
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

unsigned char keyrand(struct GOACryptState *state, int limit, unsigned char *user_key,
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
