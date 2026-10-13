/*
 * unit:     no
 * function: ISS_SWITCH_Free
 * address:  0x0202C5AC
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * An unlabelled leaf sitting inside sub_0202C590's own literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a
 * pool-word-and-bx tail call into the ARM SDK function ENV_SetResourceSet
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md
 * covers the shape, though this is a genuine tail call rather than a
 * linker veneer). Reached only through sub_0202C548's own
 * pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C5AC.c \
 *       --func ISS_SWITCH_Free --addr 0x0202C5AC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 func_020307B0(void *p);

u32 ISS_SWITCH_Free(void *p)
{
    return func_020307B0(p);
}
