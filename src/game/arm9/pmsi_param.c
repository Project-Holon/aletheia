/*
 * file:     pmsi_param.c
 * unit:     yes
 * function: PMSI_PARAM_Create, PMSI_PARAM_Delete, PMSI_PARAM_SetWord, PMSI_PARAM_SetSentence, PMSI_PARAM_CheckCanceled, PMSI_PARAM_CheckModified, PMSI_PARAM_GetWord, PMSI_PARAM_GetWords, PMSI_PARAM_GetSentence, PMSI_PARAM_GetInputMode, PMSI_PARAM_GetSaveWork, PMSI_PARAM_GetWordSave, PMSI_PARAM_GetEventFlag, PMSI_PARAM_HasInitialSentence, PMSI_PARAM_GetOptionFlag, PMSI_PARAM_GetResult, PMSI_PARAM_IsSameInput, PMSI_PARAM_SetResult, PMSI_PARAM_GetUiInputMode, PMSI_PARAM_SetUiInputMode, FX_MakeSineTable, PMSI_PARAM_ClearSentence, PMSI_PARAM_InitSentence, PMSI_PARAM_InitSentenceId, PMSI_PARAM_SetDefaultSentence, PMSI_PARAM_SetDefaultGreeting, PMSI_PARAM_ToString, PMSI_PARAM_ToStringWords, PMSI_PARAM_GetSourceString, PMSI_PARAM_IsEnabled, PMSI_PARAM_IsComplete, PMSI_PARAM_GetWordCount, PMSI_PARAM_GetWordId, PMSI_PARAM_GetWordRaw, PMSI_PARAM_IsDecoWordAt, PMSI_PARAM_IsDecoWord, PMSI_PARAM_GetDecoId, PMSI_PARAM_GetSentenceType, PMSI_PARAM_GetSentenceId, PMSI_PARAM_Compare, PMSI_PARAM_Copy, PMSI_PARAM_GetSentenceCount, PMSI_PARAM_SetSentenceId, PMSI_PARAM_SetWordAt, PMSI_PARAM_ClearUnusedWords, PMSI_PARAM_IsValid, PMSI_PARAM_Validate, PMSI_PARAM_ValidateWord, PMSI_PARAM_ValidateDecoValue, PMSI_PARAM_IsSpecialWord
 * address:  0x02024044
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   GAME_DATA_GetEventWorkFromSave  0x02012FE4  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   file_020A745C  0x020A745C  data
 *   unit_020355C4  0x020355C4  arm
 *   UI_SetInputMode 0x020355D8 arm
 *   FX_SinCosTable_   0x020A1B38  data
 *   Table_0209F724   0x0209F724  data
 *   WORDSET_CreateDefault    0x0201EC64  thumb
 *   WORDSET_Delete    0x0201ED04  thumb
 *   WORDSET_SetSlotPmsWord    0x0201EFC8  thumb
 *   WORDSET_SetSlotMarkerFlag    0x0201EFFC  thumb
 *   WORDSET_CopyTaggedText    0x0201F250  thumb
 *   STRBUF_Create    0x020457B0  arm
 *   STRBUF_Delete    0x02045808  arm
 *   MSGDATA_CreateFromArchive    0x02045B38  arm
 *   MSGDATA_Delete    0x02045C04  arm
 *   MSGDATA_AllocString    0x02045EC0  arm
 *   g_0209F724  0x0209F724  data
 *   g_0209F71C  0x0209F71C  data
 *   data_0209F734  0x0209F734  data
 *   PMS_WORD_SplitWordId  0x020248D8  thumb
 *   PMS_WORD_GetSaveData  0x02024988  thumb
 *   PRINTSYS_CountControlTag  0x0201D478  thumb
 */
#include "pms_types.h"

struct WinPanel020071CCCtrl;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   short s16;
typedef signed long long s64;

/*
 * The easy-chat input parameter object (0x20 bytes).  inputMode selects what
 * the player enters: 0 = one word, 1 = two words, 2 = a whole sentence.
 * words holds the word input of modes 0 and 1; sentence holds the sentence of
 * mode 2.  saveWork and wordSave are the two save blocks the input screens
 * read.
 */
struct PmsiParam {
    u8  inputMode;
    u8  canceled;           /* 1 until a result is stored */
    u8  changed;            /* result differs from the initial input */
    u8  eventFlagSet : 1;   /* zone event flag 0x960 at creation */
    u8  closed : 1;
    u8  hasInitialSentence : 1;
    u8  optionFlag : 1;
    u8  unused : 4;
    u8  pad04[4];
    void *saveWork;
    void *wordSave;
    struct PmsData sentence;
    u16 words[2];
    u8  pad1C[4];
};

typedef struct WordPair { u16 first, second; } WordPair;

