/*
 * file:     pms_input_data.c
 * unit:     yes
 * function: PMS_INPUT_DATA_Create, PMS_INPUT_DATA_Delete, PMS_INPUT_DATA_BuildCategoryWords, PMS_INPUT_DATA_CollectSeenWords, PMS_INPUT_DATA_CollectEventWords, PMS_INPUT_DATA_CollectUnlockedWords, PMS_INPUT_DATA_CollectOptionWords, PMS_INPUT_DATA_CollectRangeWords, PMS_INPUT_DATA_BuildInitialWords, PMS_INPUT_DATA_FilterInitialWords, PMS_INPUT_DATA_GetCategoryWordCount, PMS_INPUT_DATA_GetCategoryWordString, PMS_INPUT_DATA_GetCategoryWordId, PMS_INPUT_DATA_FilterWordList, PMS_INPUT_DATA_SkipRangeEntry, PMS_INPUT_DATA_GetInitialWordId, PMS_INPUT_DATA_GetWordString, PMS_INPUT_DATA_GetInvalidWordId
 * address:  0x021B95A0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Easy-chat word lists for the input screen: per-category and per-initial
 * word tables, filtered by what the player has unlocked, plus a bitmap of
 * the words that appear in the filtered lists.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   PMS_WORD_Create 0x020247A8 thumb
 *   d_021C3B80 0x021C3B80 data a1
 *   PMS_WORD_Delete 0x020247F0 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_021C1E80 0x021C1E80 data a4
 *   PMSI_PARAM_GetSaveWork 0x02024148 thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   PMSI_PARAM_GetEventFlag 0x02024150 thumb
 *   PMSI_PARAM_GetWordSave 0x0202414C thumb
 *   PMS_WORD_MakeWordId 0x02024888 thumb
 *   PMS_WORD_CheckFlag 0x02024994 thumb
 *   PMSI_PARAM_GetOptionFlag 0x02024160 thumb
 *   d_021C1C88 0x021C1C88 data ov110 a4
 *   PMS_WORD_GetString 0x02024810 thumb
 *   PMS_INPUT_DATA_GetCategoryWordCount 0x021B999C thumb ov110
 *   PMS_INPUT_DATA_Create 0x021B95A0 thumb ov110
 *   PMS_INPUT_DATA_Delete 0x021B95F4 thumb ov110
 *   PMS_INPUT_DATA_GetCategoryWordId 0x021B99C4 thumb ov110
 *   PMS_INPUT_DATA_GetCategoryWordString 0x021B99A4 thumb ov110
 */
#include "pms_input_data_shared_types.h"

struct PokedexSave;

typedef struct {
    int (*collect)(struct PmsInputData *, const u16 *, unsigned int, u16 *);
    const u16 *wordIds;
    unsigned int wordCount;
} CategorySource;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/pms_word.h"
struct PmsiParam;
#include "../arm9/pmsi_param.h"
struct ZukanSave;
#include "../arm9/zukan_save.h"

extern const char d_021C3B80[];
extern const CategorySource d_021C1E80[];
extern u16 *const d_021C1C88[];

#define SEEN_MARK(d, id) ((d)->seenBits[(id) >> 3] |= (u8)(1 << ((id) & 7)))
#define SEEN_TEST(d, id) ((d)->seenBits[(id) >> 3] & (1 << ((id) & 7)))

