/*
 * function: WIFIBATTLEMATCH_NET_IsRegCardReady
 * address: 0x021D6460
 * packet: pkt_ov175_021D6460
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled blocker leaf for WIFIBATTLEMATCH_NET_TaskStepL; parent confirmed unowned.
 * symbols:
 *   func_021E777C 0x021E777C thumb ov177
 */
#include "../include/Obj00171.h"
struct Work;
extern int func_021E777C(struct Work *);
int WIFIBATTLEMATCH_NET_IsRegCardReady(char *p)
{
    return func_021E777C(*(struct Work * *)&((struct Obj00171 *)p)->f1C);
}
