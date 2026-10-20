/*
 * file:     pmsi_search.c
 * unit:     yes
 * function: PMSI_SEARCH_Create, PMSI_SEARCH_Delete, PMSI_SEARCH_PushKey, PMSI_SEARCH_PopKey, PMSI_SEARCH_GetInputCount, PMSI_SEARCH_ClearInput, PMSI_SEARCH_BuildInputText, PMSI_SEARCH_Run, PMSI_SEARCH_HasResults, PMSI_SEARCH_GetResultString, PMSI_SEARCH_GetResultWordId, PMSI_SEARCH_GetKeyCount, PMSI_SEARCH_GetKeyLabel, PMSI_SEARCH_GetKeyChar, PMSI_SEARCH_GetKeyPosition, PMSI_SEARCH_GetKeyUp, PMSI_SEARCH_GetKeyDown, PMSI_SEARCH_GetKeyLeft, PMSI_SEARCH_GetKeyRight, PMSI_SEARCH_GetKeyKind
 * address:  0x021BAEDC
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Kana search for the easy-chat input screen: typed letters are looked up in
 * the 27 per-initial message banks and the matches are mapped to word ids.
 * The last initial (26) lists every word that is not one of the 10 excluded
 * characters in the table at sPmsiSearchExcludedChars.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   MSGSEARCH_Create 0x021B6C74 thumb ov067
 *   STRBUF_Create 0x020457B0 arm
 *   sPmsiSearchAllocSite 0x021C3C34 data ov110 a1
 *   sPmsiSearchBankFileIds 0x021C3770 data a2
 *   MSGSEARCH_Delete 0x021B6CCC thumb ov067
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_SetString 0x02045924 arm
 *   MSGSEARCH_Search 0x021B6CE0 thumb ov067
 *   STRBUF_Clear 0x0204581C arm
 *   MSGDATA_GetMessageCount 0x02045F50 arm
 *   sPmsiSearchExcludedChars 0x021C375C data a2
 *   STRBUF_SetStringN 0x02045994 arm
 *   sPmsiKanaKeys 0x021C37A8 data a2
 *   d_021C37AA 0x021C37AA data a1
 *   d_021C37AC 0x021C37AC data a1
 *   d_021C37AD 0x021C37AD data a1
 *   d_021C37AE 0x021C37AE data a1
 *   d_021C37AF 0x021C37AF data a1
 *   d_021C37B1 0x021C37B1 data a1
 *   PMSI_SEARCH_GetKeyCount 0x021BB1F4 thumb ov110
 *   PMSI_SEARCH_GetKeyLabel 0x021BB1F8 thumb ov110
 *   PMSI_SEARCH_GetKeyPosition 0x021BB224 thumb ov110
 *   PMSI_SEARCH_Create 0x021BAEDC thumb ov110
 *   PMSI_SEARCH_Delete 0x021BAF4C thumb ov110
 *   PMSI_SEARCH_Run 0x021BB054 thumb ov110
 *   PMSI_SEARCH_PopKey 0x021BAFAC thumb ov110
 *   PMSI_SEARCH_PushKey 0x021BAF7C thumb ov110
 *   PMSI_SEARCH_GetKeyUp 0x021BB240 thumb ov110
 *   PMSI_SEARCH_GetKeyDown 0x021BB250 thumb ov110
 *   PMSI_SEARCH_GetKeyLeft 0x021BB260 thumb ov110
 *   PMSI_SEARCH_GetKeyRight 0x021BB270 thumb ov110
 *   PMSI_SEARCH_GetKeyKind 0x021BB280 thumb ov110
 *   PMSI_SEARCH_GetResultWordId 0x021BB1E4 thumb ov110
 *   PMSI_SEARCH_HasResults 0x021BB1C0 thumb ov110
 *   PMSI_SEARCH_GetResultString 0x021BB1CC thumb ov110
 *   PMSI_SEARCH_BuildInputText  0x021BB00C  thumb  ov110
 *   PMSI_SEARCH_ClearInput 0x021BAFE4 thumb ov110
 *   PMSI_SEARCH_GetInputCount  0x021BAFDC  thumb  ov110
 *   PMS_INPUT_DATA_FilterWordList 0x021B99D8 thumb ov110
 *   PMS_INPUT_DATA_GetInitialWordId 0x021B99F0 thumb ov110
 *   PMS_INPUT_DATA_GetWordString 0x021B9A3C thumb ov110
 *   PMS_INPUT_DATA_GetInvalidWordId 0x021B9A48 thumb ov110
 */
