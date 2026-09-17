/*
 * unit:     no
 * function: func_020370C8
 * address:  0x020370C8
 * packet:   pkt_020370C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469C8      0x021469C8  data
 *
 * Two-stage shutdown guarded on a global word: always run func_02036FD8,
 * then, only when g_021469C8[1] is set, run func_02036E80 and clear the flag.
 * func_02036E80 was the sole blocker for this file; it was matched in the
 * same wave, so its PC24 site now attests on the `matched` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020370C8.c \
 *       --func func_020370C8 --addr 0x020370C8 --arm --cc 1.1p1
 */

extern void func_02036FD8(void);
extern void func_02036E80(void);
extern int g_021469C8[];

void func_020370C8(void)
{
    func_02036FD8();
    if (g_021469C8[1] == 0)
        return;
    func_02036E80();
    g_021469C8[1] = 0;
}
