/*
 * unit:     yes
 * function: func_02029F54
 * address:  0x02029F60
 * packet:   pkt_02029F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A twelve-byte forwarding thunk that pins the second argument to 0: a pool
 * word and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md) with the
 * constant materialised before the branch.  It saves no `lr`, so `disasm.py`
 * never labels it and it prints as a run of `.word`s in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x02029F60 is
 * a seed for layout/function_starts.txt.
 *
 * Kept in its own file rather than folded in with func_02029F54 so that the
 * sibling's pool word stays outside this range.
 *
 * symbols:
 *   func_0202A084  0x0202A084  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029F60.c \
 *       --addr 0x02029F60 --thumb
 */

typedef unsigned int   u32;
extern void func_0202A084(u32 *p, int event);

void func_02029F60(void *p)
{
    func_0202A084(p, 0);
}
