/*
 * function: func_021C0F20
 * address:  0x021C0F20
 * packet:   pkt_ov016_021C0F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      kDWCi_Language (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   g_021DE56C     0x021DE56C  data
 */

extern unsigned char g_021DE56C;

unsigned char func_021C0F20(void)
{
    if (g_021DE56C == 6)
        return 0x38;
    if (g_021DE56C == 1) {
        if (!((*(unsigned int *)((char *)&g_021DE56C + 8) >> 4) & 2))
            return 0x37;
    }
    return g_021DE56C + 0x31;
}
