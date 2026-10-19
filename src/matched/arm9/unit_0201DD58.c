/*
 * unit:     yes
 * address:  0x0201DD58
 * packet:   pkt_0201D6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GF_FONT_GetFixedWidth, GF_FONT_InitTextColor, GF_FONT_SetDefaultTextColor
 *
 * Three unlabelled leaves of gf_font.c: the accessor for the byte at +0x5E and
 * a two-step thunk that resets the text colour to (1, 2, 0).
 *
 * GF_FONT_InitTextColor and GF_FONT_SetDefaultTextColor are both the pool-word-and-bx shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes, and neither carries
 * a label, because a tail call saves nothing and the prologue sweep never fires.
 * The chain is real: GF_FONT_InitTextColor tail-calls GF_FONT_SetDefaultTextColor, which tail-calls
 * GF_FONT_SetTextColor with three constants.  Writing it as one function that calls
 * GF_FONT_SetTextColor directly loses eight bytes.
 *
 * GF_FONT_SetTextColor itself, the 4x4x4x4 colour expansion at 0x0201DD78, is still
 * open: the original keeps its two outer loop counters in ip and lr and spills
 * only the third, and no declaration order tried reproduces that split.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DD58.c \
 *       --addr 0x0201DD58 --thumb
 *
 * symbols:
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
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

extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);

void GF_FONT_SetDefaultTextColor(void);

u32 GF_FONT_GetFixedWidth(struct Font *p)
{
    return p->unk58[6];
}

void GF_FONT_InitTextColor(void)
{
    GF_FONT_SetDefaultTextColor();
}

void GF_FONT_SetDefaultTextColor(void)
{
    GF_FONT_SetTextColor(1, 2, 0);
}
