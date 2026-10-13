/*
 * function: func_020728E8
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
 */

typedef unsigned int u32;

extern void NNS_SndStartTimer(void);
extern void func_020894DC(u32 a, u32 b, u32 c, u32 d);
extern u32  func_02089D40(void);
extern void func_02089B38(u32 a);
extern void func_02089CD4(u32 a);

void func_020728E8(void)
{
    u32 res;

    NNS_SndStartTimer();
    func_020894DC(0, 0, 0, 0);
    res = func_02089D40();
    func_02089B38(1);
    func_02089CD4(res);
}
