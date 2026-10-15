/*
 * function: BUTTON_MAN_Func1AA0
 * address:  0x02051AA0
 * packet:   pkt_02051A54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  PC24 NNS_GfdAllocVram at +0x08: 0x020616CC lies outside both claimed windows and is branched to only from here
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_Func1AA0.c \
 *       --func BUTTON_MAN_Func1AA0 --addr 0x02051AA0 --cc 1.1p1 --arm
 *
 * symbols:
 *   NNS_GfdAllocVram  0x020616CC  arm
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 NNS_GfdAllocVram(u32 size, u32 flag, u32 dir);

int BUTTON_MAN_Func1AA0(int a, int b)
{
    return (u16)NNS_GfdAllocVram(a, b, 1) << 3;
}
