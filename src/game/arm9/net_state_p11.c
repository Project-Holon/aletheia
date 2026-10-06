/*
 * file:     net_state_p11.c
 * unit:     yes
 * function: func_020370C8, func_020370F4
 * address:  0x020370C8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469C8      0x021469C8  data
 *   func_02036E74  0x02036E74  arm
 */
typedef unsigned int u32;

extern int func_02036FD8(void);
extern void func_02036E80(unsigned char *p);
extern int *func_02036E74(int *p, int v);
void func_020370C8(void);
u32 func_020370F4(u32 a);
extern int g_021469C8[];


/*
 * Two-stage shutdown guarded on a global word: always run func_02036FD8,
 * then, only when g_021469C8[1] is set, run func_02036E80 and clear the flag.
 * func_02036E80 was the sole blocker for this file; it was matched in the
 * same wave, so its PC24 site now attests on the `matched` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020370C8.c \
 *       --func func_020370C8 --addr 0x020370C8 --arm --cc 1.1p1
 */
void func_020370C8(void)
{
    func_02036FD8();
    if (g_021469C8[1] == 0)
        return;
    func_02036E80((unsigned char *)g_021469C8[1]);
    g_021469C8[1] = 0;
}


/*
 * Forwards the argument to the handler held in the second word of the global
 * at 0x021469C8, but only when that handler is armed; an unarmed handler is
 * the `popeq` that returns 0 without touching r0.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020370F4.c \
 *       --func func_020370F4 --addr 0x020370F4 --cc 1.1p1 --arm
 */
u32 func_020370F4(u32 a)
{
    u32 v;

    v = g_021469C8[1];
    if (v == 0)
        return v;
    return (u32)func_02036E74((int *)v, a);
}
