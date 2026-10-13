/*
 * function: GetProgramaError
 * address:  0x0205D178
 * packet:   pkt_0205D178
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 */

int GetProgramaError(int err)
{
    switch (err) {
    case 1:
        return -9;
    case 0:
        return -10;
    case 2:
        return -8;
    case 3:
        return -7;
    default:
        return 0;
    }
}
