/*
 * function: GFL_NET_HANDLE_SetAllTimingValue
 * address:  0x0203A458
 * packet:   pkt_0203A458
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Broadcasts a byte value to the +0xE and +0xF bytes of all nine channel
 * records at ((u32 *)arg0)[i + 2], skipping the ones whose +0xD flag is
 * clear.  The argument truncation is written at both stores and the compiler
 * hoists the single `and r1, r1, #0xff` out of the loop into the argument
 * register itself, after the loop counter has been initialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_SetAllTimingValue.c \
 *       --func GFL_NET_HANDLE_SetAllTimingValue --addr 0x0203A458 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void GFL_NET_HANDLE_SetAllTimingValue(u8 *a0, u32 a1)
{
    int i;

    if (a0 == 0)
        return;
    for (i = 0; i < 9; i++) {
        u8 *q = *(u8 **)(a0 + (i << 2) + 8);

        if (q != 0 && q[0xD] != 0) {
            q[0xE] = (u8)a1;
            q[0xF] = (u8)a1;
        }
    }
}
