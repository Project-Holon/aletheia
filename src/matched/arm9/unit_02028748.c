/*
 * unit:     yes
 * function: FIELD_SKILL_USE_FLAGS_SetSkill
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

void FIELD_SKILL_USE_FLAGS_SetSkill(struct Obj *obj, int n, int mask)
{
    obj->flags = obj->flags | (mask << n);
}

u32 FIELD_SKILL_USE_FLAGS_IsSkillUsable(struct Obj *obj, u32 n)
{
    return (obj->flags >> n) & 1;
}
