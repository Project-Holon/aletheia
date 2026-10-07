/*
 * file:     unit_021C6000_p06.c
 * unit:     yes
 * function: func_021C6C38, func_021C6C7C, func_021C6D98, func_021C6D9C, func_021C6E8C, func_021C6F4C, func_021C6FA0, func_021C6FC4, func_021C705C
 * address:  0x021C6C38
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_021C6BD4  0x021C6BD4  thumb  ov111
 *   d_021C8768     0x021C8768  data  a2
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_020A1448     0x020A1448  data
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021C87A4     0x021C87A4  data  a4
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021C7130  0x021C7130  thumb
 *   func_021C7208  0x021C7208  thumb
 *   func_021C7228  0x021C7228  thumb
 *   func_021C72FC  0x021C72FC  thumb
 *   func_021C7504  0x021C7504  thumb
 *   func_021C75E4  0x021C75E4  thumb
 *   func_021C76A4  0x021C76A4  thumb
 *   func_021C7744  0x021C7744  thumb
 *   func_021C78C4  0x021C78C4  thumb
 *   func_021C7934  0x021C7934  thumb
 *   func_021C81A4  0x021C81A4  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_021C79A0  0x021C79A0  thumb
 *   func_021C7830  0x021C7830  thumb
 *   func_021C7970  0x021C7970  thumb
 *   func_0204A600  0x0204A600  arm
 */
struct Descriptor;
struct StrObj;
struct PlayTime;
struct Cfg;
struct Bank;
struct Obj;
struct Actor;
struct Obj0203159C;
typedef unsigned char u8;

typedef short s16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work_021C6C38;

typedef unsigned short u16;

typedef struct {
    u8 pad0[0x1C];
    void *f1C;
    u8 pad20[0x2A - 0x20];
    u16 h2A;
    u8 pad2C[2];
    u8 b2E;
} Info;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
    u8 pad3200[0x320C - 0x3200];
    void *f320C;
} Work_021C6C7C;

typedef signed char s8;

typedef int s32_021C6D98;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0xB8 - 8];
    u32 fB8;
    u32 fBC;
    u32 fC0;
    u32 fC4;
    u32 fC8;
    u32 fCC;
} Anim_021C6D9C;

typedef signed int     s32_021C6D9C;

typedef struct {
    u16 x;
    u16 y;
    u8 chr;
    u8 cell;
    u8 anm;
    u8 pri;
    u32 z;
} ObjTemplate;

typedef struct {
    ObjTemplate t[8];
} ObjTemplateTable;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pad6;
    u8 pri;
} ObjPos;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} ResSet;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0x98 - 8];
    void *obj[8];
    ResSet res[2];
} Anim_021C6E8C;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0xB8 - 8];
    ResSet res[2];
} Anim_021C6F4C;

typedef struct {
    u8 pad0[0x98];
    void *anim[1];
} Work_021C6FA0;

typedef long long s64;

typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C6FC4;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x58 - 0x18];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF8 - 0xDC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    void *f108;
    int state;
    u8 pad110[4];
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    u8 pad144[0x14C - 0x144];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
} Work_021C705C;

extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void func_021C6BD4(void *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32_021C6D9C func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021C6D9C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021C6D9C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32_021C6D9C func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204ADA4(u32 r);
extern void func_0204A8D4(u32 r);
extern void func_0204AFD8(u32 r);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0203064C(u32 a, u32 heap, u32 size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082AC0(int v, void *p, int size);
extern void func_021C7130(Work_021C6FC4 *p, void *parent);
extern void func_021C7208(void);
extern void func_021C7228(Work_021C6FC4 *p);
extern void func_021C72FC(Work_021C6FC4 *p);
extern void func_021C7504(Work_021C6FC4 *p);
extern void func_021C75E4(Work_021C6FC4 *p);
extern void func_021C76A4(Work_021C6FC4 *p);
extern void func_021C7744(Work_021C6FC4 *p);
extern void func_021C78C4(Work_021C6FC4 *p);
extern void func_021C7934(Work_021C6FC4 *p);
extern void func_021C81A4(Work_021C6FC4 *p, u16 v);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_021C79A0(Work_021C705C *p);
extern void func_021C7830(Work_021C705C *p);
extern void func_021C7970(Work_021C705C *p);
extern void func_0204A600(void);
void func_021C6C38(Work_021C6C38 *p, void *a, int x, int dx, int y, void *s);
void func_021C6C7C(Work_021C6C7C *p, void *a, int y, const Info *info, void *s, int idx);
void func_021C6D98(void);
void func_021C6D9C(Anim_021C6D9C *a, u32 x);
void func_021C6E8C(Anim_021C6E8C *a);
void func_021C6F4C(Anim_021C6F4C *a);
void func_021C6FA0(Work_021C6FA0 *p, int idx, u8 a, u8 b);
int func_021C6FC4(void *proc, int *seq, void *parent);
int func_021C705C(void *a, void *b, int c, Work_021C705C *p);
extern const u16 d_021C8768[];
extern const u8 d_020A1448[];
extern const ObjTemplateTable d_021C87A4;


/*
 * Addresses are Black-image addresses.
 */
void func_021C6C38(Work_021C6C38 *p, void *a, int x, int dx, int y, void *s)
{
    u32 w;

    w = func_0201D304(s, (u32)p->f31FC, 0);
    func_0201C7A4(func_02045770(a), x - (w + dx), y, s, p->f31FC);
}


void func_021C6C7C(Work_021C6C7C *p, void *a, int y, const Info *info, void *s, int idx)
{
    int v;

    if (info->f1C == 0) {
        func_021C6BD4(p, a, 0xD8, 0, y, s, info->b2E, 2, 2, 0xD0, 0x10, idx);
        func_021C6BD4(p, a, 0xD8, 0x13, y, s, info->h2A, 3, 1, 0xAD, 0x1B, idx);
        func_0201C7D0(func_02045770(a), 0xC6, y, p->f320C, p->f31FC, d_021C8768[idx]);
    } else {
        v = func_0200864C(info->f1C);
        if (v > 999) {
            v = 999;
        }
        func_021C6BD4(p, a, 0xD8, 0, y, s, func_02008650(info->f1C), 2, 2, 0xD0, 0x10, idx);
        func_021C6BD4(p, a, 0xD8, 0x13, y, s, v, 3, 1, 0xAD, 0x1B, idx);
        func_0201C7D0(func_02045770(a), 0xC6, y, p->f320C, p->f31FC, d_021C8768[idx]);
    }
}


void func_021C6D98(void) { }


void func_021C6D9C(Anim_021C6D9C *a, u32 x)
{
    void *h;

    h = func_020490F4(0x28, a->heap);
    func_0204A48C((const struct Cfg *)d_020A1448, x, a->heap);
    a->f4 = (u32)func_0204B100(0x23, 0, a->heap);
    a->fB8 = func_0204AC18(h, 0xC, 1, 0, 0, 5, a->heap);
    a->fBC = func_0204A6C8(h, 0x1D, 0, 1, a->heap);
    a->fC0 = func_0204AF28(h, 0x2E, 0x30, a->heap);
    func_02049238(h);
    h = func_020490F4(func_020275E4(), a->heap);
    a->fC4 = func_0204ABF0(h, func_02027614(), 1, 0xA0, a->heap);
    a->fC8 = func_0204A6C8(h, func_02027618(), 0, 1, a->heap);
    a->fCC = func_0204AF28(h, func_0202761C(0), func_02027620(0), a->heap);
    func_02049238(h);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_021C6E8C(Anim_021C6E8C *a)
{
    ObjTemplateTable tbl = d_021C87A4;
    ObjPos pos;
    int i;

    for (i = 0; i < 8; i++) {
        pos.x = tbl.t[i].x;
        pos.y = tbl.t[i].y;
        pos.z = tbl.t[i].z;
        pos.pri = tbl.t[i].pri;
        a->obj[i] = func_0204B294((void *)a->f4, a->res[tbl.t[i].cell].a, a->res[tbl.t[i].chr].b, a->res[tbl.t[i].anm].c, &pos, 1, a->heap);
        func_0204B3DC(a->obj[i], 1);
        func_0204B954(a->obj[i], 0x1000);
        func_0204B92C(a->obj[i], 1);
        if (i == 3) {
            func_0204B3DC(a->obj[i], 0);
        }
    }
    func_0204B3DC(a->obj[5], 0);
}


void func_021C6F4C(Anim_021C6F4C *a)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        func_0204ADA4(a->res[i].a);
        func_0204A8D4(a->res[i].b);
        func_0204AFD8(a->res[i].c);
    }
    func_0204B1CC((struct Bank *)a->f4);
    func_0204A5AC();
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x300010) | 0x10;
}


void func_021C6FA0(Work_021C6FA0 *p, int idx, u8 a, u8 b)
{
    func_0204B878(p->anim[idx], a);
    func_0204B9A0(p->anim[idx]);
    func_0204B3DC(p->anim[idx], b);
}


int func_021C6FC4(void *proc, int *seq, void *parent)
{
    Work_021C6FC4 *p;

    func_0203064C(1, 0x27, 0x20000);
    p = func_0203159C(proc, 0x1C8, 0x27);
    func_02082AC0(0, p, 0x1C8);
    func_021C7130(p, parent);
    func_021C7208();
    func_021C7228(p);
    func_021C72FC(p);
    func_021C7504(p);
    func_021C75E4(p);
    func_021C76A4(p);
    func_021C7744(p);
    func_021C78C4(p);
    func_021C7934(p);
    func_021C81A4(p, p->f114);
    func_0203D34C(1, 0x27);
    func_0202208C(0, 1, 1, 0, 6, 1, 0x27);
    return 1;
}


int func_021C705C(void *a, void *b, int c, Work_021C705C *p)
{
    if (func_021C79A0(p) == 0) {
        return 1;
    }
    func_021C7830(p);
    func_021C7970(p);
    func_0204A600();
    if (++p->f11C >= 0x100) {
        p->f11C = 0;
    }
    return 0;
}
