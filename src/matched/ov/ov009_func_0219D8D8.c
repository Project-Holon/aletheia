/*
 * function: SBQueryEngineSetPublicIP
 * address:  0x0219D8D8
 * packet:   pkt_ov009_0219D8D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBQueryEngineSetPublicIP (libdwcgsserverbrowsing.TWL.HYB.a(sb_queryengine.o))
 *
 * The witness func_0219E9F4 (ListCallback) was parked on: it reaches
 * SBQueryEngineSetPublicIP, whose address had no manifest entry, so the call
 * site could not resolve and stayed wildcarded.  Filed here so the `matched`
 * class finds an entry at the target address itself.
 *
 * SBQueryEngineSetPublicIP is 8 bytes in the vendor object, byte-identical to
 * the image: str r1, [r0, #0x28] ; bx lr.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov/ov009_func_0219D8D8.c \
 *       --func SBQueryEngineSetPublicIP --addr 0x0219D8D8 --region ov009 --arm \
 *       --cc 1.1p1 --lang c99
 */
#include "../include/Obj18670.h"

void SBQueryEngineSetPublicIP(int *engine, int publicip)
{
    ((struct Obj18670 *)engine)->f28 = publicip;
}
