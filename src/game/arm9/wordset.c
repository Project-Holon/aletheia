/*
 * file:     wordset.c
 * unit:     yes
 * function: WORDSET_Create, WORDSET_DeleteStrbufED04, WORDSET_Init, WORDSET_ResetSlot, WORDSET_SetSlotText, WORDSET_SetSlotFromMessage, WORDSET_SetSlotTag, WORDSET_Callback, WORDSET_SetSlotMonName, WORDSET_SetSlotMonNameAlt, WORDSET_Callback_EEC4, WORDSET_SetSlotMonNameEx, WORDSET_SetSlotMonSpecies, WORDSET_SetSlotMonSpeciesAlt, WORDSET_SetSlotFromMsgCB, WORDSET_Callback_EF40, WORDSET_Callback_EF4C, WORDSET_SetSlotFromMsg118, WORDSET_SetSlotFromBank, WORDSET_SetSlotFromMsgB6, WORDSET_SetSlotFromMsg18, WORDSET_SetSlotNumber, WORDSET_SetSlotPmsWord, WORDSET_SetSlotMarkerFlag, WORDSET_SetSlotFromMsgC7, WORDSET_SetSlotMyStatus, WORDSET_SetSlotFromMsgE7, WORDSET_DeleteMsgdataF094, WORDSET_Set, WORDSET_SetSlotPokeData, WORDSET_Callback_F124, WORDSET_SetSlotFromMsgBE, WORDSET_SetSlotFromMsgB4, WORDSET_SetSlotFromMsg37, WORDSET_SetSlotFromMsg59, WORDSET_SetSlotBoxName, WORDSET_SetSlotFromMsgA0, WORDSET_SetSlotFromMsg2B, WORDSET_SetSlotFromMsg00, WORDSET_SetSlotFromMsg38, WORDSET_DrawF1E0, WORDSET_SetSlotMonth, WORDSET_CopyTaggedText, WORDSET_ClearAllSlots, WORDSET_LoadSpeciesNameBank, WORDSET_FormatNumber, WORDSET_CopyString, WORDSET_CheckF448, WORDSET_CheckF47C, WORDSET_ParsePackedLimits
 * address:  0x0201EC74
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gf_font.c by tools/splitfile.py.
 *
 * symbols:
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_Clear  0x0204581C  arm
 *   STRBUF_AppendChar  0x02045AFC  arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   gWordsetFileName  0x020A7364  data  a1
 *   STRBUF_Create   0x020457B0  arm
 *   gSpeciesNameBank   0x020A7370  data
 *   PMSI_PARAM_ValidateDecoValue  0x0202473C  thumb
 *   BMP_OAM_Get  0x02025B94  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   gDigitGlyphsFullWidth     0x0209E784  data
 *   gDigitGlyphsHalfWidth     0x0209E758  data
 *   gPowersOfTen     0x0209E838  data
 *   gPackedCharTable  0x0209E864  data
 *   PMSI_PARAM_ValidateWord  0x020246C8  thumb
 *   PMS_WORD_LoadString  0x02024838  thumb
 *   STRBUF_Append  0x02045AA8  arm
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_Copy  0x02045838  arm
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 *   GF_FONT_GetTagChar 0x0201D5C4 thumb arm9
 *   GF_FONT_CheckD5CC 0x0201D5CC thumb arm9
 *   GF_FONT_AppendTag 0x0201D60C thumb arm9
 *   GF_FONT_GetTagParam 0x0201D670 thumb arm9
 *   GF_FONT_SkipTag 0x0201D688 thumb arm9
 */
#include "gf_font_shared_types.h"

struct MsgBank;

struct PackedLimits {
    u32 tableEndCode;
    u32 tableByteBias;
    u32 invalidFromCode;
};

extern u16 *STRBUF_GetChars(struct Strbuf *text);

extern void STRBUF_Clear(struct Strbuf *text);

extern void STRBUF_AppendChar(struct Strbuf *text, u16 value);

extern u16 STRBUF_GetLength(struct Strbuf *text);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);

extern u32 func_020307B0(void *block);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void  MI_CpuFill8(void *dest, u8 data, u32 size);

extern u32 func_02017E1C(void *mon, u32 paramId, u32 arg);

extern u32 func_02017E88(void *mon, u32 paramId, u32 arg);

extern void STRBUF_Delete(struct Strbuf *text);

extern void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src);

extern struct MsgBank *func_02045B38(u32 isResident, u32 archiveId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct MsgBank *bank);

extern void func_02045CAC(struct MsgBank *bank, u32 entryIndex, struct Strbuf *dest);

extern u32 PMSI_PARAM_ValidateWord(u16 *value, u32 mode, u32 flag);

extern u32 PMSI_PARAM_ValidateDecoValue(u32 *value, u32 mode);

extern void PMS_WORD_LoadString(u32 messageId, struct Strbuf *dest, u32 heapId);

extern u16 func_02045F50(const struct MsgBank *bank);

extern void MYSTATUS_NameToStrbuf(void *source, struct Strbuf *dest);

extern u32 BMP_OAM_Get(u32 value);

extern u32 TPOKE_DATA_GetRecordField(void *source, u32 index);

extern void func_0200785C(void *save, u32 box, struct Strbuf *dest);

extern u16  STRBUF_GetEosChar(void);

