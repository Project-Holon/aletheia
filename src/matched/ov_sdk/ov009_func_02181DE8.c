/*
 * function: gsXmlCloseWriter
 * address:  0x02181DE8
 * packet:   pkt_ov009_02181DE8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlCloseWriter (gsxml.o)
 *
 * symbols:
 *   gsiXmlUtilWriteString            0x0218325c arm
 *   gGsXmlSoapEnvelopeEnd                       0x021a3eec data
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
    int bookkeeping;/* 0x0C */
};

extern char gGsXmlSoapEnvelopeEnd[];
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str);

int gsXmlCloseWriter(void *stream)
{
    struct GSIXmlStreamWriter * writer = (struct GSIXmlStreamWriter *)stream;
    int result;

    if (gsiXmlUtilWriteString(writer, gGsXmlSoapEnvelopeEnd) == 0)
        result = 0;
    else
    {
        result = 1;
        writer->bookkeeping = 1;
    }
    return result;
}
