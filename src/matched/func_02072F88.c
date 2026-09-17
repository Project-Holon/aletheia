/*
 * function: func_02072F88
 * address:  0x02072F88
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls SND_SetPlayerChannelPriority with the object's +0x3c byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072F88.c \
 *       --func func_02072F88 --addr 0x02072F88 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void SND_SetPlayerChannelPriority(u32 v);

void func_02072F88(u8 *p)
{
    volatile u32 *vp = (volatile u32 *)p;

    if (*vp == 0) {
        return;
    }
    SND_SetPlayerChannelPriority((*(u8 **)vp)[0x3c]);
}
