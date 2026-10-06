/*
 * function: func_0203D9EC
 * address:  0x0203D9EC
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469F0  0x021469F0  data
 *
 * Tears down the net_irc_wireless singleton at 0x021469F0: releases it
 * through func_02034FB8(0x20) and the heap release, then clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D9EC.c \
 *       --func func_0203D9EC --addr 0x0203D9EC --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 g_021469F0[];

extern void func_02034FB8(u32 v);
extern u32 func_020307B0(void *p);

void func_0203D9EC(void)
{
    if (*(u32 *)g_021469F0 == 0) {
        return;
    }
    func_02034FB8(0x20);
    func_020307B0(*(void **)g_021469F0);
    *(u32 *)g_021469F0 = 0;
}