struct PmsInputData *PMS_INPUT_DATA_Create(u32 heap, void *save);
void PMS_INPUT_DATA_Delete(struct PmsInputData *d);
void PMS_INPUT_DATA_BuildCategoryWords(struct PmsInputData *d);
u32 PMS_INPUT_DATA_CollectSeenWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 PMS_INPUT_DATA_CollectEventWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 PMS_INPUT_DATA_CollectUnlockedWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 PMS_INPUT_DATA_CollectOptionWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 PMS_INPUT_DATA_CollectRangeWords(struct PmsInputData *d, const u16 *src, u32 count, u16 *out);
void PMS_INPUT_DATA_BuildInitialWords(struct PmsInputData *d);
u32 PMS_INPUT_DATA_FilterInitialWords(struct PmsInputData *d, const u16 *src, u16 *out, u32 outIndex);
u32 PMS_INPUT_DATA_GetCategoryWordCount(struct PmsInputData *d, int category);
void PMS_INPUT_DATA_GetCategoryWordString(struct PmsInputData *d, unsigned int category, unsigned int index, void *mode);
unsigned short PMS_INPUT_DATA_GetCategoryWordId(struct PmsInputData *d, unsigned int category, unsigned int index);
u32 PMS_INPUT_DATA_FilterWordList(struct PmsInputData *a, u16 *b, u16 *c);
const u16 *PMS_INPUT_DATA_SkipRangeEntry(const u16 *rangeEntry);
u16 PMS_INPUT_DATA_GetInitialWordId(struct PmsInputData *unused, int initial, int index);
void PMS_INPUT_DATA_GetWordString(struct PmsInputData *d, u16 wordId, void *mode);
int PMS_INPUT_DATA_GetInvalidWordId(struct PmsInputData *unused);

struct PmsInputData *PMS_INPUT_DATA_Create(u32 heap, void *save)
{
    struct PmsInputData *d;
    int i;
    d = GFL_HEAP_Alloc((u16)heap, sizeof(*d), 0, d_021C3B80, 88);
    d->saveData = save;
    d->wordSys = PMS_WORD_Create(heap);
    for (i = 0; i < PMS_INPUT_DATA_SEEN_BYTES; i++) d->seenBits[i] = 0;
    PMS_INPUT_DATA_BuildCategoryWords(d);
    PMS_INPUT_DATA_BuildInitialWords(d);
    return d;
}

void PMS_INPUT_DATA_Delete(struct PmsInputData *d)
{
    if (d) {
        PMS_WORD_Delete(d->wordSys);
        GFL_HEAP_Free(d);
    }
}

void PMS_INPUT_DATA_BuildCategoryWords(struct PmsInputData *d)
{
    int i;
    int n;
    i = 0;
    n = 0;
    for (; i < PMS_INPUT_DATA_CATEGORY_COUNT; i++) {
        d->categoryStart[i] = n;
        d->categoryCount[i] = d_021C1E80[i].collect(d, d_021C1E80[i].wordIds, d_021C1E80[i].wordCount, d->categoryWords + n);
        n += d->categoryCount[i];
    }
}

u32 PMS_INPUT_DATA_CollectSeenWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out)
{
    void *save;
    u32 n;
    u32 i;
    save = PMSI_PARAM_GetSaveWork(d->saveData);
    n = 0;
    for (i = 0; i < count; i++) {
        if (ZUKAN_SAVE_IsSeen(save, ids[i])) {
            u32 id = ids[i];
            SEEN_MARK(d, id);
            *out++ = id;
            n++;
        }
    }
    return n;
}

u32 PMS_INPUT_DATA_CollectEventWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out)
{
    u32 i;
    if (PMSI_PARAM_GetEventFlag(d->saveData)) {
        for (i = 0; i < count; i++) {
            u32 id = *ids;
            SEEN_MARK(d, id);
            ids++;
            *out++ = id;
        }
        return count;
    }
    return 0;
}

/*
 * Locals declared o, limit, count, base, i; `base = ...; count = 0; limit = ...`
 * in that order fixes the zero register and the stack slots.
 */
u32 PMS_INPUT_DATA_CollectUnlockedWords(struct PmsInputData *d, const u16 *ids, u32 n, u16 *out)
{
    void *wordSave;
    u32 limit;
    u32 count;
    u32 base;
    u32 i;
    wordSave = PMSI_PARAM_GetWordSave(d->saveData);
    base = PMS_WORD_MakeWordId(0x97, 0);
    count = 0;
    limit = (u16)(base + 7);
    for (i = 0; i < n; i++) {
        u32 v = ids[i];
        if (v >= base && v <= limit) {
            if (PMS_WORD_CheckFlag(wordSave, v - base) == 0)
                continue;
        }
        v = ids[i];
        SEEN_MARK(d, v);
        *out = v;
        out++;
        count++;
    }
    return count;
}

