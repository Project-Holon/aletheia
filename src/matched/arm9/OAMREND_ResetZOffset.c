/*
 * function: OAMREND_ResetZOffset
 * address:  0x02066DFC
 * packet:   pkt_02066DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148B2C 0x02148B2C data
 */

struct UVFlipState { void *pFunc; int f04; unsigned int f08; };
extern struct UVFlipState g_02148B2C;

void OAMREND_ResetZOffset(void)
{
    g_02148B2C.f04 = 0;
}