#include "pms_input_data_shared_types.h"
#include "pms_input_view_shared_types.h"
#include "pmsi_search_shared_types.h"
#include "../types.h"
#include "../ov067/msgsearch_types.h"
extern void *__builtin__clear(void *dest, unsigned long size);

#define PMSI_SEARCH_INITIAL_COUNT 27
#define PMSI_SEARCH_OTHER_INITIAL 26
#define PMSI_SEARCH_INPUT_MAX 13
#define PMSI_SEARCH_KEY_NONE 255
#define PMSI_SEARCH_RESULT_MAX 264

struct PmsInputData;

struct PmsiSearch {
    void *owner;
    struct PmsInputData *wordData;
    u16 heapId;
    struct MsgBank *messageBanks[PMSI_SEARCH_INITIAL_COUNT];
    MsgSearch *messageSearch;
    struct {
        u32 initial;
        u32 wordIndex;
    } results[PMSI_SEARCH_RESULT_MAX];
    u16 wordIds[266];
    struct U16Vec *inputText;
    u16 inputKeys[PMSI_SEARCH_INPUT_MAX];
    u16 reserved;
    u8 inputCount;
    u8 hasResults;
};

struct KanaKey {
    u16 character;
    u8 column;
    u8 row;
    u8 up;
    u8 down;
    u8 left;
    u8 right;
    u8 pad;
    u8 kind;
};

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/msgdata.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../ov067/msgsearch.h"

#include "pms_input_data.h"

extern const char sPmsiSearchAllocSite[];
extern const u16 sPmsiSearchBankFileIds[];
extern const u16 sPmsiSearchExcludedChars[10];
extern const struct KanaKey sPmsiKanaKeys[];

struct PmsiSearch *PMSI_SEARCH_Create(void *owner, struct PmsInputData *wordData, u16 heap);
void PMSI_SEARCH_Delete(struct PmsiSearch *s);
void PMSI_SEARCH_PushKey(struct PmsiSearch *s, int key);
int PMSI_SEARCH_PopKey(struct PmsiSearch *s);
u8 PMSI_SEARCH_GetInputCount(struct PmsiSearch *s);
void PMSI_SEARCH_ClearInput(struct PmsiSearch *s);
void PMSI_SEARCH_BuildInputText(struct PmsiSearch *s, struct U16Vec *out);
int PMSI_SEARCH_Run(struct PmsiSearch *s);
u8 PMSI_SEARCH_HasResults(struct PmsiSearch *s);
void PMSI_SEARCH_GetResultString(struct PmsiSearch *s, u8 resultIndex, int dest);
u16 PMSI_SEARCH_GetResultWordId(struct PmsiSearch *s, u32 resultIndex);
int PMSI_SEARCH_GetKeyCount(void);
void PMSI_SEARCH_GetKeyLabel(u32 i, struct U16Vec *dst);
u16 PMSI_SEARCH_GetKeyChar(u32 i);
void PMSI_SEARCH_GetKeyPosition(u32 i, int *column, int *row);
u8 PMSI_SEARCH_GetKeyUp(u32 i);
u8 PMSI_SEARCH_GetKeyDown(u32 i);
u8 PMSI_SEARCH_GetKeyLeft(u32 i);
int PMSI_SEARCH_GetKeyRight(int i);
u8 PMSI_SEARCH_GetKeyKind(u32 i);

