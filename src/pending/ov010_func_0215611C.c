/*
 * function: func_0215611C
 * address:  0x0215611C
 * packet:   pkt_ov010_0215611C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Unlabelled: the listing folds it into func_02156074's extent. Builds the
 * 0x1B0-byte musical result record (musical_event.c).
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_02157364  0x02157364  thumb  ov010
 *   func_02156914  0x02156914  thumb  ov010
 *   sub_02045A38   0x02045A38  arm
 *   sub_02045808   0x02045808  arm
 *   func_02012944  0x02012944  thumb
 *   func_021568E8  0x021568E8  thumb  ov010
 *   func_021FCE28  0x021FCE28  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021568A8  0x021568A8  thumb  ov010
 *   func_02157384  0x02157384  thumb  ov010
 *   sub_02045B38   0x02045B38  arm
 *   sub_02045EC0   0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A5F8  0x0200A5F8  thumb
 *   d_02172714     0x02172714  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct Rec6 {
    u16 id;
    s16 val;
    u8 slot;
    u8 pad;
} Rec6;

typedef struct Member {
    u8 pad00[8];
    u16 f08;            /* 0x08 */
    u8 f0a;             /* 0x0A */
    u8 f0b;             /* 0x0B */
    u8 f0c;             /* 0x0C */
    u8 pad0D[3];
    u32 f10;            /* 0x10 */
    Rec6 recs[9];       /* 0x14 */
    u16 total;          /* 0x4A */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Sub {
    u16 id;
    s16 val;
    u8 idx;
    u8 pad[3];
} Sub;

typedef struct Entry {
    u16 f00;
    u16 b0 : 2;
    u16 b2 : 1;
    u16 b3 : 5;
    u32 f04;
    u16 name[8];
    Sub sub[8];
} Entry;

typedef struct Blk {
    u32 kind : 5;
    u32 winners : 4;
    u32 year : 7;
    u32 month : 5;
    u32 day : 6;
    u32 self : 2;
    u32 top : 3;
    Entry ent[4];       /* 0x004 */
    u16 title[0x25];    /* 0x164 */
    u8 f1ae;            /* 0x1AE */
    u8 f1af;            /* 0x1AF */
} Blk;

typedef struct Hdr {
    u32 f00;
    u32 f04;
    Blk *blk;           /* 0x08 */
    u32 f0c;            /* 0x0C */
    void *f10;          /* 0x10 */
} Hdr;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 pad08[0xC];
    u32 f14;            /* 0x14 */
    u8 pad18[0x10];
    void *f28;          /* 0x28 */
    u8 pad2C[4];
    Party *party;       /* 0x30 */
    Hdr *hdr;           /* 0x34 */
    void *f38;          /* 0x38 */
    u8 pad3C[0xC];
    u8 order[4];        /* 0x48 */
    u8 f4c;             /* 0x4C */
} Work;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0203F4E4(RTCDate *date);
extern u8 func_02157364(void *p);
extern void *func_02156914(Work *w, int id);
extern void sub_02045A38(void *vec, u16 *out, u32 n);
extern void sub_02045808(void *vec);
extern void *func_02012944(void *p);
extern u32 func_021568E8(Work *w, u32 j);
extern void *func_021FCE28(void *p, u32 i);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u8 func_021568A8(Work *w, u8 n);
extern u8 func_02157384(void *p, int i);
extern void *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *sub_02045EC0(void *bank, u32 index);
extern void func_02045C04(void *bank);
extern void *func_020120F4(void *p);
extern void *func_02012EBC(void *p);
extern u32 func_0200A5F8(void *p);

extern const char d_02172714[];

void func_0215611C(Work *w)
{
    RTCDate date;
    u8 score[4];
    Blk *blk;
    Member *m;
    Entry *e;
    Rec6 *r;
    Sub *s;
    void *str;
    void *name;
    void *bank;
    u8 t;
    u8 max;
    u8 i;
    u8 j;
    u8 k;
    u8 l;
    u8 a;
    u8 b;
    int n;
    u8 v;

    w->hdr = sub_02030734(4, 0x14, 0, d_02172714, 786);
    w->hdr->blk = sub_02030734(4, 0x1B0, 1, d_02172714, 787);
    w->hdr->f04 = 0;
    w->hdr->f10 = w->f28;
    blk = w->hdr->blk;
    func_0203F4E4(&date);
    blk->kind = func_02157364(w->f38);
    blk->year = date.year;
    blk->month = date.month;
    blk->day = date.day;
    str = func_02156914(w, 4);
    sub_02045A38(str, blk->title, 0x25);
    sub_02045808(str);
    blk->top = 0;
    blk->f1ae = 0x15;
    blk->f1af = 1;
    blk->self = w->f4c;

    max = 0;
    for (i = 0; i < 4; i++) {
        v = w->party->members[i]->total;
        if (max < v) {
            max = v;
            blk->winners = 0;
        }
        if (max == v)
            blk->winners += 1 << i;
    }

    for (j = 0; j < 4; j++) {
        name = 0;
        m = w->party->members[j];
        e = &blk->ent[j];
        e->f00 = m->f08;
        e->b0 = m->f0a;
        e->b2 = m->f0c;
        e->b3 = m->f0b;
        e->f04 = m->f10;
        if (j == w->f4c)
            name = func_02012944(w->f04);
        else if (w->f14 == 1)
            name = func_021FCE28(w->f28, func_021568E8(w, j));
        if (name != 0) {
            MI_CpuCopy8(name, blk->ent[j].name, 0x10);
        } else {
            t = func_02157384(w->f38, func_021568A8(w, func_021568E8(w, j)));
            bank = sub_02045B38(0, 2, 0x4C, 4);
            str = sub_02045EC0(bank, t);
            sub_02045A38(str, blk->ent[j].name, 8);
            sub_02045808(str);
            func_02045C04(bank);
        }
        e = &blk->ent[j];
        for (k = l = 0; k < 8; k++) {
            e->sub[k].id = 0xFF;
            e->sub[k].val = l;
            e->sub[k].idx = 10;
        }
        for (; l < 9; l++) {
            r = &m->recs[l];
            if (r->id != 0xFF) {
                s = &e->sub[r->slot];
                s->id = r->id;
                s->val = r->val;
                s->idx = l;
            }
        }
    }

    w->hdr->f00 = 1;
    w->hdr->f0c = func_0200A5F8(func_02012EBC(func_020120F4(w->f00)));

    for (i = 0; i < 4; i++) {
        score[i] = w->party->members[i]->total;
        w->order[i] = i;
    }
    for (a = 0; a < 4; a++) {
        n = 4 - (a + 1);
        for (b = 0; b < n; b++) {
            if (score[b + 1] > score[b]) {
                v = score[b];
                score[b] = score[b + 1];
                score[b + 1] = v;
                v = w->order[b];
                w->order[b] = w->order[b + 1];
                w->order[b + 1] = v;
            }
        }
    }
}
