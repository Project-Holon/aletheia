/*
 * function: MUSICAL_EVENT_CreateShowRecord
 * address:  0x0215611C
 * packet:   pkt_ov010_0215611C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Party select screen setup: allocates the 0x14 and 0x1B0 B blocks, packs
 * the RTC date bits, fills four member records with 8 entry slots, then
 * sorts the member totals in descending order and permutes the order bytes
 * at +0x48.
 *
 * pass 2 2026-10-06 P2L42: EXACT (was 32 B off after G10L5). Three source
 * facts close it: (1) the slot clear loop and the slot fill loop share one
 * counter j (one variable, two webs), which swaps the base and zero/counter
 * registers into place; (2) the fill loop of tmp/f48 uses the sort counter a,
 * not i, which puts a at [sp,#4] and the record loop counter at [sp,#8];
 * (3) in the swap, t2 = w->f48[b + 1] is read before the store
 * tmp[b + 1] = t, so both f48 addresses are built before the loads.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   MUSICAL_PROGRAM_GetBaseProgramId  0x02157364  thumb  ov010
 *   MUSICAL_EVENT_AllocTitleString  0x02156914  thumb  ov010
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MUSICAL_EVENT_GetPlayerOfSlot  0x021568E8  thumb  ov010
 *   MUSICAL_EVENT_CountNpcSlotsBelow  0x021568A8  thumb  ov010
 *   MUSICAL_PROGRAM_GetNpcNameId  0x02157384  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MUS_COMM_FUNC_GetSlotValueA  0x021FCE28  thumb  ov132
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MUSICAL_SAVE_GetFromSave  0x0200A5F8  thumb
 *   sMusicalEventFileName  0x02172714  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct Rec6 {
    u16 id;
    s16 f2;
    u8 idx;
    u8 pad;
} Rec6;

typedef struct Member {
    u8 pad00[0x08];
    u16 f08;
    u8 f0a;
    u8 f0b;
    u8 f0c;
    u8 pad0d[3];
    u32 f10;
    Rec6 recs[9];       /* 0x14 */
    u16 total;          /* 0x4A */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Ent {
    u16 a;
    s16 b;
    u8 c;
    u8 pad[3];
} Ent;

typedef struct Rec {
    u16 id;
    u16 b0 : 2;
    u16 b2 : 1;
    u16 b3 : 5;
    u32 f04;
    u8 name[0x10];
    Ent ent[8];
} Rec;

typedef struct Disp {
    u32 a : 5;
    u32 e : 4;
    u32 b : 7;
    u32 c : 5;
    u32 d : 6;
    u32 f : 2;
    u32 g : 3;
    Rec recs[4];
    u16 text[0x25];
    u8 f1ae;
    u8 f1af;
} Disp;

typedef struct Sub {
    u32 f00;
    u32 f04;
    Disp *f08;
    void *f0c;
    void *f10;
} Sub;

