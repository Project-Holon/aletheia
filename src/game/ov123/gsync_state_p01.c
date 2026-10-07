/*
 * file:     gsync_state_p01.c
 * unit:     yes
 * function: func_021D4240, func_021D4244, func_021D424C, func_021D4384, func_021D43B8, func_021D4440, func_021D449C, func_021D44F4, func_021D451C, func_021D45F0, func_021D45F4, func_021D4730, func_021D4778, func_021D478C, func_021D4884
 * address:  0x021D4240
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DA690 0x021DA690 data a4
 *   d_021DA6B0 0x021DA6B0 data a4
 *   d_021DA6D0 0x021DA6D0 data a4
 *   d_021DA6F0 0x021DA6F0 data a4
 *   d_021DA710 0x021DA710 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_021D4AB4 0x021D4AB4 thumb ov123
 *   func_020414EC 0x020414EC arm
 *   func_021D4FB8 0x021D4FB8 thumb ov123
 *   func_021D4A04 0x021D4A04 thumb ov123
 *   func_021D4D40 0x021D4D40 thumb ov123
 *   func_021D4E7C 0x021D4E7C thumb ov123
 *   func_021D4DA4 0x021D4DA4 thumb ov123
 *   func_0204BA10 0x0204BA10 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020452E8 0x020452E8 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021D4EF0 0x021D4EF0 thumb ov123
 *   func_021D4FAC 0x021D4FAC thumb ov123
 *   func_021D4AFC 0x021D4AFC thumb ov123
 *   func_0201DD68  0x0201DD68  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021DA638 0x021DA638 data a1
 *   d_021DA634 0x021DA634 data a1
 *   d_021DA63C 0x021DA63C data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   d_021DA9D0 0x021DA9D0 data a4
 */
#include "../../matched/include/Obj00273.h"
#include "../../matched/include/Obj00471.h"
#include "../../matched/include/Obj13968.h"

struct Ctx;
struct Comm;
struct TaskMenu;
struct Actor;
struct Descriptor;
struct MsgBank;
struct Obj;
struct Cfg;
struct CharBuf;
struct StrObj;
struct GfFont;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct BgTemplate {
    u32 unk_00, unk_04, bufSize, unk_0c;
    u8 unk_10, unk_11, unk_12, unk_13;
    u32 unk_14;
    u8 unk_18, unk_19, unk_1a, unk_1b;
    u32 unk_1c;
};

typedef struct {
    char pad00[8];
    int f08;
    u16 f0c;
    char pad0e[0x256];
    void *f264;
    char pad268[0x24];
    int f28c;
} Object_021D4440;

typedef short          s16;

typedef struct {
    u32 a, b, c, d;
} Rec;

typedef struct {
    u8 pad0[0xC];
    u16 heap;
    u8 pad1[2];
    void *obj[4];
    void *res;
    void *bank;
    u8 pad2[8];
    void *font;
    u8 pad3[4];
    void *str;
    u8 pad4[0x25C - 0x3C];
    int n;
} Own;

typedef struct {
    char pad00[0x10];
    void *f10[4];
    void *f20;
    char pad24[0x238];
    int f25c;
} Object_021D4730;

typedef struct Callback Callback;

struct Callback { u32 first; int (*run)(void *,Callback *); };

struct Point { u16 x, y, z; u8 a, b; };

struct Triple { u8 v[3]; };

typedef signed int     s32;

extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_0204047C(int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);
extern void func_0202F038(u8 *);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern int func_0203CD98(void);
extern u32 func_02012138(const struct Ctx *p);
extern void func_02026400(struct Comm *p);
extern void func_021D4AB4(char *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_020414EC(u32 i);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D4FB8(char *p);
extern void func_021D4A04(char *p);
extern void func_021D4D40(char *, int);
extern int func_021D4E7C(char *);
extern void func_021D4DA4(char *);
extern void func_0204BA10(struct Actor *a);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_020452E8(struct Descriptor *d);
extern int func_02085D3C(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D4EF0(char *, int, int);
extern void func_021D4FAC(char *);
extern void func_021D4AFC(char *p);
extern void func_0201DD68(void);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02051C6C(void *p);
extern void func_02041B6C(u32 bit);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void *func_0201F5DC(void *, u32, u32, u32);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_021D4240(void **p, void *f);
void func_021D4244(char *p,void *f,int line);
void func_021D424C(char *a0);
void func_021D4384(u8 *p);
void func_021D43B8(u16 *p, const u16 *add, int n);
void func_021D4440(Object_021D4440 *p);
void func_021D449C(char *p);
void func_021D44F4(char *p);
void func_021D451C(char *p);
void func_021D45F0(void);
void func_021D45F4(int count, u32 *tbl, Own *owner, Rec *recs, u32 *xs, u32 *ys);
void func_021D4730(Object_021D4730 *p);
void func_021D4778(void *p,int flag,Callback *q);
void func_021D478C(char *p);
void func_021D4884(char *p);
extern const struct BgTemplate d_021DA690, d_021DA6B0, d_021DA6D0, d_021DA6F0, d_021DA710;
extern const struct Triple d_021DA638, d_021DA634, d_021DA63C;
extern const char d_021DA9D0[];

void func_021D4240(void **p, void *f)
{
    *p=f;
}

void func_021D4244(char *p,void *f,int line) { func_021D4240((void **)p,f); }

void func_021D424C(char *a0)
{
    struct BgTemplate b[5];
    b[4] = d_021DA690;
    func_0203FCA0(0, &b[4], 0);
    func_020414AC(0);
    func_020409B4(0);
    func_0204047C(0, 0);
    func_02040588(0, 1);
    b[3] = d_021DA6B0;
    func_0203FCA0(4, &b[3], 0);
    func_02040588(4, 1);
    func_020409B4(4);
    b[2] = d_021DA6D0;
    func_0203FCA0(5, &b[2], 0);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 32, 32, 17);
    func_020409B4(5);
    func_02040588(5, 1);
    b[1] = d_021DA6F0;
    func_0203FCA0(6, &b[1], 0);
    func_02040588(6, 1);
    func_020409B4(6);
    b[0] = d_021DA710;
    func_0203FCA0(7, &b[0], 0);
    func_02040588(7, 1);
    func_020409B4(7);
}

void func_021D4384(u8 *p) { if(*(u8 * *)&((struct Obj00273 *)p)->f288) { func_0202F038(*(u8 * *)&((struct Obj00273 *)p)->f288); *(u32 *)&((struct Obj00273 *)p)->f288=0; } *(u8 * *)&((struct Obj00273 *)p)->f288=func_0202EE8C(((struct Obj00273 *)p)->f230,((struct Obj00273 *)p)->f224,15,16,((struct Obj00273 *)p)->fC); }

void func_021D43B8(u16 *p, const u16 *add, int n)
{
    int i, j;
    u16 *row;
    u16 r, g, b;
    for (i = 0; i < n; i++) {
        row = p + i * 16;
        for (j = 0; j < 16; j++) {
            r = row[j] & 31;
            g = (row[j] & 0x3e0) >> 5;
            b = (row[j] & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            row[j] = r + (g << 5) + (b << 10);
        }
    }
}

void func_021D4440(Object_021D4440 *p)
{
    p->f28c = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, p->f0c);
    switch (p->f08) {
    case 2:
    case 3:
        if (func_0203CD98())
            func_02026400((struct Comm *)func_02012138(p->f264));
        break;
    }
    func_021D4244((char *)p, func_021D4AB4, 0x1aa);
}

void func_021D449C(char *p)
{
    if (func_020279E8(((struct Obj00273 *)p)->f238)) {
        if (!func_02027A04(((struct Obj00273 *)p)->f238)) {
            func_021D4244(p, func_021D4FB8, 0x1b6);
        } else {
            func_020414EC(5);
            ((struct Obj00273 *)p)->f8 = 0;
            func_021D4244(p, func_021D4A04, 0x1bb);
        }
        func_02027858(((struct Obj00273 *)p)->f238);
        *(int *)&((struct Obj00273 *)p)->f238 = 0;
        func_021D4D40(p, 0);
    }
}

void func_021D44F4(char *p) { if(func_021D4E7C(p)) { func_021D4DA4(p); func_021D4244(p,func_021D449C,0x1c9); } }

/*
 * extent: follower 021D45F0 already filed separately.
 */
void func_021D451C(char *p)
{
    func_0204BA10(*(void **)(p + ((struct Obj00273 *)p)->f270 * 4 + 0x2a0));
    func_0204B92C(*(void **)(p + ((struct Obj00273 *)p)->f270 * 4 + 0x2a0), 0);
    if (((struct Obj00273 *)p)->f8 == 3) {
        if (((struct Obj00273 *)p)->f224) {
            func_020452E8(((struct Obj00273 *)p)->f224);
            ((struct Obj00273 *)p)->f224 = 0;
        }
        if (func_02085D3C()) {
            func_02045CAC(((struct Obj00273 *)p)->f28, 0x20, ((struct Obj00273 *)p)->f38);
            func_021D4EF0(p, 10, 0);
            func_021D4D40(p, 1);
            func_021D4244(p, func_021D4AFC, 0x1df);
        } else {
            func_02045CAC(((struct Obj00273 *)p)->f24, 7, ((struct Obj00273 *)p)->f38);
            func_021D4FAC(p);
            func_021D4D40(p, 1);
            func_021D4244(p, func_021D44F4, 0x1e6);
        }
    } else if (((struct Obj00273 *)p)->f8 == 2 || ((struct Obj00273 *)p)->f8 == 3) {
        func_021D4244(p, func_021D4FB8, 0x1f2);
    } else {
        func_021D4244(p, func_021D4440, 0x1f5);
    }
}

/*
 * extent: bx lr callback stub, two zero alignment bytes, then labelled func_021D45F4.
 */
void func_021D45F0(void) {}


/*
 * note 2026-10-05 (wD6 lane17): closed by the real callee prototypes: func_0201DD68 takes no
 *   argument (so count is spilled and reloaded for the +0x25C store) and the record pointer is not
 *   const (the a/b/c loads stay after the outgoing stack-argument stores).
 */
void func_021D45F4(int count, u32 *tbl, Own *owner, Rec *recs, u32 *xs, u32 *ys)
{
    int i;
    int j;
    int a;
    int b;

    owner->n = count;
    func_0201DD68();
    for (i = 0; i < 4; i++) {
        if (owner->obj[i] != 0) {
            func_020456F8(owner->obj[i]);
            func_0201F7A8(owner->obj[i], 2);
            func_020452E8(owner->obj[i]);
        }
        owner->obj[i] = 0;
    }
    func_02049B40(0x17, 5, 4, 0x100, 0x20, owner->heap);
    for (j = 0; j < count; j++) {
        Rec *r = &recs[j];
        owner->obj[j] = (void *)func_020450F0(7, (u8)r->a, (u8)r->b, (u8)r->c, (u8)r->d, 8, 0);
        func_02043B5C(func_02045770(owner->obj[j]), 0);
        func_02045CAC(owner->bank, tbl[j], owner->str);
        func_0201DD78(0xF, 2, 0);
        if (xs != 0)
            a = xs[j] - func_0201D304(owner->str, (u32)owner->font, 0) / 2;
        else
            a = 0;
        if (ys != 0)
            b = ys[j] - func_0201D42C(owner->str, owner->font) / 2;
        else
            b = 0;
        func_0201C7A4(func_02045770(owner->obj[j]), (s16)a, (s16)b, owner->str, owner->font);
        func_02045334(owner->obj[j]);
        func_02045374(owner->obj[j]);
    }
    if (owner->res != 0)
        func_02051C6C(owner->res);
    owner->res = 0;
    func_020409B4(7);
}

void func_021D4730(Object_021D4730 *p)
{
    int i;
    if (p->f20)
        func_02051C6C(p->f20);
    p->f20 = 0;
    for (i = 0; i < 4; i++) {
        if (p->f10[i]) {
            func_020456F8(p->f10[i]);
            func_02041B6C(5);
            func_0201F7A8(p->f10[i], 2);
            func_020452E8(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    p->f25c = 0;
}

void func_021D4778(void *p,int flag,Callback *q) { if(flag) return; if(!q->run) return; if(q->run(p,q)) return; }

/*
 * lever: seven independent offset locals each receive 0x2ac then their final literal; both spill stores survive.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`o1 = 0x2ac;` before `o1 = 0x294;`; `o2 = 0x2ac;` before `o2 = 0x290;`
 * and 5 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021D478C(char *p)
{
    struct Triple x, y, z;
    struct Point pt;
    int i;
    int o1, o2, o3, o4, o5, o6, o7;
    x = d_021DA638;
    y = d_021DA634;
    z = d_021DA63C;
    i = 0;
    o1 = 0x294;
    o2 = 0x290;
    o3 = 0x298;
    o4 = 0x2a0;
    o5 = 0x2a0;
    o6 = 0x2a0;
    o7 = 0x2a0;
    for (; i < 3; i++) {
        pt.x = x.v[i]; pt.y = y.v[i]; pt.z = z.v[i];
        pt.a = 0; pt.b = 2;
        *(void **)(p + i * 4 + o4) = func_0204B294((void *)((struct Obj00471 *)p)->f2AC, (unsigned int)*(void **)(p + o1), *(u32 *)(p + o2), *(u32 *)(p + o3), &pt, 1, ((struct Obj00471 *)p)->fC);
        func_0204B92C(*(void **)(p + i * 4 + o5), 0);
        func_0204B3DC(*(void **)(p + i * 4 + o6), 1);
        func_0204B688(*(void **)(p + i * 4 + o7), 1);
    }
}

/*
 * interface: 02049990 arg5 is u16 at both original call-site truncations; 02049F78 arg3 is an unchanged address payload passed to 02062A98, whose body stores through it.
 */
void func_021D4884(char *p)
{
    void *h;
    void *allocated;
    void *record;
    ((struct Obj00471 *)p)->f38 = func_020457B0(300, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f30 = func_0201D7EC(23, 0, 0, 0, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f24 = func_02045B38(0, 2, 39, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f28 = func_02045B38(0, 2, 232, ((struct Obj00471 *)p)->fC);
    h = func_020490F4((u32)((void *)29), ((struct Obj00471 *)p)->fC);
    func_02049B68(h, 1, 4, 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049B68(h, 0, 0, 0, 0, ((struct Obj00471 *)p)->fC);
    allocated = func_02049F78(h, 1, (u32)(&record), ((struct Obj00471 *)p)->fC);
    func_02082D44(((struct Obj13968 *)record)->fC, p + 0x44, 0xe0);
    func_02082D44(((struct Obj13968 *)record)->fC, p + 0x124, 0xe0);
    func_021D43B8((u16 *)(p + 0x124), (const u16 *)d_021DA9D0, 7);
    func_020307B0(allocated);
    ((struct Obj00471 *)p)->f40 = func_02049740(h, 4, 4, 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049990(h, 9, 4, 0, (u16)(((struct Obj00471 *)p)->f40), 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049990(h, 14, 6, 0, (u16)(((struct Obj00471 *)p)->f40), 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049238(h);
    ((struct Obj00471 *)p)->f3C = func_0201F5DC((void *)5, 12, 0, ((struct Obj00471 *)p)->fC);
    func_02049B40(23, 5, 4, 0x1a0, 32, ((struct Obj00471 *)p)->fC);
    h = func_020490F4((u32)((void *)29), ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f294 = (void *)func_0204A6C8(h, 5, 0, 1, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f290 = (void *)func_0204AC18(h, 3, 1, 0, 0, 10, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f298 = (void *)func_0204AF28(h, 7, 16, ((struct Obj00471 *)p)->fC);
    func_02049238(h);
    func_021D478C(p);
}
