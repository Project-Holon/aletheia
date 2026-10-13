/*
 * function: func_02074F3C
 * address:  0x02074F3C
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
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern u32 NNS_SndArcGetFileAddress(u32);
struct Global;
extern struct Global *NNS_SndArcGetCurrent(void);
extern void NNS_SndArcSetFileAddress(u32, u32);
extern void *func_02074E9C(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void func_0207524C(u8 *p, u32 len, u32 b, u32 c);
u32 func_02074F3C(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = NNS_SndArcGetFileAddress(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)NNS_SndArcGetCurrent();
        r = (u32)func_02074E9C(a, (u32)func_0207524C, sz, a, (u32 *)b);
        if (c != 0 && r != 0) NNS_SndArcSetFileAddress(a, r);
    }
    return r;
}
