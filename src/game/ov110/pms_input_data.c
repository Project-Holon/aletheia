/*
 * file:     pms_input_data.c
 * unit:     yes
 * function: func_021B95A0, func_021B95F4, func_021B9608, func_021B9654, func_021B96C0, func_021B9720, func_021B97AC, func_021B9814, func_021B98A0, func_021B98F8, func_021B999C, func_021B99A4, func_021B99C4, func_021B99D8, func_021B99E4, func_021B99F0, func_021B9A3C, func_021B9A48
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
 *   func_02030734 0x02030734 arm
 *   PMS_WORD_Create 0x020247A8 thumb
 *   d_021C3B80 0x021C3B80 data a1
 *   PMS_WORD_Delete 0x020247F0 thumb
 *   func_020307B0 0x020307B0 arm
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
 *   func_021B999C 0x021B999C thumb ov110
 *   func_021B95A0 0x021B95A0 thumb ov110
 *   func_021B95F4 0x021B95F4 thumb ov110
 *   func_021B99C4 0x021B99C4 thumb ov110
 *   func_021B99A4 0x021B99A4 thumb ov110
 */
#include "pms_input_data_shared_types.h"

struct PokedexSave;

typedef struct {
    int (*collect)(struct PmsInputData *, const u16 *, unsigned int, u16 *);
    const u16 *wordIds;
    unsigned int wordCount;
} CategorySource;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct PmsWordSys *PMS_WORD_Create(u32 heapId);
extern void PMS_WORD_Delete(struct PmsWordSys *);
extern u32 func_020307B0(void *p);
extern void *PMSI_PARAM_GetSaveWork(void *p);
extern u32 ZUKAN_SAVE_IsSeen(struct PokedexSave *p, u16 id);
extern int PMSI_PARAM_GetEventFlag(void *);
extern void *PMSI_PARAM_GetWordSave(void *p);
extern u16 PMS_WORD_MakeWordId(u32 idx, u16 add);
extern int PMS_WORD_CheckFlag(const u32 *p, u32 idx);
extern int PMSI_PARAM_GetOptionFlag(void *);
extern void PMS_WORD_GetString(struct PmsWordSys *, int, int);

extern const char d_021C3B80[];
extern const CategorySource d_021C1E80[];
extern u16 *const d_021C1C88[];

#define SEEN_MARK(d, id) ((d)->seenBits[(id) >> 3] |= (u8)(1 << ((id) & 7)))
#define SEEN_TEST(d, id) ((d)->seenBits[(id) >> 3] & (1 << ((id) & 7)))

struct PmsInputData *func_021B95A0(u32 heap, void *save);
void func_021B95F4(struct PmsInputData *d);
void func_021B9608(struct PmsInputData *d);
u32 func_021B9654(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 func_021B96C0(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 func_021B9720(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 func_021B97AC(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 func_021B9814(struct PmsInputData *d, const u16 *src, u32 count, u16 *out);
void func_021B98A0(struct PmsInputData *d);
u32 func_021B98F8(struct PmsInputData *d, const u16 *src, u16 *out, u32 outIndex);
u32 func_021B999C(struct PmsInputData *d, int category);
void func_021B99A4(struct PmsInputData *d, unsigned int category, unsigned int index, int mode);
unsigned short func_021B99C4(struct PmsInputData *d, unsigned int category, unsigned int index);
u32 func_021B99D8(u32 a, u32 b, u32 c);
const u16 *func_021B99E4(const u16 *rangeEntry);
u16 func_021B99F0(int unused, int initial, int index);
void func_021B9A3C(struct PmsInputData *d, u16 wordId, int mode);
int func_021B9A48(u32 unused);

struct PmsInputData *func_021B95A0(u32 heap, void *save)
{
    struct PmsInputData *d;
    int i;
    d = func_02030734((u16)heap, 0x1E50, 0, d_021C3B80, 88);
    d->saveData = save;
    d->wordSys = PMS_WORD_Create(heap);
    for (i = 0; i < PMS_INPUT_DATA_SEEN_BYTES; i++) d->seenBits[i] = 0;
    func_021B9608(d);
    func_021B98A0(d);
    return d;
}

void func_021B95F4(struct PmsInputData *d)
{
    if (d) {
        PMS_WORD_Delete(d->wordSys);
        func_020307B0(d);
    }
}

void func_021B9608(struct PmsInputData *d)
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

u32 func_021B9654(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out)
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

u32 func_021B96C0(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out)
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
u32 func_021B9720(struct PmsInputData *d, const u16 *ids, u32 n, u16 *out)
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

u32 func_021B97AC(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out)
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

u32 func_021B9814(struct PmsInputData *d, const u16 *src, u32 count, u16 *out)
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

void func_021B98A0(struct PmsInputData *d)
{
    u32 a = 0xF58;
    u32 b;
    u32 c;
    u32 i;
    u32 offset = 0;
    u8 *p = (u8 *)d;
    a -= 0x6C;
    b = 0xF58;
    b -= 0xD8;
    c = 0xF58;
    c -= 0xD8;
    for (i = 0; i < PMS_INPUT_DATA_INITIAL_COUNT; ++i) {
        u16 *src = d_021C1C88[i];
        *(u32 *)(p + i * 4 + a) = offset;
        *(u32 *)(p + i * 4 + b) = func_021B98F8(d, src, (u16 *)(p + 0xF58), offset);
        offset += *(u32 *)(p + i * 4 + c);
    }
}

u32 func_021B98F8(struct PmsInputData *d, const u16 *src, u16 *out, u32 outIndex)
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

u32 func_021B999C(struct PmsInputData *d, int category)
{
    return d->categoryCount[category];
}

/* Two-byte zero alignment padding follows the compiled function. */
void func_021B99A4(struct PmsInputData *d, unsigned int category, unsigned int index, int mode)
{
    unsigned int start;
    start = d->categoryStart[category];
    PMS_WORD_GetString(d->wordSys, d->categoryWords[start + index], mode);
}

unsigned short func_021B99C4(struct PmsInputData *d, unsigned int category, unsigned int index)
{
    unsigned int start;
    start = d->categoryStart[category];
    return d->categoryWords[start + index];
}

u32 func_021B99D8(u32 a, u32 b, u32 c)
{
    return func_021B98F8((struct PmsInputData *)a, (u16 *)b, (u16 *)c, 0);
}

/* A 0xFFFE entry is {marker, length, id * length}: returns the last id. */
const u16 *func_021B99E4(const u16 *rangeEntry)
{
    return rangeEntry + 2 + (rangeEntry[1] - 1);
}

u16 func_021B99F0(int unused, int initial, int index)
{
    const u16 *p = d_021C1C88[initial];
    int n = 0;
    while (*p != 65535) {
        if (n == index) {
            if (*p == 65534) p = func_021B99E4(p);
            return *p;
        }
        if (*p == 65534) {
            p = func_021B99E4(p);
            p += 1;
        } else {
            p += 1;
        }
        ++n;
    }
    return 0;
}

void func_021B9A3C(struct PmsInputData *d, u16 wordId, int mode)
{
    PMS_WORD_GetString(d->wordSys, wordId, mode);
}

int func_021B9A48(u32 unused)
{
    return 0xffff;
}
