/*
 * file:     musical_shot.c
 * unit:     yes
 * function: MUSICAL_SHOT_GetSize, MUSICAL_SHOT_Init, MUSICAL_SHOT_GetFromSave, MUSICAL_SHOT_CopyPhoto, MUSICAL_SHOT_CopyPhotoRev, MUSICAL_SHOT_GetTitle, MUSICAL_SHOT_GetExtraData
 * address:  0x0200A840
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_data.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   EVENT_FIELD_PROCLINK_InitEventdataSystem    0x02161D98  thumb  ov010
 *   EVENT_FIELD_PROCLINK_InitIdList    0x02161EEC  thumb  ov010
 *   EVENT_FIELD_PROCLINK_InitReturnHeader    0x02161F00  thumb  ov010
 */
#include "wifilist_tail_shared_types.h"

/* Save block 0x2B, the musical shot (0x2DC bytes). */
struct MusicalShotPhoto {
    u8 data[0x1E8];
};

struct MusicalShot {
    struct MusicalShotPhoto photo;
    u16 title[10];
    u8  extraData[0xE0];
};

#include "mi_memory.h"

#include "save_control.h"
struct ProcLinkReturnList;

#include "../ov010/event_field_proclink.h"

#include "../ov010/event_field_proclink_return.h"
struct ProcLinkRequest;


u32 MUSICAL_SHOT_GetSize(void);

void MUSICAL_SHOT_Init(struct MusicalShot *shot);

struct MusicalShot *MUSICAL_SHOT_GetFromSave(struct SaveControl *save);

void MUSICAL_SHOT_CopyPhoto(struct MusicalShotPhoto *dest, const struct MusicalShotPhoto *src);

void MUSICAL_SHOT_CopyPhotoRev(const struct MusicalShotPhoto *src, struct MusicalShotPhoto *dest);

u16 *MUSICAL_SHOT_GetTitle(struct MusicalShot *shot);

u8 *MUSICAL_SHOT_GetExtraData(struct MusicalShot *shot);

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 8 bytes, 0x0200A840..0x0200A848, one function, which carries no label in
 * the generated listing: it is the three-instruction size getter that opens
 * every save block file in this region, and it has no prologue.
 *
 * The size it returns, 0x2DC, is what fixes the tail of the record.  The
 * constructor in the next function hands out the two sub-objects at +0x1E8
 * and +0x1FC, so the only free choice left is how much follows the second
 * one, and 0xE0 is what makes sizeof agree with the getter.
 *
 * Near miss, and the reason this unit stops at 0x0200A848: MUSICAL_SHOT_Init, 28
 * bytes, reproduces every concrete byte and caps at MATCH.  It is
 *
 *     void MUSICAL_SHOT_Init(struct MusicalShot *shot)
 *     {
 *         EVENT_FIELD_PROCLINK_InitEventdataSystem(&shot->photo);
 *         EVENT_FIELD_PROCLINK_InitIdList(shot->title);
 *         EVENT_FIELD_PROCLINK_InitReturnHeader(shot->extraData);
 *     }
 *
 * and all three callees live in overlay space.  0x02161D98 is attested by the
 * overlay-resident callee class (label x1, witness 0x02012674).  The other
 * two are not: 0x02161EEC has exactly two branch witnesses image wide, one of
 * them this call and the other 0x02186378, and 0x02161F00 has exactly one,
 * this call.  Neither address carries a func_ label in any overlay that
 * contains it, which is part 1 of the overlay rule, so neither can be
 * attested and no cut helps: the only witness is the call that needs it.  It
 * closes the day disasm.py labels either address.
 */
u32 MUSICAL_SHOT_GetSize(void)
{
    return sizeof(struct MusicalShot);
}

/*
 * note:     wave 16: promoted.  02161EEC is the unlabelled ov010 leaf now
 *           matched in src/matched/EVENT_FIELD_PROCLINK_InitIdList.c (shard ov010/pkt_02161EEC),
 *           which attests the call as `matched, overlay` under the ov010
 *           hint below; 02161F00 resolves as sole-ref/code (overlay).
 */
void MUSICAL_SHOT_Init(struct MusicalShot *shot)
{
    EVENT_FIELD_PROCLINK_InitEventdataSystem((struct ProcLinkReturnList *)&shot->photo);
    EVENT_FIELD_PROCLINK_InitIdList(shot->title);
    EVENT_FIELD_PROCLINK_InitReturnHeader((struct ProcLinkRequest *)shot->extraData);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
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
struct MusicalShot *MUSICAL_SHOT_GetFromSave(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x2B);
}

void MUSICAL_SHOT_CopyPhoto(struct MusicalShotPhoto *dest, const struct MusicalShotPhoto *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct MusicalShotPhoto));
}

void MUSICAL_SHOT_CopyPhotoRev(const struct MusicalShotPhoto *src, struct MusicalShotPhoto *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct MusicalShotPhoto));
}

u16 *MUSICAL_SHOT_GetTitle(struct MusicalShot *shot)
{
    return shot->title;
}

u8 *MUSICAL_SHOT_GetExtraData(struct MusicalShot *shot)
{
    return shot->extraData;
}
