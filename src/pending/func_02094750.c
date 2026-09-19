/*
 * function: func_02094750
 * address:  0x02094750
 * packet:   pkt_020944CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  +0024 ABS32 g_02153FB0             -> unresolved: 02153FB0 (data, from header) has no witness outside 02094750..02094778
 *
 * symbols:
 *   g_02153FB0       0x02153FB0  data
 *   func_02094778    0x02094778  arm
 *
 * Calls the hook stored at 0x02153FB0 when it is set, otherwise falls through
 * to the default handler at 0x02094778.
 *
 * The hook is taken as a three-argument pointer because that is the only thing
 * that reproduces the original's `ldr r3` / `blx r3`: with a zero- or
 * one-argument callee the compiler puts the target in r0 or r1 and the head of
 * the function shifts.  The arguments are passed straight through, so nothing
 * in the bytes fixes their values.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02094750.c \
 *       --func func_02094750 --addr 0x02094750 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef void (*Hook02153FB0)(u32, u32, u32);

extern Hook02153FB0 g_02153FB0;
extern void func_02094778(void);

void func_02094750(u32 a, u32 b, u32 c)
{
    if (g_02153FB0 != 0) {
        g_02153FB0(a, b, c);
    } else {
        func_02094778();
    }
}
