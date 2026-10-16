/*
 * file:     msgsearch.c
 * unit:     yes
 * function: MSGSEARCH_Create, MSGSEARCH_Delete, MSGSEARCH_Search, MSGSEARCH_PrefixMatches
 * address:  0x021B6C74
 * region:   ov067
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   d_021B9558     0x021B9558  data  a1
 *   ENV_SetResourceSet  0x020307B0  arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   func_02082A7C 0x02082A7C arm
 *   MSGDATA_GetMessageCount 0x02045F50 arm
 *   func_02045CAC 0x02045CAC arm
 *   STRBUF_GetChars  0x02045A90  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#include "msgsearch_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern struct StrBuf *STRBUF_Create(u32 capacity, u16 heapId);
extern void STRBUF_Delete(struct StrBuf *str);
extern void ENV_SetResourceSet(void *p);
extern u16 STRBUF_GetLength(struct StrBuf *str);
extern void func_02082A7C(u32 value, void *dest, u32 size);
extern u16 MSGDATA_GetMessageCount(const struct MsgBank *bank);
extern void func_02045CAC(struct MsgBank *bank, u32 index, struct StrBuf *dest);
extern u16 *STRBUF_GetChars(struct StrBuf *str);
MsgSearch *MSGSEARCH_Create(struct MsgBank **banks, u32 bankCount, u16 heapId);
void MSGSEARCH_Delete(MsgSearch *search);
u32 MSGSEARCH_Search(MsgSearch *search, u32 bankIndex, u32 unused, struct StrBuf *prefix, MsgSearchHit *hits, u32 maxHits);
int MSGSEARCH_PrefixMatches(struct StrBuf *prefix, struct StrBuf *text, u32 length);
extern const char d_021B9558[];


MsgSearch *MSGSEARCH_Create(struct MsgBank **banks, u32 bankCount, u16 heapId)
{
    u32 size;
    MsgSearch *search;
    u32 i;

    size = bankCount * sizeof(struct MsgBank *) + MSGSEARCH_HEADER_SIZE;
    search = GFL_HEAP_Alloc(heapId, size, 0, d_021B9558, 0x40);
    i = 0;
    MI_CpuFill8(search, 0, size);
    search->bankCount = bankCount;
    for (i = 0; i < bankCount; i++) {
        search->bank[i] = banks[i];
    }
    search->scratch = STRBUF_Create(0x80, heapId);
    return search;
}


void MSGSEARCH_Delete(MsgSearch *search)
{
    STRBUF_Delete(search->scratch);
    ENV_SetResourceSet(search);
}


/*
 * Finds the messages of one bank that start with prefix. Fills hits with up to
 * maxHits matches (unused entries are set to -1) and returns how many
 * messages matched in all. Messages are compared with MSGSEARCH_PrefixMatches.
 */
u32 MSGSEARCH_Search(MsgSearch *search, u32 bankIndex, u32 unused, struct StrBuf *prefix, MsgSearchHit *hits, u32 maxHits)
{
    u32 matchCount;
    u32 messageCount;
    struct MsgBank *bank;
    u32 messageIndex, hitCount, prefixLength;

    matchCount = 0;
    prefixLength = STRBUF_GetLength(prefix);
    func_02082A7C(-1, hits, maxHits * sizeof(MsgSearchHit));
    if (prefixLength) {
        messageCount = MSGDATA_GetMessageCount(search->bank[bankIndex]);
        bank = search->bank[bankIndex];
        messageIndex = 0;
        hitCount = 0;
        for (;; messageIndex++) {
            if (messageIndex >= messageCount) break;
            if (hitCount >= maxHits) break;
            func_02045CAC(bank, messageIndex, search->scratch);
            if (MSGSEARCH_PrefixMatches(prefix, search->scratch, STRBUF_GetLength(prefix))) {
                if (hitCount < maxHits) {
                    hits[hitCount].bankIndex = bankIndex;
                    hits[hitCount].messageIndex = messageIndex;
                    hitCount++;
                }
                matchCount++;
            }
        }
    }
    return matchCount;
}


/* Returns 1 when both strings are at least length characters long and their first length characters are equal. */
int MSGSEARCH_PrefixMatches(struct StrBuf *prefix, struct StrBuf *text, u32 length)
{
    u16 *prefixChars;
    u16 *textChars;
    u32 i;

    if (STRBUF_GetLength(prefix) < length) {
        return 0;
    }
    if (STRBUF_GetLength(text) < length) {
        return 0;
    }
    prefixChars = STRBUF_GetChars(prefix);
    textChars = STRBUF_GetChars(text);
    for (i = 0; i < length; i++) {
        if (*prefixChars++ != *textChars++) {
            return 0;
        }
    }
    return 1;
}
