/*
 * file:     pms_word.c
 * unit:     yes
 * function: PMS_WORD_Create, PMS_WORD_Delete, PMS_WORD_GetString, PMS_WORD_LoadString, PMS_WORD_MakeWordId, PMS_WORD_SplitWordId, PMS_WORD_GetSaveEntry, PMS_WORD_SetSaveEntry, PMS_WORD_GetSaveSize, PMS_WORD_InitSave, PMS_WORD_GetSaveData, PMS_WORD_CheckFlag, PMS_WORD_SetFlag, PMS_WORD_IsSameGroup
 * address:  0x020247A8
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
 *   MSGDATA_CreateFromArchive    0x02045B38  arm
 *   MSGDATA_Delete    0x02045C04  arm
 *   g_pmsWordSourceFile   0x020A746C  data  a1
 *   g_pmsWordBankFileIds  0x0209F7AC  data
 *   g_pmsWordBankSizes    0x0209F792  data
 *   STRBUF_Clear    0x0204581C  arm
 *   MSGDATA_ReadString    0x02045CAC  arm
 *   g_pmsWordDefaultFlagTable   0x0209F784  data  a1
 *   g_pmsWordSimilarGroups  0x0209F7C8  data
 */
#include "../version.h"
#include "pms_types.h"
struct WinPanel020071CCCtrl;
struct MsgBank;
struct Rec;
struct U16Vec;

#include "../types.h"

struct PmsWordSys {
    u32   heapId;
    void *msg[13];
};

struct PmsWord {
    u32 flags;
    u32 extraFlags;
    struct PmsData sentence[20];
};

typedef struct Group {
    const u16 *list;
    int count;
} Group;

#include "gfl_heap_wrap.h"
#include "mi_memory.h"
struct SaveControl;
#include "save_control.h"
#ifdef __MWERKS__
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
extern struct MsgBank *MSGDATA_CreateFromArchive(int resident, int arcId, u32 fileId, u16 heapId); /* original prototype; the definition differs in argument sign, argument width */
#else
#include "msgdata.h"
#endif
struct Strbuf;
#include "strbuf.h"
struct PmsWordSys *PMS_WORD_Create(u32 heapId);
void PMS_WORD_Delete(struct PmsWordSys *p);
void PMS_WORD_GetString(struct PmsWordSys *p, u32 id, void *dest);
void PMS_WORD_LoadString(u32 id, void *dest, u16 heap);
u16 PMS_WORD_MakeWordId(u32 idx, u16 add);
int PMS_WORD_SplitWordId(u32 v, u32 *bankIndex, u32 *wordIndex);
void *PMS_WORD_GetSaveEntry(char *p, int idx);
void PMS_WORD_SetSaveEntry(struct PmsWord *p, s32 idx, const void *src);
u32 PMS_WORD_GetSaveSize(void);
void PMS_WORD_InitSave(struct PmsWord *p);
void *PMS_WORD_GetSaveData(struct WinPanel020071CCCtrl *ctrl);
int PMS_WORD_CheckFlag(const u32 *p, u32 idx);
void PMS_WORD_SetFlag(int *p, int bit);
int PMS_WORD_IsSameGroup(u32 a, u16 b);

extern const char g_pmsWordSourceFile[];
extern const u16 g_pmsWordBankFileIds[];
extern const u16 g_pmsWordBankSizes[];
extern const u8 g_pmsWordDefaultFlagTable[][2];
#define PMS_WORD_GROUP_COUNT PM_LANG_EU(13, 12, 7, 2, 10)

#if LANGUAGE != LANGUAGE_JAPANESE
extern const Group g_pmsWordSimilarGroups[];
#endif

/*
 * pms_word.c: allocate the 0x38-byte word-message system and open its
 * thirteen message archives (ids from the u16 table at 0x0209F7AC).  The
 * heap id store sits inside the loop in the image, so it is inside the
 * loop here.  The r4/r5 swap of docs/notes/pkt_02024768.c.txt was the
 * declaration order: the counter is declared before the result pointer
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md),
 * found by tools/permuter.py and reduced to that one change.
 */
struct PmsWordSys *PMS_WORD_Create(u32 heapId)
{
    int i;
    struct PmsWordSys *p;

    p = GFL_HEAP_Alloc((u16)heapId, sizeof(*p), 0, g_pmsWordSourceFile, 0x32);
    for (i = 0; i < 13; i++) {
        p->heapId = heapId;
        p->msg[i] = MSGDATA_CreateFromArchive(0, 2, g_pmsWordBankFileIds[i], heapId);
    }
    return p;
}

void PMS_WORD_Delete(struct PmsWordSys *p)
{
    int i;
    for (i = 0; i < 0xd; i++)
        MSGDATA_Delete((struct MsgBank *)p->msg[i]);
    GFL_HEAP_Free(p);
}

void PMS_WORD_GetString(struct PmsWordSys *p, u32 id, void *dest)
{
    u32 x, y;
    PMS_WORD_SplitWordId(id, &x, &y);
    MSGDATA_ReadString((struct MsgBank *)p->msg[x], y, dest);
}

