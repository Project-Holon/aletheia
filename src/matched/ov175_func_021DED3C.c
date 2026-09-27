/*
 * function: func_021DED3C
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
 *   d_021E3DF8     0x021E3DF8  data
 *   d_021E3EFC     0x021E3EFC  data
 *   d_021E3F04     0x021E3F04  data
 *   d_021E3F1C     0x021E3F1C  data
 *   func_02182AC0  0x02182AC0  arm
 *   func_02182CF0  0x02182CF0  arm
 *   func_021DE184  0x021DE184  arm  ov175
 */

typedef unsigned int u32;

extern char d_021E3DF8[];
extern char d_021E3EFC[];
extern char d_021E3F04[];
extern char d_021E3F1C[];
extern void func_02182AC0(void *, void *, void *, void *);
extern void func_02182CF0(void *, void *, void *, int);
extern void func_021DE184(u32, u32, u32);

int func_021DED3C(u32 ctx)
{
    u32 *p = *(u32 **)((char *)ctx + 8);

    func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3EFC,
                  (void *)p[0]);
    if (p[3] != 0)
        func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3F04,
                      (void *)p[3]);
    func_02182CF0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3F1C, 1);
    func_021DE184(ctx, p[1], p[2]);
    return 0;
}
