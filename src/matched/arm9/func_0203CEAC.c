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
 *
 * Net bring-up: fetch the state object, run its per-frame tick, and if the
 * object exists stamp the caller's handle into it, then install one of two
 * handlers according to the object's mode byte and finish with the shared
 * tail.  Both handler installs take the same address (0x0203CDD4) and the
 * image loads it from one pool word at 0x0203CF00, so the source names the
 * function at both call sites rather than hoisting it into a local.
 *
 * FILED EXACT 2026-09-22.  This file sat in src/pending as MATCH on two
 * blockers that were both bookkeeping errors, not evidence gaps:
 *
 *   * the `bl` at +0040 was declared `func_0203D70C8` / `0x0203D70C8`, an
 *     address with NINE hex digits.  The instruction is `bl #0x20370c8`, so
 *     the target is 0x020370C8 -- a stray `D`.  The real address is an EXACT
 *     manifest entry (src/matched/func_020370C8.c) and also carries 15
 *     outside branches, so it attests as `label` immediately.
 *   * the ABS32 at +0054 was declared `g_0203CDD4 ... data`.  0x0203CDD4 is
 *     a traced ARM function start (it pushes lr), i.e. this is a FUNCTION
 *     POINTER argument, not a data address.  Declared `data` it was routed
 *     to sole-ref/data, which correctly refuses a code target; declared
 *     `arm` it resolves through sole-ref/code.
 *
 * The C itself was already byte-correct and is unchanged apart from the two
 * declarations and the argument type (void * rather than u8 *).
 *
 * Two spellings still matter, from the original lane's work:
 *   * `if (p != 0) { ... return 1; } return 0;` -- the `if (p == 0) return 0;`
 *     guard form compiles to `moveq r0, #0` + `popeq {r3, r4, r5, pc}` and
 *     shifts every following byte; the image branches to a separate
 *     out-of-line `mov r0, #0; pop {...}` block at 0x0203CEF8.
 *   * the mode byte is read into a named local *before* the caller's handle
 *     is stored into the object, which is the image's order (`ldrb r0,
 *     [r4, #0x65]` at +001C, `str r5, [r4, #0x348]` at +0020).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0203CEAC.c \
 *       --func func_0203CEAC --addr 0x0203CEAC --cc 1.1p1 --arm
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203DA20  0x0203DA20  arm
 *   func_0203C774  0x0203C774  arm
 *   func_0203BF9C  0x0203BF9C  arm
 *   func_020370C8  0x020370C8  arm
 *   func_0203CDD4  0x0203CDD4  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *func_0203D788(int a0);
extern void func_0203DA20(void);
extern void func_0203C774(u32 v);
extern void func_0203BF9C(u32 v);
extern void func_020370C8(void);
extern void func_0203CDD4(void);

int func_0203CEAC(int a0)
{
    u8 *p;

    p = func_0203D788(a0);
    func_0203DA20();
    if (p != 0) {
        u8 t = p[0x65];

        *(int *)(p + 0x348) = a0;
        if (t == 1) {
            func_0203C774((u32)func_0203CDD4);
        } else {
            func_0203BF9C((u32)func_0203CDD4);
        }
        func_020370C8();
        return 1;
    }
    return 0;
}
