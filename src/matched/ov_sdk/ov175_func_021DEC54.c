/*
 * function: func_021DEC54
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
 *   d_021E3DF8     0x021E3DF8  data
 *   d_021E3EFC     0x021E3EFC  data
 *   func_02182AC0  0x02182AC0  arm
 *   func_021DE1F8  0x021DE1F8  arm  ov175
 *   func_021DE184  0x021DE184  arm  ov175
 */

typedef unsigned int u32;

extern char d_021E3DF8[];
extern char d_021E3EFC[];
extern void func_02182AC0(void *, void *, void *, void *);
extern void func_021DE1F8(u32 ctx, u32 *arr, int n);
extern void func_021DE184(u32 ctx, u32 *arr, int n);

int func_021DEC54(u32 ctx)
{
    u32 *p = *(u32 **)((char *)ctx + 8);

    func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3EFC,
                  (void *)p[0]);
    func_021DE1F8(ctx, (u32 *)p[1], p[2]);
    func_021DE184(ctx, (u32 *)p[3], p[4]);
    return 0;
}
