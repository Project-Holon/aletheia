/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200A3FC
 * packet:   pkt_0200A3D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MYSTERY_DATA_GetSaveType, MYSTERY_DATA_GetCardMax, MYSTERY_DATA_GetBuffer, MYSTERY_DATA_GetEventFlags,
 *           MYSTERY_DATA_GetCardSlot, MYSTERY_DATA_Encrypt, MYSTERY_DATA_Decrypt, MYSTERY_DATA_EncryptBuffer,
 *           MYSTERY_DATA_DecryptBuffer, MUSICAL_SAVE_GetSize, MUSICAL_SAVE_Init, MUSICAL_SAVE_GetFromSave,
 *           MUSICAL_SAVE_InitOutfits, MUSICAL_SAVE_GetOutfits, MUSICAL_SAVE_IsShowActive, MUSICAL_SAVE_NoOp,
 *           MUSICAL_SAVE_IsPropOwned, MUSICAL_SAVE_IsPropNew, MUSICAL_SAVE_AddProp
 *
 * 764 bytes, 0x0200A3FC..0x0200A6F8, 19 functions.  Five of the nineteen
 * carry no label in the generated listing (0x0200A53C, 0x0200A628,
 * 0x0200A630, 0x0200A640 and 0x0200A680): none of them saves lr, so
 * disasm.py's prologue sweep does not fire and the listing prints their
 * bytes as `.word` data in the middle of a literal pool.  They were read out
 * of those words.  0x0200A53C is the giveaway of the three: `movs r0, #0xa9;
 * lsls r0, #2; bx lr` returns 0x2A4, which is exactly the size the
 * constructor at 0x0200A544 clears, the same "a block file opens with a
 * function returning its own size" shape docs/MATCHING.md records for the
 * 0x0200857C run.
 *
 * This unit absorbs the previously matched single function
 * src/matched/sub_0200A6BC.c (0x0200A6BC, 60 bytes), which is its last
 * function.  Its legacy manifest entry is superseded by this unit.
 *
 * What the range is.  Two objects, and two layers.
 *
 * `struct Obj` is a twelve byte handle: a pointer to a block, a kind that is
 * only ever 0 or 1, and a third word.  Every accessor on it is a `switch`
 * over that kind with the default falling through to a zero return, and the
 * two arms are byte for byte identical in three of the four cases, so the
 * distinction is in the source and not in the code.  The 0x0200A4B8 /
 * 0x0200A50C pair stamps and clears a four byte header sitting at the end of
 * the block (offset 0x364 or 0xA90 for the two kinds), holding a 32-bit key
 * built out of a system word and handed to the pair of routines at
 * 0x0203F2FC / 0x0203F328 / 0x0203F37C.
 *
 * `struct Big` is a 0x2A4-byte record with two parallel 0x20-byte bitmaps at
 * 0x258 and 0x278.  0x0200A6BC sets the same bit in both, 0x0200A644 tests
 * the first and 0x0200A680 tests the second; the constructor at 0x0200A544
 * clears the record, seeds two arrays and then sets fifteen of those bits by
 * hand.  100 (0x64) is the bound on every one of the three, so 100 of the
 * 256 bits are in use.
 *
 * symbols:
 *   (none; 0x02FFFC3C is a cast address constant, not a relocation)
 *
 * Three things in this unit cost time and are recorded under docs/idioms/:
 *
 *  - the assignment that both arms of a switch make is emitted once, at a
 *    merge point the default case jumps over.  Writing it after the switch
 *    instead puts the default's branch on that merge point and changes one
 *    branch target and the whole register allocation of the function.  See
 *    docs/idioms/switch-arms-tail-merge.md.
 *  - a repeated read of a hardware address has to be written as two named
 *    locals.  `(X << 8) | X` on a volatile lvalue interleaves the shift
 *    between the two loads; the original loads both and then shifts.  See
 *    docs/idioms/volatile-reread-needs-two-locals.md.
 *  - 0x02FFFC3C is a cast address constant and not an extern.  An `extern
 *    volatile u32` at that address produces an ABS32 relocation and puts the
 *    address in a different register.  Same idiom file as above.
 *
 * Near miss, left out of this unit deliberately: the function at
 * 0x0200A3D0, which is the one immediately before it and is almost certainly
 * part of the same original file.  Two separate reasons, either of which is
 * enough:
 *
 *  1. it calls 0x021DFDB8, which is an overlay address.  `attest()` now has a
 *     rule for those: a target inside an overlay per layout/layout.json is
 *     attested when that overlay's own listing carries a `func_` label at the
 *     address, the label's ISA is the declared ISA, and some branch outside
 *     the compared range targets it.  The third part holds here (a `bl` from
 *     0x02006F42 inside arm9_main and another from ov088 at 0x021BC378); the
 *     first does not.  0x021DFDB8 is inside seven overlays at once, because
 *     overlays share load windows, and they disagree about what is there:
 *     ov093 has an instruction in the middle of a function, ov119 a `movs`,
 *     ov170 a data word, ov228 an eight byte Thumb thunk.  None of them
 *     labels it, so nothing says which of the seven the call means and the
 *     relocation stays a wildcard.  (The thunk in ov228 is the linker's Thumb
 *     veneer shape, which the `veneer` class deliberately does not recognise:
 *     mwccarm emits those same eight bytes for a Thumb tail call.  See "The
 *     veneer class" in docs/MATCHING.md.)
 *  2. two concrete bytes are wrong regardless.  The original materialises the
 *     constant 0xE4 with `ldr r0, [pc, #0x10]` out of its own literal pool,
 *     where every spelling of the integer 228 tried here (decimal, hex,
 *     suffixed, cast, enumerator, `sizeof`, `offsetof`) compiles to `movs
 *     r0, #0xE4` under all nine front ends at every optimisation level.  The
 *     function immediately before it does the same thing with the same value,
 *     so whatever the construct is, it is used twice in a row and is not an
 *     accident.  The rest of the function is byte for byte right.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

struct Sub020071CCCtrl;
extern u32 func_0203F2FC(const u8 *p, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern void func_0203F37C(void *base, u32 size, u32 seed);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)

struct Obj {
    void *unk00;
    u32   unk04;
    void *unk08;
};

struct Hdr {
    u16 unk00;
    u16 unk02;
};

struct BigSub6 { u8 unk0; u8 unk1[5]; };
struct BigSub4 { u8 unk0; u8 unk1[3]; };

struct Big {
    u8 unk000[0x1B0];
    struct BigSub6 unk1B0[8];
    struct BigSub4 unk1E0[10];
    u8  unk208[0x4A];
    u16 unk252;
    u16 unk254;
    u16 unk256;
    u8  unk258[0x20];
    u8  unk278[0x20];
    u8  unk298[4];
    u8  unk29C;
    u8  unk29D;
    u8  unk29E;
    u8  unk29F;
    u8  unk2A0[4];
};

void *MYSTERY_DATA_GetBuffer(struct Obj *obj);
void MYSTERY_DATA_EncryptBuffer(void *base, u32 kind);
void MYSTERY_DATA_DecryptBuffer(void *base, u32 kind);
void MUSICAL_SAVE_InitOutfits(struct Big *p);
void MUSICAL_SAVE_AddProp(struct Big *p, u32 index);

u32 MYSTERY_DATA_GetSaveType(struct Obj *obj)
{
    return obj->unk04;
}

u32 MYSTERY_DATA_GetCardMax(struct Obj *obj)
{
    switch (obj->unk04) {
    case 0:
        return 3;
    case 1:
        return 12;
    }
    return 0;
}

void *MYSTERY_DATA_GetBuffer(struct Obj *obj)
{
    return obj->unk00;
}

void *MYSTERY_DATA_GetEventFlags(struct Obj *obj)
{
    switch (obj->unk04) {
    case 0:
        return MYSTERY_DATA_GetBuffer(obj);
    case 1:
        return MYSTERY_DATA_GetBuffer(obj);
    }
    return 0;
}

void *MYSTERY_DATA_GetCardSlot(struct Obj *obj, u32 index)
{
    MYSTERY_DATA_GetCardMax(obj);
    switch (obj->unk04) {
    case 0:
        return (u8 *)MYSTERY_DATA_GetBuffer(obj) + 0x100 + index * 0xCC;
    case 1:
        return (u8 *)MYSTERY_DATA_GetBuffer(obj) + 0x100 + index * 0xCC;
    }
    return 0;
}

void MYSTERY_DATA_Encrypt(struct Obj *obj)
{
    MYSTERY_DATA_EncryptBuffer(MYSTERY_DATA_GetBuffer(obj), MYSTERY_DATA_GetSaveType(obj));
}

void MYSTERY_DATA_Decrypt(struct Obj *obj)
{
    MYSTERY_DATA_DecryptBuffer(MYSTERY_DATA_GetBuffer(obj), MYSTERY_DATA_GetSaveType(obj));
}

void MYSTERY_DATA_EncryptBuffer(void *base, u32 kind)
{
    u32 size;
    struct Hdr *h;
    u32 a, b;

    switch (kind) {
    case 0:
        size = 0x368;
        h = (struct Hdr *)((u8 *)base + (size - 4));
        break;
    case 1:
        size = 0xA94;
        h = (struct Hdr *)((u8 *)base + (size - 4));
        break;
    }
    a = unk_02FFFC3C;
    b = unk_02FFFC3C;
    h->unk02 = (u16)((a << 8) | b);
    if (h->unk02 == 0) {
        h->unk02 = 1;
    }
    h->unk00 = func_0203F2FC(base, size - 4);
    func_0203F328(base, size - 4, h->unk00 + (h->unk02 << 16));
}

void MYSTERY_DATA_DecryptBuffer(void *base, u32 kind)
{
    u32 size;
    struct Hdr *h;

    switch (kind) {
    case 0:
        size = 0x368;
        h = (struct Hdr *)((u8 *)base + (size - 4));
        break;
    case 1:
        size = 0xA94;
        h = (struct Hdr *)((u8 *)base + (size - 4));
        break;
    }
    func_0203F37C(base, size - 4, h->unk00 + (h->unk02 << 16));
    h->unk02 = 0;
}

u32 MUSICAL_SAVE_GetSize(void)
{
    return sizeof(struct Big);
}

void MUSICAL_SAVE_Init(struct Big *p)
{
    u8 i;

    MI_CpuFill8(p, 0, sizeof(struct Big));
    MUSICAL_SAVE_InitOutfits(p);
    for (i = 0; i < 10; i++) {
        p->unk1E0[i].unk0 = 4;
    }
    p->unk29D = 0;
    p->unk29E = 0;
    MUSICAL_SAVE_AddProp(p, 0x30);
    MUSICAL_SAVE_AddProp(p, 0x46);
    MUSICAL_SAVE_AddProp(p, 0x53);
    MUSICAL_SAVE_AddProp(p, 0x4B);
    MUSICAL_SAVE_AddProp(p, 0x00);
    MUSICAL_SAVE_AddProp(p, 0x01);
    MUSICAL_SAVE_AddProp(p, 0x0A);
    MUSICAL_SAVE_AddProp(p, 0x1C);
    MUSICAL_SAVE_AddProp(p, 0x08);
    MUSICAL_SAVE_AddProp(p, 0x3B);
    MUSICAL_SAVE_AddProp(p, 0x3F);
    MUSICAL_SAVE_AddProp(p, 0x42);
    MUSICAL_SAVE_AddProp(p, 0x10);
    MUSICAL_SAVE_AddProp(p, 0x59);
    MUSICAL_SAVE_AddProp(p, 0x4C);
}

void *MUSICAL_SAVE_GetFromSave(void *sys)
{
    return func_020071CC(sys, 0x2A);
}

void MUSICAL_SAVE_InitOutfits(struct Big *p)
{
    u8 i;

    for (i = 0; i < 8; i++) {
        p->unk1B0[i].unk0 = 10;
    }
}

u8 *MUSICAL_SAVE_GetOutfits(struct Big *p)
{
    return (u8 *)p->unk1B0;
}

struct Bits {
    u32 unk00_0  : 16;
    u32 unk00_16 : 5;
    u32 unk00_21 : 11;
};

u32 MUSICAL_SAVE_IsShowActive(struct Bits *p)
{
    return p->unk00_16 != 0;
}

void MUSICAL_SAVE_NoOp(void)
{
}

u32 MUSICAL_SAVE_IsPropOwned(struct Big *p, u8 index)
{
    if (index < 100) {
        u8 shift = (s32)index % 8;
        u8 byte  = index >> 3;
        if ((p->unk258[byte] & (1 << shift)) > 0) {
            return 1;
        }
    }
    return 0;
}

u32 MUSICAL_SAVE_IsPropNew(struct Big *p, u8 index)
{
    if (index < 100) {
        u8 shift = (s32)index % 8;
        u8 byte  = index >> 3;
        if ((p->unk278[byte] & (1 << shift)) > 0) {
            return 1;
        }
    }
    return 0;
}

void MUSICAL_SAVE_AddProp(struct Big *p, u32 index)
{
    u8 shift, byte;

    if (index >= 100) {
        return;
    }
    shift = (s32)index % 8;
    byte  = index >> 3;
    p->unk258[byte] |= (u8)(1 << shift);
    p->unk278[byte] |= (u8)(1 << shift);
}
