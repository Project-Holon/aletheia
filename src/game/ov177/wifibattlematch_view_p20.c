/*
 * file:     wifibattlematch_view_p20.c
 * unit:     yes
 * function: func_021E7DF0, func_021E7E08, func_021E7E0C, func_021E7E3C, func_021E82BC, func_021E8338
 * address:  0x021E7DF0
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../../matched/include/Obj06583.h"

struct Obj;
struct Cfg;
struct Descriptor;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct StrObj;
struct Vec2;
struct Actor;
struct PtS;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { short x, y; } Pos;

typedef struct { short x, y; u16 id; u8 a, flag; } Request;

typedef struct { void *win; u8 shown; } Entry;

typedef struct {
    void *pal;
    void *chr[7];
    void *cell;
    void *chrB;
    void *palB;
    void *cellB;
    void *spr[14];
    void *win[6];
    Entry ent[6];
    unsigned count;
    short base[14];
} Work_021E7E3C;

typedef signed int     s32;

typedef struct {
    char pad0[0x30];
    void *obj[14];
    char pad68[0xb0 - 0x68];
    unsigned count;
    short base[14];
} Work_021E8338;

extern void func_0204B3B4(struct Obj *p);
extern u32 func_020307B0(void *p);
extern void func_020061E4(unsigned se);
extern void func_020061F8(int i);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_02030734(unsigned heap, unsigned size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0200BAF4(int a0, int a1);
extern void func_0204989C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, u16 flags);
extern void *func_020490F4(unsigned int id, unsigned heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern unsigned func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern void *func_020185F4(void *);
extern unsigned func_0201BA68(void *);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *);
extern unsigned func_020275E4(void);
extern unsigned func_02027694(void);
extern u32 func_0202769C(u32 i);
extern u32 func_020276A0(u32 i);
extern unsigned func_02027698(void);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void *func_0204B294(void *, void *, void *, void *, const Request *, unsigned short, unsigned);
extern int func_0201BBE8(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void *func_0201EC64(u16);
extern void *func_020457B0(unsigned capacity, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_02045770(struct Descriptor *win);
extern void func_0201C724(unsigned print, void *bmp, short x, short y, void *str, unsigned font, u16 color);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0207D63C(int, int, int, int, int);
extern void func_020456F8(struct Descriptor *d);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_020407E8(u32 layer);
extern int func_0209C2B0(int, int);
extern void func_02041EE4(u32 index, u32 a, u32 b);
void func_021E7DF0(int *p);
void func_021E7E08(int p);
void func_021E7E0C(void **p, int on);
Work_021E7E3C *func_021E7E3C(void *src, void *owner, int unused, unsigned font, unsigned print, void *msg, unsigned heap);
void func_021E82BC(char *p);
int func_021E8338(Work_021E8338 *p);
extern const char d_021E8DBC[];


void func_021E7DF0(int *p)
{
    func_0204B3B4((struct Obj *)(*(int *)((char *)p + 4)));
    func_0204B3B4((struct Obj *)(*(int *)p));
    func_020307B0(p);
}

/*
 * extent: bx lr followed by two bytes zero alignment and existing labelled 021E7E0C.
 */
void func_021E7E08(int p) {}

void func_021E7E0C(void **p, int on)
{
    if (on == 1) {
        func_020061E4(0x80D);
    } else {
        func_020061F8(2);
    }
    func_0204B3DC(p[0], on);
    func_0204B3DC(p[1], on);
}

static inline unsigned HeapTemp(unsigned heap)
{
    heap &= 0x7FFF;
    heap |= 0x8000;
    return heap;
}

/*
 * The temporary heap id is formed twice: once through an inline that
 * rewrites its own parameter (the image copies heap before the and), held
 * in r7 for the first block; then as a plain expression, which the
 * compiler CSEs into a temporary slot below the loop pointers. One shared
 * expression or one shared local CSEs both blocks together.
 */
