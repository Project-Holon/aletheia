/*
 * function: func_020057C4
 * address:  0x020057C4
 * packet:   pkt_020057C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035108  0x02035108  arm
 *   sub_02005794   0x02005794  thumb
 *
 * Promoted from src/pending/ in the third 0-64 byte band pass (lane 1).  It
 * was parked there on its one call site only - 0x02035108 is reached by the
 * `blx` inside this function and by nothing else in the image, so `label` had
 * no witness - and it needed no change to its C: 0x02035108 now has an EXACT
 * entry of its own (pkt_0203508C), the site resolves through the `matched`
 * class, and the file printed EXACT on the first re-run.  This is the chain
 * class of the band brief working exactly as described, one pass later than
 * the target list expected, because the callee is another lane's row.
 *
 * "Is the master volume callback still the initial one": the pool word is
 * sub_02005794 with its Thumb bit set (0x02005795) and is compared against the
 * word func_02035108 hands back, so the C compares the call's result with the
 * *address* of the thunk - which is why the constant is a relocation and not a
 * plain literal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020057C4.c \
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
