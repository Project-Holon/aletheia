/*
 * function: func_02156074
 * address:  0x02156074
 * packet:   pkt_ov010_02156074
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT* only because the unlabelled function at 0x0215611C follows
 * (seed it into layout/function_starts.txt). The u8 local t is what puts the
 * truncation of func_021F5140's result ahead of the w->f38 load.
 *
 * symbols:
 *   func_021FD964  0x021FD964  thumb  ov186
 *   func_021F4F14  0x021F4F14  thumb  ov112
 *   func_021F5140  0x021F5140  thumb  ov112
 *   func_021F4F40  0x021F4F40  thumb  ov112
 *   func_02157394  0x02157394  thumb  ov010
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
    u8 pad4C[8];
    u32 used[9];        /* 0x54 */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Work {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x10];
    void *f28;          /* 0x28 */
    u8 pad2C[4];
    Party *party;       /* 0x30 */
    u8 pad34[4];
    void *f38;          /* 0x38 */
} Work;

extern u32 func_021FD964(void *p, u32 i, u32 j);
extern void *func_021F4F14(u32 heap);
extern u32 func_021F5140(void *h, u16 id);
extern void func_021F4F40(void **p);
extern u16 func_02157394(void *p, u8 v);

void func_02156074(Work *w)
{
    Member *m;
    void *h;
    u8 i;
    u8 j;
    u32 k;
    u8 t;

    if (w->f14 == 1) {
        for (i = 0; i < 4; i++) {
            m = w->party->members[i];
            for (j = 0; j < 2; j++) {
                k = func_021FD964(w->f28, i, j);
                if (k != 0xFF)
                    m->used[k] = 1;
            }
        }
    }
    h = func_021F4F14(4);
    for (i = 0; i < 4; i++) {
        m = w->party->members[i];
        for (j = 0; j < 9; j++) {
            if (m->used[j] == 1) {
                t = func_021F5140(h, m->recs[j].id);
                m->total += func_02157394(w->f38, t);
            }
        }
    }
    func_021F4F40(h);
}
