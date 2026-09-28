/*
 * function: gsXmlParseBuffer
 * address:  0x02181D10
 * packet:   pkt_ov009_02181D10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlParseBuffer (gsxml.o)
 *
 * symbols:
 *   gsXmlResetReader                 0x02181dc4 arm
 *   gsiXmlUtilParseElement           0x02181e80 arm
 */

extern void gsXmlResetReader(void *stream);
extern int gsiXmlUtilParseElement(void *stream, char *buffer, int len, int *pos, int parentIndex);

int gsXmlParseBuffer(void *stream, char *data, int len)
{
    int readPos = 0;

    gsXmlResetReader(stream);
    while (readPos < len)
    {
        if (gsiXmlUtilParseElement(stream, data, len, &readPos, -1) == 0)
            return 0;
    }
    return 1;
}