struct PmsiSearch *PMSI_SEARCH_Create(void *owner, struct PmsInputData *wordData, u16 heap)
{
    int i;
    struct PmsiSearch *s;
    s = GFL_HEAP_Alloc(heap, 0xaf4, 1, sPmsiSearchAllocSite, 137);
    s->owner = owner;
    s->wordData = wordData;
    s->heapId = heap;
    PMSI_SEARCH_ClearInput(s);
    for (i = 0; i < PMSI_SEARCH_INITIAL_COUNT; i++) s->messageBanks[i] = MSGDATA_CreateFromArchive(1, 2, sPmsiSearchBankFileIds[i], heap);
    s->messageSearch = MSGSEARCH_Create(s->messageBanks, PMSI_SEARCH_INITIAL_COUNT, s->heapId);
    s->inputText = (struct U16Vec *)STRBUF_Create(27, heap);
    return s;
}

void PMSI_SEARCH_Delete(struct PmsiSearch *s)
{
    int i;
    STRBUF_Delete((struct Strbuf *)s->inputText);
    MSGSEARCH_Delete(s->messageSearch);
    for (i = 0; i < PMSI_SEARCH_INITIAL_COUNT; i++) MSGDATA_Delete(s->messageBanks[i]);
    GFL_HEAP_Free(s);
}

void PMSI_SEARCH_PushKey(struct PmsiSearch *s, int key)
{
    int n;
    s->inputKeys[s->inputCount] = key;
    n = s->inputCount + 1;
    if (n > 12) n = 12;
    else if (n < 0) n = 0;
    s->inputCount = n;
}

int PMSI_SEARCH_PopKey(struct PmsiSearch *s)
{
    if (s->inputCount == 0) return 0;
    if (s->inputKeys[12] == PMSI_SEARCH_KEY_NONE) --s->inputCount;
    s->inputKeys[s->inputCount] = PMSI_SEARCH_KEY_NONE;
    return 1;
}

u8 PMSI_SEARCH_GetInputCount(struct PmsiSearch *s)
{
    return s->inputCount;
}

void PMSI_SEARCH_ClearInput(struct PmsiSearch *s)
{
    int i;
    for (i = 0; i < PMSI_SEARCH_INPUT_MAX; i++) s->inputKeys[i] = PMSI_SEARCH_KEY_NONE;
    s->inputCount = 0;
    s->hasResults = 0;
}

/*
 * lever: struct member keeps the far offset in-loop; array store uses i++.
 */
void PMSI_SEARCH_BuildInputText(struct PmsiSearch *s, struct U16Vec *out)
{
    u16 text[14];
    int i;
    for (i = 0; i < PMSI_SEARCH_INPUT_MAX;) {
        u16 key;
        key = s->inputKeys[i];
        if (key == PMSI_SEARCH_KEY_NONE) { text[i] = STRBUF_GetEosChar(); break; }
        text[i++] = PMSI_SEARCH_GetKeyChar(key);
    }
    text[13] = STRBUF_GetEosChar();
    STRBUF_SetString((struct Strbuf *)out, text);
}

/*
 * evidence: ov110 loads ov067 at 021C0134; 021BAEDC creates messageSearch via ov067 021B6C74.
 * lever: id/k clear order and value-before-j declaration; pooled table has alignment-only hint.
 */
