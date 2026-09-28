/*
 * function: func_021C98A4
 * address:  0x021C98A4
 * packet:   pkt_ov114_021C98A4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      my_rand (dwc_encsession.o)
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   g_021CF7AC     0x021CF7AC  data
 *   g_021D4228     0x021D4228  data
 */

typedef struct {
    char pad[0x44];
    unsigned int mul;
    unsigned int add;
    unsigned int mod;
} Session;
extern Session g_021CF7AC;
extern int g_021D4228;

unsigned char func_021C98A4(void)
{
    g_021D4228 = (g_021CF7AC.mul * g_021D4228 + g_021CF7AC.add) % g_021CF7AC.mod;
    return g_021D4228 >> 16;
}
