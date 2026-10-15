/*
 * function: MUSICAL_EVENT_SetPokemonNameWord
 * address:  0x02156AD4
 * packet:   pkt_ov010_02156AD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of MUSICAL_EVENT_SetPlayerNameWord for the second word-set field: the local player's
 * record at +0x18, the session's record for a remote member (0x021FCE44),
 * or failing both the fallback string from message bank 0x4D.
 *
 * First draft; the ov132 call to 0x021FCE44 resolves since seeds_2 labelled it.
 *
 * symbols:
 *   MUSICAL_EVENT_GetPlayerOfSlot  0x021568E8  thumb  ov010
 *   MUSICAL_EVENT_CountNpcSlotsBelow  0x021568A8  thumb  ov010
 *   MUSICAL_PROGRAM_GetNpcNameId  0x02157384  thumb  ov010
 *   MUS_COMM_FUNC_GetSlotValueB  0x021FCE44  thumb  ov132
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   WORDSET_SetSlotMonSpecies  0x0201EEF4  thumb
 *   WORDSET_SetSlotMonSpeciesAlt  0x0201EF14  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[0x14 - 0x08];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    u8 pad1C[0x28 - 0x1C];
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    u8 pad3C[0x4C - 0x3C];
    u8 f4c;             /* 0x4C */
} Work;

extern u8 MUSICAL_EVENT_GetPlayerOfSlot(Work *w, u8 j);
extern u8 MUSICAL_EVENT_CountNpcSlotsBelow(Work *w, u8 n);
struct MsgBank;
struct Rec;
struct Table;
struct U16Vec;
struct WordSet;
extern u8 MUSICAL_PROGRAM_GetNpcNameId(struct Table *t, int i);
extern int MUS_COMM_FUNC_GetSlotValueB(char *p, u32 index);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotMonSpeciesAlt(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);

void MUSICAL_EVENT_SetPokemonNameWord(Work *w, u8 j, void *ws, u32 slot)
{
    int done = 0;
    u8 k = MUSICAL_EVENT_GetPlayerOfSlot(w, j);
    void *p;

    if (j == w->f4c) {
        GAME_DATA_GetMyStatus(w->f04);
        WORDSET_SetSlotMonSpecies(ws, slot, w->f18);
        done = 1;
    } else if (w->f14 == 1) {
        p = (void *)MUS_COMM_FUNC_GetSlotValueB(w->f28, k);
        if (p != 0) {
            WORDSET_SetSlotMonSpeciesAlt(ws, slot, p);
            done = 1;
        }
    }
    if (!done) {
        u8 n = MUSICAL_PROGRAM_GetNpcNameId(w->f38, MUSICAL_EVENT_CountNpcSlotsBelow(w, k));
        void *bank = func_02045B38(0, 2, 0x4D, 4);
        void *str = func_02045EC0(bank, n);

        WORDSET_SetSlotTag(ws, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(bank);
    }
}
