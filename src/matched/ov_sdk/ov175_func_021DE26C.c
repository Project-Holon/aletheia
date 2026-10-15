/*
 * function: sakeiFillSoapRequestOwnerIds
 * address:  0x021DE26C
 * packet:   pkt_ov175_021DE26C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sakeiFillSoapRequestFieldNames
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.  Another
 * integer-element variant with a distinct field-name anchor.
 *
 * symbols:
 *   sReadXmlNamespacePrefix     0x021E3DF8  data
 *   sReadTagOwnerids     0x021E3E1C  data
 *   sReadTagInt     0x021E3E18  data
 *   gsXmlWriteOpenTag  0x021829AC  arm
 *   gsXmlWriteIntElement  0x02182CF0  arm
 *   gsXmlWriteCloseTag  0x02182A2C  arm
 */

typedef unsigned int u32;

extern char sReadXmlNamespacePrefix[];
extern char sReadTagOwnerids[];
extern char sReadTagInt[];
extern void gsXmlWriteOpenTag(void *, void *, void *);
extern void gsXmlWriteIntElement(void *, void *, void *, void *);
extern void gsXmlWriteCloseTag(void *, void *, void *);

void sakeiFillSoapRequestOwnerIds(u32 ctx, u32 *arr, int n)
{
    int i;

    gsXmlWriteOpenTag(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagOwnerids);
    for (i = 0; i < n; i++)
        gsXmlWriteIntElement(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagInt,
                      (void *)arr[i]);
    gsXmlWriteCloseTag(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagOwnerids);
}