int PMSI_SEARCH_Run(struct PmsiSearch *s)
{
    u16 specialWords[265];
    u16 normalWords[265];
    u32 matchCount, initialId;
    unsigned i, specialCount, isExcluded;
    u32 wordValue;
    unsigned j;
    initialId = s->inputKeys[0];
    if (initialId >= PMSI_SEARCH_INITIAL_COUNT) {
        s->hasResults = 0;
        return 0;
    }
    STRBUF_Clear((struct Strbuf *)s->inputText);
    PMSI_SEARCH_BuildInputText(s, s->inputText);
    if (initialId == PMSI_SEARCH_OTHER_INITIAL) {
        matchCount = MSGDATA_GetMessageCount(s->messageBanks[initialId]);
        specialCount = 0;
        __builtin__clear(specialWords, sizeof(specialWords));
        for (i = 0; i < matchCount; i++) {
            wordValue = PMS_INPUT_DATA_GetInitialWordId(s->wordData, initialId, i);
            isExcluded = 0;
            for (j = 0; j < 10; j++) {
                if (wordValue == sPmsiSearchExcludedChars[j]) { isExcluded = 1; break; }
            }
            if (!isExcluded) {
                s->results[specialCount].initial = initialId;
                s->results[specialCount].wordIndex = i;
                specialWords[specialCount] = wordValue;
                specialCount++;
            }
        }
        specialWords[specialCount] = PMS_INPUT_DATA_GetInvalidWordId(s->wordData);
        s->hasResults = PMS_INPUT_DATA_FilterWordList((uptr)s->wordData, (uptr)specialWords, (uptr)s->wordIds);
        if (s->hasResults) return 1;
        return 0;
    } else {
        __builtin__clear(normalWords, sizeof(normalWords));
        matchCount = MSGSEARCH_Search(s->messageSearch, initialId, 0, (struct Strbuf *)s->inputText, (MsgSearchHit *)s->results, PMSI_SEARCH_RESULT_MAX);
        for (i = 0; i < matchCount; i++) {
            normalWords[i] = PMS_INPUT_DATA_GetInitialWordId(s->wordData, initialId, s->results[i].wordIndex);
        }
        normalWords[matchCount] = PMS_INPUT_DATA_GetInvalidWordId(s->wordData);
        s->hasResults = PMS_INPUT_DATA_FilterWordList((uptr)s->wordData, (uptr)normalWords, (uptr)s->wordIds);
        if (s->hasResults) return 1;
        return 0;
    }
}

u8 PMSI_SEARCH_HasResults(struct PmsiSearch *s)
{
    return s->hasResults;
}

void PMSI_SEARCH_GetResultString(struct PmsiSearch *s, u8 resultIndex, int dest)
{
    PMS_INPUT_DATA_GetWordString(s->wordData, s->wordIds[resultIndex], dest);
}

u16 PMSI_SEARCH_GetResultWordId(struct PmsiSearch *s, u32 resultIndex)
{
    return s->wordIds[resultIndex];
}

int PMSI_SEARCH_GetKeyCount(void)
{
    return 0x1b;
}

void PMSI_SEARCH_GetKeyLabel(u32 i, struct U16Vec *dst)
{
    STRBUF_SetStringN((struct Strbuf *)dst, (u16 *)((const u8 *)sPmsiKanaKeys + i * 10), 2);
}

u16 PMSI_SEARCH_GetKeyChar(u32 i)
{
    return *(const u16 *)((const u8 *)sPmsiKanaKeys + i * 10);
}

/*
 * The original object reaches each column of the key table through its own
 * symbol (separate literal pool entries), so every accessor keeps its own extern.
 */
typedef struct { u8 column, row; } KanaKeyPosition;
extern KanaKeyPosition d_021C37AA;
extern const u8 d_021C37AC[];
extern const u8 d_021C37AD[];
extern const u8 d_021C37AE[];
extern const u8 d_021C37AF[];
extern const u8 d_021C37B1[];

void PMSI_SEARCH_GetKeyPosition(u32 i, int *column, int *row)
{
    *column = *(u8 *)((uptr)&d_021C37AA.column + i * 10);
    *row = *(u8 *)((uptr)&d_021C37AA.row + i * 10);
}

u8 PMSI_SEARCH_GetKeyUp(u32 i)
{
    return *(const u8 *)(d_021C37AC + i * 10);
}

u8 PMSI_SEARCH_GetKeyDown(u32 i)
{
    return *(const u8 *)(d_021C37AD + i * 10);
}

u8 PMSI_SEARCH_GetKeyLeft(u32 i)
{
    return *(const u8 *)(d_021C37AE + i * 10);
}

int PMSI_SEARCH_GetKeyRight(int i)
{
    return *(const u8 *)((uptr)d_021C37AF + i * 10);
}

u8 PMSI_SEARCH_GetKeyKind(u32 i)
{
    return *(const u8 *)(d_021C37B1 + i * 10);
}
