/*
 * function: gsiXmlUtilSkipWhiteSpace
 * address:  0x02181E28
 * packet:   pkt_ov009_02181E28
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilSkipWhiteSpace (gsxml.o)
 *
 * symbols:
 *   strchr                           0x02094a28 arm
 *   gGsXmlWhiteSpaceChars                       0x021a3f14 data
 */

extern char gGsXmlWhiteSpaceChars[];
extern char *strchr(const char *s, int c);

static int gsiXmlUtilSkipWhiteSpace(void *unused, char *buffer, int len, int *pos)
{
    while (*pos < len)
    {
        if (strchr(gGsXmlWhiteSpaceChars, buffer[*pos]) == 0)
            return 1;
        (*pos)++;
    }
    return 0;
}
