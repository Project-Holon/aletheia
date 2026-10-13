/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02045730
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: BMP_WIN_GetBgLayer, BMP_WIN_GetWidth, BMP_WIN_GetHeight, BMP_WIN_GetDispWidth,
 *           BMP_WIN_GetDispHeight, BMP_WIN_GetPosX, BMP_WIN_GetPosY, BMP_WIN_GetCharOffset,
 *           BMP_WIN_GetBmp, BMP_WIN_GetPalette, BMP_WIN_SetPosX, BMP_WIN_SetPosY,
 *           BMP_WIN_SetDispHeight, BMP_WIN_SetPalette
 *
 * The leaf accessor bank of the allocator family's descriptor object.
 * Fourteen relocation-free 8-byte functions in a row, each one load or
 * store of a single field, which is why they can be folded into one unit
 * with no witnesses required at all.
 *
 * The descriptor they read is the argument block the surrounding
 * constructors carry around (BMP_WIN_TransferChars, at the head of this packet,
 * uses the same offsets: +2, +5, +6, +0xa, +0xc). The fields this bank
 * exposes:
 *
 *   +0x02  u8   BMP_WIN_GetBgLayer get
 *   +0x03  u8   BMP_WIN_GetPosX get / BMP_WIN_SetPosX set
 *   +0x04  u8   BMP_WIN_GetPosY get / BMP_WIN_SetPosY set
 *   +0x05  u8   BMP_WIN_GetWidth get
 *   +0x06  u8   BMP_WIN_GetHeight get
 *   +0x07  u8   BMP_WIN_GetDispWidth get
 *   +0x08  u8   BMP_WIN_GetDispHeight get / BMP_WIN_SetDispHeight set
 *   +0x09  u8   BMP_WIN_GetPalette get / BMP_WIN_SetPalette set
 *   +0x0a  u16  BMP_WIN_GetCharOffset get
 *   +0x0c  void *  BMP_WIN_GetBmp get
 *
 * BMP_WIN_GetBmp is the heap-handle getter of this family: the pointer it
 * returns at +0xc is what BMP_WIN_TransferChars feeds to BMP_GetPixels before the
 * allocation call at 0x02040B1C, so +0xc is the descriptor's heap /
 * owning-context handle rather than a payload pointer. It carries the
 * largest fan-in of the whole bank (1149 branch references image-wide),
 * which is consistent with every user of a descriptor reaching for its
 * heap handle.
 *
 * Only BMP_WIN_GetBgLayer, BMP_WIN_GetWidth, BMP_WIN_GetHeight, BMP_WIN_GetDispWidth,
 * BMP_WIN_GetDispHeight, BMP_WIN_GetPosX, BMP_WIN_GetPosY, BMP_WIN_GetCharOffset, BMP_WIN_GetBmp,
 * BMP_WIN_GetPalette and BMP_WIN_SetPalette carry labels in the listing.
 * BMP_WIN_SetPosX, BMP_WIN_SetPosY and BMP_WIN_SetDispHeight are unlabelled followers:
 * they save no lr, so disasm.py folds them into BMP_WIN_GetPalette's extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). They
 * should be seeded into layout/function_starts.txt by the integrator.
 *
 * Field names are left descriptive rather than semantic: this whole
 * family is scheduled for a semantic rename once the allocator's argument
 * shapes settle.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045730.c \
 *       --addr 0x02045730 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Descriptor {
    u8    unk0;
    u8    unk1;
    u8    unk2;
    u8    unk3;
    u8    unk4;
    u8    unk5;
    u8    unk6;
    u8    unk7;
    u8    unk8;
    u8    unk9;
    u16   unkA;
    void *heap;
};

u8 BMP_WIN_GetBgLayer(struct Descriptor *p)
{
    return p->unk2;
}

u8 BMP_WIN_GetWidth(struct Descriptor *p)
{
    return p->unk5;
}

u8 BMP_WIN_GetHeight(struct Descriptor *p)
{
    return p->unk6;
}

u8 BMP_WIN_GetDispWidth(struct Descriptor *p)
{
    return p->unk7;
}

u8 BMP_WIN_GetDispHeight(struct Descriptor *p)
{
    return p->unk8;
}

u8 BMP_WIN_GetPosX(struct Descriptor *p)
{
    return p->unk3;
}

u8 BMP_WIN_GetPosY(struct Descriptor *p)
{
    return p->unk4;
}

u16 BMP_WIN_GetCharOffset(struct Descriptor *p)
{
    return p->unkA;
}

void *BMP_WIN_GetBmp(struct Descriptor *p)
{
    return p->heap;
}

u8 BMP_WIN_GetPalette(struct Descriptor *p)
{
    return p->unk9;
}

void BMP_WIN_SetPosX(struct Descriptor *p, u8 v)
{
    p->unk3 = v;
}

void BMP_WIN_SetPosY(struct Descriptor *p, u8 v)
{
    p->unk4 = v;
}

void BMP_WIN_SetDispHeight(struct Descriptor *p, u8 v)
{
    p->unk8 = v;
}

void BMP_WIN_SetPalette(struct Descriptor *p, u8 v)
{
    p->unk9 = v;
}
