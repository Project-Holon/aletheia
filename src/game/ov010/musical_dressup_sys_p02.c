/*
 * file:     musical_dressup_sys_p02.c
 * unit:     yes
 * function: func_0215611C
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
	unsigned short id;
	short f2;
	unsigned char idx;
	unsigned char pad5[0x1];
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
	unsigned int f00;
	unsigned int f04;
	Disp *f08;
	void *f0c;
	void *f10;
	unsigned char pad14[0x34];
	int f48;
	int f4c;
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
struct Big;
struct Ctx;
struct MsgBank;
struct Table;
struct U16Vec;
extern u8 func_02157364(char *a0);
extern void *func_02156914(int a0, int a1);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void func_02045808(struct U16Vec *vec);
extern u8 func_021568E8(Work *w, u8 idx);
extern u8 func_021568A8(Work *w, u8 n);
extern u8 func_02157384(struct Table *, int);
extern u8 *func_02012944(void *p);
extern int func_021FCE28(char *, u32);
extern void func_02082D44(void *src, void *dst, u32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A5F8(void *p);

extern const char d_02172714[];

void func_0215611C(struct Work *w){
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
    str = func_02156914((int)w, 4);
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
            x = (void *)func_021FCE28(w->f28, func_021568E8(w, i));
        if (x != 0) {
            func_02082D44(x, d->recs[i].name, 0x10);
        } else {
            u8 val = func_02157384(w->f38, func_021568A8(w, func_021568E8(w, i)));

            bank = func_02045B38(0, 2, 0x4C, 4);
            str = func_02045EC0(bank, val);
            func_02045A38(str, (u16 *)d->recs[i].name, 8);
            func_02045808(str);
            func_02045C04(bank);
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
    w->f34->f0c = func_0200A5F8(func_02012EBC(func_020120F4(w->f00)));
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
