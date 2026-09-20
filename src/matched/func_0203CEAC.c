/*
 * function: func_0203CEAC
 * address:  0x0203CEAC
 * packet:   pkt_0203CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  label: func_0203D70C8 (0x0203D70C8) is reached only by the `bl` at
 *           +0040 inside this function and carries no `func_` label in the
 *           listing, so `label` has no witness outside 0203CEAC..0203CF04;
 *           own-pool: the ABS32 target 0x0203CDD4 occurs exactly once in the
 *           whole arm9 image, in this function's own pool at 0x0203CF00
 *           (+0054), so `literal` refuses it and no cut can free it.
 *
 * Net bring-up: fetch the state object, run its per-frame tick, and if the
 * object exists stamp the caller's handle into it, then install one of two
 * handlers according to the object's mode byte and finish with the shared
 * tail.  The two handler installs take the same address (0x0203CDD4) and the
 * image loads it from the pool separately in each arm, so the source spells
 * the address at both call sites rather than hoisting it into a local.
 *
 * All 88 bytes reproduce: the only wildcarded fields are the two sites above.
 * Two spellings mattered:
 *   * `if (p != 0) { ... return 1; } return 0;` - the `if (p == 0) return 0;`
 *     guard form compiles to `moveq r0, #0` + `popeq {r3, r4, r5, pc}` and
 *     shifts every following byte; the image branches to a separate out-of-line
 *     `mov r0, #0; pop {r3, r4, r5, pc}` block at 0x0203CEF8.
 *   * the mode byte is read into a named local *before* the caller's handle is
 *     stored into the object, which is the image's order (`ldrb r0, [r4, #0x65]`
 *     at +001C, `str r5, [r4, #0x348]` at +0020, `cmp r0, #1` at +0024).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203CEAC.c \
 *       --func func_0203CEAC --addr 0x0203CEAC --cc 1.1p1 --arm
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203DA20  0x0203DA20  arm
 *   func_0203C774  0x0203C774  arm
 *   func_0203BF9C  0x0203BF9C  arm
 *   func_0203D70C8 0x0203D70C8 arm
 *   g_0203CDD4     0x0203CDD4  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *func_0203D788(int a0);
extern void func_0203DA20(void);
extern void func_0203C774(u8 *p);
extern void func_0203BF9C(u8 *p);
extern void func_0203D70C8(void);
extern u8 g_0203CDD4[];

int func_0203CEAC(int a0)
{
    u8 *p;

    p = func_0203D788(a0);
    func_0203DA20();
    if (p != 0) {
        u8 t = p[0x65];

        *(int *)(p + 0x348) = a0;
        if (t == 1) {
            func_0203C774(g_0203CDD4);
        } else {
            func_0203BF9C(g_0203CDD4);
        }
        func_0203D70C8();
        return 1;
    }
    return 0;
}
