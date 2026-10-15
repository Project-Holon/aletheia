/*
 * function: MUSICAL_PROGRAM_SplitBonus
 * address:  0x02157174
 * packet:   pkt_ov010_02157174
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Splits each deal bonus over the four members by how many of their nine
 * records fall in each category (232 bytes, ov010 battle overlay).
 * recoup 2026-10-05 (wave P10 Y7): the loop 2 and loop 4 member pointer and
 * the loop 2 byte counter j are block-local declarations (Member *m inside each
 * for body, u8 j inside the loop 2 body). Function-scope m and j gave 21 bytes
 * of register swaps. Pragmas (lifetimes, propagation, common_subs,
 * dead_assignments, scheduling, peephole), row pointer, id local, const party
 * all left 21 or worse. Verified EXACT in c99 and c.
 *
 * symbols:
 *   MUSICAL_MCSS_LoadActorData  0x021F4F14  thumb  ov112
 *   MUSICAL_MCSS_GetElemA  0x021F5140  thumb  ov112
 *   _s32_div_f  0x0209C0A4  arm
 *   MUSICAL_MCSS_FreeActorData  0x021F4F40  thumb  ov112
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
    u16 part[4];        /* 0x4C */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Deal {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
} Deal;

extern u32 *MUSICAL_MCSS_LoadActorData(int heap);
extern unsigned char MUSICAL_MCSS_GetElemA(void *p, int i);
extern void MUSICAL_MCSS_FreeActorData(void **p);
extern int _s32_div_f(int dividend, int divisor);

void MUSICAL_PROGRAM_SplitBonus(u32 heap, Deal *d, Party *party)
{
    void *h;
    u8 i;
    u8 j;
    u8 t;
    u8 v;
    u8 tot[4];
    u8 cnt[4][4];

    h = MUSICAL_MCSS_LoadActorData((u32)heap);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            cnt[j][i] = 0;
        tot[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        Member *m = party->members[i];
        u8 j;
        for (j = 0; j < 9; j++) {
            if (m->recs[j].id != 0xFF) {
                t = (u32)MUSICAL_MCSS_GetElemA(h, (u16)m->recs[j].id);
                cnt[i][t]++;
                tot[t]++;
            }
        }
    }
    for (i = 0; i < 4; i++)
        d->f04[i] = _s32_div_f(d->f00[i], tot[i]);
    for (i = 0; i < 4; i++) {
        Member *m = party->members[i];
        for (j = 0; j < 4; j++) {
            v = d->f04[j] * cnt[i][j];
            m->total += v;
            m->part[j] = v;
        }
    }
    MUSICAL_MCSS_FreeActorData(h);
}
