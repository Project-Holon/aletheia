/*
 * function: func_021BF57C
 * address:  0x021BF57C
 * packet:   pkt_ov114_021BF57C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ShutdownGHTTP (dwc_ghttp.o)
 *
 * symbols:
 *   func_021C204C  0x021C204C  arm  ov114
 *   func_021BFB20  0x021BFB20  arm  ov114
 *   g_021D3B20     0x021D3B20  data
 */

extern int g_021D3B20;
extern void func_021C204C(void);
extern void func_021BFB20(void);

int func_021BF57C(void)
{
    if (g_021D3B20 <= 0) {
        return 1;
    }
    func_021C204C();
    if (--g_021D3B20 == 0) {
        func_021BFB20();
    }
    return 1;
}
