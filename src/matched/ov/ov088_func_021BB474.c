/*
 * function: func_021BB474
 * address:  0x021BB474
 * packet:   pkt_ov088_021BB474
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-calls the release of the handle kept at +0x118.
 *
 * symbols:
 *   func_0202CA0C  0x0202CA0C  thumb
 */
#include "../include/Obj20818.h"

struct WinMgr;
extern void func_0202CA0C(struct WinMgr *mgr);

void func_021BB474(char *p)
{
    func_0202CA0C(((struct Obj20818 *)p)->f118);
}
