/*
 * file:     scrcmd_musical_p08.c
 * unit:     yes
 * function: func_0215E364, func_0215E3A0, func_0215E3E4, func_0215E404, func_0215E428, func_0215E440, func_0215E580, func_0215E5B0, func_0215E6A8, func_0215E6F8, func_0215E724, func_0215E740, func_0215E7DC, func_0215E804, func_0215E840, func_0215EA14, func_0215EA30, func_0215EA38, func_0215EA58, func_0215EA6C, func_0215EA94, func_0215EAC8, func_0215EAF0, func_0215EB18, func_0215EB4C, func_0215EB60, func_0215EB88, func_0215EBBC, func_0215EBD0, func_0215EBF8, func_0215EC2C
 * address:  0x0215E364
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_02012984 0x02012984 thumb
 *   func_0200D488 0x0200D488 thumb
 *   func_0215E358 0x0215E358 thumb ov010
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D478 0x0200D478 thumb
 *   d_021711C6 0x021711C6 data a2
 *   func_0200D45C  0x0200D45C  thumb
 *   func_0200D50C  0x0200D50C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02008530  0x02008530  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0200D470  0x0200D470  thumb
 *   d_0217293C     0x0217293C  data
 *   func_0200D468 0x0200D468 thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201313C  0x0201313C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200D494  0x0200D494  thumb
 *   func_0200D480  0x0200D480  thumb
 *   func_020113D8 0x020113D8 thumb
 *   d_021711A8 0x021711A8 data ov010 a2
 *   func_0200D4B8  0x0200D4B8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3250  0x021A3250  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021A3128  0x021A3128  thumb  ov021
 *   func_021A3504  0x021A3504  thumb  ov021
 *   func_021A3524  0x021A3524  thumb  ov021
 *   func_021A35FC  0x021A35FC  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_0216E5B0  0x0216E5B0  thumb  ov010
 *   func_0215F118  0x0215F118  thumb  ov010
 *   func_02013C40  0x02013C40  thumb
 *   func_02013C50  0x02013C50  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014470  0x02014470  thumb
 *   func_021CD440  0x021CD440  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   func_0201400C  0x0201400C  thumb
 *   func_02014018  0x02014018  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_02012B70  0x02012B70  thumb
 *   d_021711EC     0x021711EC  data
 *   d_021711F4     0x021711F4  data
 *   func_0215F088  0x0215F088  thumb  ov010
 *   func_0215F0B8  0x0215F0B8  thumb  ov010
 *   func_0215F104  0x0215F104  thumb  ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_0201296C 0x0201296C thumb
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_02159058 0x02159058 thumb ov010
 *   func_021C6078 0x021C6078 thumb ov021
 */
#include "../../matched/include/Obj02057.h"
#include "../../matched/include/Obj12311.h"
#include "../../matched/include/Obj17698.h"
#include "../../matched/include/Obj12312.h"
#include "../../matched/include/Obj12313.h"
#include "../../matched/include/Obj12314.h"
#include "../../matched/include/Obj12315.h"

struct Big;
struct Blk38;
struct BigObj;
struct GdsEnt;
struct Blk37;
struct Mon;
struct Sub0200852CObj;
struct Rec44;
struct SaveBlock;
struct Actor;
struct Sub02014444Obj;
struct Ctx;
struct Obj00020;
struct Desc;
struct Obj;
struct Pair;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef struct Work {
    int f00;            /* 0x00 */
    int f04;            /* 0x04 */
    u8 pad08[0x8C - 0x08];
    int f8c;            /* 0x8C */
} Work;

struct Ent { u16 n; u8 v[4]; };

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Area {
    u16 x;
    u16 z;
    u16 w;
    u16 h;
} Area;

typedef struct Info {
    u16 id;             /* 0x00 */
    u16 flags;          /* 0x02 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    void *obj;          /* 0x0C */
    void *field;        /* 0x10 */
} Info;

typedef struct Query {
    u16 a;              /* 0x00 */
    u16 b;              /* 0x02 */
    u32 c;              /* 0x04 */
} Query;

typedef enum { B_FALSE, B_TRUE } Bool;

extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *);
extern u8 func_02012984(const struct BigObj *p);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern void func_0215E358(int a, int b, int c);
extern struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);
extern u8 func_0200D478(struct Blk38 *p, u32 i);
extern int func_0200D45C();
extern void func_0200D50C(struct GdsEnt *e, u32 i, u32 v);
extern u8 *func_02012944(void *p);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_0200CA10(void *save);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);
extern void func_0200D470(struct Blk38 *p, u32 i, u32 v);
extern u8 func_0200D468(struct Blk38 *p, u32 i);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern void *func_0201313C(void *p, int v);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02005728(u32 v);
extern void func_0200D494(struct GdsEnt *e);
extern void func_0200D480(struct Blk38 *p, u32 i, u8 v);
extern u32 func_020113D8(u32 b);
extern u32 func_0200D4B8(const struct GdsEnt *e, u32 i);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u16 func_02188C9C(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C7C(u8 *p);
extern u32 func_021A3098(u8 *p);
extern void *func_021A3250(void *q);
extern u16 func_021A3050(u8 *p);
extern u32 func_021A30C8(void **ctx);
extern u32 func_021A3128(u32 *a, u32 b);
extern int func_021A3504(u8 *a, int b, int c);
extern int func_021A3524(u8 *a, int b, int c);
extern void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c);
extern u16 func_0216D598(void *obj);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_0216E5FC(u16 kind);
extern int func_0216E5B0(void *map, const VecFx32 *pos);
extern int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field);
extern u32 func_02013C40(u32 id);
extern u32 func_02013C50(u32 id);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012B38(const struct BigObj *p);
extern u16 func_02014470(struct Sub02014444Obj *o);
extern int func_021CD440(void *field, u16 *out);
extern u32 func_02013FFC(u32 id);
extern u32 func_0201400C(u32 id);
extern u32 func_02014018(u32 id);
extern u32 func_02013E04(u32 id);
extern int func_02012B70(const struct BigObj *p);
extern int func_0215F088(u16 *p, int i);
extern int func_0215F0B8(u16 *p, int i);
extern int func_0215F104(int a0, int a1);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215F0E8(u32 *out, const struct Pair *in, u32 *ctx);
extern u32 func_0201296C(const struct BigObj *p);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_021C6078(void *, void *, u8);
void func_0215E364(void *a);
void func_0215E3A0(void *a);
u32 func_0215E3E4(void *p, u32 slot);
int func_0215E404(int a0);
void func_0215E428(int a0, int a1);
void func_0215E440(void *sys, u8 which);
void func_0215E580(void *a);
void func_0215E5B0(void *a0, Work *w);
int func_0215E6A8(void *a, int x);
int func_0215E6F8(int a0);
int func_0215E724(int species);
void func_0215E740(void *a, u32 b, u16 c, int d);
void func_0215E7DC(void *p,u32 i,u8 v,u32 n);
struct GdsEnt *func_0215E804(int a0, int a1);
void func_0215E840(void *field, Info *out);
int func_0215EA14(int a0, int a1);
void func_0215EA30(Query *q, u16 a, u16 b, u32 c);
int func_0215EA38(int a0, int a1, int a2);
int func_0215EA58(int a0, int a1);
void *func_0215EA6C(void *a,void *b);
int func_0215EA94(void *a,void *b,void *c);
int func_0215EAC8(int a0, int a1);
void *func_0215EAF0(void *a, void *b);
int func_0215EB18(void *a, int *state, void *b);
int func_0215EB4C(void *p);
void *func_0215EB60(void *a, void *b);
int func_0215EB88(void *a, int *state, void *b);
int func_0215EBBC(void *p);
void *func_0215EBD0(void *a, void *b);
int func_0215EBF8(void *a, int *state, void *b);
int func_0215EC2C(void *p);
void *func_0215EC40(u16 *a, void *b);
extern const u16 d_021711C6[];
extern const char d_0217293C[];
extern struct Ent d_021711A8[];
extern const Area d_021711EC;
extern const Area d_021711F4;

void func_0215E364(void *a)
{
    u8 i;
    void *q;
    void *p;
    p = func_0200D418(func_02012EBC(a));
    q = (void *)func_02012984(a);
    for (i = 0; i < 2; i++) {
        if (func_0200D488(p, i) != 0) func_0215E358((int)p, (int)q, i);
    }
}


