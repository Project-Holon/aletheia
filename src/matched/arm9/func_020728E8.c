/*
 * function: NNS_SndPrependPostSleepCallback
 * address:  0x020728E8
 * packet:   pkt_020728E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_SndStartTimer  0x02073EE4  arm
 *   SND_StopTimer  0x020894DC  arm
 *   SND_WaitForCommandProc  0x02089CD4  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 */

typedef unsigned int u32;

extern void NNS_SndStartTimer(void);
extern void SND_StopTimer(u32 a, u32 b, u32 c, u32 d);
extern u32  SND_GetCurrentCommandTag(void);
extern void func_02089B38(u32 a);
extern void SND_WaitForCommandProc(u32 a);

void NNS_SndPrependPostSleepCallback(void)
{
    u32 res;

    NNS_SndStartTimer();
    SND_StopTimer(0, 0, 0, 0);
    res = SND_GetCurrentCommandTag();
    func_02089B38(1);
    SND_WaitForCommandProc(res);
}
