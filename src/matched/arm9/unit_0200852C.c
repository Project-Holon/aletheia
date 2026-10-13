/*
 * A whole translation unit, matched as one byte range rather than one
 * function at a time.  Written from the disassembly in
 * asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x0200852C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MYSTATUS_SetId, MYSTATUS_GetId, MYSTATUS_GetIdLow16, MYSTATUS_GetProfileId,
 *           MYSTATUS_SetProfileIdOnce, MYSTATUS_SetOutfitVariant, MYSTATUS_GetOutfitVariant, MYSTATUS_GetOutfit,
 *           MYSTATUS_SetOutfit, MYSTATUS_GetAvatarId, MYSTATUS_SetAvatarId, MYSTATUS_GetGender,
 *           MYSTATUS_SetGender, MYSTATUS_GetLanguage, MYSTATUS_GetVersion, MYSTATUS_SetLanguageAndVersion
 *
 * 0x0200852C..0x0200857C is 80 bytes of nothing but accessors on one object,
 * sixteen of them, and the address range is closed on both sides: the
 * function before it ends exactly at 0x0200852C and the function after it
 * starts exactly at 0x0200857C.  That preceding function is the last one in
 * unit_020084BC.c, so the two files together cover 0x020084BC..0x0200857C,
 * 190 contiguous bytes and 23 functions, with no gap and no overlap.
 *
 * Four of the sixteen carry no label in the
 * generated listing at all (0x0200852C, 0x02008540, 0x0200854C, 0x02008564),
 * because they have no register-saving prologue and disasm.py's labeller only
 * fires on one; they are recovered here by reading the bytes.
 *
 * The run is the TU-granularity experiment.  What it shows, in order:
 *
 *   - source order is emission order.  mwccarm writes one PROGBITS section
 *     per function, in the order the functions appear in the file, and the
 *     linker concatenates them in that order.  These sixteen are in the
 *     original's address order and nothing had to be permuted.
 *   - alignment padding is reproduced.  Two of the functions are an odd
 *     number of halfwords long (0x02008540 is 10 bytes, 0x02008574 is 6) and
 *     each is followed by two bytes of 0x00 before the next four-byte
 *     boundary.  That fill is the linker's, not the compiler's: it is the gap
 *     between two sections, and it is zero, where compiler-internal padding
 *     inside a section is a Thumb nop (0xC0 0x46).  Both kinds are visible in
 *     this neighbourhood; see docs/MATCHING.md.
 *   - there is no literal pool anywhere in the range, because no function in
 *     it references anything outside itself.  Pool placement is tested
 *     separately in docs/MATCHING.md, and it is per function, not per unit.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200852C.c \
 *       --addr 0x0200852C
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub0200852CObj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B;
    u8  unk1C;
    u8  unk1D;
};

void MYSTATUS_SetId(struct Sub0200852CObj *obj, u32 value)
{
    obj->unk10 = value;
}

u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj)
{
    return obj->unk10;
}

u16 MYSTATUS_GetIdLow16(const struct Sub0200852CObj *obj)
{
    return (u16)obj->unk10;
}

u32 MYSTATUS_GetProfileId(const struct Sub0200852CObj *obj)
{
    return obj->unk14;
}

/* Set once: the store is skipped if the field is already non-zero.  The
 * compare-and-branch is over the store, which is why this one function is 10
 * bytes and drags two bytes of fill in behind it. */
void MYSTATUS_SetProfileIdOnce(struct Sub0200852CObj *obj, u32 value)
{
    if (obj->unk14 == 0) {
        obj->unk14 = value;
    }
}

void MYSTATUS_SetOutfitVariant(struct Sub0200852CObj *obj, u8 value)
{
    obj->unk1D = value;
}

u8 MYSTATUS_GetOutfitVariant(const struct Sub0200852CObj *obj)
{
    return obj->unk1D;
}

u8 MYSTATUS_GetOutfit(const struct Sub0200852CObj *obj)
{
    return obj->unk1C;
}

void MYSTATUS_SetOutfit(struct Sub0200852CObj *obj, u8 value)
{
    obj->unk1C = value;
}

u8 MYSTATUS_GetAvatarId(const struct Sub0200852CObj *obj)
{
    return obj->unk1B;
}

void MYSTATUS_SetAvatarId(struct Sub0200852CObj *obj, u8 value)
{
    obj->unk1B = value;
}

u8 MYSTATUS_GetGender(const struct Sub0200852CObj *obj)
{
    return obj->unk1A;
}

void MYSTATUS_SetGender(struct Sub0200852CObj *obj, u8 value)
{
    obj->unk1A = value;
}

u8 MYSTATUS_GetLanguage(const struct Sub0200852CObj *obj)
{
    return obj->unk18;
}

u8 MYSTATUS_GetVersion(const struct Sub0200852CObj *obj)
{
    return obj->unk19;
}

void MYSTATUS_SetLanguageAndVersion(struct Sub0200852CObj *obj, u8 a, u8 b)
{
    obj->unk18 = a;
    obj->unk19 = b;
}
