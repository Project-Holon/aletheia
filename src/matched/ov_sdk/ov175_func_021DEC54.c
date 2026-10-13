/*
 * function: sakeiGetSpecificRecordsFillSoapRequest
 * address:  0x021DEC54
 * packet:   pkt_ov175_021DEC54
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sakeiGetSpecificRecordsFillSoapRequest
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.  Emit the SOAP
 * envelope, the name list and the specific-record table.
 *
 * symbols:
 *   sReadXmlNamespacePrefix     0x021E3DF8  data
 *   sReadTagTableid     0x021E3EFC  data
 *   func_02182AC0  0x02182AC0  arm
 *   sakeiFillSoapRequestRecordIds  0x021DE1F8  arm  ov175
 *   sakeiFillSoapRequestFieldNames  0x021DE184  arm  ov175
 */

typedef unsigned int u32;

extern char sReadXmlNamespacePrefix[];
extern char sReadTagTableid[];
extern void func_02182AC0(void *, void *, void *, void *);
extern void sakeiFillSoapRequestRecordIds(u32 ctx, u32 *arr, int n);
extern void sakeiFillSoapRequestFieldNames(u32 ctx, u32 *arr, int n);

int sakeiGetSpecificRecordsFillSoapRequest(u32 ctx)
{
    u32 *p = *(u32 **)((char *)ctx + 8);

    func_02182AC0(*(void **)((char *)ctx + 0x18), sReadXmlNamespacePrefix, sReadTagTableid,
                  (void *)p[0]);
    sakeiFillSoapRequestRecordIds(ctx, (u32 *)p[1], p[2]);
    sakeiFillSoapRequestFieldNames(ctx, (u32 *)p[3], p[4]);
    return 0;
}
