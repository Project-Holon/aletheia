/*
 * function: func_0200A348
 * address:  0x0200A348
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four bytes of code and a pool word: the plain Thumb tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  It carries no label in the
 * generated listing (it saves nothing), so it was read out of the bytes; it
 * sits between func_0200A338 and func_0200A350 at the end of its packet.
 * Its target reads one object pointer in r0 and returns the unsigned count
 * used by the overlay callers.
 */

typedef unsigned int u32;
struct Obj;
extern u32 func_0200A400(struct Obj *obj);

u32 func_0200A348(struct Obj *obj)
{
    return func_0200A400(obj);
}