/*
 * Loads one archived message/graphics entry into the caller's buffer.
 * The flat id is split by PMS_WORD_SplitWordId into a bank index and an
 * entry index; the bank index selects an archive id out of the
 * halfword table at 0x0209F7AC, that archive is opened, the entry is
 * read into dest and the archive closed again.  The sentinel id
 * 0xffff means "nothing to load" and only clears dest.
 */
void PMS_WORD_LoadString(u32 id, void *dest, u16 heap)
{
    u32 bank;
    u32 entry;

    if (id != 0xffff) {
        void *arc;

        PMS_WORD_SplitWordId(id, &bank, &entry);
        bank = g_pmsWordBankFileIds[bank];
        arc = MSGDATA_CreateFromArchive(0, 2, bank, heap);
        MSGDATA_ReadString(arc, entry, dest);
        MSGDATA_Delete(arc);
    } else {
        STRBUF_Clear(dest);
    }
}

u16 PMS_WORD_MakeWordId(u32 idx, u16 add)
{
    u32 i;
    u16 sum;
    u16 k;

    for (i = 0; i < 0xD; i++) {
        if (idx == g_pmsWordBankFileIds[i]) {
            k = 0;
            sum = 0;
            for (; k < i; k++) {
                sum = (u16)(sum + g_pmsWordBankSizes[k]);
            }
            return (u16)(sum + add);
        }
    }
    return 0xFFFF;
}

int PMS_WORD_SplitWordId(u32 wordId, u32 *bankIndex, u32 *wordIndex)
{
    u32 i;
    u32 sum;

    wordId &= 0x7ff;
    sum = 0;
    for (i = 0; i < 0xd; i++) {
        u16 n = g_pmsWordBankSizes[i];

        sum += n;
        if (wordId < sum) {
            *bankIndex = i;
            *wordIndex = wordId - (sum - n);
            return 1;
        }
    }
    return 0;
}

/*
 * Unlabelled Thumb leaf: address of the 8-byte entry idx of the table at p + 8.
 */
void *PMS_WORD_GetSaveEntry(char *p, int idx)
{
    return p + 8 + idx * 8;
}

void PMS_WORD_SetSaveEntry(struct PmsWord *p, s32 idx, const void *src)
{
    if (idx < 0 || idx >= 20) {
        return;
    }

    MI_CpuCopy8(src, &p->sentence[idx], 8);
}

/*
 * Save-table size callback: returns 0xA8, the size of the block whose
 * init is PMS_WORD_InitSave.  Pointer word 0x02024935 at 0x0209DC00.
 */
u32 PMS_WORD_GetSaveSize(void)
{
    return 0xA8;
}

/*
 * pms_word.c: clear the flag words, seed all forty word slots to 0xFFFF,
 * then set the flag bit named by the first row of the 7 x 2 byte table at
 * 0x0209F784 whose kind is 2.  The table is a 2D array: `tbl[k][1]` is what
 * gives the image's second pool word 0x0209F785 (symbol + 1, indexed by
 * the same 2k), where a struct {kind, val} folds the +1 into the load
 * (docs/notes/pkt_02024938.c.txt).  k is unsigned (`blo`); the first two
 * loops count in int.
 */
void PMS_WORD_InitSave(struct PmsWord *p)
{
    int i, j;
    u32 k;

    p->flags = 0;
    p->extraFlags = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 2; j++)
            p->sentence[i].word[j] = 0xffff;
    }
    for (k = 0; k < 7; k++) {
        if (g_pmsWordDefaultFlagTable[k][0] == PM_LANG_ID) {
            PMS_WORD_SetFlag((int *)p, g_pmsWordDefaultFlagTable[k][1]);
            return;
        }
    }
}

void *PMS_WORD_GetSaveData(struct WinPanel020071CCCtrl *ctrl)
{
    return SAVE_CONTROL_GetBlock((struct SaveControl *)ctrl, 0x27);
}

int PMS_WORD_CheckFlag(const u32 *p, u32 idx){return (*p >> idx) & 1;}

void PMS_WORD_SetFlag(int *p, int bit)
{
    *p |= 1 << bit;
}

/* The Japanese cartridge has no similar-word groups. */
#if LANGUAGE != LANGUAGE_JAPANESE
/*
 * Unlabelled arm9 leaf: true when a == b, or when the first of the halfword
 * groups that contains a also contains b. Filed as the relocation witness for
 * ov021 SCRCMD_CheckPmsWordPair (wave A1).
 */
int PMS_WORD_IsSameGroup(u32 a, u16 b)
{
    u32 i;
    int j, k;

    if (a == b) {
        return 1;
    }
    for (i = 0; i < PMS_WORD_GROUP_COUNT; i++) {
        for (j = 0; j < g_pmsWordSimilarGroups[i].count; j++) {
            if (a == g_pmsWordSimilarGroups[i].list[j]) {
                for (k = 0; k < g_pmsWordSimilarGroups[i].count; k++) {
                    if (b == g_pmsWordSimilarGroups[i].list[k]) {
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
#endif
