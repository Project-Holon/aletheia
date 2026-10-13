/*
 * function: NNSi_SndArcForgetFileAddress
 * address:  0x020751F4
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_SndArcSetCurrent  0x020742E4  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   NNS_SndArcSetFileAddress  0x02074694  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
struct Global;
extern struct Global *NNS_SndArcSetCurrent(struct Global *val);
extern u32 NNS_SndArcGetFileAddress(u32);
extern void NNS_SndArcSetFileAddress(u32, u32);
void NNSi_SndArcForgetFileAddress(u32 a, u32 b, u32 c) {
    u32 t, s;
    if (b == 0) return;
    s = OS_DisableInterrupts();
    t = (u32)NNS_SndArcSetCurrent((struct Global *)b);
    if (NNS_SndArcGetFileAddress(c) == a) NNS_SndArcSetFileAddress(c, 0);
    NNS_SndArcSetCurrent((struct Global *)t);
    OS_RestoreInterrupts(s);
}
