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
 * element variant (func_02182CF0 writer).
 *
 * symbols:
 *   sReadXmlNamespacePrefix     0x021E3DF8  data
 *   sReadTagRecordids     0x021E3E0C  data
 *   sReadTagInt     0x021E3E18  data
 *   func_021829AC  0x021829AC  arm
 *   func_02182CF0  0x02182CF0  arm
 *   func_02182A2C  0x02182A2C  arm
 */

typedef unsigned int u32;

extern char sReadXmlNamespacePrefix[];
extern char sReadTagRecordids[];
extern char sReadTagInt[];
extern void func_021829AC(void *, void *, void *);
extern void func_02182CF0(void *, void *, void *, void *);
extern void func_02182A2C(void *, void *, void *);

void sakeiFillSoapRequestRecordIds(u32 ctx, u32 *arr, int n)
{
    int i;

    func_021829AC(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagRecordids);
    for (i = 0; i < n; i++)
        func_02182CF0(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagInt,
                      (void *)arr[i]);
    func_02182A2C(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagRecordids);
}