/* The special-word table: 12 easy-chat word ids. */
struct SpecialWordTable {
    u16 words[12];
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void *SAVE_CONTROL_GetBlock(struct WinPanel020071CCCtrl *ctrl, u32 id);
extern void *GAME_DATA_GetEventWorkFromSave(struct WinPanel020071CCCtrl *save);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, int id);
extern u32 unit_020355C4(void);
extern void UI_SetInputMode(void *);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void WORDSET_SetSlotPmsWord(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotMarkerFlag(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void  *STRBUF_Create(u32 size, u16 heap);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern struct MsgBank *MSGDATA_CreateFromArchive(int resident, int arcId, u32 fileId, u16 heapId);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern u32 PRINTSYS_CountControlTag(void *s);
struct PmsiParam *PMSI_PARAM_Create(u32 inputMode, u32 unused, void *initialSentence, u32 optionFlag, void *saveControl, u32 heapId);
void PMSI_PARAM_Delete(void *obj);
void PMSI_PARAM_SetWord(struct PmsiParam *obj, u16 word);
void PMSI_PARAM_SetSentence(struct PmsiParam *obj, const struct PmsData *sentence);
int PMSI_PARAM_CheckCanceled(const struct PmsiParam *obj);
int PMSI_PARAM_CheckModified(const struct PmsiParam *obj);
unsigned int PMSI_PARAM_GetWord(const struct PmsiParam *obj);
void PMSI_PARAM_GetWords(const struct PmsiParam *obj, unsigned short *__restrict outWords);
void PMSI_PARAM_GetSentence(const struct PmsiParam *obj, struct PmsData *outSentence);
u32 PMSI_PARAM_GetInputMode(const struct PmsiParam *obj);
void *PMSI_PARAM_GetSaveWork(const struct PmsiParam *obj);
void *PMSI_PARAM_GetWordSave(const struct PmsiParam *obj);
int PMSI_PARAM_GetEventFlag(const struct PmsiParam *obj);
u32 PMSI_PARAM_HasInitialSentence(const struct PmsiParam *obj);
int PMSI_PARAM_GetOptionFlag(const struct PmsiParam *obj);
void PMSI_PARAM_GetResult(const struct PmsiParam *obj, u16 *outWords, u16 *outSentence);
u32 PMSI_PARAM_IsSameInput(const struct PmsiParam *obj, const u16 *words, const struct PmsData *sentence);
void PMSI_PARAM_SetResult(struct PmsiParam *obj, const u16 *words, const struct PmsData *sentence);
void PMSI_PARAM_GetUiInputMode(void);
void PMSI_PARAM_SetUiInputMode(void *unused, void *inputMode);
void FX_MakeSineTable(s16 *table, u32 count, u16 step, int amplitude);
void PMSI_PARAM_ClearSentence(struct PmsData *sentence);
void PMSI_PARAM_InitSentence(struct PmsData *sentence, u32 sentenceType);
void PMSI_PARAM_InitSentenceId(struct PmsData *sentence, u32 sentenceType, u32 sentenceId);
void PMSI_PARAM_SetDefaultSentence(struct PmsData *sentence, u32 preset);
void PMSI_PARAM_SetDefaultGreeting(struct PmsData *sentence);
void *PMSI_PARAM_ToString(const struct PmsData *sentence, unsigned int heapId);
void *PMSI_PARAM_ToStringWords(const struct PmsData *sentence, u32 heapId, int wordCount);
void *PMSI_PARAM_GetSourceString(const struct PmsData *sentence, u32 heapId);
int PMSI_PARAM_IsEnabled(const u16 *word);
int PMSI_PARAM_IsComplete(struct PmsData *sentence, u16 heapId);
u32 PMSI_PARAM_GetWordCount(u32 sentenceType, u32 sentenceId, u16 heapId);
u16 PMSI_PARAM_GetWordId(const struct PmsData *sentence, u32 index);
u16 PMSI_PARAM_GetWordRaw(const struct PmsData *sentence, u32 index);
u32 PMSI_PARAM_IsDecoWordAt(const struct PmsData *sentence, u32 index);
u32 PMSI_PARAM_IsDecoWord(u32 word);
u32 PMSI_PARAM_GetDecoId(u32 word);
int PMSI_PARAM_GetSentenceType(const struct PmsData *sentence);
unsigned int PMSI_PARAM_GetSentenceId(const struct PmsData *sentence);
int PMSI_PARAM_Compare(const struct PmsData *left, const struct PmsData *right);
void PMSI_PARAM_Copy(struct PmsData *dst, const struct PmsData *src);
u8 PMSI_PARAM_GetSentenceCount(u32 sentenceType);
void PMSI_PARAM_SetSentenceId(struct PmsData *sentence, int sentenceType, int sentenceId);
void PMSI_PARAM_SetWordAt(struct PmsData *sentence, unsigned index, u16 word);
void PMSI_PARAM_ClearUnusedWords(struct PmsData *sentence, u16 heapId);
u32 PMSI_PARAM_IsValid(struct PmsData *sentence, u32 heapId);
u32 PMSI_PARAM_Validate(struct PmsData *sentence, u32 allowEmpty, u32 heapId);
u32 PMSI_PARAM_ValidateWord(u16 *word, u32 allowEmpty, u32 allowDeco);
u32 PMSI_PARAM_ValidateDecoValue(u32 *decoId, u32 allowZero);
int PMSI_PARAM_IsSpecialWord(u32 word);
int PMS_WORD_SplitWordId(u32 word, u32 *wordGroup, u32 *wordIndex);
void *PMS_WORD_GetSaveData(struct WinPanel020071CCCtrl *ctrl);

extern u8 file_020A745C[];
extern const s16 FX_SinCosTable_[];
extern u16 Table_0209F724[];
extern u16 g_0209F724[];
extern u8 g_0209F71C[];
extern const struct SpecialWordTable data_0209F734;

/*
 * pmsi_param.c's constructor (the __FILE__ anchor at 0x020A745C reads
 * "pmsi_param.c", line 0x56).  Allocates the 0x20-byte parameter object,
 * hangs two sub-objects off it, seeds the flag byte at +3 and then takes
 * one of two initialisation paths on `kind`.
 *
 * Four spellings are load-bearing and each was isolated against the bytes:
 *   - `heapId` is a u32 parameter narrowed by an EXPLICIT (u16) cast at the
 *     allocator call.  A u16 parameter gives `ldrh` at +0x08 where the
 *     original loads a full word and narrows with lsls/lsrs #0x10.
 *   - ZONEDATA_CheckEventFlag returns u32 and the result is narrowed by an explicit
 *     (u8) cast before the bitfield store.  Declaring the return u8 folds
 *     the `lsls #0x18 / lsrs #0x18` pair away and loses 4 bytes.
 *   - `optionFlag` is likewise u32 with an explicit (u8) cast into the bitfield:
 *     the original's `lsls r2,r7,#0x18 / lsrs r2,r2,#0x18` is that cast,
 *     and the following `lsls #0x1f / lsrs #0x1c` is the 1-bit bitfield at
 *     bit 3 (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *   - 0x02082D44 is called (src, dest, size), i.e. MI_CpuCopy8's order, not
 *     memcpy's: the original loads r0 from `initialSentence` and r1 from `obj + 0x10`.
 *     Spelling it memcpy(dst, src, n) swaps r0/r1 and costs two bytes.
 *
 * `obj->eventFlagSet = ...` and `obj->closed = 0` must stay two separate bitfield writes
 * (bics/orrs then bics), not a folded mask.
 *
 * EXACT*: the inferred extent runs to 344 bytes because the follower at
 * 0x020240F4 is the unlabelled 8-byte thunk PMSI_PARAM_Delete and the run of
 * unlabelled leaf accessors after it (they save no lr, so disasm.py never
 * labels them).  The compiled 184 bytes are byte-identical.  Unlabelled
 * follower to seed into layout/function_starts.txt: 0x020240F4.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMSI_PARAM_Create.c \
 *       --func PMSI_PARAM_Create --addr 0x02024044 --thumb --cc 1.1p1
 */
struct PmsiParam *PMSI_PARAM_Create(u32 inputMode, u32 unused, void *initialSentence, u32 optionFlag,
                          void *saveControl, u32 heapId)
{
    struct PmsiParam *obj;
    int i;

    obj = (struct PmsiParam *)GFL_HEAP_Alloc((u16)heapId, 0x20, 1, (const char *)file_020A745C, 0x56);
    obj->inputMode = (u8)inputMode;
    obj->saveWork = SAVE_CONTROL_GetBlock(saveControl, 0x37);
    obj->wordSave = PMS_WORD_GetSaveData(saveControl);
    obj->eventFlagSet = (u8)ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWorkFromSave(saveControl), 0x960);
    obj->closed = 0;
    obj->canceled = 1;
    obj->changed = 0;
    obj->optionFlag = (u8)optionFlag;
    if (inputMode == 2) {
        if (initialSentence == 0) {
            PMSI_PARAM_InitSentence(&obj->sentence, 0);
        } else {
            MI_CpuCopy8(initialSentence, &obj->sentence, 8);
            obj->hasInitialSentence = 1;
        }
    } else {
        for (i = 0; i < 2; i++) {
            obj->words[i] = 0xFFFF;
        }
    }
    return obj;
}

/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x020307B0, the callee's
 * address with its low bit clear, i.e. an ARM target (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_Delete.c \
 *       --func PMSI_PARAM_Delete --addr 0x020240FC --thumb --cc 1.1p1
 */
void PMSI_PARAM_Delete(void *obj)
{
    GFL_HEAP_Free(obj);
}

void PMSI_PARAM_SetWord(struct PmsiParam *obj, u16 word)
{
    obj->words[0] = word;
}

void PMSI_PARAM_SetSentence(struct PmsiParam *obj, const struct PmsData *sentence)
{
    obj->sentence.sentenceType = sentence->sentenceType;
    obj->sentence.sentenceId = sentence->sentenceId;
    obj->sentence.word[0] = sentence->word[0];
    obj->sentence.word[1] = sentence->word[1];
}

/*
 * Unlabelled Thumb leaf accessor: the canceled byte at +1.
 */
int PMSI_PARAM_CheckCanceled(const struct PmsiParam *obj)
{
    return obj->canceled;
}

/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
int PMSI_PARAM_CheckModified(const struct PmsiParam *obj) { return obj->changed; }

/*
 * Unlabelled Thumb leaf accessor: halfword at +0x18.
 */
unsigned int PMSI_PARAM_GetWord(const struct PmsiParam *obj)
{
    return obj->words[0];
}

/*
 * Unlabelled Thumb leaf accessor: copy the halfwords at +0x18 and +0x1a to out. __restrict on outWords makes both loads precede both stores.
 */
void PMSI_PARAM_GetWords(const struct PmsiParam *obj, unsigned short *__restrict outWords)
{
    outWords[0] = obj->words[0];
    outWords[1] = obj->words[1];
}

/*
 * Unlabelled Thumb tail-call thunk: PMSI_PARAM_Copy(outSentence, &obj->sentence), where PMSI_PARAM_Copy copies a halfword pair.
 */
void PMSI_PARAM_GetSentence(const struct PmsiParam *obj, struct PmsData *outSentence)
{
    PMSI_PARAM_Copy(outSentence, &obj->sentence);
}

u32 PMSI_PARAM_GetInputMode(const struct PmsiParam *obj) { return obj->inputMode; }

void *PMSI_PARAM_GetSaveWork(const struct PmsiParam *obj){return obj->saveWork;}

void *PMSI_PARAM_GetWordSave(const struct PmsiParam *obj){return obj->wordSave;}

int PMSI_PARAM_GetEventFlag(const struct PmsiParam *obj){return obj->eventFlagSet;}

/*
 * Unlabelled Thumb leaf in the ARM9 module: extracts bit 2 of the byte at
 * +3. Pairs with PMSI_PARAM_GetOptionFlag, which extracts bit 3.
 *
 * Addresses are Black-image addresses.
 */
u32 PMSI_PARAM_HasInitialSentence(const struct PmsiParam *obj)
{
    return obj->hasInitialSentence;
}

int PMSI_PARAM_GetOptionFlag(const struct PmsiParam *obj){return obj->optionFlag;}

void PMSI_PARAM_GetResult(const struct PmsiParam *obj, u16 *outWords, u16 *outSentence) {
    WordPair pair;
    switch(obj->inputMode) {
    case 0: outWords[0]=obj->words[0]; break;
    case 1:
        pair=*(const WordPair *)obj->words; *(WordPair *)outWords=pair; break;
    case 2:
        outSentence[0]=obj->sentence.sentenceType; outSentence[1]=obj->sentence.sentenceId;
        pair=*(const WordPair *)obj->sentence.word; *(WordPair *)(outSentence+2)=pair; break;
    }
}

u32 PMSI_PARAM_IsSameInput(const struct PmsiParam *obj, const u16 *words, const struct PmsData *sentence)
{
    switch (obj->inputMode) {
    case 0:
        if (*words == obj->words[0]) {
            return 1;
        }
        return 0;
    case 1:
        if (words[0] == obj->words[0] && words[1] == obj->words[1]) {
            return 1;
        }
        return 0;
    case 2:
        break;
    }

    return PMSI_PARAM_Compare(&obj->sentence, sentence);
}

void PMSI_PARAM_SetResult(struct PmsiParam *obj, const u16 *words, const struct PmsData *sentence)
{
    int i;

    obj->changed = (PMSI_PARAM_IsSameInput(obj, words, sentence) == 0);
    obj->canceled = 0;
    for (i = 0; i < 2; i++) {
        obj->words[i] = words[i];
    }
    obj->sentence.sentenceType = sentence->sentenceType;
    obj->sentence.sentenceId = sentence->sentenceId;
    obj->sentence.word[0] = sentence->word[0];
    obj->sentence.word[1] = sentence->word[1];
}

/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x020355C4, the callee's
 * address with its low bit clear, i.e. an ARM target (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_GetUiInputMode.c \
 *       --func PMSI_PARAM_GetUiInputMode --addr 0x0202421C --thumb --cc 1.1p1
 */
void PMSI_PARAM_GetUiInputMode(void)
{
    unit_020355C4();
}

void PMSI_PARAM_SetUiInputMode(void *unused, void *inputMode) { UI_SetInputMode(inputMode); }

/*
 * pmsi_param.c: fill table[0..count) with amplitude * sin(phase), phase advancing
 * by step through 16 bits.  The table is FX_SinCosTable_ at 0x020A1B38
 * (sin/cos s16 pairs, hence the stride of two halfwords: the SDK's
 * FX_SinIdx); the old notes misread the pool word as 0x02021B38.
 *
 * The last byte of docs/notes/FX_MakeSineTable.c.txt was the phase type: it is
 * a plain u16.  The wrap is then `lsrs` (u16 narrowing) and the index is
 * still `asrs` because the u16 promotes to int before the shift.  The s64
 * temporary for the widened table value is the permuter's find from wave 5.
 */
void FX_MakeSineTable(s16 *table, u32 count, u16 step, int amplitude)
{
    u32 i;
    u16 phase;

    phase = 0;
    i = 0;
    while (i < count) {
        s64 sinValue = (s64)FX_SinCosTable_[(phase >> 4) * 2];
        s64 scaled = sinValue * (s64)amplitude;

        table[i] = (s16)((int)((scaled + 0x800) >> 12) >> 12);
        i++;
        phase = (u16)(phase + step);
    }
}

/*
 * A slot-clearing sibling of PMSI_PARAM_InitSentence (src/matched/PMSI_PARAM_InitSentence.c):
 * the same three-halfword sentinel fill, but the leading id field is
 * also set to the sentinel instead of taking a caller-supplied id, so
 * there is no second parameter. The loop counter is signed, the same
 * `blt` tell as the sibling function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_ClearSentence.c \
 *       --func PMSI_PARAM_ClearSentence --addr 0x0202428C --cc 1.1p1 --thumb
 */
void PMSI_PARAM_ClearSentence(struct PmsData *sentence)
{
    int i;

    sentence->sentenceType = 0xFFFF;
    for (i = 0; i < 2; i++) {
        sentence->word[i] = 0xFFFF;
    }
}

/*
 * The common slot initialiser shared by PMSI_PARAM_SetDefaultGreeting and the four arms of
 * PMSI_PARAM_SetDefaultSentence (src/matched/unit_020242D8.c): store the id, zero the
 * flag halfword at +2, then a two-iteration loop seeds the trailing
 * halfwords at +4 and +6 with a shared 0xFFFF sentinel. The loop counter
 * is signed (the original's `blt`, not `blo`, on a literal trip count of
 * 2); an unsigned counter compiles to `blo` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_InitSentence.c \
 *       --func PMSI_PARAM_InitSentence --addr 0x020242A4 --cc 1.1p1 --thumb
 */
void PMSI_PARAM_InitSentence(struct PmsData *sentence, u32 sentenceType)
{
    int i;

    sentence->sentenceType = (u16)sentenceType;
    sentence->sentenceId = 0;
    for (i = 0; i < 2; i++) {
        sentence->word[i] = 0xFFFF;
    }
}

void PMSI_PARAM_InitSentenceId(struct PmsData *sentence, u32 sentenceType, u32 sentenceId)
{
    PMSI_PARAM_InitSentence(sentence, sentenceType);
    PMSI_PARAM_SetSentenceId(sentence, (int)sentenceType, (int)sentenceId);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * PMSI_PARAM_SetDefaultSentence dispatches on a 0..3 preset through a dense jump table
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md); an index
 * over 3 lands on the shared epilogue with neither a call nor a store,
 * which only a `default: break;` with nothing else in it produces. Each
 * arm calls the shared initialiser PMSI_PARAM_InitSentence (its own file,
 * src/matched/PMSI_PARAM_InitSentence.c, EXACT) with a small id, then overwrites the
 * flag halfword and one trailing field with plain 16-bit constants; the
 * four constants are narrowed by the `strh`, not addresses. Case 3 passes
 * the same id as case 1 (2) but a different flag (0xd instead of 0), so
 * the four arms cannot be collapsed by id alone.
 *
 * PMSI_PARAM_SetDefaultGreeting is the same shape as one switch arm inlined outside a
 * switch: call PMSI_PARAM_InitSentence with id 0, then overwrite the flag and
 * trailing field it just set.
 *
 * The two functions are contiguous with no gap: PMSI_PARAM_SetDefaultSentence's own
 * literal pool (the four constants) runs right up to PMSI_PARAM_SetDefaultGreeting's
 * entry point.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020242D8.c \
 *       --addr 0x020242D8 --thumb
 */
void PMSI_PARAM_SetDefaultSentence(struct PmsData *sentence, u32 preset)
{
    switch (preset) {
    case 0:
        PMSI_PARAM_InitSentence(sentence, 1);
        sentence->sentenceId = 0;
        sentence->word[0] = 0x5D2;
        break;
    case 1:
        PMSI_PARAM_InitSentence(sentence, 2);
        sentence->sentenceId = 0;
        sentence->word[0] = 0x5CD;
        break;
    case 2:
        PMSI_PARAM_InitSentence(sentence, 3);
        sentence->sentenceId = 0;
        sentence->word[0] = 0x667;
        break;
    case 3:
        PMSI_PARAM_InitSentence(sentence, 2);
        sentence->sentenceId = 0xd;
        sentence->word[0] = 0x573;
        break;
    default:
        break;
    }
}

void PMSI_PARAM_SetDefaultGreeting(struct PmsData *sentence)
{
    PMSI_PARAM_InitSentence(sentence, 0);
    sentence->sentenceId = 1;
    sentence->word[0] = 0x58F;
}

/*
 * PMSI_PARAM_ToStringWords with a count of 2: a tail call through the pool.  Seeded in
 * layout/function_starts.txt from the bl sites in ov010, ov069 and ov093
 * (w6_fix18).
 */
void *PMSI_PARAM_ToString(const struct PmsData *sentence, unsigned int heapId)
{
    return PMSI_PARAM_ToStringWords(sentence, heapId, 2);
}

/*
 * Archived graphics-slot loader: opens the bank named by the id table at
 * 0x0209F724 for the requested stream, unpacks a scratch buffer out of
 * it, and walks the sentence's word array telling the slot
 * manager what each entry is.
 *
 * A slot word of 0xffff means "empty" and is registered with the
 * fixed-size flag; otherwise bit 11 of the word says whether the value
 * carries a 0x7ff payload (registered masked) or is a plain size
 * (registered whole).  The two branches into the size-carrying
 * registration merge on one call site, so they are written as two
 * separate calls in the source and left to the compiler.
 *
 * The 0x100 buffer request is materialised as `movs r5, #2` followed by
 * `adds r5, #0xfe`: the 2 already sits in r5 from the previous call's
 * argument, and 2 + 0xfe is four bytes either way.
 */
void *PMSI_PARAM_ToStringWords(const struct PmsData *sentence, u32 heapId, int wordCount)
{
    struct WordSet *wordSet;
    void *buffer;
    void *bank;
    void *message;
    int i;

    wordSet = WORDSET_CreateDefault((u16)heapId);
    for (i = 0; i < wordCount; i++) {
        u16 word = sentence->word[i];

        if (word != 0xffff) {
            if ((word >> 11) & 1) {
                WORDSET_SetSlotMarkerFlag(wordSet, i, word & 0x7ff);
            } else {
                WORDSET_SetSlotPmsWord(wordSet, i, word);
            }
        } else {
            WORDSET_SetSlotMarkerFlag(wordSet, i, 1);
        }
    }
    bank = MSGDATA_CreateFromArchive(0, 2, Table_0209F724[sentence->sentenceType], (u16)heapId);
    buffer = STRBUF_Create(0x100, (u16)heapId);
    message = MSGDATA_AllocString(bank, sentence->sentenceId);
    WORDSET_CopyTaggedText(wordSet, buffer, message);
    STRBUF_Delete(message);
    MSGDATA_Delete(bank);
    WORDSET_Delete(wordSet);
    return buffer;
}

void *PMSI_PARAM_GetSourceString(const struct PmsData *sentence, u32 heapId)
{
    void *message;
    void *bank;
    u16 heap = (u16)heapId;

    bank = MSGDATA_CreateFromArchive(0, 2, Table_0209F724[sentence->sentenceType], heap);
    message = MSGDATA_AllocString(bank, sentence->sentenceId);
    MSGDATA_Delete(bank);

    return message;
}

int PMSI_PARAM_IsEnabled(const u16 *word)
{
    if (*word != 0xFFFF) {
        return 1;
    }
    return 0;
}

int PMSI_PARAM_IsComplete(struct PmsData *sentence, u16 heapId)
{
    u32 wordCount = PMSI_PARAM_GetWordCount(sentence->sentenceType, sentence->sentenceId, heapId);
    u32 i;

    for (i = 0; i < wordCount; i++) {
        if (sentence->word[i] == 0xffff) {
            return 0;
        }
    }
    return 1;
}

u32 PMSI_PARAM_GetWordCount(u32 sentenceType, u32 sentenceId, u16 heapId)
{
    struct MsgBank *bank = MSGDATA_CreateFromArchive(0, 2, g_0209F724[sentenceType], heapId);
    void *message = MSGDATA_AllocString(bank, sentenceId);
    u32 length;

    MSGDATA_Delete((struct Rec *)bank);
    length = PRINTSYS_CountControlTag(message);
    STRBUF_Delete((struct U16Vec *)message);

    return length;
}

u16 PMSI_PARAM_GetWordId(const struct PmsData *sentence, u32 index)
{
    u16 val = sentence->word[index];

    if (val == 0xffff) {
        return 0xffff;
    }
    return (u16)(val & (0xffff >> 5));
}

u16 PMSI_PARAM_GetWordRaw(const struct PmsData *sentence, u32 index)
{
    return sentence->word[index];
}

u32 PMSI_PARAM_IsDecoWordAt(const struct PmsData *sentence, u32 index)
{
    return PMSI_PARAM_IsDecoWord(sentence->word[index]);
}

/*
 * A sentinel-guarded bit test: 0xFFFF is treated as "unset" and reads as
 * bit 0, everything else reads back bit 11.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_IsDecoWord.c \
 *       --func PMSI_PARAM_IsDecoWord --addr 0x02024508 --cc 1.1p1 --thumb
 */
u32 PMSI_PARAM_IsDecoWord(u32 word)
{
    if (word == 0xFFFF) {
        return 0;
    }
    return ((int)word >> 11) & 1;
}

/*
 * A plain bitmask, `& 0x7FF`. Immediately followed by two unlabelled
 * one-argument halfword accessors (`ldrh r0,[r0]`/`bx lr` and
 * `ldrh r0,[r0,#2]`/`bx lr`) that carry no push prologue and so are
 * invisible to disasm.py's sweep; not reproduced here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_GetDecoId.c \
 *       --func PMSI_PARAM_GetDecoId --addr 0x02024520 --cc 1.1p1 --thumb
 */
u32 PMSI_PARAM_GetDecoId(u32 word)
{
    return word & 0x7FF;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module: returns the first halfword.
 *
 * Addresses are Black-image addresses.
 */
int PMSI_PARAM_GetSentenceType(const struct PmsData *sentence)
{
    return sentence->sentenceType;
}

/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
unsigned int PMSI_PARAM_GetSentenceId(const struct PmsData *sentence) { return sentence->sentenceId; }

int PMSI_PARAM_Compare(const struct PmsData *left, const struct PmsData *right)
{
    int i;

    if (left->sentenceType != right->sentenceType || left->sentenceId != right->sentenceId) {
        return 0;
    }

    for (i = 0; i < 2; i++) {
        if (left->word[i] != right->word[i]) {
            return 0;
        }
    }

    return 1;
}

/*
 * A plain 4-halfword struct copy.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_Copy.c \
 *       --func PMSI_PARAM_Copy --addr 0x02024570 --cc 1.1p1 --thumb
 */
void PMSI_PARAM_Copy(struct PmsData *dst, const struct PmsData *src)
{
    *dst = *src;
}

u8 PMSI_PARAM_GetSentenceCount(u32 sentenceType)
{
    if (sentenceType < 7) {
        return g_0209F71C[sentenceType];
    }
    return 0;
}

void PMSI_PARAM_SetSentenceId(struct PmsData *sentence, int sentenceType, int sentenceId)
{
    sentence->sentenceType = (unsigned short)sentenceType;
    sentence->sentenceId = (unsigned short)sentenceId;
}

void PMSI_PARAM_SetWordAt(struct PmsData *sentence, unsigned index, u16 word)
{
    if (index < 2) {
        sentence->word[index] = word;
    }
}

void PMSI_PARAM_ClearUnusedWords(struct PmsData *sentence, u16 heapId)
{
    u32 wordCount = PMSI_PARAM_GetWordCount(sentence->sentenceType, sentence->sentenceId, heapId);

    if (wordCount < 2) {
        do {
            sentence->word[wordCount] = 0xffff;
            wordCount++;
        } while (wordCount < 2);
    }
}

/*
 * pmsi_param.c's word-array validator: guards the (category, page) pair
 * against the per-category count, asks PMSI_PARAM_GetWordCount how many words the
 * page carries, and runs each word through the same two-arm check
 * PMSI_PARAM_ValidateWord performs on a single word.
 *
 * THE LEVER that closed this (it was DIFF, 132 bytes against 136, for the
 * whole of the previous wave -- see docs/notes/PMSI_PARAM_IsValid.diff.c.txt):
 * BOTH arms of the two-arm check write the `ok = 0; goto ret;` tail out,
 * and the label `setfail` sits INSIDE THE FIRST ARM'S COPY.  That is the
 * mixed case of docs/idioms/two-arms-write-the-tail-out-and-the-third-
 * branches-back-into-one.md.  The original spends a conditional AND an
 * unconditional branch at +0x64/+0x66 (`bne <loop increment>; b <setfail>`)
 * exactly because the two arms did not cross-jump; every shape that shares
 * one copy behind a single label folds them into one inverted `beq`, loses
 * four bytes and shifts every later branch target.
 *
 * Equally load-bearing: the `!= 0` arm is written FIRST
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  With the
 * `== 0` arm first the two call sites swap and 17 bytes differ.
 *
 * `sentenceId` must be a named local: the guard reads sentence->sentenceId once and the same
 * value is handed to PMSI_PARAM_GetWordCount, which is what keeps r5 live across the
 * PMSI_PARAM_GetSentenceCount call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMSI_PARAM_IsValid.c \
 *       --func PMSI_PARAM_IsValid --addr 0x020245D4 --thumb --cc 1.1p1
 */
u32 PMSI_PARAM_IsValid(struct PmsData *sentence, u32 heapId)
{
    u32 valid;
    u32 wordCount;
    u32 i;
    u32 wordIndex, wordGroup;
    u32 sentenceId;

    if (sentence->sentenceType >= 7) {
        goto fail;
    }
    sentenceId = sentence->sentenceId;
    if (sentenceId >= PMSI_PARAM_GetSentenceCount(sentence->sentenceType)) {
        goto fail;
    }

    wordCount = PMSI_PARAM_GetWordCount(sentence->sentenceType, sentenceId, (u16)((heapId & 0x7FFF) | 0x8000));
    valid = 1;
    for (i = 0; i < wordCount; i++) {
        if (PMSI_PARAM_IsDecoWord(sentence->word[i]) != 0) {
            int decoId = PMSI_PARAM_GetDecoId(sentence->word[i]);

            if (decoId >= 1 && decoId < 11) {
                continue;
            }
setfail:
            valid = 0;
            goto ret;
        } else {
            if (PMS_WORD_SplitWordId(sentence->word[i], &wordGroup, &wordIndex) != 0) {
                continue;
            }
            valid = 0;
            goto ret;
        }
    }
ret:
    return valid;
fail:
    return 0;
}

u32 PMSI_PARAM_Validate(struct PmsData *sentence, u32 allowEmpty, u32 heapId)
{
    u32 valid = 1;
    u32 wordCount;
    u32 i;

    if (sentence->sentenceType >= 7 || sentence->sentenceId >= (u32)PMSI_PARAM_GetSentenceCount(sentence->sentenceType)) {
        valid = 0;
        sentence->sentenceType = 0;
        sentence->sentenceId = 0;
    }

    wordCount = PMSI_PARAM_GetWordCount(sentence->sentenceType, sentence->sentenceId, (u16)((heapId & 0x7FFF) | 0x8000));
    if (wordCount > 2) {
        wordCount = 2;
    }
    for (i = 0; i < wordCount; i++) {
        if (PMSI_PARAM_ValidateWord(&sentence->word[0] + i, allowEmpty, 1) == 0) {
            valid = 0;
        }
    }
    return valid;
}

/*
 * pmsi_param.c's single-word validator (see docs/families/pmsi_param.h and
 * PMSI_PARAM_IsValid, which runs the same two-arm check over a word array).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 116/116, 1 byte out at +0x3E
 * for three waves, docs/notes/PMSI_PARAM_ValidateWord.diff.c.txt): the allowDeco arm writes
 * the fail tail `valid = 0; *word = 0x6A1; goto done;` out after the range test,
 * like the allowDeco == 0 arm does. The image's `blt` lands on an unconditional
 * `b bad` instead of on `bad` itself: a branch that jump threading did not
 * follow is a branch into a cross-jumped copy of a written-out tail, because
 * cross-jumping runs after threading. Falling into the shared `bad:` label
 * lets 1.1p1 thread the hop away.
 */
u32 PMSI_PARAM_ValidateWord(u16 *word, u32 allowEmpty, u32 allowDeco)
{
    u32 valid = 1;
    u32 wordIndex, wordGroup;

    if (allowEmpty != 0) {
        if (*word == 0xFFFF) {
            return valid;
        }
    } else {
        if (*word == 0xFFFF) {
            *word = 0x6A1;
            return 0;
        }
    }

    if (PMSI_PARAM_IsDecoWord(*word) != 0) {
        int decoId;

        if (allowDeco != 0) {
            decoId = PMSI_PARAM_GetDecoId(*word);
            if (decoId >= 1 && decoId < 11) {
                goto done;
            }
            valid = 0;
            *word = 0x6A1;
            goto done;
        } else {
            valid = 0;
            *word = 0x6A1;
            goto done;
        }
    } else {
        if (PMSI_PARAM_IsSpecialWord(*word) == 0) {
            if (PMS_WORD_SplitWordId(*word, &wordGroup, &wordIndex) != 0) {
                goto done;
            }
        }
    }
bad:
    valid = 0;
    *word = 0x6A1;
done:
    return valid;
}

/*
 * Clamp a counter to the range 1..10, with a mode argument that changes
 * only the zero case: called with `a == 0` and a zero field, the field is
 * reset to 1 and 0 is returned; called with `a != 0` a zero field is left
 * alone and 1 is returned outright, skipping the range check entirely.
 * Every other value goes through the same range test regardless of `a`.
 *
 * The `result` local has to be initialised before either branch reads
 * `*p` (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md): that ordering, not the declaration order, is
 * what keeps the constant 1 resident in one register across both early
 * returns and the range check's shared exit, instead of each arm
 * rematerialising its own `movs r0, #k; bx lr`. The two early returns
 * (the `a != 0` zero case and the `a == 0` zero case) are written as
 * direct `return` statements and stay as separate tails; only the range
 * check's in-range case and the clamp's fallthrough share one exit block,
 * reached by a `goto` from the first and by falling into it from the
 * second, exactly as the original's single `blt` past the clamp and the
 * clamp's own fallthrough both land on one `adds r0, r2, #0; bx lr`.
 *
 * This is wordset.c's normaliser: src/pending/WORDSET_SetSlotMarkerFlag.c calls it and
 * is promoted alongside this file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_ValidateDecoValue.c \
 *       --func PMSI_PARAM_ValidateDecoValue --addr 0x0202473C --cc 1.1p1 --thumb
 */
u32 PMSI_PARAM_ValidateDecoValue(u32 *decoId, u32 allowZero)
{
    u32 result = 1;
    int value;

    if (allowZero != 0) {
        value = (int)*decoId;
        if (value != 0) {
            goto range;
        }
        return result;
    }
    value = (int)*decoId;
    if (value != 0) {
        goto range;
    }
    *decoId = result;
    return 0;

range:
    if (value < 1) {
        goto clamp;
    }
    if (value < 0xb) {
        goto end;
    }

clamp:
    *decoId = 1;
    result = 0;

end:
    return result;
}

/*
 * Blocked: data_0209F734 (a 12-halfword table) is named by exactly one pool word,
 * 0x020247A4, and that word is inside this function's own range once the
 * body compiles to its full 64 bytes; the `literal` class discards it. Every
 * concrete byte reproduces.
 */
int PMSI_PARAM_IsSpecialWord(u32 word)
{
    struct SpecialWordTable table;
    u8 i;

    table = data_0209F734;
    for (i = 0; i < 12; i++) {
        if (word == table.words[i]) {
            return 1;
        }
    }
    return 0;
}
