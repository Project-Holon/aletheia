/*
 * function: gti2GetResponse
 * address:  0x02194C6C
 * packet:   pkt_ov009_02194C6C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2GetResponse (libdwcgsgt2.TWL.HYB.a(gt2auth.o))
 *
 * symbols:
 *   strlen                   0x0209477C  arm
 *   gti2VerifyChallenge      0x02194AD8  arm  ov009
 *   rand                     0x02094694  arm
 *   _s32_div_f               0x0209C0A4  arm
 *   abs                      0x02091588  arm
 *   g_021A591C               0x021A591C  data
 */

extern int strlen();
extern int gti2VerifyChallenge();
extern int rand();
extern int abs();
extern char g_021A591C[];

unsigned char *gti2GetResponse(unsigned char *buffer, unsigned char *challenge)
{
    int i;
    int valid;
    char cchar;
    int keylen;
    int chalrand;

    keylen = strlen(g_021A591C);
    valid = gti2VerifyChallenge(challenge);
    for (i = 0; i < 32; i++)
    {
        if (!valid || i == 0 || i == 13)
        {
            chalrand = rand();
            buffer[i] = (unsigned char)(33 + chalrand % 93);
        }
        else
        {
            if (i == 1 || i == 14)
                cchar = challenge[i];
            else
                cchar = challenge[i - 1];
            chalrand = g_021A591C[(i + challenge[i]) % keylen];
            buffer[i] = (unsigned char)(33 + abs(challenge[(i * challenge[i] + chalrand) % 32] ^ g_021A591C[(cchar * (i * 17991)) % keylen]) % 93);
        }
    }
    return buffer;
}
