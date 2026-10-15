/*
 * function: GSMD5Print
 * address:  0x02185854
 * packet:   pkt_ov009_02185854
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GSMD5Print (md5c)
 *
 * symbols:
 *   gMd5cHexDigits  0x021A1A40 data
 */

extern char gMd5cHexDigits[];

void GSMD5Print(unsigned char * digest, char * output)
{
    unsigned int i;

    for (i = 0; i < 16; i++)
    {
        output[i * 2] = gMd5cHexDigits[digest[i] / 16];
        output[i * 2 + 1] = gMd5cHexDigits[digest[i] % 16];
    }
    output[32] = 0;
}