typedef struct Work {
    void *f00;
    void *f04;
    u8 pad08[0x14 - 0x08];
    u32 f14;
    u8 pad18[0x28 - 0x18];
    void *f28;
    u8 pad2C[0x30 - 0x2C];
    Party *party;       /* 0x30 */
    Sub *f34;
    void *f38;
    u8 pad3C[0x48 - 0x3C];
    u8 f48[4];
    u8 f4C;
} Work;

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void GF_STANDARD_GetCachedDate(struct RtcDate *date);
struct Big;
struct Ctx;
struct MsgBank;
struct Table;
struct U16Vec;
extern u8 MUSICAL_PROGRAM_GetBaseProgramId(char *a0);
extern void *MUSICAL_EVENT_AllocTitleString(int a0, int a1);
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u8 MUSICAL_EVENT_GetPlayerOfSlot(Work *w, u8 idx);
extern u8 MUSICAL_EVENT_CountNpcSlotsBelow(Work *w, u8 n);
extern u8 MUSICAL_PROGRAM_GetNpcNameId(struct Table *t, int i);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int MUS_COMM_FUNC_GetSlotValueA(char *p, u32 index);
extern void MI_CpuCopy8(void *src, void *dst, u32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MUSICAL_SAVE_GetFromSave(void *p);

extern const char sMusicalEventFileName[];

void MUSICAL_EVENT_CreateShowRecord(Work *w)
{
    Disp *d;
    struct RtcDate date;
    void *str;
    u8 tmp[4];
    u8 i;
    u8 j;
    u8 b;
    u8 max;
    u8 v;
    int n;
    void *x;
    Member *m;
    void *bank;
    u8 t;
    u8 t2;
    u8 u;
    u8 a;

    w->f34 = func_02030734(4, 0x14, 0, sMusicalEventFileName, 0x312);
    w->f34->f08 = func_02030734(4, 0x1b0, 1, sMusicalEventFileName, 0x313);
    w->f34->f04 = 0;
    w->f34->f10 = w->f28;
    d = w->f34->f08;
    GF_STANDARD_GetCachedDate(&date);
    d->a = MUSICAL_PROGRAM_GetBaseProgramId(w->f38);
    d->b = date.year;
    d->c = date.month;
    d->d = date.day;
    str = MUSICAL_EVENT_AllocTitleString((int)w, 4);
    STRBUF_ToChars(str, d->text, 0x25);
    STRBUF_Delete(str);
    d->g = 0;
    d->f1ae = 0x15;
    d->f1af = 1;
    d->f = w->f4C;
    max = 0;
    for (i = 0; i < 4; i++) {
        v = w->party->members[i]->total;
        if (max < v) {
            d->e = 0;
            max = v;
        }
        if (max == v)
            d->e = d->e + (1 << i);
    }
    for (i = 0; i < 4; i++) {
        x = 0;
        m = w->party->members[i];
        d->recs[i].id = m->f08;
        d->recs[i].b0 = m->f0a;
        d->recs[i].b2 = m->f0c;
        d->recs[i].b3 = m->f0b;
        d->recs[i].f04 = m->f10;
        if (i == w->f4C)
            x = GAME_DATA_GetMyStatus(w->f04);
        else if (w->f14 == 1)
            x = (void *)MUS_COMM_FUNC_GetSlotValueA(w->f28, MUSICAL_EVENT_GetPlayerOfSlot(w, i));
        if (x != 0) {
            MI_CpuCopy8(x, d->recs[i].name, 0x10);
        } else {
            u8 val = MUSICAL_PROGRAM_GetNpcNameId(w->f38, MUSICAL_EVENT_CountNpcSlotsBelow(w, MUSICAL_EVENT_GetPlayerOfSlot(w, i)));

            bank = func_02045B38(0, 2, 0x4C, 4);
            str = func_02045EC0(bank, val);
            STRBUF_ToChars(str, (u16 *)d->recs[i].name, 8);
            STRBUF_Delete(str);
            MSGDATA_Delete(bank);
        }
        for (j = 0; j < 8; j++) {
            d->recs[i].ent[j].a = 0xFF;
            d->recs[i].ent[j].b = 0;
            d->recs[i].ent[j].c = 10;
        }
        for (j = 0; j < 9; j++) {
            if (m->recs[j].id != 0xFF) {
                u8 slot = m->recs[j].idx;

                d->recs[i].ent[slot].a = m->recs[j].id;
                d->recs[i].ent[slot].b = m->recs[j].f2;
                d->recs[i].ent[slot].c = j;
            }
        }
    }
    w->f34->f00 = 1;
    w->f34->f0c = MUSICAL_SAVE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(w->f00)));
    for (a = 0; a < 4; a++) {
        tmp[a] = w->party->members[a]->total;
        w->f48[a] = a;
    }
    for (a = 0; a < 4; a++) {
        n = 4 - (a + 1);
        for (b = 0; b < n; b++) {
            t = tmp[b];
            u = tmp[b + 1];
            if (u > t) {
                t2 = w->f48[b + 1];
                tmp[b + 1] = t;
                w->f48[b + 1] = w->f48[b];
                tmp[b] = u;
                w->f48[b] = t2;
            }
        }
    }
}
