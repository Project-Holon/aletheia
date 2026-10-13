/*
 * function: BTL_ACTION_SetFight
 * address:  0x021D82D0
 * packet:   pkt_ov093_021D82D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };

void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub)
{
    struct Unk021D82D0 t = {0};
    t.kind = 1;
    t.sub = sub;
    t.id = id;
    *out = t;
}
