/*
 * function: WmClearFifoRecvFlag
 * address:  0x0208E9A4
 * packet:   pkt_0208E9A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned short u16;

void WmClearFifoRecvFlag(void)
{
    u16 *flag = (u16 *)0x02FFFF96;

    if (*flag & 1) {
        *flag = (u16)(*flag & 0xFFFE);
    }
}