void func_0215E3A0(void *a)
{
    u8 i;
    void *q;
    void *p;

    p = func_0200D418(func_02012EBC(a));
    q = (void *)func_02012984(a);
    for (i = 0; i < 2; i++) {
        func_0200D4AC(p, i);
        if (func_0200D488(p, i) != 0) {
            func_0215E358((int)p, (int)q, i);
        }
    }
}

u32 func_0215E3E4(void *p, u32 slot)
{
    u32 i = func_0200D478(p, slot);
    if (i > 16) return 319;
    return d_021711C6[i];
}


int func_0215E404(int a0)
{
    int a1;
    int t4;
    int t5;

t4 = a0 + 0;
t5 = 0;
loc_0215E40A:
a0 = t4 + 0;
a1 = t5 + 0;
    a0 = func_0200D488((struct Blk38 *)a0, a1);
loc_0215E412:
    if (a0 == 0) goto loc_0215E41A;
loc_0215E416:
a0 = 1;
    return a0;
loc_0215E41A:
a0 = t5 + 1;
a0 = a0 << 0x18;
t5 = (unsigned)a0 >> 0x18;
    if ((unsigned)t5 < (unsigned)2) goto loc_0215E40A;
loc_0215E424:
a0 = 0;
    return a0;}


void func_0215E428(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0215E404(a0);
loc_0215E432:
    if (a0 == 0) goto loc_0215E43E;
loc_0215E436:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0200D45C(a0, a1);
loc_0215E43E:
    return;}


/*
 * Hand out the legendary for slot `which` (Thundurus 642 or Tornadus
 * 641 at level 40): fill the event record, create the Pokemon into the
 * box, and mark the slot. Levers: level and the record flag assigned the
 * same value in both switch arms (the tail-merged assignments keep them
 * as variables: level spilled to the frame, the flag in r6), species as
 * u32 truncated at the call, `a` declared before `save`.
 */
