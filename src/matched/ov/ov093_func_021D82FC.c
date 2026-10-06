/*
 * unit:     yes
 * function: func_021D82FC, func_021D8318, func_021D832C
 * address:  0x021D82FC
 * packet:   pkt_ov093_021D82FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three accessors on the kind-1 record of func_021D82D0 (kind:4, sub:3,
 * id:16): set the 3-bit sub (unless 6), set the flag at bit 26, read it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct Unk021D82FC { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 pad : 3; u32 flag : 1; u32 rest : 5; };

void func_021D82FC(struct Unk021D82FC *p, int sub)
{
    if (p->kind == 1) {
        if (sub != 6)
            p->sub = sub;
    }
}

void func_021D8318(struct Unk021D82FC *p)
{
    if (p->kind == 1)
        p->flag = 1;
}

u32 func_021D832C(struct Unk021D82FC *p)
{
    if (p->kind == 1)
        return p->flag;
    return 0;
}
