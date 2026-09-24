/*
 * function: func_021E22E4
 * address:  0x021E22E4
 * packet:   pkt_021E22E4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   func_0217D254  0x0217D254  arm
 *   g_021ACEF8     0x021ACEF8  data
 *   g_021ACEFC     0x021ACEFC  data
 *   g_021E49D0     0x021E49D0  data
 *   g_021E4A18     0x021E4A18  data
 *   g_021E53BC     0x021E53BC  data
 *
 * Session state probe: state 1 initialises the 0x021E53BC flag through
 * func_02084F80 and reports the flag; any other state asks func_0217D254 to
 * bring the 0x021E4A18 scene up (3/1).
 */

typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;

extern u32 g_021ACEF8;
extern u32 g_021ACEFC[];
extern u32 g_021E49D0[];
extern u32 g_021E4A18[];
extern s8 g_021E53BC[];
extern void func_02084F80(s8 *, u32, u32 *, u32 *);
extern void func_0217D254(int, int, int, u32 *);

s32 func_021E22E4(void)
{
    if (g_021ACEF8 == 1) {
        if (g_021E53BC[0] == 0)
            func_02084F80(g_021E53BC, 0x80, g_021E49D0, g_021ACEFC);
        return (s32)g_021E53BC;
    }
    func_0217D254(0, 3, 1, g_021E4A18);
    return 0;
}
