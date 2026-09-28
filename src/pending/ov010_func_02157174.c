/*
 * function: func_02157174
 * address:  0x02157174
 * packet:   pkt_ov010_02157174
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Splits each deal bonus over the four members by how many of their nine
 * records fall in each category. Size and schedule right (232 of the
 * listing's 260 are this function; the rest is two unlabelled leaves at
 * 0x0215725C and 0x02157260); 19 instructions out, all a register swap:
 * the image colours the inner counter j in r4 and the row base in r5 (r2/r3
 * for m/row in the last loop), this C swaps them. Declaration order (720
 * permutations) is flat at 19, a row pointer local makes it 29, the
 * permuter (seed 7203, budget 400) found nothing.
 *
 * symbols:
 *   func_021F4F14  0x021F4F14  thumb  ov112
 *   func_021F5140  0x021F5140  thumb  ov112
 *   _s32_div_f  0x0209C0A4  arm
 *   func_021F4F40  0x021F4F40  thumb  ov112
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

extern void *func_021F4F14(u32 heap);
extern u32 func_021F5140(void *h, u16 id);
extern void func_021F4F40(void *h);

void func_02157174(u32 heap, Deal *d, Party *party)
{
    void *h;
    Member *m;
    u8 i;
    u8 j;
    u8 t;
    u8 v;
    u8 tot[4];
    u8 cnt[4][4];

    h = func_021F4F14(heap);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            cnt[j][i] = 0;
        tot[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        m = party->members[i];
        for (j = 0; j < 9; j++) {
            if (m->recs[j].id != 0xFF) {
                t = func_021F5140(h, m->recs[j].id);
                cnt[i][t]++;
                tot[t]++;
            }
        }
    }
    for (i = 0; i < 4; i++)
        d->f04[i] = d->f00[i] / tot[i];
    for (i = 0; i < 4; i++) {
        m = party->members[i];
        for (j = 0; j < 4; j++) {
            v = d->f04[j] * cnt[i][j];
            m->total += v;
            m->part[j] = v;
        }
    }
    func_021F4F40(h);
}
