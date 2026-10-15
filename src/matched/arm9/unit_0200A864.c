/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200A864
 * packet:   pkt_0200A6F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MUSICAL_SHOT_GetFromSave, MUSICAL_SHOT_CopyPhoto, MUSICAL_SHOT_CopyPhotoRev, MUSICAL_SHOT_GetTitle,
 *           MUSICAL_SHOT_GetExtraData, IRC_RANKING_GetFromSave, IRC_RANKING_GetEntryCount, IRC_RANKING_GetEntry,
 *           IRC_RANKING_GetEntryScore, IRC_RANKING_GetEntryMeetCount, IRC_RANKING_GetEntryGender
 *
 * 162 bytes, 0x0200A864..0x0200A906, 11 functions, six of which carry no
 * label in the generated listing.
 *
 * The object is a 0x34C-byte record holding thirty 0x1C-byte entries
 * followed by one word of flags; 30 * 0x1C is 0x348, which is exactly the
 * offset IRC_RANKING_GetLastSlot reads that word at, so the array length and the
 * record size check against each other.  Each entry carries a packed word at
 * +0x10 whose fields this file reads one at a time: 7 bits at bit 0, 10 bits
 * at bit 7, one bit at bit 17, and one bit at bit 31 that IRC_RANKING_GetEntryCount
 * scans for to find how many entries are in use.
 *
 * The bit widths are not guesses.  Each getter is a `lsls`/`lsrs` pair whose
 * two shift counts give the field's position and width directly, and where
 * the return type is narrower than the field the compiler adds a second
 * truncating pair: IRC_RANKING_GetEntryScore's `lsls #25 / lsrs #25` is the 7-bit field
 * and its `lsls #24 / lsrs #24` is the `u8` return, and dropping either
 * changes two instructions.
 *
 * Near miss, and the reason this unit stops where it does: IRC_RANKING_GetEntryProfile at
 * 0x0200A908, 40 bytes, which unpacks four fields of one entry through four
 * out-parameters.  Two of the four are bitfields of the same byte at +0x1B,
 * and the original loads that byte exactly once, with `ldrb` into the
 * register that held the entry pointer, and then does each field's shift pair
 * immediately before its own store.  Writing the two reads directly is two
 * `ldrb`s, because the intervening store through a `u8 *` may alias the
 * struct and the compiler reloads; writing them into locals first gets the
 * single load but hoists both shift pairs above both stores.  Sixteen
 * spellings were tried (locals for each subset of the four outputs, a nested
 * one-byte bitfield struct copied to a local, the whole tail as a `u32`
 * bitfield container, and the shifts written out by hand), and the best of
 * them is sixteen bytes wrong in exactly that scheduling.  Every other byte
 * of the function is right.  The next unit therefore resumes at 0x0200A930.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

struct Rec2Head {
    u8 unk000[0x1E8];
};

struct Rec2 {
    u8 unk000[0x1E8];
    u8 unk1E8[0x14];
    u8 unk1FC[0x14];
};

struct Entry {
    u8  unk00[0x10];
    u32 f10_0  : 7;
    u32 f10_7  : 10;
    u32 f10_17 : 1;
    u32 f10_18 : 13;
    u32 f10_31 : 1;
    u32 unk14;
    u16 unk18;
    u8  unk1A;
    u8  f1B_0 : 6;
    u8  f1B_6 : 1;
    u8  f1B_7 : 1;
};

struct Rec {
    struct Entry entries[30];
    u32 f348_0 : 8;
    u32 f348_8 : 24;
};

void *MUSICAL_SHOT_GetFromSave(void *sys)
{
    return func_020071CC(sys, 0x2B);
}

void MUSICAL_SHOT_CopyPhoto(struct Rec2Head *dest, const struct Rec2Head *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct Rec2Head));
}

void MUSICAL_SHOT_CopyPhotoRev(const struct Rec2Head *src, struct Rec2Head *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Rec2Head));
}

u8 *MUSICAL_SHOT_GetTitle(struct Rec2 *p)
{
    return p->unk1E8;
}

u8 *MUSICAL_SHOT_GetExtraData(struct Rec2 *p)
{
    return p->unk1FC;
}

void *IRC_RANKING_GetFromSave(void *sys)
{
    return func_020071CC(sys, 0x2C);
}

s32 IRC_RANKING_GetEntryCount(struct Rec *r)
{
    s32 i;

    for (i = 0; i < 30; i++) {
        if (r->entries[i].f10_31 == 0) {
            break;
        }
    }
    return i;
}

struct Entry *IRC_RANKING_GetEntry(struct Rec *r, u32 index)
{
    return &r->entries[index];
}

u8 IRC_RANKING_GetEntryScore(struct Rec *r, u32 index)
{
    return r->entries[index].f10_0;
}

u16 IRC_RANKING_GetEntryMeetCount(struct Rec *r, u32 index)
{
    return r->entries[index].f10_7;
}

u32 IRC_RANKING_GetEntryGender(struct Rec *r, u32 index)
{
    return r->entries[index].f10_17;
}