void func_0215E440(void *sys, u8 which)
{
    void *a;
    void *save;
    void *rec;
    void *party;
    void *mon;
    u32 species;
    u16 level;
    u32 flag;

    save = func_02012EBC(sys);
    a = func_0200D418(save);
    rec = func_0200D4AC(a, which);
    switch (which) {
    case 0:
        species = 642;
        level = 40;
        flag = 1;
        break;
    case 1:
        species = 641;
        level = 40;
        flag = 1;
        break;
    default:
        return;
    }
    func_0200D50C(rec, 4, species);
    func_0200D50C(rec, 6, level);
    func_0200D50C(rec, 9, flag);
    party = func_02012944(sys);
    mon = func_02030734(0x8003, func_020173EC(), 1, d_0217293C, 0x12E);
    func_02017588(mon, species, level, func_02008530(party), 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
    func_0200D50C(rec, 7, 0);
    func_0200D50C(rec, 8, 1);
    func_0200D50C(rec, 2, func_02017E1C(mon, 0xAC, 0));
    func_0200D50C(rec, 3, func_02017E1C(mon, 0, 0));
    func_0200D50C(rec, 10, func_02017E1C(mon, 0x70, 0));
    func_0200D50C(rec, 5, func_02017E1C(mon, 0xA1, 0));
    func_0200CFA0(func_0200CA10(save), mon);
    func_020307B0(mon);
    func_0215E740(a, (u32)((void *)func_02012984(sys)), which, 5);
    func_0200D470(a, which, 1);
}

void func_0215E580(void *a)
{
 int i;
 void *p = func_0200D418(func_02012EBC(a));
 for(i=0;i<2;i++) {
  if(func_0200D468(p,(u8)i)==2) func_0215E440(a,i);
 }
}


/*
 * Reads species (5), a word at 0xA0 and a byte at 0x9D of the lead party
 * member, looks up a record for the species (func_0215E804) and either
 * rolls a 30% chance of func_0215E364 when there is none, sets one of two
 * states on it for modes 1-2 (with field 0xA0 clear) or 5, or copies the two
 * values into it and calls func_0215E364.
 *
 * MATCH, bytes exact. Blocker: func_0201313C (arm9, Thumb) is an unlabelled
 * leaf (a .word after func_02013128's pool), so neither label nor
 * sole-ref/code reaches it. It is EXACT from
 *     void *func_0201313C(void *p, int i)
 *     { return ((void **)((char *)p + 0x24))[i]; }
 * as src/matched/arm9/func_0201313C.c (pkt_0201313C), outside this ov lane's
 * write set; once that shard exists this file verifies EXACT.
 * The local declaration order (mon, species, v, idx, tbl, b) is load-bearing.
 *
 * 2026-10-05 (wave D8): The arm9 leaf func_0201313C now has an EXACT witness src/matched/arm9/func_0201313C.c (pkt_0201313C); once its shard exists this file verifies EXACT.
 */
void func_0215E5B0(void *a0, Work *w)
{
    void *mon;
    u16 species;
    u16 v;
    u32 idx;
    void *tbl;
    u8 b;

    if (w->f04 != 0 || w->f00 != 0) {
        return;
    }
    func_02012AC8(func_020127A4(a0));
    mon = func_0201AB28(func_0201313C(w, 1), 0);
    species = func_02017E1C(mon, 5, 0);
    v = func_02017E1C(mon, 0xA0, 0);
    b = func_02017E1C(mon, 0x9D, 0);
    tbl = func_0200D418(func_02012EBC(a0));
    mon = func_0215E804((int)tbl, species);
    if (mon == 0) {
        if (func_02005728(100) < 30) {
            func_0215E364(a0);
        }
        return;
    }
    idx = func_0215E724(species);
    if ((w->f8c == 1 || w->f8c == 2) && v == 0) {
        func_0200D494(mon);
        func_0200D480(tbl, idx, 0x10);
        func_0200D470(tbl, idx, 2);
        return;
    }
    if (w->f8c == 5) {
        func_0200D494(mon);
        func_0200D480(tbl, idx, 0x10);
        func_0200D470(tbl, idx, 3);
        return;
    }
    func_0200D50C(mon, 5, v);
    func_0200D50C(mon, 7, b);
    func_0215E364(a0);
}


int func_0215E6A8(void *a, int x)
{
    u8 i;
    void *p;

    p = func_0200D418(func_02012EBC(a));
    i = 0;
    if (func_0200D488(p, 0) != 0 && x == func_0215E3E4(p, i)) {
        return 6;
    }
    i = 1;
    if (func_0200D488(p, 1) != 0 && x == func_0215E3E4(p, i)) {
        return 7;
    }
    return 0xffff;
}


int func_0215E6F8(int a0)
{
    int a1;
    int t4;
    void *p;
    void *t5;

    p = func_02012EBC((struct Big *)a0);
loc_0215E6FE:
    t5 = func_0200D418(p);
loc_0215E702:
a1 = 0;
t4 = 0;
    a0 = func_0200D488(t5, a1);
loc_0215E70C:
    if (a0 != 0) goto loc_0215E71C;
loc_0215E710:
a1 = 1;
    a0 = func_0200D488(t5, a1);
loc_0215E718:
    if (a0 == 0) goto loc_0215E720;
loc_0215E71C:
a0 = 1;
    return a0;
loc_0215E720:
a0 = t4 + 0;
    return a0;}

int func_0215E724(int species)
{
    switch(species) {
    case 642: return 0;
    case 641: return 1;
    }
    return 2;
}

/*
 * Lever: slot c is u16 in the function and both receiving externs,
 * causing its immediate home reload; the selected byte remains u8.
 */
void func_0215E740(void *a, u32 b, u16 c, int d)
{
    struct Ent *e;
    int s;
    u8 buf[4];
    u8 w;
    int v;
    int k;
    int i;
    s = func_0200D478(a, c);
    e = &d_021711A8[(u16)func_020113D8(b)];
    if (s != 0x10 && func_02005728(100) < 20) {
        func_0215E7DC(a, c, 0x10, 0xffff);
        return;
    }
    k = 0;
    for (i = 0; i < e->n; i++) {
        v = e->v[i];
        if (v != s && v != d) {
            buf[k++] = v;
        }
    }
    w = buf[func_02005728(k)];
    func_0215E7DC(a, c, w, w > 0x10 ? 0x13f : d_021711C6[w]);
}

void func_0215E7DC(void *p,u32 i,u8 v,u32 n)
{
 void *rec = func_0200D4AC(p,i);
 func_0200D480(p,i,v);
 func_0200D50C(rec,1,n);
}


struct GdsEnt *func_0215E804(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    struct GdsEnt *t7;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
loc_0215E80C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0200D488((struct Blk38 *)a0, a1);
loc_0215E814:
    if (a0 == 0) goto loc_0215E830;
loc_0215E818:
a0 = t5 + 0;
a1 = t4 + 0;
    t7 = func_0200D4AC((struct Blk38 *)a0, a1);
loc_0215E820:
a1 = 4;
    a0 = func_0200D4B8(t7, a1);
loc_0215E828:
    if (t6 != a0) goto loc_0215E830;
loc_0215E82C:
    return t7;
loc_0215E830:
a0 = t4 + 1;
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
    if ((unsigned)t4 < (unsigned)2) goto loc_0215E80C;
loc_0215E83A:
    return 0;}


/*
 * Fill the 0x14-byte Info for the field: id, the ov021 handles, and the
 * flags word from the object kind, the map tests and the save flags.
 * One lever: the u16 for func_021CD440 is declared before x (stack order).
 */
void func_0215E840(void *field, Info *out)
{
    VecFx32 pos;
    u16 v;
    u16 x;
    u16 y;
    u16 z;
    void *q;
    void *obj;
    void *map;
    u16 kind;
    u32 a;
    u32 b;
    u32 c;

    MI_CpuFill8(out, 0, sizeof(Info));
    out->id = func_02188C9C(field);
    out->f08 = (u32)func_02188C80(field);
    out->field = field;
    q = func_02188CB4(field);
    out->f04 = func_021A3098(q);
    obj = func_021A3250(q);
    out->obj = obj;
    if (obj != 0) {
        kind = func_0216D598(obj);
        map = func_02188C7C(field);
        func_0216D88C(obj, &pos);
        if (func_0216E5FC(kind) && func_0216E5B0(map, &pos) == 0)
            out->flags |= 8;
        if (kind == 0x6C)
            out->flags |= 1;
    }
    a = func_021A3050(q);
    b = func_021A30C8(q);
    c = func_021A3128(q, a);
    if (func_021A3504((u8 *)q, b, c) == 1)
        out->flags |= 2;
    if (func_021A3524((u8 *)q, b, c) == 1)
        out->flags |= 4;
    if (func_02013C40(out->id) == 1) {
        out->flags |= 0x10;
        out->flags |= 0x40;
    }
    if (func_02013C50(out->id) == 1)
        out->flags |= 0x80;
    if (func_02014470(func_02012B38(func_020120F4((const struct Ctx *)out->f08))) & 1)
        out->flags |= 0x20;
    if (func_021CD440(field, &v) == 1)
        out->flags |= 0x400;
    if (func_02013FFC(out->id)) {
        func_021A35FC(func_02188CB4(out->field), &x, &y, &z);
        if (func_0201400C(out->id) && func_0215F118(&d_021711EC, x, z, 0x113, field))
            out->flags |= 0x20;
        if (func_02014018(out->id) && func_0215F118(&d_021711F4, x, z, 0x112, field))
            out->flags |= 8;
    }
    if (func_02013E04(out->id) == 0) {
        out->flags = 0;
    } else {
        out->flags |= 0x100;
        out->flags |= 0x200;
    }
    if (func_02012B70(func_020120F4((const struct Ctx *)out->f08)) == 1)
        out->flags = 0;
}


int func_0215EA14(int a0, int a1)
{
    int a2;
    int t4;

a2 = a0 + 0;
t4 = a1 + 0;
a0 = t4 + 0;
a1 = a2 + 0;
    a0 = func_0215F088((u16 *)a0, a1);
loc_0215EA22:
a1 = a0 + 0;
    if (a1 != 0) goto loc_0215EA2A;
loc_0215EA26:
a0 = 1;
    return a0;
loc_0215EA2A:
a0 = t4 + 0;
    a0 = ((int (*)())a1)(a0);
loc_0215EA2E:
    return a0;}


/*
 * Unlabelled leaf after func_0215E840's pool (bl from 0x0215FE3C).
 */
void func_0215EA30(Query *q, u16 a, u16 b, u32 c)
{
    q->a = a;
    q->b = b;
    q->c = c;
}


int func_0215EA38(int a0, int a1, int a2)
{
    int a3;
    int t4;
    int t5;

a3 = a0 + 0;
t4 = a2 + 0;
t5 = a1 + 0;
a0 = t4 + 0;
a1 = a3 + 0;
    a0 = func_0215F0B8((u16 *)a0, a1);
loc_0215EA48:
a2 = a0 + 0;
    if (a2 != 0) goto loc_0215EA50;
loc_0215EA4C:
a0 = 0;
    return a0;
loc_0215EA50:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = ((int (*)())a2)(a0, a1);
loc_0215EA56:
    return a0;}


int func_0215EA58(int a0, int a1)
{
    int t4;

a1 = 0;
t4 = 0;
    a0 = func_0215F104(a0, a1);
loc_0215EA62:
    if (a0 != 0) goto loc_0215EA68;
loc_0215EA66:
t4 = 1;
loc_0215EA68:
a0 = t4 + 0;
    return a0;}

void *func_0215EA6C(void *a,void *b)
{
 void *t = func_020122C0(((struct Obj02057 *)b)->f8,0,func_0215EA94,20);
 func_0215F0E8(func_020124E8(t),a,b);
 return t;
}

int func_0215EA94(void *a,void *b,void *c)
{
 int h;
 int t;
 func_0201296C(func_020120F4(((struct Obj12311 *)c)->f8));
 h = ((struct Obj12311 *)c)->fC;
 t = func_021587B0((int)a,0x2715,0,0);
 func_02159058(t,h,0,0,0);
 return 0;
}


int func_0215EAC8(int a0, int a1)
{
    int t4;

a1 = ((struct Obj17698 *)a0)->f4;
    if (a1 != 2) goto loc_0215EAD4;
loc_0215EAD0:
a0 = 4;
    return a0;
loc_0215EAD4:
    if (a1 != 3) goto loc_0215EADC;
loc_0215EAD8:
a0 = 1;
    return a0;
loc_0215EADC:
a1 = 1;
t4 = 1;
    a0 = func_0215F104(a0, a1);
loc_0215EAE4:
    if (a0 == 0) goto loc_0215EAEA;
loc_0215EAE8:
t4 = 0;
loc_0215EAEA:
a0 = t4 + 0;
    return a0;}

void *func_0215EAF0(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215EB18, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}

/*
 * Interface: 021587B0 returns its final ldr r0,[r4] at 021587DC;
 * caller consumes that result despite older callers declaring void.
 */
int func_0215EB18(void *a, int *state, void *b)
{
    int h;
    int t;
    func_0201296C(func_020120F4(((struct Obj12312 *)b)->f8));
    h = ((struct Obj12312 *)b)->fC;
    t = func_021587B0((int)a, 0x2713, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}

int func_0215EB4C(void *p)
{
    return func_0215F104((int)p, 2) != 0 ? B_FALSE : B_TRUE;
}

void *func_0215EB60(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215EB88, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}

int func_0215EB88(void *a, int *state, void *b)
{
    int h;
    int t;
    func_0201296C(func_020120F4(((struct Obj12313 *)b)->f8));
    h = ((struct Obj12313 *)b)->fC;
    t = func_021587B0((int)a, 0x2717, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}

int func_0215EBBC(void *p)
{
    return func_0215F104((int)p, 3) != 0 ? B_FALSE : B_TRUE;
}

void *func_0215EBD0(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215EBF8, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}

int func_0215EBF8(void *a, int *state, void *b)
{
    int h;
    int t;
    func_0201296C(func_020120F4(((struct Obj12314 *)b)->f8));
    h = ((struct Obj12314 *)b)->fC;
    t = func_021587B0((int)a, 0x2711, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}

int func_0215EC2C(void *p)
{
    return func_0215F104((int)p, 8) != 0 ? B_FALSE : B_TRUE;
}

void *func_0215EC40(u16 *a, void *b)
{
    return func_021C6078(((struct Obj12315 *)b)->f8, ((struct Obj12315 *)b)->f10, *a);
}
