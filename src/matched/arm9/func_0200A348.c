/*
 * function: MYSTERY_DATA_GetCardSlotNum
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
 * sits between MYSTERY_DATA_Delete and MYSTERY_DATA_IsMainSave at the end of its packet.
 * Its target reads one object pointer in r0 and returns the unsigned count
 * used by the overlay callers.
 *
 * symbols:
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 */

typedef unsigned int u32;
struct Obj;
extern u32 MYSTERY_DATA_GetCardMax(struct Obj *obj);

u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *obj)
{
    return MYSTERY_DATA_GetCardMax(obj);
}
