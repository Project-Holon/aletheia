/*
 * function: func_021B1AC0
 * address:  0x021B1AC0
 * packet:   pkt_ov013_021B1AC0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * RFC 3550 update_seq shape: MAX_DROPOUT 3000, MAX_MISORDER 100.
 *
 * symbols:
 *   func_021B1AA0  0x021B1AA0  arm  ov013
 */
#include "../include/Obj01641.h"
#include "../include/Obj12461.h"

extern void func_021B1AA0(char *p, unsigned short v);

int func_021B1AC0(char *p, char *pkt, unsigned short seq)
{
    unsigned short last = ((struct Obj01641 *)p)->f68;
    unsigned short delta = seq - last;

    if (delta < 3000) {
        if (seq < last)
            ((struct Obj01641 *)p)->f60 += 0x10000;
        ((struct Obj01641 *)p)->f68 = seq;
    } else if (delta <= 0x10000 - 100) {
        if (seq == ((struct Obj01641 *)p)->f64) {
            func_021B1AA0(p, seq);
            ((struct Obj01641 *)p)->f54 = (unsigned short)(seq - 1);
        } else {
            ((struct Obj01641 *)p)->f64 = (unsigned short)(seq + 1);
            return 0;
        }
    } else if (seq + ((struct Obj01641 *)p)->f60 > ((struct Obj01641 *)p)->f54 + 0x10000 - 100) {
        ((struct Obj12461 *)pkt)->f18 = seq + ((struct Obj01641 *)p)->f60 - 0x10000;
        return 1;
    }
    ((struct Obj12461 *)pkt)->f18 = seq + ((struct Obj01641 *)p)->f60;
    return 1;
}
