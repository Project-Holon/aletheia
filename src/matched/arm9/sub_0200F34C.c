/*
 * function: sub_0200F34C
 * address:  0x0200F34C
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02059A5C  0x02059A5C  arm
 *   func_020598EC  0x020598EC  arm
 *
 * A three-way friend-key comparator: bails out (0) if func_02059A5C(a, c)
 * flags the pair invalid. Otherwise compares b against a with
 * func_020598EC; if that says "no difference" (<= 0) the function reports
 * "not newer" (2). Otherwise it re-derives the b-against-a comparison
 * (the call is issued twice) and compares it against a fresh b-against-c
 * comparison, reporting "newer" (1) only when they agree and "not newer"
 * (2) otherwise.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F34C.c \
 *       --func sub_0200F34C --addr 0x0200F34C --cc 1.1p1
 */

extern int func_02059A5C(void *b, void *c);
struct DWCstAccUserData;
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);

int sub_0200F34C(void *a, void *b, void *c)
{
    if (func_02059A5C(a, c) != 0) {
        return 0;
    }

    if (func_020598EC(b, a) > 0) {
        int lhs = func_020598EC(b, a);
        int rhs = func_020598EC(b, c);
        if (lhs == rhs) {
            return 1;
        }
    }
    return 2;
}
