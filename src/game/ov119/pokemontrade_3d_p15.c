/*
 * file:     pokemontrade_3d_p15.c
 * unit:     yes
 * function: func_021E4324, func_021E43DC, func_021E4420, func_021E4570, func_021E4598, func_021E467C, func_021E4810, func_021E4888, func_021E48E0, func_021E496C, func_021E4984, func_021E49DC, func_021E4A1C, func_021E4A84
 * address:  0x021E4324
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_021E42B4  0x021E42B4  thumb  ov119
 *   func_020307B0 0x020307B0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0200785C 0x0200785C thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045788 0x02045788 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02042FB0 0x02042FB0 arm
 *   func_02045780 0x02045780 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_021E69A4 0x021E69A4 thumb ov119
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_021E7058 0x021E7058 thumb ov119
 *   func_021E1CA8 0x021E1CA8 thumb ov119
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_021D8E24 0x021D8E24 thumb ov119
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B454 0x0204B454 arm
 *   d_021E82A4 0x021E82A4 data
 */
#include "../../matched/include/Obj00908.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj00252.h"
#include "../../matched/include/Obj03781.h"
#include "../../matched/include/Obj22805.h"
#include "../../matched/include/Obj13921.h"
#include "../../matched/include/Obj13922.h"
#include "../../matched/include/Obj22806.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Cfg;
struct Obj;
struct Actor;
struct PtS;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    char pad00[0x24];
    u16 v[0x300];       /* 0x024 */
} Buf;

typedef unsigned char u8;

typedef short s16;

typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;

typedef signed int     s32;

extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void func_021E42B4(char *p);
extern u32 func_020307B0(void *p);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0200785C(void *,u32,void *);
extern void func_0201DD78(u32,u32,u32);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045334(struct Descriptor *d);
extern void func_02045788(struct Descriptor *p, u8 v);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02042FB0(u32, u32, u32, u16);
extern void func_02045780(struct Descriptor *p, u8 v);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern int func_0204ACEC(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern s32 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern s32 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_021E69A4(char *);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_021E7058(void *);
extern void func_021E1CA8(char *p);
extern int func_021D8AF4(int, char *);
extern int func_021D8B0C(int, int);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern char *func_021D8E24(int, int, char *);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
void func_021E4324(char *p, int d);
void func_021E43DC(char *p);
void func_021E4420(char *p);
void func_021E4570(char *p);
void func_021E4598(char *p);
void func_021E467C(char *p);
void func_021E4810(char *p, int n);
void func_021E4888(char *p);
void func_021E48E0(char *p);
void func_021E496C(int x, int y, unsigned short *out);
int func_021E4984(int v, int a, int b, char *p, int *out);
char *func_021E49DC(int a, int b, char *p);
void func_021E4A1C(char *p);
int func_021E4A84(char *p, int i);
extern const unsigned char d_021E82A4[];


/*
 * 2026-10-03 (wB3 lane07): EXACT. The doubled zero-extension of the loop-invariant
 * comes from an int parameter stored in a u16 local and then added as (int)e.
 */
void func_021E4324(char *p, int d)
{
    int i;
    u16 e;

    *(Buf * *)&((struct Obj00908 *)p)->f1174 = func_02048F60(0x66, 0xE, ((struct Obj00908 *)p)->f5F4);
    *(Buf * *)&((struct Obj00908 *)p)->f1178 = func_02048F60(0x66, 0xF, ((struct Obj00908 *)p)->f5F4);
    *(Buf * *)&((struct Obj00908 *)p)->f117C = func_02048F60(0x66, 0x19, ((struct Obj00908 *)p)->f5F4);
    *(Buf * *)&((struct Obj00908 *)p)->f1180 = func_02048F60(0x66, 0x1A, ((struct Obj00908 *)p)->f5F4);
    e = d;
    for (i = 0; i < 0x300; i++) {
        (*(Buf * *)&((struct Obj00908 *)p)->f1174)->v[i] += (int)e;
        (*(Buf **)(p + 0x1178))->v[i] += (int)e;
        (*(Buf **)(p + 0x117C))->v[i] += (int)e;
        (*(Buf **)(p + 0x1180))->v[i] += (int)e;
    }
    ((struct Obj00908 *)p)->f107C = ((struct Obj00908 *)p)->f63C - 0x50;
    func_021E42B4(p);
}

void func_021E43DC(char *p)
{
    if (((struct Obj00001 *)p)->f1174) {
        func_020307B0(((struct Obj00001 *)p)->f1174);
        ((struct Obj00001 *)p)->f1174 = 0;
        func_020307B0(((struct Obj00001 *)p)->f1178);
        ((struct Obj00001 *)p)->f1178 = 0;
        func_020307B0(((struct Obj00001 *)p)->f117C);
        ((struct Obj00001 *)p)->f117C = 0;
        func_020307B0(((struct Obj00001 *)p)->f1180);
        ((struct Obj00001 *)p)->f1180 = 0;
    }
}

/*
 * arithmetic: count additions wrap unsigned then compare signed results; indexed address uses typed word-pointer addition under valid-object preconditions; the guarded int counter never increments above INT_MAX.
 * note 2026-10-05 (wave D9r lane 131): removed the 11 dead first assignments
 * (`off1 = 0x5F4;` before `off1 = 0x6B8;`; `off3 = 0x828;` before `off3 =
 * 0x730;` and 9 more). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
void func_021E4420(char *p)
{
    int off1, h, off, off2, off3;
    int a,b,c,d,e,f,g;
    int i, zero;
    char *q;
    off = 0x5F4;
    func_02049B40(23,5,4,448,32,*(u16 *)(p+off));
    i = 0;
    if (i >= (int)((u32)*(int *)(p+off+0x3C)+1u)) goto done;
        zero = 0;
        off1 = 0x6B8;
        off = 0x630;
        off3 = 0x730;
        off2 = 0x730;
        a = 0x6B8;
        b = 0x6B8;
        c = 0x728;
        d = 0x730;
        e = 0x6B8;
        f = 0x6B8;
        g = 0x630;
        h = 0x6B8;
        do {
            q = (char *)((u32 *)p+i);
            if (*(u32 *)(q+h) == 0)
                *(u32 *)(q+off1) = func_020450F0(5,0,0,15,2,14,0);
            if (i == *(int *)(p+off))
                func_02045CAC(((struct Obj00001 *)p)->f720,16,*(void **)(p+off2));
            else func_0200785C(((struct Obj00001 *)p)->f828,i,*(void **)(p+off3));
            func_0201DD78(15,2,zero);
            func_02043B5C(func_02045770(*(void **)(q+a)),zero);
            func_0201C7A4(func_02045770(*(void **)(q+b)),zero,1,*(void **)(p+d),*(void **)(p+c));
            func_02045334(*(void **)(q+e));
            func_02045788(*(void **)(q+f),zero);
        } while (++i < (int)((u32)*(int *)(p+g)+1u));
done:;
}

void func_021E4570(char *p)
{
    int i;
    for (i = 0; i < 25; i++) {
        if (*(void **)(p + i * 4 + 0x6B8)) {
            func_020452E8(*(void **)(p + i * 4 + 0x6B8));
            *(void **)(p + i * 4 + 0x6B8) = 0;
        }
    }
}

/*
 * arithmetic: full-word index and scroll ADD/SUB/MUL use modulo-2^32 arithmetic; casts restore the original signed comparisons.
 * note 2026-10-05 (wave D9r lane 131): removed the 3 dead first assignments
 * (`off1 = 0x638;` before `off1 = 0x6B8;`; `off2 = 0x638;` before `off2 =
 * 0x6B8;` and 1 more). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
void func_021E4598(char *p)
{
    int x, y, scroll, first, i, n, pos, idx;
    int off1, off2, bound;
    char *q;
    scroll = ((struct Obj00001 *)p)->f107C / 8;
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 64; x++) {
            func_02042FB0(5, x, y, 0);
        }
    }
    if (((struct Obj00001 *)p)->f107C < 96) first = ((struct Obj00001 *)p)->f630;
    else first = (((struct Obj00001 *)p)->f107C - 96) / 160;
    i = 0;
    off1 = 0x6B8;
    off2 = 0x6B8;
    bound = 0x630;
    for (; i < 3; i++) {
        idx = (int)((u32)first+(u32)i);
        n = *(int *)(p + bound);
        if (idx > n) idx = (int)((u32)idx-(u32)n-1u);
        else if (idx < 0) idx = (int)((u32)idx+(u32)n+1u);
        if (idx == n) {
            pos = (int)(((struct Obj00001 *)p)->f638-(u32)scroll);
            if (scroll > pos) scroll = (int)((u32)scroll-((struct Obj00001 *)p)->f638);
            else pos = (int)(0u-(u32)scroll);
        } else pos = (int)((u32)idx*20u+12u-(u32)scroll);
        if (pos >= -10 && pos <= 33) {
            q = (char *)((u32)p+(u32)idx*4u);
            func_02045780(*(void **)(q + off1), pos + 1);
            func_02045374(*(void **)(q + off2));
        }
    }
    func_02041B6C(5);
}

void func_021E467C(char *p)
{
    int i, j, z;
    void *arc;
    char *q;
    ObjTmpl t;
    arc = func_020490F4(7, ((struct Obj00252 *)p)->f5F4);
    ((struct Obj00252 *)p)->f87C = (void *)func_0204ACEC(arc, func_0201BC3C(), 1, 0x60, ((struct Obj00252 *)p)->f5F4);
    ((struct Obj00252 *)p)->f8AC = (void *)func_0204AF28(arc, func_0201BC78(), func_0201BCB4(), ((struct Obj00252 *)p)->f5F4);
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 5; j++) {
            z = 0;
            t.x = z;
            t.y = z;
            t.prio = 1;
            t.pal = 0x10;
            t.mode = 3;
            q = p + i * 20 + j * 4;
            ((struct Obj03781 *)q)->f9CC = (void *)func_0204A6C8(arc, 0x51b, z, 1, ((struct Obj00252 *)p)->f5F4);
            ((struct Obj03781 *)q)->fAC0 = func_0204B294(((struct Obj00252 *)p)->f9C4, (unsigned int)((struct Obj03781 *)q)->f9CC,
                (unsigned int)((struct Obj00252 *)p)->f87C, (unsigned int)((struct Obj00252 *)p)->f8AC, &t, 1, ((struct Obj00252 *)p)->f5F4);
            t.prio = z;
            t.pal = 0xf;
            ((struct Obj03781 *)q)->fBB0 = func_0204B294(((struct Obj00252 *)p)->f9C4, (unsigned int)((struct Obj00252 *)p)->f894,
                (unsigned int)((struct Obj00252 *)p)->f880, (unsigned int)((struct Obj00252 *)p)->f8B0, &t, 1, ((struct Obj00252 *)p)->f5F4);
            func_0204B92C(((struct Obj03781 *)q)->fAC0, z);
            func_0204B3DC(((struct Obj03781 *)q)->fAC0, z);
            func_0204B3DC(((struct Obj03781 *)q)->fBB0, z);
            func_0204B92C(((struct Obj03781 *)q)->fBB0, 1);
        }
    }
    func_02049238(arc);
}

/*
 * follower: two zero padding bytes at 0x021E4886 before labelled 021E4888.
 */
void func_021E4810(char *p, int n)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (*(int *)(p + n * 20 + i * 4 + 0xac0)) {
            func_0204B3B4((struct Obj *)(*(int *)(p + n * 20 + i * 4 + 0xac0)));
            *(int *)(p + n * 20 + i * 4 + 0xac0) = 0;
        }
        if (*(int *)(p + n * 20 + i * 4 + 0xbb0)) {
            func_0204B3B4((struct Obj *)(*(int *)(p + n * 20 + i * 4 + 0xbb0)));
            *(int *)(p + n * 20 + i * 4 + 0xbb0) = 0;
        }
        if (*(int *)(p + n * 20 + i * 4 + 0x9cc)) {
            func_0204A8D4(*(int *)(p + n * 20 + i * 4 + 0x9cc));
            *(int *)(p + n * 20 + i * 4 + 0x9cc) = 0;
        }
    }
}