Work_021E7E3C *func_021E7E3C(void *src, void *owner, int unused, unsigned font, unsigned print, void *msg, unsigned heap)
{
    Work_021E7E3C *work;
    void *party;
    void *handle;
    void *mon;
    u8 x;
    void *fmt;
    void *buf;
    void *sLevel;
    void *sMale;
    void *sFemale;
    void *win;
    u8 level;
    int i;
    unsigned h;
    Request req;
    Request req2;
    Pos pos;
    work = func_02030734(heap, sizeof(Work_021E7E3C), 0, d_021E8DBC, 0xC8A);
    func_02082BCC(work, 0, sizeof(Work_021E7E3C));
    h = HeapTemp(heap);
    party = func_0200BAF4((int)src, (u16)h);
    func_0204989C((int)0x85, (int)7, (int)2, (int)0, (int)0, (int)0, h);
    handle = func_020490F4(7, (unsigned)heap);
    work->pal = (void *)func_0204ACEC(handle, func_0201BC3C(), 0, 0xA0, h);
    work->cell = (void *)func_0204AF28(handle, func_0201BC40(), func_0201BCB4(), (u16)h);
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, (int)i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            work->chr[i] = (void *)func_0204A6C8(handle, func_0201BA68(func_020185F4(mon)), 0, 0, h);
        }
    }
    func_02049238(handle);
    handle = func_020490F4(func_020275E4(), (unsigned)heap);
    work->chrB = (void *)func_0204AC18(handle, func_02027694(), 0, 0x100, 0, 1, (heap & 0x7FFF) | 0x8000);
    work->cellB = (void *)func_0204AF28(handle, func_0202769C((int)2), func_020276A0((int)2), (u16)((heap & 0x7FFF) | 0x8000));
    work->palB = (void *)func_0204A6C8(handle, func_02027698(), 0, 0, (heap & 0x7FFF) | 0x8000);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.x = 0x18;
    req.y = 0x2C;
    req.id = 1;
    req.a = 1;
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, (int)i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            req.x = i * 0x28 + 0x18;
            work->spr[i] = func_0204B294(owner, work->chr[i], work->pal, work->cell, &req, 0, heap);
            func_0204B6F4(work->spr[i], func_0201BBE8(func_020185F4(mon)), 0);
            if (func_02017E1C(mon, 6, 0) != 0) {
                req2 = req;
                req2.x += 12;
                req2.y += 8;
                req2.a = 0;
                req2.id = 0;
                work->spr[i + 7] = func_0204B294(owner, work->palB, work->chrB, work->cellB, &req2, 0, heap);
            }
        }
    }
    fmt = func_0201EC64((u16)((heap & 0x7FFF) | 0x8000));
    buf = func_020457B0(0x80, (u16)((heap & 0x7FFF) | 0x8000));
    sLevel = func_02045EC0(msg, 0x63);
    sMale = func_02045EC0(msg, 0x64);
    sFemale = func_02045EC0(msg, 0x65);
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, (int)i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            work->win[i] = (void *)func_020450F0((unsigned char)1, (unsigned char)(i * 5 + 1), (unsigned char)4, (unsigned char)5, 6, 15, 1);
            win = work->win[i];
            func_02045334(win);
            func_02045374(win);
            func_020409B4((int)func_02045730(win));
            work->ent[i].win = work->win[i];
            work->ent[i].shown = 0;
            if (func_02017E1C(mon, 0x6E, 0) == 0) {
                func_0201C724(print, func_02045770(work->ent[i].win), 0x20, 0, sMale, font, 0x14C0);
                work->ent[i].shown = 1;
            } else if (func_02017E1C(mon, 0x6E, 0) == 1) {
                func_0201C724(print, func_02045770(work->ent[i].win), 0x20, 0, sFemale, font, 0xC80);
                work->ent[i].shown = 1;
            }
            level = func_02017E1C(mon, 0x9E, 0);
            func_0201EFA4(fmt, 0, level, 3, 1, 1);
            func_0201F250(fmt, buf, sLevel);
            x = 20 - func_0201D304(buf, font, 0) / 2;
            func_0201C724(print, func_02045770(work->ent[i].win), x, 0x24, buf, font, 0x440);
            work->ent[i].shown = 1;
        }
    }
    func_02045808(sFemale);
    func_02045808(sMale);
    func_02045808(sLevel);
    func_02045808(buf);
    func_0201ED04(fmt);
    for (i = 0; i < 14; i++) {
        if (work->spr[i] != 0) {
            func_0204B454(work->spr[i], (struct PtS *)&pos, 0);
            pos.x += 0x100;
            func_0204B404(work->spr[i], (const struct Vec2 *)(&pos), 0);
        }
    }
    func_02040618((int)2, (int)0, (int)(-0x100));
    func_02040618((int)1, (int)0, (int)(-0x100));
    func_020307B0(party);
    func_0207D63C(0x04000050, 4, 8, 15, 3);
    return work;
}

/*
 * volatile: hardware write 021E82C4.
 */
void func_021E82BC(char *p)
{
 int i;
 *(volatile unsigned short *)0x04000050 = 0;
 for(i=0;i<6;i++) {if(*(void **)(p+i*4+0x68)!=0){func_020456F8(*(void **)(p+i*4+0x68));func_020452E8(*(void **)(p+i*4+0x68));}}
 for(i=0;i<14;i++)if(*(void **)(p+i*4+0x30)!=0)func_0204B3B4(*(void **)(p+i*4+0x30));
 func_0204A8D4((u32)(((struct Obj06583 *)p)->f28));func_0204AFD8((u32)(((struct Obj06583 *)p)->f2C));func_0204ADA4((u32)(((struct Obj06583 *)p)->f24));
 for(i=0;i<6;i++)if(*(void **)(p+i*4+0x30)!=0)func_0204A8D4((u32)(*(void **)(p+i*4+4)));
 func_0204AFD8((u32)(((struct Obj06583 *)p)->f20));func_0204ADA4((u32)(((struct Obj06583 *)p)->f0));func_020307B0(p);
}

int func_021E8338(Work_021E8338 *p)
{
    int done;
    int shift;
    Pos pos[2];
    int i;
    if (func_020407E8(2) == 0) {
        return 1;
    }
    done = 0;
    if (p->count == 0) {
        for (i = done; i < 14; i++) {
            if (p->obj[i] != 0) {
                func_0204B454(p->obj[i], (struct PtS *)&pos[1], 0);
                p->base[i] = pos[1].x;
            }
        }
    }
    shift = func_0209C2B0(p->count << 8, 20) - 0x100;
    for (i = 0; i < 14; i++) {
        if (p->obj[i] != 0) {
            func_0204B454(p->obj[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->base[i] - func_0209C2B0(p->count << 8, 20);
            func_0204B404(p->obj[i], (const struct Vec2 *)(&pos[0]), 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0;
        p->count = 0;
        done = 1;
    }
    func_02041EE4(2, 0, shift);
    func_02041EE4(1, 0, shift);
    return done;
}
