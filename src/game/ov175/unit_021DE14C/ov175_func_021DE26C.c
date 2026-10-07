/*
 * function: func_021DE26C
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
 *   d_021E3DF8     0x021E3DF8  data
 *   d_021E3E1C     0x021E3E1C  data
 *   d_021E3E18     0x021E3E18  data
 *   func_021829AC  0x021829AC  arm
 *   func_02182CF0  0x02182CF0  arm
 *   func_02182A2C  0x02182A2C  arm
 */

typedef unsigned int u32;

extern char d_021E3DF8[];
extern char d_021E3E1C[];
extern char d_021E3E18[];
extern void func_021829AC(void *, void *, void *);
extern void func_02182CF0(void *, void *, void *, void *);
extern void func_02182A2C(void *, void *, void *);

void func_021DE26C(u32 ctx, u32 *arr, int n)
{
    int i;

    func_021829AC(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E1C);
    for (i = 0; i < n; i++)
        func_02182CF0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E18,
                      (void *)arr[i]);
    func_02182A2C(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E1C);
}
