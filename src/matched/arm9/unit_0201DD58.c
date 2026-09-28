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
 * function: func_0201DD58, func_0201DD60, func_0201DD68
 *
 * Three unlabelled leaves of gf_font.c: the accessor for the byte at +0x5E and
 * a two-step thunk that resets the text colour to (1, 2, 0).
 *
 * func_0201DD60 and func_0201DD68 are both the pool-word-and-bx shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes, and neither carries
 * a label, because a tail call saves nothing and the prologue sweep never fires.
 * The chain is real: func_0201DD60 tail-calls func_0201DD68, which tail-calls
 * func_0201DD78 with three constants.  Writing it as one function that calls
 * func_0201DD78 directly loses eight bytes.
 *
 * func_0201DD78 itself, the 4x4x4x4 colour expansion at 0x0201DD78, is still
 * open: the original keeps its two outer loop counters in ip and lr and spills
 * only the third, and no declaration order tried reproduces that split.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DD58.c \
 *       --addr 0x0201DD58 --thumb
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

extern void func_0201DD78(u32 r, u32 g, u32 b);

void func_0201DD68(void);

u32 func_0201DD58(struct Font *p)
{
    return p->unk58[6];
}

void func_0201DD60(void)
{
    func_0201DD68();
}

void func_0201DD68(void)
{
    func_0201DD78(1, 2, 0);
}
