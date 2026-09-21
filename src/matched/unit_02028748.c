/*
 * unit:     yes
 * function: func_02028748
 * address:  0x02028748
 * packet:   pkt_02028748
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A pair of leaf accessors over a 32-bit flag word at offset 0x14: or
 * `mask << n` into it, and test bit `n`.  Neither calls anything.
 */

typedef unsigned int u32;

struct Obj {
    u32 pad_00[5];
    u32 flags;
};

void func_02028748(struct Obj *obj, u32 n, u32 mask)
{
    obj->flags = obj->flags | (mask << n);
}

u32 func_02028754(struct Obj *obj, u32 n)
{
    return (obj->flags >> n) & 1;
}
