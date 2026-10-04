/*
 * function: func_0218ED20
 * address:  0x0218ED20
 * packet:   pkt_ov021_0218ED20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf: forwards the handle at +0xc to func_02048B0C.
 * Filed as the only unmatched callee of ov056 func_021F392C.
 *
 * symbols:
 *   func_02048B0C  0x02048B0C  arm
 */
#include "../include/Obj19565.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_02048B0C(u32 h, void *out);

void func_0218ED20(void *p, void *out)
{
    func_02048B0C(((struct Obj19565 *)p)->fC, out);
}
