/*
 * function: PMi_DummyCallback
 * address:  0x0208B840
 * packet:   pkt_0208B840
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PMi_DummyCallback.
 */

void PMi_DummyCallback(unsigned int result, unsigned int *arg)
{
    if (arg) {
        *arg = result;
    }
}