extern u32 _u32_div_f(u32 dividend, u32 divisor);

extern void STRBUF_Append(struct Strbuf *dst, struct Strbuf *src);

u32 GF_FONT_GetTagChar(void);

u32 GF_FONT_CheckD5CC(const u16 *tag);

void GF_FONT_AppendTag(struct Strbuf *text, u32 group, u32 kind, u16 paramCount, const u16 *params);

u32 GF_FONT_GetTagParam(const u16 *tag, u32 paramIndex);

u16 *GF_FONT_SkipTag(u16 *tag);

struct WordSet *WORDSET_Create(u32 slotCount, u32 textCapacity, u16 heapId);

u32 WORDSET_DeleteStrbufED04(struct WordSet *words);

void WORDSET_Init(struct WordTag *tag);

void WORDSET_ResetSlot(struct WordSet *words, u32 slot);

void WORDSET_SetSlotText(struct WordSet *words, u32 slot, struct Strbuf *src, const struct WordTag *tag);

void WORDSET_SetSlotFromMessage(struct WordSet *words, u32 slot, u32 messageId, u32 entryIndex);

void WORDSET_SetSlotTag(struct WordSet *words, u32 slot, struct Strbuf *src, u32 grammarCase, u32 isPlural, u32 gender);

void WORDSET_Callback(struct WordSet *words, u32 slot, u16 speciesId);

void WORDSET_SetSlotMonName(struct WordSet *words, u32 slot, void *mon);

void WORDSET_SetSlotMonNameAlt(struct WordSet *words, u32 slot, void *mon);

