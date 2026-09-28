/*
 * unit:     yes
 * address:  0x0201DC6C
 * packet:   pkt_0201D6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201DC6C, func_0201DC80
 *
 * The gf_font.c width query and the accessor for the byte at +0x59.
 *
 * func_0201DC6C returns whatever the function pointer at +0x6C returns, and the
 * tail call shape (`ldr r2, [r4, #0x6c]`, `blx r2`, `pop {r4, pc}`) is the same
 * bytes whether the C declares a return value or not, so the return type is
 * fixed by the caller instead: func_0201D528 adds the result to a running width.
 *
 * func_0201DC80 has no label in the listing; it is three halfwords between two
 * literal pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DC6C.c \
 *       --addr 0x0201DC6C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Font {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    void *unk60;
    void *unk64;
    void *unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

extern u32 func_0201DB20(struct Font *p, u16 ch);

u32 func_0201DC6C(struct Font *p, u16 ch)
{
    return ((u32 (*)(struct Font *, u32))p->unk6C)(p, func_0201DB20(p, ch));
}

u32 func_0201DC80(struct Font *p)
{
    return p->unk58[1];
}
