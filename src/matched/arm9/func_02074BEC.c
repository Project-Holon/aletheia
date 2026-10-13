/*
 * function: NNSi_SndArcLoadSeq
 * address:  0x02074BEC
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 *   NNSi_SndArcLoadBank  0x02074CD0  arm
 *   NNSi_SndArcLoadSeqFile  0x02074F3C  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 */
#include "../include/Obj08948.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *NNS_SndArcGetSeqInfo(int index);
extern u32 NNSi_SndArcLoadBank(u32 a, u32 flags, u32 c, u32 d, u32 *out);
extern u32  NNSi_SndArcLoadSeqFile(u32 a, u32 b, u32 c);
extern u32  NNS_SndArcGetFileAddress(u32 a);

u32 NNSi_SndArcLoadSeq(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    u8 *p = NNS_SndArcGetSeqInfo(a);
    u32 r;

    if (p == 0) return 2;
    r = NNSi_SndArcLoadBank(((struct Obj08948 *)p)->f4, b, c, d, 0);
    if (r != 0) return r;
    if (b & 1) {
        r = NNSi_SndArcLoadSeqFile(((struct Obj08948 *)p)->f0, c, d);
        if (r == 0) return 6;
    } else {
        r = NNS_SndArcGetFileAddress(((struct Obj08948 *)p)->f0);
    }
    if (out != 0) *out = r;
    return 0;
}
