/*
 * function: sub_02035224
 * address:  0x02035224
 * packet:   pkt_02035224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   unk_021469BC  0x021469BC  data
 *   OS_Terminate  0x02088234  arm
 *
 * The singleton accessor for the UI context sub_02034E24 publishes: stop the
 * machine if it has not been constructed yet, otherwise hand it back.  The
 * pointer is loaded twice off the one pool word because OS_Terminate is an
 * ordinary extern as far as the compiler is concerned, so the global has to
 * be re-read after the call.
 *
 * This is the most-called function in the 0x02035000 block: a hundred-odd
 * branches reach it image-wide.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035224.c \
 *       --func sub_02035224 --addr 0x02035224 --cc 1.1p1 --arm
 */

struct UiCtx;

extern struct UiCtx *unk_021469BC;
extern void OS_Terminate(void);

struct UiCtx *sub_02035224(void)
{
    if (unk_021469BC == 0) {
        OS_Terminate();
    }
    return unk_021469BC;
}
