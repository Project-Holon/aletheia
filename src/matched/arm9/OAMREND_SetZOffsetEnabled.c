/*
 * function: NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled
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
 *   sUVFlipState 0x02148B2C data
 */

struct UVFlipState { void *pFunc; int f04; unsigned int f08; };
extern struct UVFlipState sUVFlipState;

void NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(unsigned int callback)
{
    sUVFlipState.f08 = callback;
}
