/*
 * file:     dup_fitting_item_p08.c
 * unit:     yes
 * function: func_021B9028, func_021B9118, func_021B918C, func_021B940C, func_021B94C0
 * address:  0x021B9028
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4B10 0x021F4B10 thumb ov112
 *   func_021F4AFC 0x021F4AFC thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ffixu 0x0209C4C8 arm
 *   _fgr 0x0209BBB0 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   FX_Atan2Idx 0x0207CFB8 arm
 *   func_021B765C 0x021B765C thumb ov133
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_02040618 0x02040618 arm
 *   func_0204B404 0x0204B404 arm
 *   d_020A1B38 0x020A1B38 data
 *   d_021BA594 0x021BA594 data ov133 a1
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035C08 0x02035C08 arm
 *   func_021B96D8 0x021B96D8 thumb ov133
 *   func_020061E4 0x020061E4 thumb
 *   func_021BA098 0x021BA098 thumb ov133
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_021B9C08 0x021B9C08 thumb ov133
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021B952C 0x021B952C thumb ov133
 *   func_021B8FA8 0x021B8FA8 thumb ov133
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 */
#include "../../matched/include/Obj03825.h"
#include "../../matched/include/Obj10571.h"
#include "../../matched/include/Obj05409.h"
#include "../../matched/include/Obj00004.h"
#include "../../matched/include/Obj23317.h"
#include "../../matched/include/Obj23318.h"
#include "../../matched/include/Obj23319.h"
#include "../../matched/include/Obj23320.h"

#define FXI(d) ((fx32)(((d) > 0) ? ((d) * 4096 + .5f) : ((d) * 4096 - .5f)))
#define FXF(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))
struct Obj;
struct Vec2;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int fx32;

typedef struct { short s; short c; } SC;

typedef struct { short x; short y; } Pt;

typedef struct { u8 bytes[12]; } Rects;

