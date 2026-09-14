/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C6A0
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0202C6A0, func_0202C6AC
 *
 * symbols:
 *   sub_0202C6BC  0x0202C6BC  thumb
 *
 * Two unlabelled leaves, back to back
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): each is a
 * three-instruction, six-byte forwarding call with a literal second
 * argument, padded to eight with a `nop` and its own pool word. Reached
 * only through sub_0202C570 and sub_0202C578's pool-word-and-bx tail
 * calls (src/matched/unit_0202C548.c). Neither carries a
 * register-saving prologue, so neither is in the worklist's function
 * list; both sit exactly between func_0202C688's last instruction and
 * sub_0202C6B8's label.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C6A0.c \
 *       --addr 0x0202C6A0 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C6BC(void *p, u32 v);

u32 func_0202C6A0(void *p)
{
    return sub_0202C6BC(p, 0);
}

u32 func_0202C6AC(void *p)
{
    return sub_0202C6BC(p, 1);
}
