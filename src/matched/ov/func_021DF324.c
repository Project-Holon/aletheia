/*
 * function: BOX2_MAIN_PushPartySceneB
 * address:  0x021DF324
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Clamp p[0x16] to 0x1e below the limit of the p+0xc object's
 *   byte 0xf, then hand the object to the SDK.  The callee argument is the
 *   re-read expression, not the local, which is why the image re-loads it.
 */
#include "../include/Obj04901.h"
#include "../include/Obj12155.h"


typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int BOX2_MAIN_PushPartySceneB(char *p)
{
    int q = ((struct Obj04901 *)p)->fC;
    if (((struct Obj04901 *)p)->f18 == 0) {
        if (((struct Obj04901 *)p)->f16 < 0x1e)
            ((struct Obj04901 *)p)->f16 = ((struct Obj12155 *)q)->fF;
        else
            ((struct Obj04901 *)p)->f16 = ((struct Obj12155 *)q)->fF + 0x1e;
    }
    func_020307B0((void *)(((struct Obj04901 *)p)->fC));
    return 0;
}
