/*
 * unit:     yes
 * address:  0x02017D30
 * packet:   pkt_02017C50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_DecodePartyParam, POKE_TOOL_EncodePartyParam, POKE_TOOL_DecodeBoxParam, POKE_TOOL_EncodeBoxParam
 *
 * symbols:
 *   func_02019A50  0x02019A50  thumb
 *   func_02019A9C  0x02019A9C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02019A50(u16 *p, u32 size, u32 seed);
extern u16 func_02019A9C(const u16 *p, u32 size);


struct Sav {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 14;
    u16 unk06;
    u8  unk08[0x80];
    u8  unk88[0x54];
};

u32 POKE_TOOL_DecodePartyParam(struct Sav *p)
{
    u32 r = 0;

    if (p->b0 == 0) {
        r = 1;
        p->b0 = 1;
        p->b1 = 1;
        func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}

u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f)
{
    u32 r = 0;

    if (p->b0 == 1 && f == 1) {
        p->b0 = 0;
        p->b1 = 0;
        r = 1;
        func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}

u32 POKE_TOOL_DecodeBoxParam(struct Sav *p)
{
    u32 r = 0;

    if (p->b1 == 0) {
        p->b1 = 1;
        r = 1;
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}

u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f)
{
    u32 r = 0;

    if (p->b1 == 1 && f == 1) {
        r = 1;
        p->b1 = 0;
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}
