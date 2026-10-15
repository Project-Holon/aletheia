/*
 * function: sakeiFillSoapRequestRecordIds
 * address:  0x021DE1F8
 * packet:   pkt_ov175_021DE1F8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sakeiFillSoapRequestFieldNames
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.  The integer
 * element variant (gsXmlWriteIntElement writer).
 *
 * symbols:
 *   sReadXmlNamespacePrefix     0x021E3DF8  data
 *   sReadTagRecordids     0x021E3E0C  data
 *   sReadTagInt     0x021E3E18  data
 *   gsXmlWriteOpenTag  0x021829AC  arm
 *   gsXmlWriteIntElement  0x02182CF0  arm
 *   gsXmlWriteCloseTag  0x02182A2C  arm
 */

typedef unsigned int u32;

extern char sReadXmlNamespacePrefix[];
extern char sReadTagRecordids[];
extern char sReadTagInt[];
extern void gsXmlWriteOpenTag(void *, void *, void *);
extern void gsXmlWriteIntElement(void *, void *, void *, void *);
extern void gsXmlWriteCloseTag(void *, void *, void *);

void sakeiFillSoapRequestRecordIds(u32 ctx, u32 *arr, int n)
{
    int i;

    gsXmlWriteOpenTag(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagRecordids);
    for (i = 0; i < n; i++)
        gsXmlWriteIntElement(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagInt,
                      (void *)arr[i]);
    gsXmlWriteCloseTag(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagRecordids);
}
