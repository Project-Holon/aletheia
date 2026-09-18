/*
 * function: func_020057C4
 * address:  0x020057C4
 * packet:   pkt_020057C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02035108 (arm) - reached only by the `blx` inside this function,
 *           so the `label` class has no witness outside the compared range
 *           and the callee is not matched.  The pool word resolves through
 *           the `matched` class against src/matched/unit_02005794.c, so
 *           everything except this one site is attested.  All 20 concrete
 *           bytes are right.
 *
 * symbols:
 *   func_02035108  0x02035108  arm
 *   sub_02005794   0x02005794  thumb
 *
 * "Is the master volume callback still the initial one": the pool word is
 * sub_02005794 with its Thumb bit set (0x02005795) and is compared against
 * the word func_02035108 hands back, so the C compares the call's result
 * with the *address* of the thunk - which is why the constant is a
 * relocation and not a plain literal.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020057C4.c \
 *       --func func_020057C4 --addr 0x020057C4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32  func_02035108(void);
extern void sub_02005794(void);

int func_020057C4(void)
{
    u32 v;

    v = func_02035108();
    return v == (u32)sub_02005794;
}
