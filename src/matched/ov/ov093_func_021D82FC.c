/*
 * unit:     yes
 * function: BTL_ACTION_SetFightTarget, BTL_ACTION_SetFightSlotFlag, BTL_ACTION_GetFightSlotFlag
 * address:  0x021D82FC
 * packet:   pkt_ov093_021D82FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three accessors on the kind-1 record of BTL_ACTION_SetFight (kind:4, sub:3,
 * id:16): set the 3-bit sub (unless 6), set the flag at bit 26, read it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct Unk021D82FC { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 pad : 3; u32 flag : 1; u32 rest : 5; };

void BTL_ACTION_SetFightTarget(struct Unk021D82FC *p, int sub)
{
    if (p->kind == 1) {
        if (sub != 6)
            p->sub = sub;
    }
}

void BTL_ACTION_SetFightSlotFlag(struct Unk021D82FC *p)
{
    if (p->kind == 1)
        p->flag = 1;
}

u32 BTL_ACTION_GetFightSlotFlag(struct Unk021D82FC *p)
{
    if (p->kind == 1)
        return p->flag;
    return 0;
}
