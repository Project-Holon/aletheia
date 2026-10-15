/*
 * function: sakeiFillSoapRequestFieldNames
 * address:  0x021DE184
 * packet:   pkt_ov175_021DE184
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sakeiFillSoapRequestFieldNames
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.  Open the field
 * list, add one formatted element per name, then close it.
 *
 * symbols:
 *   sReadXmlNamespacePrefix     0x021E3DF8  data
 *   sReadTagFields     0x021E3DFC  data
 *   sReadTagString     0x021E3E04  data
 *   gsXmlWriteOpenTag  0x021829AC  arm
 *   gsXmlWriteStringElement  0x02182AC0  arm
 *   gsXmlWriteCloseTag  0x02182A2C  arm
 */

typedef unsigned int u32;

extern char sReadXmlNamespacePrefix[];
extern char sReadTagFields[];
extern char sReadTagString[];
extern void gsXmlWriteOpenTag(void *, void *, void *);
extern void gsXmlWriteStringElement(void *, void *, void *, void *);
extern void gsXmlWriteCloseTag(void *, void *, void *);

void sakeiFillSoapRequestFieldNames(u32 ctx, u32 *arr, int n)
{
    int i;

    gsXmlWriteOpenTag(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagFields);
    for (i = 0; i < n; i++)
        gsXmlWriteStringElement(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagString,
                      (void *)arr[i]);
    gsXmlWriteCloseTag(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagFields);
}