extern int func_021F4B10(u8 *p, int index, int mode);
extern int func_021F4AFC(u8 *p, int index, int mode);
extern void func_021B765C(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern void *func_021BA184(char *p);
extern u8 *func_021BA228(u8 *p);
extern u32 func_021BA218(u8 *p);
extern u32 func_021BA208(u8 *p);
extern void func_021F4EA4(u32 unused, u32 p, u32 q);
extern void func_021F4E8C(u8 *, int, int *);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int FX_Sqrt(int);
extern int FX_Atan2Idx(int, int);
extern unsigned int func_02035CB8(unsigned int *outA, unsigned int *outB);
extern int func_02035C08(const void *);
extern void func_021B96D8(char *p);
extern void func_020061E4(u32 a);
extern void func_021BA098(u8 *);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_021B9C08(u8 *, unsigned int, void *);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021B952C(u8 *);
extern void func_021B8FA8(u8 *);
extern unsigned int func_021BA258(char *p);
extern u8 *func_021F5450(u8 *, int);
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
void func_021B9028(u8 *p, int kind, u16 start);
u16 func_021B9118(u8 *p, u8 *q, int v);
void func_021B918C(u8 *p);
int func_021B940C(u8 *p);
void func_021B94C0(u8 *p);
extern const SC d_020A1B38[];
extern const Rects d_021BA594;

/*
 * lever: explicit redundant pointer/bound temporaries from the bounded permuter settled the three spill homes.
 */
void func_021B9028(u8 *p, int kind, u16 start)
{
    u8 *positionptr;
    u16 i, j, index, position, weight, next, best;
    u8 *tmp;
    u8 *tmp1;
    u8 **tmp2;
    u16 tmp3, tmp4;
    for (i = 0; i < ((struct Obj03825 *)p)->fA8; i++) {
        index = (u16)((start + i) % ((struct Obj03825 *)p)->fA8);
        *(u8 **)(p + index * 4 + 0x1434) = (p + 0xAC) + i * 20;
    }
    for (i = 0; i < ((struct Obj03825 *)p)->fA8; i++) {
        position = (u16)((start + i) % ((struct Obj03825 *)p)->fA8);
        best = position;
        tmp1 = p + position * 4;
        positionptr = tmp1;
        weight = func_021B9118(p, *(u8 * *)&((struct Obj10571 *)positionptr)->f1434, kind);
        for (j = i + 1; j < *(u16 *)(p + 0xA8); j++) {
            tmp4 = *(u16 *)(p + 0xA8);
            tmp3 = tmp4;
            index = (u16)((start + j) % tmp3);
            next = func_021B9118(p, *(u8 **)(p + index * 4 + 0x1434), kind);
            if (weight < next) { weight = next; best = index; }
        }
        if (best != position) {
            tmp = *(u8 **)(positionptr + 0x1434);
            *(u8 **)(positionptr + 0x1434) = *(u8 **)(p + best * 4 + 0x1434);
            tmp2 = (u8 **)(p + best * 4 + 0x1434);
            *tmp2 = tmp;
        }
    }
}

u16 func_021B9118(u8 *p, u8 *q, int v)
{
    int a = func_021F4B10(((struct Obj03825 *)p)->f1884, ((struct Obj05409 *)q)->f0, v);
    int b = func_021F4AFC(((struct Obj03825 *)p)->f1884, ((struct Obj05409 *)q)->f0, v);
    int n;
    if (a == 1) {
        if (((struct Obj05409 *)q)->f10 == 1) n = 6000;
        else n = 5000;
    } else if (b == 1) {
        if (((struct Obj05409 *)q)->f10 == 1) n = 4000;
        else n = 3000;
    } else {
        if (((struct Obj05409 *)q)->f10 == 1) n = 2000;
        else n = 1000;
    }
    return n + (999 - ((struct Obj05409 *)q)->f0);
}


void func_021B918C(u8 *p)
{
    u8 *e;
    Pt r;
    func_021B765C(p, *(u16 *)(p + 0x182C), 0, (u16)(*(int *)(p + 0x10) + 0x48), (u32)(48.0f + (float)*(int *)(p + 0x10) * 0.6666667f));
    e = func_021BA184((char *)(*(u8 **)(p + 0x1820)));
    while (e) {
        int *pos = (int *)func_021BA228(e);
        int id = func_021BA218(e);
        int y;
        int x;
        int d;
        int dist, ang, k;
        const SC *sc;
        int v[3];
        x = (short)(pos[0] - 0x80);
        y = (short)(pos[1] - 0x50);
        d = x * x + y * y;
        dist = FX_Sqrt(FXI(d));
        ang = FX_Atan2Idx(FXI(y), FXI(x));
        func_021F4EA4((u32)(*(u8 **)(p + 0x1884)), id, (u32)v);
        k = dist + FXI(*(int *)(p + 0x10));
        sc = &d_020A1B38[ang >> 4];
        v[0] = (fx32)(((long long)sc->c * k + 0x800) >> 12) + 0x80000;
        k = dist + FXF((float)*(int *)(p + 0x10) * 0.6666667f);
        v[1] = (fx32)(((long long)sc->s * k + 0x800) >> 12) + 0x50000;
        func_021F4E8C(*(u8 **)(p + 0x1884), id, v);
        e = (u8 *)func_021BA208(e);
    }
    func_02040618(2, 3, -*(int *)(p + 0x10));
    r.x = 0x20;
    {
        int t = 0xC0 - *(int *)(p + 0x10);
        if (t >= 0x40) t = 0x40;
        r.y = t + 0xA0;
    }
    func_0204B404((struct Obj *)(*(u8 **)(p + 0x184C)), (const struct Vec2 *)(&r), 0);
    r.x = 0xE0;
    {
        int t = 0xC0 - *(int *)(p + 0x10);
        if (t >= 0x40) t = 0x40;
        r.y = t + 0xA0;
    }
    func_0204B404((struct Obj *)(*(u8 **)(p + 0x1850)), (const struct Vec2 *)(&r), 0);
}

int func_021B940C(u8 *p)
{
    Rects rects = d_021BA594;
    void *obj;
    func_02035CB8((unsigned int *)(p + 0x1c), (unsigned int *)(p + 0x20));
    switch (func_02035C08(&rects)) {
    case 0:
        func_021B96D8((char *)p);
        func_020061E4(1358);
        func_021BA098(p);
        return 2;
    case 1:
        ((struct Obj00004 *)p)->fC = 6;
        ((struct Obj00004 *)p)->f10 = 192;
        func_020061E4(1962);
        func_021B94C0(p);
        obj = func_0201EC64(((struct Obj00004 *)p)->f0);
        func_0201EEF4(obj, 0, ((struct Obj23318 *)(*(u8 * *)&((struct Obj23317 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4))->f4);
        func_021B9C08(p, 0, obj);
        func_0201ED04(obj);
        func_021BA098(p);
        break;
    case -1:
        func_021B952C(p);
        break;
    }
    func_021B8FA8(p);
    return 0;
}

void func_021B94C0(u8 *p)
{
    u8 i;
    u8 *e, *q;
    u16 index;
    for (i = 0; i < 9; i++)
        *(u16 *)(*(u8 * *)&((struct Obj23319 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4 + 0x16 + i * 6) = 0;
    e = func_021BA184(((struct Obj00004 *)p)->f1824);
    while (e) {
        index = func_021BA258((char *)e);
        q = func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880, index);
        func_021F4ED4((u32)(((struct Obj00004 *)p)->f1884), func_021BA218(e), ((struct Obj23320 *)q)->f36);
        e = (u8 *)func_021BA208(e);
    }
}