void WORDSET_Callback_EEC4(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotMonNameEx(struct WordSet *words, u32 slot, void *mon);

void WORDSET_SetSlotMonSpecies(struct WordSet *words, u32 slot, void *mon);

void WORDSET_SetSlotMonSpeciesAlt(struct WordSet *words, u32 slot, void *mon);

void WORDSET_SetSlotFromMsgCB(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_Callback_EF40(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_Callback_EF4C(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotFromMsg118(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotFromBank(struct WordSet *words, u32 slot, u32 entryIndex, u32 useFirstBank, u32 useSecondBank);

void WORDSET_SetSlotFromMsgB6(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotFromMsg18(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotNumber(struct WordSet *words, u32 slot, u32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth);

void WORDSET_SetSlotPmsWord(struct WordSet *words, u32 slot, u32 pmsWord);

void WORDSET_SetSlotMarkerFlag(struct WordSet *words, u32 slot, u32 markerFlag);

void WORDSET_SetSlotFromMsgC7(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotMyStatus(struct WordSet *words, u32 slot, void *source);

void WORDSET_SetSlotFromMsgE7(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_DeleteMsgdataF094(struct WordSet *words, u32 slot, u32 key, u32 entryIndex);

void WORDSET_Set(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotPokeData(struct WordSet *words, u32 slot, void *source);

void WORDSET_Callback_F124(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotFromMsgBE(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotFromMsgB4(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotFromMsg37(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotFromMsg59(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotBoxName(struct WordSet *words, u32 slot, void *save, u32 boxIndex);

void WORDSET_SetSlotFromMsgA0(struct WordSet *words, u32 slot, s32 entryIndex);

void WORDSET_SetSlotFromMsg2B(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotFromMsg00(struct WordSet *words, u32 slot, u8 entryIndex);

void WORDSET_SetSlotFromMsg38(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_DrawF1E0(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_SetSlotMonth(struct WordSet *words, u32 slot, u32 entryIndex);

void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);

void WORDSET_ClearAllSlots(struct WordSet *words);

void WORDSET_LoadSpeciesNameBank(u16 heapId);

void WORDSET_FormatNumber(struct Strbuf *text, s32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth);

void WORDSET_CopyString(const u16 *src, u16 *dst, u32 maxLength);

u32 WORDSET_CheckF448(const u16 *left, const u16 *right);

u32 WORDSET_CheckF47C(struct Strbuf *text);

void WORDSET_ParsePackedLimits(struct Strbuf *dst, struct Strbuf *src);

extern char gWordsetFileName[];

extern void *gSpeciesNameBank;

extern u16  gDigitGlyphsFullWidth[];

extern u16  gDigitGlyphsHalfWidth[];

extern u32  gPowersOfTen[];

extern const u16 gPackedCharTable[];

/*
 * wordset.c's constructor, the function src/matched/unit_0201EC64.c tail
 * calls with the default counts (8 slots, 0x20 bytes of string each).  It
 * allocates a 0x10-byte header and an array of `n` 0xc-byte WordSlot records
 * through the debug allocator func_02030734(heap, size, flag, file, line),
 * gives the header and every entry a string object from STRBUF_Create, and
 * returns 0 as soon as any allocation fails.
 *
 * The `__FILE__` argument is 0x020A7364, "wordset.c", and IS attestable by
 * the `string` class: the six bytes before it are the NUL terminator of
 * "gf_font.c" plus padding, so the run start is fixed from outside this
 * range (unlike the tables of
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md).
 *
 * TWO LEVERS, both of which the earlier pass in docs/notes/pkt_0201EC74.c.txt
 * missed and which together took the function from 152 bytes / 65 differing
 * rows to EXACT:
 *
 *  - **The failure path is a `goto fail;` chain with ONE `return 0;` at the
 *    end.**  Every failure return in the image lands on the single epilogue
 *    at 0x0201ECFA.  Written as four separate `return 0;` statements the
 *    compiler materialises the epilogue inline at the FIRST failure site and
 *    branches over the copy, which is eight bytes too long and reshuffles
 *    the two callee-saved slots (the pool word lands in r7 and the parameter
 *    copy of `n` in r5, the opposite of the image).  This is the explicit
 *    `goto` case of
 *    docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md:
 *    statements sit between the guards, so nothing else reproduces the
 *    shared exit.  That alone brings the compile to 144 bytes and 14
 *    differing bytes.
 *
 *  - **`heap` is `u8`, not `u32`.**  With `u32` the prologue schedules the
 *    three argument spills and the pool load in a different order
 *    (`ldr r5,[pc]` ahead of `adds r7,r0,#0`, and `str r1,[sp,#4]` ahead of
 *    `str r2,[sp,#8]`), fourteen bytes across the prologue and the first
 *    store pair.  Narrowing the parameter changes nothing about the code
 *    that runs -- the value is spilled to sp+8 untruncated and read back as
 *    a word for `p->heap = heap` -- but it changes the order mwccarm's value
 *    numbering creates the three incoming values in, which is what the
 *    prologue schedule follows.  This is the family's heap-id width seen
 *    once more: WORDSET_LoadSpeciesNameBank in src/matched/unit_0201F31C.c takes its heap
 *    as u16 for the same class of reason.
 *
 *    Found by tools/permuter.py (--mode hill --budget 800 --jobs 8 --types),
 *    which reported `type:p(heap:u32->u8)` at compile 244 of 800:
 *      baseline  DIFF   asm=855  bytes-out=14  size=144/144
 *      244       EXACT  asm=0    bytes-out=0   size=144/144
 *
 * STRBUF_Create is ARM, not Thumb.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table; the two counts are the caller's, not content constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WORDSET_Create.c \
 *       --func WORDSET_Create --addr 0x0201EC74 --cc 1.1p1 --thumb
 */
struct WordSet *WORDSET_Create(u32 slotCount, u32 textCapacity, u16 heapId)
{
    struct WordSet *words;
    u32 slot = 0;

    words = func_02030734(heapId, 0x10, 0, gWordsetFileName, 0x9F);
    if (words == 0) {
        goto fail;
    }
    words->slotCount = slotCount;
    words->heapId = heapId;
    words->scratch = STRBUF_Create(textCapacity, heapId);
    if (words->scratch == 0) {
        goto fail;
    }
    words->slots = func_02030734(heapId, slotCount * 0xc, slot, gWordsetFileName, 0xA8);
    if (words->slots == 0) {
        goto fail;
    }
    while (slot < slotCount) {
        WORDSET_Init(&words->slots[slot].tag);
        words->slots[slot].text = STRBUF_Create(textCapacity, heapId);
        if (words->slots[slot].text == 0) {
            break;
        }
        slot++;
    }
    if (slot != slotCount) {
        goto fail;
    }
    return words;
fail:
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           WORDSET_SetSlotFromMessage, WORDSET_SetSlotTag, WORDSET_Callback, WORDSET_SetSlotMonName,
 *           WORDSET_SetSlotMonNameAlt, WORDSET_Callback_EEC4, WORDSET_SetSlotMonNameEx, WORDSET_SetSlotMonSpecies,
 *           WORDSET_SetSlotMonSpeciesAlt, WORDSET_SetSlotFromMsgCB, WORDSET_Callback_EF40, WORDSET_Callback_EF4C,
 *           WORDSET_SetSlotFromMsg118, WORDSET_SetSlotFromBank, WORDSET_SetSlotFromMsgB6, WORDSET_SetSlotFromMsg18,
 *           WORDSET_SetSlotNumber, WORDSET_SetSlotPmsWord
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 slotCount; u32 heapId; struct WordSlot *slots;
 *                      struct Strbuf *scratch; };
 *     struct WordSlot { struct WordTag tag; struct Strbuf *text; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to WORDSET_SetSlotText, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * WORDSET_SetSlotTag are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * WORDSET_Init is the tag clear and takes a `struct WordTag *`, not a
 * `struct WordSlot *`: WORDSET_SetSlotTag calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * WORDSET_Callback reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * WORDSET_LoadSpeciesNameBank's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * WORDSET_SetSlotFromBank is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
u32 WORDSET_DeleteStrbufED04(struct WordSet *words)
{
    u32 slot;

    if (words->slots != 0) {
        for (slot = 0; slot < words->slotCount; slot++) {
            if (words->slots[slot].text == 0) {
                break;
            }
            STRBUF_Delete(words->slots[slot].text);
        }
        func_020307B0(words->slots);
    }
    if (words->scratch != 0) {
        STRBUF_Delete(words->scratch);
    }
    words->slotCount = 0;
    return func_020307B0(words);
}

void WORDSET_Init(struct WordTag *tag)
{
    MI_CpuFill8(tag, 0, 5);
    tag->addsMarker = 0;
}

void WORDSET_ResetSlot(struct WordSet *words, u32 slot)
{
    WORDSET_Init(&words->slots[slot].tag);
    STRBUF_Clear(words->slots[slot].text);
}

void WORDSET_SetSlotText(struct WordSet *words, u32 slot, struct Strbuf *src,
                   const struct WordTag *tag)
{
    if (slot < words->slotCount) {
        if (tag != 0) {
            words->slots[slot].tag = *tag;
        } else {
            WORDSET_Init(&words->slots[slot].tag);
        }
        STRBUF_Copy(words->slots[slot].text, src);
    }
}

void WORDSET_SetSlotFromMessage(struct WordSet *words, u32 slot, u32 messageId, u32 entryIndex)
{
    struct MsgBank *bank = func_02045B38(0, 2, (u16)messageId, (u16)words->heapId);

    if (bank != 0) {
        func_02045CAC(bank, entryIndex, words->scratch);
        WORDSET_SetSlotText(words, slot, words->scratch, 0);
        MSGDATA_Delete(bank);
    }
}

void WORDSET_SetSlotTag(struct WordSet *words, u32 slot, struct Strbuf *src, u32 grammarCase, u32 isPlural, u32 gender)
{
    struct WordTag tag;

    WORDSET_Init(&tag);
    tag.grammarCase = grammarCase;
    tag.isSingular = (isPlural == 0);
    WORDSET_SetSlotText(words, slot, src, &tag);
}

void WORDSET_Callback(struct WordSet *words, u32 slot, u16 speciesId)
{
    func_02045CAC(gSpeciesNameBank, speciesId, words->scratch);
    WORDSET_SetSlotText(words, slot, words->scratch, 0);
}

void WORDSET_SetSlotMonName(struct WordSet *words, u32 slot, void *mon)
{
    WORDSET_Callback(words, slot, func_02017E1C(mon, 5, 0));
}

void WORDSET_SetSlotMonNameAlt(struct WordSet *words, u32 slot, void *mon)
{
    WORDSET_Callback(words, slot, func_02017E88(mon, 5, 0));
}

void WORDSET_Callback_EEC4(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0x119, entryIndex);
}

void WORDSET_SetSlotMonNameEx(struct WordSet *words, u32 slot, void *mon)
{
    WORDSET_Callback_EEC4(words, slot, (u16)func_02017E1C(mon, 5, 0));
}

void WORDSET_SetSlotMonSpecies(struct WordSet *words, u32 slot, void *mon)
{
    func_02017E1C(mon, 0x73, (u32)words->scratch);
    WORDSET_SetSlotText(words, slot, words->scratch, 0);
}

void WORDSET_SetSlotMonSpeciesAlt(struct WordSet *words, u32 slot, void *mon)
{
    func_02017E88(mon, 0x73, (u32)words->scratch);
    WORDSET_SetSlotText(words, slot, words->scratch, 0);
}

void WORDSET_SetSlotFromMsgCB(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0xCB, entryIndex);
}

void WORDSET_Callback_EF40(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0x36, entryIndex);
}

void WORDSET_Callback_EF4C(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0x117, entryIndex);
}

void WORDSET_SetSlotFromMsg118(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0x118, entryIndex);
}

void WORDSET_SetSlotFromBank(struct WordSet *words, u32 slot, u32 entryIndex, u32 useFirstBank, u32 useSecondBank)
{
    if (useFirstBank != 0) {
        WORDSET_SetSlotFromMsg118(words, slot, entryIndex);
        return;
    }
    if (useSecondBank != 0) {
        WORDSET_Callback_EF4C(words, slot, entryIndex);
        return;
    }
    WORDSET_Callback_EF40(words, slot, entryIndex);
}

void WORDSET_SetSlotFromMsgB6(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0xB6, entryIndex);
}

void WORDSET_SetSlotFromMsg18(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0x18, entryIndex);
}

void WORDSET_SetSlotNumber(struct WordSet *words, u32 slot, u32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth)
{
    WORDSET_FormatNumber(words->scratch, number, topDigitIndex, padMode, isHalfWidth);
    WORDSET_SetSlotText(words, slot, words->scratch, 0);
}

void WORDSET_SetSlotPmsWord(struct WordSet *words, u32 slot, u32 pmsWord)
{
    u16 word = pmsWord;

    PMSI_PARAM_ValidateWord(&word, 0, 0);
    PMS_WORD_LoadString((u16)word, words->scratch, (u16)words->heapId);
    WORDSET_SetSlotText(words, slot, words->scratch, 0);
}

/*
 * Promoted from src/pending/sub_0201EFFC.c: every concrete byte was
 * already reproduced, and the one relocation, the call to
 * PMSI_PARAM_ValidateDecoValue, was capped at MATCH because the only branch to that
 * address anywhere in the image is the one inside this function. Now
 * that src/matched/sub_0202473C.c is an EXACT entry, the `matched` class
 * attests the call without needing a second caller (docs/MATCHING.md,
 * "the matched class"), and this file closes to EXACT.
 *
 * The last function of wordset.c's body: it normalises a value through
 * PMSI_PARAM_ValidateDecoValue and stores the result into the one-byte flag of the
 * slot's tag. The value is passed by address, so it lives on the stack
 * and is read back after the call; the `str r2, [sp]` before the call and
 * the `ldr r2, [sp]` after it are that, not a spill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201EFFC.c \
 *       --func WORDSET_SetSlotMarkerFlag --addr 0x0201EFFC --cc 1.1p1 --thumb
 */
void WORDSET_SetSlotMarkerFlag(struct WordSet *words, u32 slot, u32 markerFlag)
{
    u32 flag = markerFlag;

    PMSI_PARAM_ValidateDecoValue(&flag, 0);
    if (slot < words->slotCount) {
        words->slots[slot].tag.addsMarker = flag;
    }
}

/*
 * Three of the wordset.c setters, cut off at 0x0201F094 because the function
 * there is the only caller of 0x02025B94 anywhere in the image and so cannot
 * be attested; see src/pending/sub_0201F094.c.  The rest of the run continues
 * in src/matched/unit_0201F0F8.c.
 *
 * WORDSET_SetSlotFromMsgE7 renders message 0xE7 with an argument and falls back to
 * clearing the slot when the argument is out of the message's own range; the
 * `bhs` is the unsigned compare against func_02045F50's result, and the
 * fall-through arm is the in-range one
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to WORDSET_ResetSlot is carried by the `matched` class: its only six
 * callers in the image are all inside this packet, so no cut reaches it, but
 * src/matched/unit_0201ED04.c is an EXACT entry covering that address.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F020.c  *       --addr 0x0201F020 --thumb
 */
void WORDSET_SetSlotFromMsgC7(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0xC7, entryIndex);
}

void WORDSET_SetSlotMyStatus(struct WordSet *words, u32 slot, void *source)
{
    MYSTATUS_NameToStrbuf(source, words->scratch);
    WORDSET_SetSlotText(words, slot, words->scratch, 0);
}

void WORDSET_SetSlotFromMsgE7(struct WordSet *words, u32 slot, u32 entryIndex)
{
    struct MsgBank *bank = func_02045B38(0, 2, (u16)0xE7, (u16)words->heapId);

    if (bank != 0) {
        if (entryIndex < func_02045F50(bank)) {
            func_02045CAC(bank, entryIndex, words->scratch);
            WORDSET_SetSlotText(words, slot, words->scratch, 0);
        } else {
            WORDSET_ResetSlot(words, slot);
        }
        MSGDATA_Delete(bank);
    }
}

/*
 * Promoted from src/pending/sub_0201F094.c: every concrete byte was
 * already reproduced, and the one relocation, the call to
 * BMP_OAM_Get, was capped at MATCH because the only branch to that
 * address anywhere in the image is the one inside this function. Now
 * that src/matched/sub_02025B94.c is an EXACT entry, the `matched` class
 * attests the call without needing a second caller, and this file closes
 * to EXACT.
 *
 * A wordset.c setter that maps a caller value to a message id through
 * BMP_OAM_Get and renders it. That is why the wordset.c setter run is
 * committed as src/matched/unit_0201F020.c and
 * src/matched/unit_0201F0F8.c with this function left out between them;
 * it can now be folded back in on a future pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201F094.c \
 *       --func WORDSET_DeleteMsgdataF094 --addr 0x0201F094 --cc 1.1p1 --thumb
 */
void WORDSET_DeleteMsgdataF094(struct WordSet *words, u32 slot, u32 key, u32 entryIndex)
{
    u32 messageId = BMP_OAM_Get(key);
    struct MsgBank *bank;

    if (messageId != 0 && entryIndex != 0) {
        bank = func_02045B38(0, 2, (u16)messageId, (u16)words->heapId);
        if (bank != 0) {
            if (entryIndex < func_02045F50(bank)) {
                func_02045CAC(bank, entryIndex, words->scratch);
                WORDSET_SetSlotText(words, slot, words->scratch, 0);
                MSGDATA_Delete(bank);
                return;
            }
            MSGDATA_Delete(bank);
        }
    }
    WORDSET_ResetSlot(words, slot);
}

/*
 *           WORDSET_SetSlotFromMsgB4, WORDSET_SetSlotFromMsg37, WORDSET_SetSlotFromMsg59, WORDSET_SetSlotBoxName,
 *           WORDSET_SetSlotFromMsgA0, WORDSET_SetSlotFromMsg2B, WORDSET_SetSlotFromMsg00, WORDSET_SetSlotFromMsg38,
 *           WORDSET_DrawF1E0, WORDSET_SetSlotMonth
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through WORDSET_SetSlotFromMessage.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * WORDSET_SetSlotFromMsgA0 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * WORDSET_DrawF1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to WORDSET_ResetSlot are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void WORDSET_Set(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0xBF, entryIndex);
}

void WORDSET_SetSlotPokeData(struct WordSet *words, u32 slot, void *source)
{
    WORDSET_Set(words, slot, (u8)TPOKE_DATA_GetRecordField(source, 1));
}

void WORDSET_Callback_F124(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0x11B, entryIndex);
}

void WORDSET_SetSlotFromMsgBE(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0xBE, entryIndex);
}

void WORDSET_SetSlotFromMsgB4(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0xB4, entryIndex);
}

void WORDSET_SetSlotFromMsg37(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0x37, entryIndex);
}

void WORDSET_SetSlotFromMsg59(struct WordSet *words, u32 slot, u32 entryIndex)
{
    WORDSET_SetSlotFromMessage(words, slot, 0x59, entryIndex);
}

void WORDSET_SetSlotBoxName(struct WordSet *words, u32 slot, void *save, u32 boxIndex)
{
    func_0200785C(save, boxIndex, words->scratch);
    WORDSET_SetSlotText(words, slot, words->scratch, 0);
}

void WORDSET_SetSlotFromMsgA0(struct WordSet *words, u32 slot, s32 entryIndex)
{
    if (entryIndex >= 0x30) {
        entryIndex = 0;
    }
    WORDSET_SetSlotFromMessage(words, slot, 0xA0, entryIndex);
}

void WORDSET_SetSlotFromMsg2B(struct WordSet *words, u32 slot, u32 entryIndex)
{
    if (entryIndex > 8) {
        WORDSET_ResetSlot(words, slot);
        return;
    }
    WORDSET_SetSlotFromMessage(words, slot, 0x2B, entryIndex);
}

void WORDSET_SetSlotFromMsg00(struct WordSet *words, u32 slot, u8 entryIndex)
{
    if (entryIndex > 0x91) {
        WORDSET_ResetSlot(words, slot);
        return;
    }
    WORDSET_SetSlotFromMessage(words, slot, 0, entryIndex);
}

void WORDSET_SetSlotFromMsg38(struct WordSet *words, u32 slot, u32 entryIndex)
{
    if (entryIndex > 8) {
        WORDSET_ResetSlot(words, slot);
        return;
    }
    WORDSET_SetSlotFromMessage(words, slot, 0x38, entryIndex);
}

void WORDSET_DrawF1E0(struct WordSet *words, u32 slot, u32 weekday)
{
    struct MsgBank *bank = func_02045B38(0, 3, (u16)0x1CD, (u16)words->heapId);

    WORDSET_ResetSlot(words, slot);
    if (weekday <= 6 && bank != 0) {
        func_02045CAC(bank, weekday + 0x2B, words->scratch);
        WORDSET_SetSlotText(words, slot, words->scratch, 0);
        MSGDATA_Delete(bank);
    }
}

void WORDSET_SetSlotMonth(struct WordSet *words, u32 slot, u32 month)
{
    if (month < 1) {
        month = 1;
    } else if (month > 0xC) {
        month = 0xC;
    }
    WORDSET_SetSlotFromMessage(words, slot, 0x116, month - 1);
}

/*
 * wordset.c's message expander, 204 bytes.  It walks the source message a
 * halfword at a time and rewrites it into the destination buffer: an ordinary
 * character is copied straight through, a 0xF000 tag that is not a word
 * reference is copied verbatim halfword by halfword, and a word reference is
 * replaced by the stored word itself.
 *
 * The tag primitives it calls are the seven of src/matched/unit_0201D5C4.c:
 * GF_FONT_GetTagChar is the 0xF000 marker, GF_FONT_CheckD5CC says whether the tag is a
 * word reference, GF_FONT_GetTagParam reads parameter 0 (the word index),
 * GF_FONT_AppendTag writes a new tag, and GF_FONT_SkipTag steps the cursor past a
 * tag.  The word table hangs off the object at +8 and its entries are 0xC
 * bytes: a flag at +4 and the word's own message at +8.  When the flag is set
 * the expansion is bracketed by two freshly built 0xBD tags, kinds 6 and 4,
 * whose single parameter is the word index and the constant 0x54.
 *
 * Three details cost time:
 *
 *   - **The entry pointer is a named local for the first tag write and the
 *     written-out expression for the second.**  `&tbl[i]` must be bound to a
 *     local, because the two `strh`s into the parameter buffer sit between the
 *     flag test and the first write, and the buffer has its address taken, so
 *     re-reading `words->slots` after them costs a reload the original does not
 *     have.  Binding it for the *second* write as well is four bytes too long
 *     the other way: the local would then be live across GF_FONT_AppendTag and the
 *     index has to be spilled.  The original recomputes the address from the
 *     two callee-saved registers it already holds, which is what writing the
 *     expression out gives.
 *   - **The character copies are `*p++`, not `p[0]` then `p++`.**  With the
 *     increment spelled separately the compiler sinks it past the call and
 *     then folds the loop-bottom re-read into the copy's own load; the
 *     function is four bytes short and the bottom of the loop is wrong.
 *   - **`q` is declared before `p`.**  The two cursors are the only locals
 *     live across the inner loop, and declaring `p` first swaps r4 and r5
 *     throughout (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * EXACT*: the two bytes after the epilogue are the unit's alignment padding
 * and 0x0201F31C, the next function, already carries a label.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201F250.c \
 *       --func WORDSET_CopyTaggedText --addr 0x0201F250 --cc 1.1p1 --thumb
 */
void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src)
{
    u16 tagParams[2];
    u32 terminator;
    u32 tagMarker;
    u16 *copyCursor;
    u16 *cursor;
    u32 slot;
    struct WordSlot *entry;

    cursor = STRBUF_GetChars(src);
    STRBUF_Clear(dst);
    terminator = STRBUF_GetEosChar();
    tagMarker = GF_FONT_GetTagChar();
    while (cursor[0] != terminator) {
        if (cursor[0] == tagMarker) {
            if (GF_FONT_CheckD5CC(cursor) != 0) {
                slot = GF_FONT_GetTagParam(cursor, 0);
                entry = &words->slots[slot];
                if (entry->tag.addsMarker != 0) {
                    tagParams[1] = (u16)slot;
                    tagParams[0] = 0x54;
                    GF_FONT_AppendTag(entry->text, 0xBD, 6, 1, &tagParams[1]);
                    GF_FONT_AppendTag(words->slots[slot].text, 0xBD, 4, 1, &tagParams[0]);
                }
                WORDSET_ParsePackedLimits(dst, words->slots[slot].text);
                cursor = GF_FONT_SkipTag(cursor);
            } else {
                copyCursor = cursor;
                cursor = GF_FONT_SkipTag(cursor);
                while (copyCursor < cursor) {
                    STRBUF_AppendChar(dst, *copyCursor++);
                }
            }
        } else {
            STRBUF_AppendChar(dst, *cursor++);
        }
    }
}

/*
 * The wordset.c "clear every slot" walk and the one-line initialiser that
 * fills the file-scope template string at 0x020A7370.  That pointer is loaded
 * by WORDSET_Callback in src/matched/unit_0201ED04.c and by seven functions
 * outside this region, so the `literal` class has witnesses to spare.
 *
 * WORDSET_LoadSpeciesNameBank takes its heap id as a u16: the 4th argument of
 * func_02045B38 is a u16 and the original passes the incoming register
 * straight through with no `lsls`/`lsrs` truncation pair, which a u32
 * parameter would have cost.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F31C.c  *       --addr 0x0201F31C --thumb
 */
void WORDSET_ClearAllSlots(struct WordSet *words)
{
    u32 slot;

    for (slot = 0; slot < words->slotCount; slot++) {
        STRBUF_Clear(words->slots[slot].text);
    }
}

void WORDSET_LoadSpeciesNameBank(u16 heapId)
{
    gSpeciesNameBank = func_02045B38(0, 2, 0x46, heapId);
}

/*
 *           The three data pool words -- gDigitGlyphsFullWidth, gDigitGlyphsHalfWidth, gPowersOfTen -- have no
 *           witness outside 0201F35C..0201F41C: each address appears in exactly one
 *           literal pool image-wide, this function's own, so the 'literal' class has
 *           nothing to offer and no other matched entry names them. A second reader of
 *           any of the three tables would release this file to EXACT.
 */
void WORDSET_FormatNumber(struct Strbuf *text, s32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth)
{
    u16 *digitGlyphs;
    u32 divisor;
    u32 digit;

    if (isHalfWidth == 0) {
        digitGlyphs = gDigitGlyphsFullWidth;
    } else {
        digitGlyphs = gDigitGlyphsHalfWidth;
    }
    STRBUF_Clear(text);

    if ((u16)(number < 0) != 0) {
        u32 glyph;
        s32 minusOne = ~0;
        number = minusOne * number;
        if (isHalfWidth == 0) {
            glyph = 0x30FC;
        } else {
            glyph = 0x2D;
        }
        STRBUF_AppendChar(text, (u16)glyph);
    }

    divisor = gPowersOfTen[topDigitIndex];
    while (divisor != 0) {
        digit = _u32_div_f((u32)number, divisor);
        digit = (u16)digit;
        number = number - divisor * digit;
        if (digit >= 10) {
            digit = 10;
        }
        if (padMode == 2) {
            STRBUF_AppendChar(text, digitGlyphs[digit]);
        } else if (digit != 0 || divisor == 1) {
            padMode = 2;
            STRBUF_AppendChar(text, digitGlyphs[digit]);
        } else if (padMode == 1) {
            u32 glyph;
            if (isHalfWidth == 0) {
                glyph = 0x3000;
            } else {
                glyph = 0x20;
            }
            STRBUF_AppendChar(text, (u16)glyph);
        }
        divisor = _u32_div_f(divisor, 10);
    }
}

/*
 * Decimal number printer.  STRBUF_Clear(ctx) resets the glyph writer;
 * STRBUF_AppendChar(ctx, u16) emits one glyph; _u32_div_f is the mwccarm
 * integer-division helper (docs/idioms/runtime-helper-reloc.md).
 *
 * `flag` selects one of two glyph tables (0x0209E784 full-width,
 * 0x0209E758 half-width) and the matching minus / space glyphs
 * (0x30FC vs 0x2D, 0x3000 vs 0x20): this is the full-width/half-width
 * font pair, not a version-specific table.
 *
 * Two idioms carried the last four bytes: the negation is `~0 * n`, not
 * `-n` (which compiles to `rsbs`), and the remainder is `n - d * q`, not
 * `n - q * d` (docs/idioms/commutative-operand-order-names-the-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WORDSET_FormatNumber.c \
 *       --func WORDSET_FormatNumber --addr 0x0201F35C --cc 1.1p1 --thumb
 */


/*
 * Two wide-string helpers.  WORDSET_CopyString is a bounded copy that always
 * terminates the destination; WORDSET_CheckF448 is an equality test.  Both read
 * the terminator character from STRBUF_GetEosChar rather than from a constant,
 * and both hold it in a named local, which is what puts the call result in
 * the left slot of WORDSET_CopyString's `cmp r0, r1`
 * (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * The last store of WORDSET_CopyString is `*(dst + n - 1) = eos`, not
 * `dst[n - 1] = eos`.  The two are the same value and different code: the
 * subscript form folds the subtraction into the index and scales once
 * (`subs`/`lsls`/`strh` with a register offset), while the pointer form
 * scales `n`, adds it to the base and then subtracts the element size
 * (`lsls`/`adds`/`subs #2`/`strh`).  Seven bytes, and nothing else in the
 * function moves; see
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F41C.c  *       --addr 0x0201F41C --thumb
 */
void WORDSET_CopyString(const u16 *src, u16 *dst, u32 maxLength)
{
    u16 terminator = STRBUF_GetEosChar();
    u32 index;

    for (index = 0; index < maxLength; index++) {
        dst[index] = src[index];
        if (terminator == src[index]) {
            break;
        }
    }
    *(dst + maxLength - 1) = terminator;
}

u32 WORDSET_CheckF448(const u16 *left, const u16 *right)
{
    u16 terminator = STRBUF_GetEosChar();

    while (*left != terminator) {
        if (*left != *right) {
            return 0;
        }
        left++;
        right++;
    }
    if (*right != terminator) {
        return 0;
    }
    return 1;
}

/*
 * "Is this string a packed nine-bit run", the predicate WORDSET_ParsePackedLimits tests
 * before unpacking.  A non-empty string whose first character is 0xF100 is
 * one; the marker is materialised as `movs r0, #0xF1` / `lsls r0, #8` rather
 * than from a pool word, so it is a plain constant.
 *
 * The two tests share one `movs r0, #0; pop` exit and neither jumps over an
 * inline epilogue, which is the single-conjunction shape of
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md:
 * written as two separate early returns the function grows a second epilogue.
 *
 * This is its own file rather than part of src/pending/sub_0201F4A0.c
 * because WORDSET_ParsePackedLimits holds the only call to it in the image.  Matched
 * apart, that call is an ordinary `label` witness from outside this range,
 * and the `matched` class then carries the site in WORDSET_ParsePackedLimits itself.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F47C.c \
 *       --addr 0x0201F47C --thumb
 */
u32 WORDSET_CheckF47C(struct Strbuf *text)
{
    if (STRBUF_GetLength(text) != 0 && *STRBUF_GetChars(text) == 0xF100) {
        return 1;
    }
    return 0;
}

/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * The nine-bit unpacker.  A string whose first character is 0xF100
 * (WORDSET_CheckF47C, src/matched/unit_0201F47C.c) carries its text as a run of
 * nine-bit codes packed into the halfwords after the marker; this walks them
 * and appends one character at a time to the destination.  0x1FF is the
 * terminator as well as the field mask, codes 0x100..0x131 are translated
 * through a 16-bit table and anything at or above 0x132 becomes 0x3F, '?'.
 *
 * Every concrete byte is reproduced.  The one unresolved relocation is the
 * table address 0x0209E864, and the pool word inside this function is the
 * only word in the image that holds it, so the `literal` class discards its
 * only witness and no cut helps.  Expressing the address as an offset from
 * WORDSET_FormatNumber's nearby table would resolve it, but that is a claim that the
 * two are one object and the image does not say so.
 *
 * Three details cost time and are worth keeping:
 *
 *  - the bit cursor is signed.  `cmp r5, #0x10` / `blt` is a signed compare
 *    even though the value is never negative, so the local is `s32`; `u32`
 *    gives `blo` and one wrong byte.
 *  - the two range limits and the table bias live in a local aggregate, not
 *    in scalars.  Each of the two limits is stored twice, once as 0x1FF and
 *    once as 0x1FF - 0xCD, because mwccarm's value numbering follows a scalar
 *    local but stops at a member of an aggregate; written as scalars the
 *    constants fold and six instructions disappear.  That is
 *    docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md seen
 *    from the assignment side rather than the test side.
 *  - the unpacking loop is the fall-through arm and the plain-string copy is
 *    the `else`.  Written as an early return for the plain case the copy is
 *    emitted first and every branch in the function moves
 *    (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201F4A0.c  *       --addr 0x0201F4A0 --thumb
 */
void WORDSET_ParsePackedLimits(struct Strbuf *dst, struct Strbuf *src)
{
    u32 codeMask = 0x1FF;
    struct PackedLimits limits;
    const u16 *cursor;
    s32 bitPos;
    u16 code;

    if (WORDSET_CheckF47C(src) != 0) {
        cursor = STRBUF_GetChars(src) + 1;
        limits.tableEndCode = codeMask;
        limits.tableEndCode -= 0xCD;
        limits.invalidFromCode = codeMask;
        limits.invalidFromCode -= 0xCD;
        limits.tableByteBias = codeMask + 1;
        bitPos = 0;
        for (;;) {
            code = (*cursor >> bitPos) & codeMask;
            bitPos += 9;
            if (bitPos >= 16) {
                cursor++;
                bitPos -= 16;
                if (bitPos != 0) {
                    code |= (*cursor << (9 - bitPos)) & codeMask;
                }
            }
            if (code == codeMask) {
                return;
            }
            if (code >= 0x100 && code < limits.tableEndCode) {
                code = *(const u16 *)((const u8 *)&gPackedCharTable[code]
                                      - limits.tableByteBias);
            } else if (code >= limits.invalidFromCode) {
                code = 0x3F;
            }
            STRBUF_AppendChar(dst, code);
        }
    } else {
        STRBUF_Append(dst, src);
    }
}
