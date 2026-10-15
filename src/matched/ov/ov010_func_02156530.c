/*
 * function: MUSICAL_EVENT_RollProgramRewards
 * address:  0x02156530
 * packet:   pkt_ov010_02156530
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct. Two levers: the spilled locals are declared in the order
 * of their stack slots from the top down (i, lvl, n, q, row, t), and the
 * table row pointer is set in the for-initialiser after j (a separate
 * statement stores it before `j = 0`). Blocker (MATCH): 0x021FD8F8 and
 * 0x021FD4F8 have no func_ label in any overlay listing (ov094, ov132,
 * ov135 and ov186 overlap them).
 *
 * 2026-10-05 (wave D9): the ov132 token on the 0x021FD8F8 and 0x021FD4F8 symbols
 * lines resolves 0x021FD8F8 (matched in ov132_func_021FD8EC.c). 0x021FD4F8 is an
 * unlabelled 50-byte Thumb leaf in ov132; filed as the witness
 * src/matched/ov/ov132_func_021FD4F8.c (EXACT). Still MATCH only until the
 * integrator gives that leaf a shard or label; then this file is EXACT.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MUSICAL_SAVE_GetProgram  0x0200A750  thumb
 *   MUSICAL_SAVE_GetFanPoints  0x0200A81C  thumb
 *   MUSICAL_EVENT_GetScoreCapped  0x02156934  thumb  ov010
 *   MUSICAL_EVENT_GetPlayerOfSlot  0x021568E8  thumb  ov010
 *   STA_NET_GetSlotWordByIndex  0x021FD8F8  thumb  ov132
 *   STA_NET_FindRecValueByKey  0x021FD4F8  thumb  ov132
 *   MUSICAL_PROGRAM_GetPropRow  0x0215736C  thumb  ov010
 *   MUSICAL_SAVE_IsPropOwned  0x0200A644  thumb
 *   MUSICAL_PROGRAM_GetBestCategory  0x021572C0  thumb  ov010
 *   func_02005728  0x02005728  thumb
 *   func_020307B0  0x020307B0  arm
 *   sMusicalEventFileName  0x02172714  data
 *   d_0216FF14  0x0216FF14  data
 *   d_0216FF28  0x0216FF28  data
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
    u8 pad1C[0x28 - 0x1C];
    void *f28;          /* 0x28 */
    u8 pad2C[0x30 - 0x2C];
    Party *party;       /* 0x30 */
    u8 pad34[0x38 - 0x34];
    void *f38;          /* 0x38 */
    u8 pad3C[0x40 - 0x3C];
    void *f40;          /* 0x40 */
    u8 pad44[0x48 - 0x44];
    u8 f48;             /* 0x48 */
    u8 pad49[3];
    u8 f4C;             /* 0x4C */
} Work;

typedef struct Slot {
    u8 f00;             /* 0x00 */
    u8 f01;             /* 0x01 */
    u16 f02;            /* 0x02 */
} Slot;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
struct Big;
struct BigSub4;
struct Ctx;
struct Deal;
extern struct BigSub4 *MUSICAL_SAVE_GetProgram(struct Big *p, u32 index);
extern u16 MUSICAL_SAVE_GetFanPoints(struct Big *p);
extern u8 MUSICAL_EVENT_GetScoreCapped(Work *w, u8 idx);
extern int MUSICAL_EVENT_GetPlayerOfSlot(int a0, u8 a1);
extern u32 STA_NET_GetSlotWordByIndex(char *p, u32 index);
extern u32 STA_NET_FindRecValueByKey(struct Ctx *p, u8 key);
extern int MUSICAL_PROGRAM_GetPropRow(int a0);
extern u32 MUSICAL_SAVE_IsPropOwned(struct Big *p, u8 index);
extern u8 MUSICAL_PROGRAM_GetBestCategory(struct Deal *d);
extern u32 func_02005728(u32 range);
extern u32 func_020307B0(void *p);

extern const char sMusicalEventFileName[];
extern const u16 d_0216FF14[10];
extern const u8 d_0216FF28[7][0x28];

void MUSICAL_EVENT_RollProgramRewards(Work *w)
{
    u8 order[10];
    u8 *buf;
    Slot *e;
    u32 sum;
    u32 r;
    u16 *pv;
    u8 j;
    u8 v;
    u8 x;
    u8 c;
    u8 i;
    u8 lvl;
    u8 n;
    u32 q;
    const u8 *row;
    u8 t;

    buf = func_02030734(4, 0x28, 1, sMusicalEventFileName, 0x3F9);
    sum = 0;
    for (i = 0; i < 10; i++) {
        e = (Slot *)MUSICAL_SAVE_GetProgram(w->f40, i);
        e->f00 = 4;
        e->f01 = 0;
        e->f02 = 0;
    }
    if (w->f14 == 0) {
        sum = MUSICAL_SAVE_GetFanPoints(w->f40) + MUSICAL_EVENT_GetScoreCapped(w, w->f4C);
    } else {
        for (j = 0; j < 4; j++) {
            pv = (u16 *)STA_NET_GetSlotWordByIndex(w->f28, MUSICAL_EVENT_GetPlayerOfSlot((int)w, j));
            if (STA_NET_FindRecValueByKey(w->f28, j) != 0) {
                sum += *pv;
                sum += MUSICAL_EVENT_GetScoreCapped(w, j);
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if (d_0216FF14[i] <= sum) {
            lvl = 10 - i;
            break;
        }
    }
    r = MUSICAL_PROGRAM_GetPropRow((int)w->f38);
    if (r < 7) {
        n = 0;
        for (j = 0, row = d_0216FF28[r]; j < 0x28; j++) {
            v = row[j];
            if (MUSICAL_SAVE_IsPropOwned(w->f40, v) == 0) {
                buf[n] = v;
                n++;
            }
        }
    }
    q = MUSICAL_PROGRAM_GetBestCategory(w->f38);
    for (i = 0; i < 10; i++)
        order[i] = i;
    for (t = 0; t < 10; t++) {
        for (j = 0; j < 10; j++) {
            x = func_02005728(10);
            v = order[j];
            order[j] = order[x];
            order[x] = v;
        }
    }
    for (i = 0; i < lvl; i++) {
        e = (Slot *)MUSICAL_SAVE_GetProgram(w->f40, order[i]);
        c = MUSICAL_EVENT_GetScoreCapped(w, w->f4C);
        e->f00 = q;
        if ((u8)func_02005728(100) < c && n != 0) {
            x = func_02005728(n);
            e->f01 = 1;
            e->f02 = buf[x];
            for (; x < n - 1; x++)
                buf[x] = buf[x + 1];
            n--;
        }
    }
    func_020307B0(buf);
}
