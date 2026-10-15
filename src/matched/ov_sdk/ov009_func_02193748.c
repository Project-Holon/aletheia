/*
 * function: gpiEncodeString
 * address:  0x02193748
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiEncodeString: seed the shared RNG with the constant 0x79707367 ("gspy"),
 * XOR each plaintext byte with a random byte, then hand the temporary to
 * B64Encode with mode 1.
 *
 * symbols:
 *   strlen  0x0209477C  arm
 *   Util_RandSeed  0x0217F790  arm  ov009
 *   Util_RandInt  0x0217F7AC  arm  ov009
 *   B64Encode  0x0217FA90  arm  ov009
 */

typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern void Util_RandSeed(unsigned int v);
extern unsigned int Util_RandInt(unsigned int min, unsigned int max);
extern void B64Encode(const char *input, char *output, int inlen, int encodingType);

void gpiEncodeString(const char *plaintext, char *encoded)
{
    char temp[0x20];
    unsigned int i;
    unsigned int len;

    len = strlen((const u8 *)plaintext);
    Util_RandSeed(0x79707367);
    for (i = 0; i < len; i++)
        temp[i] = plaintext[i] ^ (char)Util_RandInt(0, 0xff);
    temp[i] = 0;
    B64Encode(temp, encoded, len, 1);
}