void func_021E4888(char *p)
{
    int i;
    func_021E69A4(p);
    for (i = 0; i < 12; i++) func_021E4810(p, i);
    if (((struct Obj00001 *)p)->f87C) {
        func_0204ADA4(((struct Obj00001 *)p)->f87C);
        ((struct Obj00001 *)p)->f87C = 0;
    }
    if (((struct Obj00001 *)p)->f8AC) {
        func_0204AFD8(((struct Obj00001 *)p)->f8AC);
        ((struct Obj00001 *)p)->f8AC = 0;
    }
    if (((struct Obj00001 *)p)->f1184) func_020307B0(((struct Obj00001 *)p)->f1184);
    ((struct Obj00001 *)p)->f1184 = 0;
}

void func_021E48E0(char *p)
{
    int i;
    func_021E7058(p);
    func_021E1CA8(p);
    for (i = 0; i < 10; i++) {
        if (*(int *)(p + i * 4 + 0xefc)) {
            func_0204B3B4((struct Obj *)(*(int *)(p + i * 4 + 0xefc)));
            *(int *)(p + i * 4 + 0xefc) = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            func_0204ADA4(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
    for (; i < 12; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            func_0204A8D4(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
    for (; i < 18; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            func_0204AFD8(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
}

void func_021E496C(int x, int y, unsigned short *out)
{
    out[0] = (x + 1) * 0x18;
    out[1] = y * 0x18 + 0x48;
}

int func_021E4984(int v, int a, int b, char *p, int *out)
{
    int n, m;
    if (a >= 2) {
        n = func_021D8AF4(a, p);
        m = func_021D8B0C(a, b);
        *out = 0;
        return (int)func_021D8DD0((void *)v, n, m, p);
    }
    if (b < 3) {
        *out = 1;
        return (int)func_021D8DD0((void *)v, ((struct Obj00001 *)p)->f630, a + b * 2, p);
    }
    return 0;
}

char *func_021E49DC(int a, int b, char *p)
{
    int n;
    if (a >= 2) {
        n = func_021D8AF4(a, p);
        return func_021D8E24(n, func_021D8B0C(a, b), p);
    }
    if (b < 3)
        return func_021D8E24(((struct Obj22805 *)p)->f630, a + b * 2, p);
    return 0;
}

void func_021E4A1C(char *p)
{
    short xy[2];
    int i, j;
    char *q, *r;
    for (i = 0; i < 5; i++) {
        q = p + i * 4;
        for (j = 0; j < 12; j++) {
            r = q + j * 20;
            if (func_0204B3F4((struct Obj *)(((struct Obj13922 *)r)->fBB0))) {
                func_0204B454((struct Actor *)((struct Obj13922 *)r)->fBB0, (struct PtS *)xy, 1);
                ((struct Obj13921 *)p)->fF54 = xy[0];
                ((struct Obj13921 *)p)->fF58 = xy[1];
            }
        }
    }
}

int func_021E4A84(char *p, int i)
{
    int v = ((struct Obj22806 *)p)->f800;
    if (v != 0 && v - 1 == d_021E82A4[i]) {
        return 1;
    }
    return 0;
}
