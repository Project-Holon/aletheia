/*
 * function: NNSi_SndArcLoadSeqArc
 * address:  0x02074C70
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_SndArcGetSeqArcInfo  0x02074388  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   NNSi_SndArcLoadSeqArcFile  0x02074FA8  arm
 */
#include "../include/Obj11687.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern void *NNS_SndArcGetSeqArcInfo(int index);
extern u32 NNSi_SndArcLoadSeqArcFile(u32, u32, u32);
extern u32 NNS_SndArcGetFileAddress(u32);
u32 NNSi_SndArcLoadSeqArc(u32 a, u32 b, u32 c, u32 d, u32 *out) {
    void *p = NNS_SndArcGetSeqArcInfo(a);
    u32 r;
    if (p == 0) return 3;
    if (b & 8) {
        r = NNSi_SndArcLoadSeqArcFile(((struct Obj11687 *)p)->f0, c, d);
        if (r == 0) return 7;
    } else {
        r = NNS_SndArcGetFileAddress(((struct Obj11687 *)p)->f0);
    }
    if (out != 0) *out = r;
    return 0;
}