u32 PMS_INPUT_DATA_CollectOptionWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out)
{
    u32 i;
    u32 n;
    if (!PMSI_PARAM_GetOptionFlag(d->saveData)) return 0;
    i = 0;
    n = 0;
    for (; i < count; i++) {
        u32 id = ids[i];
        SEEN_MARK(d, id);
        *out++ = i + 0x801;
        n++;
    }
    return n;
}

u32 PMS_INPUT_DATA_CollectRangeWords(struct PmsInputData *d, const u16 *src, u32 count, u16 *out)
{
    u32 i;
    for (i = 0; i < count; i++) {
        u32 c = *src;
        if (c == 0xFFFE) {
            u32 len;
            src++;
            len = *src++;
            while (len != 0) {
                u32 v = *src++;
                SEEN_MARK(d, v);
                len--;
            }
            *out = src[-1];
        } else {
            SEEN_MARK(d, c);
            src++;
            *out = c;
        }
        out++;
    }
    return count;
}

void PMS_INPUT_DATA_BuildInitialWords(struct PmsInputData *d)
{
    u32 i;
    u32 offset = 0;
    for (i = 0; i < PMS_INPUT_DATA_INITIAL_COUNT; ++i) {
        u16 *src = d_021C1C88[i];
        d->initialStart[i] = offset;
        d->initialCount[i] = PMS_INPUT_DATA_FilterInitialWords(d, src, d->initialWords, offset);
        offset += d->initialCount[i];
    }
}

u32 PMS_INPUT_DATA_FilterInitialWords(struct PmsInputData *d, const u16 *src, u16 *out, u32 outIndex)
{
    u32 count = 0;
    u32 c = *src;
    while (c != 0xFFFF) {
        if (c == 0xFFFE) {
            u32 len;
            u32 i;
            src++;
            len = *src++;
            for (i = 0; i < len; i++) {
                u32 v = src[i];
                if (SEEN_TEST(d, v)) {
                    out[outIndex++] = v;
                    count++;
                    break;
                }
            }
            src += len;
        } else {
            if (SEEN_TEST(d, c)) {
                out[outIndex++] = c;
                count++;
            }
            src++;
        }
        c = *src;
    }
    return count;
}

u32 PMS_INPUT_DATA_GetCategoryWordCount(struct PmsInputData *d, int category)
{
    return d->categoryCount[category];
}

/* Two-byte zero alignment padding follows the compiled function. */
void PMS_INPUT_DATA_GetCategoryWordString(struct PmsInputData *d, unsigned int category, unsigned int index, void *mode)
{
    unsigned int start;
    start = d->categoryStart[category];
    PMS_WORD_GetString(d->wordSys, d->categoryWords[start + index], mode);
}

unsigned short PMS_INPUT_DATA_GetCategoryWordId(struct PmsInputData *d, unsigned int category, unsigned int index)
{
    unsigned int start;
    start = d->categoryStart[category];
    return d->categoryWords[start + index];
}

u32 PMS_INPUT_DATA_FilterWordList(struct PmsInputData *a, u16 *b, u16 *c)
{
    return PMS_INPUT_DATA_FilterInitialWords(a, b, c, 0);
}

/* A 0xFFFE entry is {marker, length, id * length}: returns the last id. */
const u16 *PMS_INPUT_DATA_SkipRangeEntry(const u16 *rangeEntry)
{
    return rangeEntry + 2 + (rangeEntry[1] - 1);
}

u16 PMS_INPUT_DATA_GetInitialWordId(struct PmsInputData *unused, int initial, int index)
{
    const u16 *p = d_021C1C88[initial];
    int n = 0;
    while (*p != 65535) {
        if (n == index) {
            if (*p == 65534) p = PMS_INPUT_DATA_SkipRangeEntry(p);
            return *p;
        }
        if (*p == 65534) {
            p = PMS_INPUT_DATA_SkipRangeEntry(p);
            p += 1;
        } else {
            p += 1;
        }
        ++n;
    }
    return 0;
}

void PMS_INPUT_DATA_GetWordString(struct PmsInputData *d, u16 wordId, void *mode)
{
    PMS_WORD_GetString(d->wordSys, wordId, mode);
}

int PMS_INPUT_DATA_GetInvalidWordId(struct PmsInputData *unused)
{
    return 0xffff;
}
