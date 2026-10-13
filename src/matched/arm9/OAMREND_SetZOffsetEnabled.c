/*
 * function: OAMREND_SetZOffsetEnabled
 * address:  0x02066DEC
 * packet:   pkt_02066DEC
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

void OAMREND_SetZOffsetEnabled(unsigned int callback)
{
    g_02148B2C.f08 = callback;
}
