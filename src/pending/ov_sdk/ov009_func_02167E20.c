/*
 * function: func_02167E20
 * address:  0x02167E20
 * packet:   pkt_ov009_02167E20
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * u21: the defining object wmif.o is .comment 4.0.0.1024 -> dsi/1.1p1, so the front end is right
 *      and this is a body wall: 1.1p1 if-converts the one-statement then-arm into `subne r5,r5,#5`
 *      (100 B) where the image keeps `mov r5,#0 / cmp r0,#0 / beq 0x2167e68 / mvn r5,#4` (104 B).
 *      First divergence +003C image `cmp r0, #0` | ours `ldr r6, [r4, #0x2c]` (the callback load
 *      also hoists above the compare).
 * u1: re-measured, unchanged at 100 B vs 104 B; the one-statement then-arm is still if-converted and the [r4,#0x2c] load still hoists above the compare.
 *
 * w9_nm: unchanged at 100 B vs 104 B: the constant spelled ~4, if/else, an extra add-zero statement in the arm, and a volatile result local (108 B) all keep the arm if-converted.
 *
 * u31: six more arm shapes -- if/else with the zero arm spelled out, the ternary
 * in both senses, `if (f != 0 && (wcmResult = -5)) ;`, a named long temp for -5,
 * and a `wcmResult = wcmResult;` self-assign blocker -- all still if-convert the
 * arm at -O4,p. if/else and the ternary move the -5 into r6 before the compare and
 * make it worse (37 B). The image's real branch (beq + mvn r5, #4) with the
 * un-hoisted `ldr r6, [r4, #0x2c]` is not reachable from any source shape tried
 * here or in the w5/w9 passes.
 *
 * w8_67E20: the `subne r5,r5,#5` is a fold off the adjacent `mov r5,#0`, and an
 * enum *local* breaks it (an-enum-local-materialises-a-large-complement-constant):
 * `typedef enum { OK, ERR = -5 } E; E err; ... err = ERR; wcmResult = 0;
 * if (field != 0) wcmResult = err;` compiles to 104 B (the image's size) with the
 * mvn materialised -- `mvn r1, #4 / mov r5, #0 / cmp r0, #0 / movne r5, r1`. But
 * the arm is *still predicated* (`movne r5, r1`), so the branch is not recovered.
 * 10 concrete bytes left, and the residual is exactly the predication decision.
 * Nine more spellings (err assigned after the default, both arms enum, a goto
 * label, a nested if, `&&`, a one-trip loop with explicit continue/break, six
 * repeated `wcmResult = -5;` dead stores that CSE away) all give 104 B and the
 * same `movne`; the spellings that fold back to the subtract give 100 B.
 *
 * sdk:      WcmWmcbSetDCFDataAsync (wmif.o)
 *
 * blocker:  Front-end predication wall. 1.1p1 at -O4,p always if-converts a
 *           guard arm of five instructions or fewer
 *           (predication-of-short-guard-arms-is-the-front-end-not-the-shape,
 *           an-arm-guard-block-of-five-instructions-or-fewer-is-predicated);
 *           here it predicates the one-instruction then-arm, and an enum local
 *           only swaps `subne r5,r5,#5` for `movne r5,r1` while keeping the
 *           predication. The image keeps a real branch
 *           (`mov r5,#0 / cmp / beq / mvn r5,#4`), which is the "kept branches"
 *           tell FRONTEND-PINS.md documents as ../2.0/sp2, not 1.1p1. No plain-C
 *           spelling reaches it under 1.1p1 (w5/w9/u21/u31/w8 all measured); the
 *           honest route is a per-function pin to ../2.0/sp2, which this lane is
 *           not allowed to take (no stamp sweeps; one function only). Recompute
 *           under the pin: the same C is 104 B with 0 predicted mismatches.
 *
 * w5_nm: still 35 bytes with DWARF-named fields and the `cb` local.  Also
 *           tried: switch on sendError (case 0 / default), ternary in both
 *           senses, if/else, goto over the arm, a `(void)0` or self-assign
 *           padding the arm, a block local for -5, unsigned compare, a
 *           break-out while, and the callback tail written into both arms
 *           (57 bytes, not cross-jumped).  The then-arm is always if-converted.
 *
 * symbols:
 *   WCMi_GetCpsifWork                0x02166378 arm
 *   WCMi_ResetKeepAliveAlarm         0x02165af4 arm
 *   WCMi_CpsifUnlockMutexInIRQ       0x02166594 arm
 */

struct WCMCpsifWork;

extern struct WCMCpsifWork *WCMi_GetCpsifWork(void);
extern void WCMi_ResetKeepAliveAlarm(void);
extern void WCMi_CpsifUnlockMutexInIRQ(void *mutex);

static void func_02167E20(void *arg)
{
    struct WCMCpsifWork *wcmiw = WCMi_GetCpsifWork();
    long wcmResult;
    void (*sendCallback)(long);

    if (*(unsigned short *)arg != 0x12)
        return;
    *(unsigned short *)((char *)wcmiw + 0x24) = *(unsigned short *)((char *)arg + 2);
    if (*(unsigned short *)((char *)arg + 2) == 0)
        WCMi_ResetKeepAliveAlarm();
    wcmResult = 0;
    if (*(unsigned short *)((char *)wcmiw + 0x24) != 0)
        wcmResult = -5;
    sendCallback = *(void (**)(long))((char *)wcmiw + 0x2c);
    *(void (**)(long))((char *)wcmiw + 0x2c) = 0;
    WCMi_CpsifUnlockMutexInIRQ((char *)wcmiw + 0xc);
    sendCallback(wcmResult);
}
