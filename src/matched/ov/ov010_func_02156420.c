/*
 * function: MUSICAL_EVENT_ApplyResults
 * address:  0x02156420
 * packet:   pkt_ov010_02156420
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The u16 read through GAME_DATA_GetMyPlayerWork's result goes through a local k;
 * passed inline it is copied to r2 before the ldrh. The tally array is
 * `u8 cnt[4] = {0, ...}` in a nested block (as in MUSICAL_PROGRAM_Create).
 * EXACT* because the listing extent carries two bytes of pad.
 *
 * symbols:
 *   MUSICAL_EVENT_GetScoreCapped  0x02156934  thumb  ov010
 *   MUSICAL_SAVE_IncrementShowCount  0x0200A768  thumb
 *   MUSICAL_SAVE_IncrementTopRankCount  0x0200A788  thumb
 *   MUSICAL_SAVE_SetSelectedProgram  0x0200A7C0  thumb
 *   MUSICAL_SAVE_AddFanPoints  0x0200A800  thumb
 *   MUSICAL_MCSS_LoadActorData  0x021F4F14  thumb  ov112
 *   MUSICAL_MCSS_GetElemA  0x021F5140  thumb  ov112
 *   MUSICAL_SAVE_SetEquippedProp  0x0200A7AC  thumb
 *   MUSICAL_MCSS_FreeActorData  0x021F4F40  thumb  ov112
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   NATSUKI_Calc  0x0201B7A0  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02008DAC  0x02008DAC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec6 {
    u16 id;
    u8 pad[4];
} Rec6;

typedef struct Member {
    u8 pad00[0x14];
    Rec6 recs[9];       /* 0x14 */
    u16 total;          /* 0x4A */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Work {
    u8 pad00[0x04];
    void *f04;          /* 0x04 */
    u8 pad08[0x14 - 0x08];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    u8 pad1C[0x30 - 0x1C];
    Party *party;       /* 0x30 */
    u8 pad34[0x40 - 0x34];
    void *f40;          /* 0x40 */
    u8 pad44[0x48 - 0x44];
    u8 f48;             /* 0x48 */
    u8 pad49[3];
    u8 f4C;             /* 0x4C */
} Work;

extern u8 MUSICAL_EVENT_GetScoreCapped(Work *w, u8 idx);
typedef signed int     s32;
struct Big;
struct Sub02008C20Obj;
extern void MUSICAL_SAVE_IncrementShowCount(struct Big *p);
extern void MUSICAL_SAVE_IncrementTopRankCount(struct Big *p);
extern void MUSICAL_SAVE_SetSelectedProgram(struct Big *p, u8 value);
extern void MUSICAL_SAVE_AddFanPoints(struct Big *p, s32 delta);
extern u32 *MUSICAL_MCSS_LoadActorData(int heap);
extern unsigned char MUSICAL_MCSS_GetElemA(void *p, int i);
extern void MUSICAL_SAVE_SetEquippedProp(struct Big *p, u32 index, u8 value);
extern void MUSICAL_MCSS_FreeActorData(void **p);
extern u16 *GAME_DATA_GetMyPlayerWork(void *p);
extern void NATSUKI_Calc(void *a0, int a1, int a2, int a3);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);

void MUSICAL_EVENT_ApplyResults(Work *w)
{
    u8 a;
    u8 b;
    u8 j;
    void *h;
    Member *m;
    void *p;
    u16 k;

    a = MUSICAL_EVENT_GetScoreCapped(w, w->f4C);
    b = MUSICAL_EVENT_GetScoreCapped(w, w->f48);
    MUSICAL_SAVE_IncrementShowCount(w->f40);
    if (a == b && a != 0)
        MUSICAL_SAVE_IncrementTopRankCount(w->f40);
    MUSICAL_SAVE_SetSelectedProgram(w->f40, a);
    MUSICAL_SAVE_AddFanPoints(w->f40, a);
    {
        u8 cnt[4] = {0, 0, 0, 0};

        h = MUSICAL_MCSS_LoadActorData((u32)4);
        m = w->party->members[w->f4C];
        for (j = 0; j < 9; j++) {
            if (m->recs[j].id != 0xFF)
                cnt[(u8)(u32)MUSICAL_MCSS_GetElemA(h, (u16)m->recs[j].id)]++;
        }
        for (j = 0; j < 4; j++)
            MUSICAL_SAVE_SetEquippedProp(w->f40, j, cnt[j]);
    }
    MUSICAL_MCSS_FreeActorData(h);
    k = *GAME_DATA_GetMyPlayerWork(w->f04);
    NATSUKI_Calc(w->f18, 6, k, 4);
    p = GAME_DATA_GetTrainerRecord(w->f04);
    if (w->f14 == 0) {
        func_02008DF0(p, 0x72);
        if (a == b && a != 0)
            func_02008DF0(p, 0x73);
    } else {
        func_02008DF0(p, 0x74);
        if (a == b && a != 0)
            func_02008DF0(p, 0x75);
    }
    func_02008DAC(p, 0x76, a);
}
