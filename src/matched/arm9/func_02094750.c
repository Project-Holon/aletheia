/*
 * function: MSL_C_LIB_CallExitHook
 * address:  0x02094750
 * packet:   pkt_020944CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0024 ABS32 gMslExitHook             -> unresolved: 02153FB0 (data, from header) has no witness outside 02094750..02094778
 *
 * symbols:
 *   gMslExitHook       0x02153FB0  data
 *   MSL_C_LIB_DefaultExitHook    0x02094778  arm
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
 *   python tools/match.py one --src src/matched/MSL_C_LIB_CallExitHook.c \
 *       --func MSL_C_LIB_CallExitHook --addr 0x02094750 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef void (*Hook02153FB0)(u32, u32, u32);

extern Hook02153FB0 gMslExitHook;
extern void MSL_C_LIB_DefaultExitHook(void);

void MSL_C_LIB_CallExitHook(u32 a, u32 b, u32 c)
{
    if (gMslExitHook != 0) {
        gMslExitHook(a, b, c);
    } else {
        MSL_C_LIB_DefaultExitHook();
    }
}
