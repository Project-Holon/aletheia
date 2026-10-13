/*
 * function: GFL_NET_GetInitParam
 * address:  0x0203D798
 * packet:   pkt_0203D798
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   gGFLNetMain  0x021469E0  data
 *
 * Accessor for the +8 handle of the singleton at 0x021469E0, with the null
 * case spelled out.  The `moveq r0, #0` is a no-op on the value it guards,
 * so it is only there because the source writes the null return
 * explicitly; a plain `return g->unk_08;` loses the `cmp` and the `moveq`
 * and is eight bytes short.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D7C8 because the
 * follower at 0x0203D7B0 has no label.  It is not a byte difference; the
 * follower is a pair of eight-byte ARM long-branch veneers (0x0203D7B0 ->
 * 0x0203C8E8 and 0x0203D7BC -> 0x0203C900), which save no lr and so are
 * invisible to disasm.py.  Both want seeding into
 * layout/function_starts.txt, which is the integrator's file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetInitParam.c \
 *       --func GFL_NET_GetInitParam --addr 0x0203D798 --cc 1.1p1 --arm
 */

#include "../include/G_Singleton.h"

typedef unsigned char u8;

extern struct Singleton gGFLNetMain;

void *GFL_NET_GetInitParam(void)
{
    if (gGFLNetMain.unk_08 == 0) {
        return 0;
    }
    return gGFLNetMain.unk_08;
}
