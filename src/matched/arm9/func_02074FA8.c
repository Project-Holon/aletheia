/*
 * function: NNSi_SndArcLoadSeqArcFile
 * address:  0x02074FA8
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_SndArcGetCurrent  0x020742FC  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   NNS_SndArcSetFileAddress  0x02074694  arm
 *   NNSi_SndArcLoadFile  0x02074E9C  arm
 *   NNSi_SndArcDisposeSeq  0x0207524C  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern u32 NNS_SndArcGetFileAddress(u32);
struct Global;
extern struct Global *NNS_SndArcGetCurrent(void);
extern void NNS_SndArcSetFileAddress(u32, u32);
extern void *NNSi_SndArcLoadFile(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void NNSi_SndArcDisposeSeq(u8 *p, u32 len, u32 b, u32 c);
u32 NNSi_SndArcLoadSeqArcFile(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = NNS_SndArcGetFileAddress(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)NNS_SndArcGetCurrent();
        r = (u32)NNSi_SndArcLoadFile(a, (u32)NNSi_SndArcDisposeSeq, sz, a, (u32 *)b);
        if (c != 0 && r != 0) NNS_SndArcSetFileAddress(a, r);
    }
    return r;
}
