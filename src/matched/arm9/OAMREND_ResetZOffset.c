/*
 * function: NNS_G2dResetOamSoftEmuAutoZOffset
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
 *   sUVFlipState 0x02148B2C data
 */

struct UVFlipState { void *pFunc; int f04; unsigned int f08; };
extern struct UVFlipState sUVFlipState;

void NNS_G2dResetOamSoftEmuAutoZOffset(void)
{
    sUVFlipState.f04 = 0;
}
