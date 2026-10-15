/*
 * function: GOADecrypt
 * address:  0x0219D478
 * packet:   pkt_ov009_0219D478
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GOADecrypt (libdwcgsserverbrowsing.TWL.HYB.a(sb_crypt.o))
 *
 * symbols:
 *   GOADecryptByte  0x0219D3AC  arm  ov009
 */

struct GOACryptState {
    unsigned char cards[256];
    unsigned char rotor;
    unsigned char ratchet;
    unsigned char avalanche;
    unsigned char last_plain;
    unsigned char last_cipher;
};

extern unsigned char GOADecryptByte(struct GOACryptState *state, unsigned char b);

void GOADecrypt(struct GOACryptState *state, unsigned char *bp, int len)
{
    int i;

    for (i = 0; i < len; i++)
        bp[i] = GOADecryptByte(state, bp[i]);
}
