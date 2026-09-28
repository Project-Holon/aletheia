/*
 * function: func_021DE184
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
 *   d_021E3DF8     0x021E3DF8  data
 *   d_021E3DFC     0x021E3DFC  data
 *   d_021E3E04     0x021E3E04  data
 *   func_021829AC  0x021829AC  arm
 *   func_02182AC0  0x02182AC0  arm
 *   func_02182A2C  0x02182A2C  arm
 */

typedef unsigned int u32;

extern char d_021E3DF8[];
extern char d_021E3DFC[];
extern char d_021E3E04[];
extern void func_021829AC(void *, void *, void *);
extern void func_02182AC0(void *, void *, void *, void *);
extern void func_02182A2C(void *, void *, void *);

void func_021DE184(u32 ctx, u32 *arr, int n)
{
    int i;

    func_021829AC(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3DFC);
    for (i = 0; i < n; i++)
        func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E04,
                      (void *)arr[i]);
    func_02182A2C(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3DFC);
}
