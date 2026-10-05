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
 * 2026-10-05 (wave P2, lane Q7, pengy share): first full draft, 768 B
 * compiled against 772 (pad). Semantics read from the listing: party
 * select screen setup (alloc 0x14 and 0x1B0 B blocks, RTC date bits, four
 * member records with 8 entry slots, then a 4-element descending sort of
 * member totals that permutes the order bytes at +0x48). Residue is all
 * register colour: the original keeps w in r4, the zero (max) in r5, the
 * tag 0x312 in r6 and the file string in r7 across both allocations, then
 * puts d in r7 and rebuilds 0x1B0 (movs 0x1b; lsls 4; subs k) at each use.
 * Mine holds 0x1B0 in r7 (the 0x164, 0x1AE, 0x1AF offsets reuse it), so d
 * is spilled to [sp,#8] and w/zero swap to r5/r4. Without the three
 * derived-offset uses (text copy, bytes at 0x1AE/0x1AF) the prefix colours
 * as the original except w/zero. Tried, no change: max=0 first or before the
 * loop, max declared first or last, file/tag as locals, raw byte offsets for
 * the tail, a local h=0x1b0 for the offsets, int size parameter, no rec
 * pointer (796 B, worse), pragmas opt_lifetimes (772 B but same prefix),
 * opt_propagation (800 B), opt_common_subs, peephole, dead_assignments,
 * scheduling (no change). The original also uses base d+i*0x58 with
 * fields at +4 (mov ip copy), mine builds d+4 first; to be revisited once
 * the allocation is fixed. Left as DIFF.
 *
 * 2026-10-05 (wave P2, lane Q7b): fields of the member records are now
 * written as d->recs[i].f (no rec pointer local). That form gives the
 * original's `mov ip, r0; strh r1,[r0,#4]`, `adds r2,d,#6` + `[r2,idx]`
 * for the bitfield halfword and `mov r0, ip; str r1,[r0,#8]` exactly, and it
 * also puts w in r4 and the zero/max in r5 as in the original (the old
 * rec pointer form built d+4 first and swapped w/zero). Size is 796 B now
 * (original 772) only because of the remaining residue below.
 * Remaining residue (one cause): the original does NOT pool 0x1b0. It
 * rebuilds it (movs 0x1b; lsls 4) for the alloc argument and again for the
 * text offset (subs 0x4c) and the bytes at 0x1AE/0x1AF (subs 2, subs 1), and
 * keeps tag 0x312 (r6) and the file string (r7) in callee-saved registers.
 * Ours pools 0x1b0 in r7 (4 uses beat the string's 2), the string is
 * reloaded from the pool per call, and d (r7 in the original for the whole
 * function) is spilled to [sp,#8]. With only the text use kept (the two byte
 * stores removed) 0x1b0 takes r6, the string keeps r7, but d is still
 * spilled (five values live at the call to func_02156914), so the pooling is
 * not the only pressure. Tried this lane, no change in the prefix (all
 * compiled against the old rec form unless noted): sizeof(Disp) as the alloc
 * size (identical bytes), int h = 0x1b0 used for the alloc and as `d + h - k`
 * and `d + (h - k)` (identical: the derived offsets come from the pooled
 * constant either way), opt_common_subs off with h (same), static inline
 * alloc wrapper taking size (propagated, same), d declared last (same),
 * `u32 max` (same), opt_lifetimes off (772 B with the old form, 800 B with
 * the new; prefix unchanged, d still spilled). Idiom reading: the pooler
 * pools a repeated constant only when its uses are in one block
 * (docs/idioms/a-repeated-constant-pools-only-within-one-block-...), so the
 * original likely has the four uses of 0x1b0 in different blocks, but the
 * listing shows no branch between them; no source form found that splits
 * them without adding code. Left as DIFF.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_02157364  0x02157364  thumb  ov010
 *   func_02156914  0x02156914  thumb  ov010
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_021568E8  0x021568E8  thumb  ov010
 *   func_021568A8  0x021568A8  thumb  ov010
 *   func_02157384  0x02157384  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_021FCE28  0x021FCE28  thumb  ov132
 *   func_02082D44  0x02082D44  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A5F8  0x0200A5F8  thumb
 *   d_02172714  0x02172714  data
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
extern void func_0203F4E4(struct RtcDate *date);
extern u8 func_02157364(void *p);
extern void *func_02156914(Work *w, u32 heap);
extern void func_02045A38(void *str, void *out, u32 n);
extern void func_02045808(void *str);
extern u8 func_021568E8(Work *w, u8 idx);
extern u8 func_021568A8(Work *w, u8 n);
extern u8 func_02157384(void *t, int i);
extern u8 *func_02012944(void *p);
extern void *func_021FCE28(void *sess, int i);
extern void func_02082D44(void *src, void *dst, u32 size);
extern void *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045C04(void *bank);
extern void *func_020120F4(void *p);
extern void *func_02012EBC(void *p);
extern void *func_0200A5F8(void *p);

extern const char d_02172714[];

void func_0215611C(Work *w)
{
    Disp *d;
    struct RtcDate date;
    void *str;
    u8 tmp[4];
    u8 i;
    u8 j;
    u8 k;
    u8 a;
    u8 b;
    u8 max;
    u8 v;
    int n;
    void *x;
    Member *m;
    void *bank;
    u8 t;
    u8 t2;

    w->f34 = func_02030734(4, 0x14, 0, d_02172714, 0x312);
    w->f34->f08 = func_02030734(4, 0x1b0, 1, d_02172714, 0x313);
    w->f34->f04 = 0;
    w->f34->f10 = w->f28;
    d = w->f34->f08;
    func_0203F4E4(&date);
    d->a = func_02157364(w->f38);
    d->b = date.year;
    d->c = date.month;
    d->d = date.day;
    str = func_02156914(w, 4);
    func_02045A38(str, d->text, 0x25);
    func_02045808(str);
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
            x = func_02012944(w->f04);
        else if (w->f14 == 1)
            x = func_021FCE28(w->f28, func_021568E8(w, i));
        if (x != 0) {
            func_02082D44(x, d->recs[i].name, 0x10);
        } else {
            u8 val = func_02157384(w->f38, func_021568A8(w, func_021568E8(w, i)));

            bank = func_02045B38(0, 2, 0x4C, 4);
            str = func_02045EC0(bank, val);
            func_02045A38(str, d->recs[i].name, 8);
            func_02045808(str);
            func_02045C04(bank);
        }
        for (j = 0; j < 8; j++) {
            d->recs[i].ent[j].a = 0xFF;
            d->recs[i].ent[j].b = 0;
            d->recs[i].ent[j].c = 10;
        }
        for (k = 0; k < 9; k++) {
            if (m->recs[k].id != 0xFF) {
                Ent *e = &d->recs[i].ent[m->recs[k].idx];

                e->a = m->recs[k].id;
                e->b = m->recs[k].f2;
                e->c = k;
            }
        }
    }
    w->f34->f00 = 1;
    w->f34->f0c = func_0200A5F8(func_02012EBC(func_020120F4(w->f00)));
    for (i = 0; i < 4; i++) {
        tmp[i] = w->party->members[i]->total;
        w->f48[i] = i;
    }
    for (a = 0; a < 4; a++) {
        n = 4 - (a + 1);
        for (b = 0; b < n; b++) {
            if (tmp[b + 1] > tmp[b]) {
                t = tmp[b];
                tmp[b] = tmp[b + 1];
                tmp[b + 1] = t;
                t2 = w->f48[b + 1];
                w->f48[b + 1] = w->f48[b];
                w->f48[b] = t2;
            }
        }
    }
}
