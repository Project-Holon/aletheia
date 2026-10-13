/*
 * function: sakeiGetRandomRecordFillSoapRequest
 * address:  0x021DED3C
 * packet:   pkt_ov175_021DED3C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sakeiGetRandomRecordFillSoapRequest
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.
 *
 * symbols:
 *   sReadXmlNamespacePrefix     0x021E3DF8  data
 *   sReadTagTableid     0x021E3EFC  data
 *   sReadTagFilter     0x021E3F04  data
 *   sReadTagMax     0x021E3F1C  data
 *   func_02182AC0  0x02182AC0  arm
 *   func_02182CF0  0x02182CF0  arm
 *   sakeiFillSoapRequestFieldNames  0x021DE184  arm  ov175
 */

typedef unsigned int u32;

extern char sReadXmlNamespacePrefix[];
extern char sReadTagTableid[];
extern char sReadTagFilter[];
extern char sReadTagMax[];
extern void func_02182AC0(void *, void *, void *, void *);
extern void func_02182CF0(void *, void *, void *, int);
extern void sakeiFillSoapRequestFieldNames(u32 ctx, u32 *arr, int n);

int sakeiGetRandomRecordFillSoapRequest(u32 ctx)
{
    u32 *p = *(u32 **)((char *)ctx + 8);

    func_02182AC0(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagTableid,
                  (void *)p[0]);
    if (p[3] != 0)
        func_02182AC0(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagFilter,
                      (void *)p[3]);
    func_02182CF0(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagMax, 1);
    sakeiFillSoapRequestFieldNames(ctx, (u32 *)p[1], p[2]);
    return 0;
}
