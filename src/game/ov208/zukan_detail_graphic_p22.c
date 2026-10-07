/*
 * file:     zukan_detail_graphic_p22.c
 * unit:     yes
 * function: func_021BFE08, func_021BFFEC, func_021C0048, func_021C0090, func_021C0130, func_021C0134, func_021C03C4, func_021C0450, func_021C0524, func_021C0544, func_021C06A0, func_021C06C8, func_021C06EC
 * address:  0x021BFE08
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021BC3CC  0x021BC3CC  thumb  ov208
 *   func_021BC40C  0x021BC40C  thumb  ov208
 *   func_021C1AD4  0x021C1AD4  thumb  ov208
 *   func_021C1D0C  0x021C1D0C  thumb  ov208
 *   func_021C1920  0x021C1920  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_021BDC2C  0x021BDC2C  thumb  ov208
 *   func_02012BE0  0x02012BE0  thumb
 *   func_021C239C 0x021C239C thumb ov208
 *   func_021C2304 0x021C2304 thumb ov208
 *   func_021C231C 0x021C231C thumb ov208
 *   func_021C232C 0x021C232C thumb ov208
 *   func_021BC4F4 0x021BC4F4 thumb ov208
 *   func_021BC6BC 0x021BC6BC thumb ov208
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   d_021C8670 0x021C8670 data a2
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B258  0x0204B258  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   func_0204B404  0x0204B404  arm
 *   data_021C8558  0x021C8558  data
 *   data_021C8560  0x021C8560  data
 *   data_021C8568  0x021C8568  data
 *   data_021C8580  0x021C8580  data
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B084 0x0204B084 arm
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_02166CD0  0x02166CD0  thumb
 */
#include "../../matched/include/Obj08397.h"
#include "../../matched/include/Obj25495.h"
#include "../../matched/include/Obj02546.h"
#include "../../matched/include/Obj12126.h"
#include "../../matched/include/Obj09204.h"

#define W(o) (*(u32 *)(p + (o)))
#define WP(o) (*(void **)(p + (o)))
#define OBJ(i) (*(u32 *)(p + (i) * 4 + 0xbc))
struct Ov208Cur;
struct Obj;
struct Vec2;
struct Actor;
struct Bank;
struct Node;
struct PrintSys;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_021BFE08;

typedef signed int     s32_021BFE08;

struct S {
    u8 pad0[0x424];
    u32 f424;
    u32 f428;
    u32 f42c;
    u32 f430;
    u32 f434;
};

typedef int            s32_021C0090;

typedef short          s16_021C0134;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u32 w[4];
} BankDesc;

typedef struct {
    u8 v[7];
} Row7;

typedef struct {
    s16_021C0134 x;
    s16_021C0134 y;
} Pt;

typedef signed int     s32_021C0134;

typedef short          s16_021C0450;

typedef int            s32_021C0450;

typedef short          s16_021C0544;

typedef int            s32_021C0544;

typedef struct {
    char pad[0x1e0];
    int arr[0x7a];
} S;

extern int func_021BC3B4(int *p);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
extern void func_021BC40C(struct Ov208Cur *p);
extern void func_021C1AD4(u16 *heap, u8 *p, int key);
extern void func_021C1D0C(int a, int b, int c);
extern void func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern void func_021BDBA0(int p);
extern int func_021BC3A4(int *p);
extern int func_021BDC2C(char *p);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_021C239C(char *);
extern void func_021C2304(char *);
extern void func_021C231C(char *);
extern void func_021C232C(char *);
extern void func_021BC4F4(int flag, int *p);
extern void func_021BC6BC(char *p);
extern u16 func_021BBB3C(char *, int, int);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B258(struct Bank *bank, void *p);
extern s32_021C0134 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021C0134 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021C0134 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02082BCC(void *dst, int v, int n);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B84C(u32 obj, int v);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3B4(struct Obj *);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B084(void *);
extern int  ov208_func_021BC3A4(int key);
extern int  func_02166CD0(int a, u32 msg);
extern u32 func_0201C440(void *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
void func_021BFE08(void *a0, void *a1, void *heap, struct S *st, int *obj, int key);
void func_021BFFEC(void *unused, char *p);
void func_021C0048(u16 *unused, char *p, int a2);
void ov208_func_021C0090(u16 *heap, u8 *p, int key);
void ov208_func_021C0130(u16 *heap, u8 *p, int key);
void func_021C0134(u16 *heap, u8 *p, int key);
void func_021C03C4(void *unused, char *p, void *a2);
void ov208_func_021C0450(u16 *heap, u8 *p, int key);
void func_021C0524(void *unused, char *p, void *a2);
void ov208_func_021C0544(u16 *heap, u8 *p, int key);
void func_021C06A0(int unused, S *s);
void func_021C06C8(unsigned short *a, char *b, int a2);
void func_021C06EC(void *unused, char *p, void *a2);
extern const u16 d_021C8670[];
extern const BankDesc data_021C8580;
extern const Row7 data_021C8558;
extern const Row7 data_021C8560;
extern const Row7 data_021C8568;


void func_021BFE08(void *a0, void *a1, void *heap, struct S *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 16: case 19:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 17: case 18: case 20:
        st->f428 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 8: case 9: case 19:
        flag = 1;
        st->f428 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C1AD4(heap, (u8 *)st, (int)obj);
            func_021C1D0C((int)heap, (int)st, (int)obj);
            st->f42c = 1;
            st->f430 = 0;
            st->f434 = 0;
        } else {
            st->f42c = 1;
            st->f430 = 1;
            st->f434 = 0;
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C1AD4(heap, (u8 *)st, (int)obj);
            func_021C1D0C((int)heap, (int)st, (int)obj);
            st->f42c = 1;
            st->f430 = 0;
            st->f434 = 0;
        } else {
            st->f42c = 1;
            st->f430 = 1;
            st->f434 = 0;
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f424 = 2;
        return;
    case 6: case 8: case 9:
        st->f424 = 1;
        return;
    case 3:
        if (st->f42c != 0) {
            st->f434 = 1;
            if (st->f430 != 0) {
                st->f42c = 0;
                func_021BDBA0(sc);
                return;
            }
        }
        break;
    case 4:
        if (st->f42c != 0) {
            st->f434 = 1;
            if (st->f430 != 0) {
                st->f42c = 0;
                func_021BDBA0(sc);
                return;
            }
        }
        break;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x12, func_021BDC2C((char *)sc));
        func_021BDBA0(sc);
        return;
    case 19:
        func_021C1920(heap, (u8 *)st, (int)obj, 6);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0(sc);
        }
        break;
    }
}

void func_021BFFEC(void *unused, char *p)
{
    switch (((struct Obj08397 *)p)->f414) {
    case 1: func_021C239C(p); func_021C2304(p); break;
    case 2: func_021C231C(p); func_021C232C(p); break;
    case 3:
        func_021C239C(p);
        func_021C231C(p);
        func_021BC4F4(0, (int *)(((struct Obj08397 *)p)->f418));
        break;
    }
    ((struct Obj08397 *)p)->f414 = 0;
    func_021BC6BC(((struct Obj08397 *)p)->f420);
}

void func_021C0048(u16 *unused, char *p, int a2)
{
    u8 i;
    for (i = 0; i < 61; i++) {
        u16 value = func_021BBB3C(*(char * *)&((struct Obj25495 *)p)->f3C8, i, 0);
        u8 j;
        for (j = 0; j < 61; j++) {
            if (value == d_021C8670[j]) {
                *(u8 *)(p + i + 0x3cc) = j;
                break;
            }
        }
    }
}


void ov208_func_021C0090(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(0x55, *heap);
    func_02049B68(h, 0, 2, 0x6000, 0x2000, *heap);
    func_02049B68(h, 0, 2, 0x4000, 0x2000, *heap);
    func_02049658(h, 5, 2, 0, 0x4000, 0, *heap);
    func_02049658(h, 7, 3, 0, 0xc000, 0, *heap);
    func_020498F4(h, 0x11, 2, 0, 0x800, 0, *heap);
    func_020498F4(h, 0x10, 3, 0, 0x800, 0, *heap);
    func_02049238(h);
}


void ov208_func_021C0130(u16 *heap, u8 *p, int key)
{
}


void func_021C0134(u16 *heap, u8 *p, int key)
{
    BankDesc desc;
    Row7 anim, pri, pal;
    ObjPos pos;
    Pt pt;
    void *h;
    u8 i;

    desc = data_021C8580;
    WP(0x1d4) = func_0204B034((u8 *)(&desc), 1, *heap);
    W(0x1d0) = (u32)func_0204B100(0x10, 0, *heap);
    func_0204B258((struct Bank *)W(0x1d0), WP(0x1d4));

    h = func_020490F4(0x55, *heap);
    W(0x9c) = func_0204AC18(h, 2, 0, 0, 0, 5, *heap);
    W(0x98) = func_0204A6C8(h, 8, 0, 0, *heap);
    W(0xa0) = func_0204AF28(h, 0xc, 0x13, *heap);
    func_02049238(h);

    h = func_020490F4(0x9f, *heap);
    W(0xa8) = func_0204AC18(h, 6, 0, 0xa0, 0, 2, *heap);
    W(0xa4) = func_0204A6C8(h, 0x10, 0, 0, *heap);
    W(0xac) = func_0204AF28(h, 0x1d, 0x2e, *heap);
    func_02049238(h);

    h = func_020490F4(0x9f, *heap);
    W(0xb4) = func_0204AC18(h, 5, 0, 0xe0, 0, 1, *heap);
    W(0xb0) = func_0204A6C8(h, 0xf, 0, 0, *heap);
    W(0xb8) = func_0204AF28(h, 0x1c, 0x2d, *heap);
    func_02049238(h);

    anim = data_021C8560;
    pri = data_021C8558;
    pal = data_021C8568;

    func_02082BCC(&pos, 0, sizeof(pos));
    for (i = 4; i < 7; i++)
        OBJ(i) = (u32)func_0204B294((void *)W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
    for (i = 0; i < 4; i++)
        OBJ(i) = (u32)func_0204B294((void *)W(0x1d0), W(0xa4), W(0xa8), W(0xac), &pos, 0, *heap);

    for (i = 0; i < 7; i++) {
        func_0204B878((struct Obj *)OBJ(i), anim.v[i]);
        func_0204B92C((struct Obj *)OBJ(i), 1);
        func_0204B84C(OBJ(i), pri.v[i]);
        func_0204B800((struct Node *)OBJ(i), pal.v[i]);
        func_0204B3DC((struct Obj *)OBJ(i), 0);
        func_0204B688((struct Actor *)OBJ(i), 1);
    }

    pt.x = 0x80;
    pt.y = 0x60;
    for (i = 0; i < 4; i++)
        func_0204B404((struct Obj *)OBJ(i), (const struct Vec2 *)(&pt), 0);

    p[0xd8] = 7;
}

/*
 * Tail: 021C044E..021C0450 is two zero alignment bytes, not a follower.
 */
void func_021C03C4(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 7; i++) func_0204B3B4(*(struct Obj **)(p + i * 4 + 0xbc));
    func_0204AFD8(((struct Obj02546 *)p)->fB8);
    func_0204A8D4(((struct Obj02546 *)p)->fB0);
    func_0204ADA4(((struct Obj02546 *)p)->fB4);
    func_0204AFD8(((struct Obj02546 *)p)->fAC);
    func_0204A8D4(((struct Obj02546 *)p)->fA4);
    func_0204ADA4(((struct Obj02546 *)p)->fA8);
    func_0204AFD8(((struct Obj02546 *)p)->fA0);
    func_0204A8D4(((struct Obj02546 *)p)->f98);
    func_0204ADA4(((struct Obj02546 *)p)->f9C);
    func_0204B1CC(*(struct Bank * *)&((struct Obj02546 *)p)->f1D0);
    func_0204B084(((struct Obj02546 *)p)->f1D4);
}


void ov208_func_021C0450(u16 *heap, u8 *p, int key)
{
    ObjPos pos;
    u8 i;

    func_02082BCC(&pos, 0, sizeof(pos));
    for (i = 0; i < 0x3d; i++) {
        pos.x = func_021BBB3C((char *)W(0x3c8), i, 0x19);
        pos.y = func_021BBB3C((char *)W(0x3c8), i, 0x1a);
        *(u32 *)(p + i * 4 + 0xdc) = (u32)func_0204B294((void *)W(0), W(0xb0), W(0xb4), W(0xb8), &pos, 0, *heap);
        func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xdc)), func_021BBB3C((char *)W(0x3c8), i, 0x18));
        func_0204B92C((struct Obj *)*(u32 *)(p + i * 4 + 0xdc), 1);
        func_0204B84C(*(u32 *)(p + i * 4 + 0xdc), 2);
        func_0204B800((struct Node *)(*(u32 *)(p + i * 4 + 0xdc)), 4);
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0xdc), 0);
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xdc)), 1);
    }
}


/*
 * Releases each of the 0x3D handles held from +0xDC on.
 */
void func_021C0524(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++)
        func_0204B3B4((struct Obj *)(*(int *)(p + i * 4 + 0xdc)));
}


void ov208_func_021C0544(u16 *heap, u8 *p, int key)
{
    int k;
    u8 i;
    u16 kind;
    u16 msg;
    ObjPos pos;

    k = ov208_func_021BC3A4(key);
    for (i = 0; i < 0x3d; i++) {
        msg = func_021BBB3C((char *)W(0x3c8), i, 0x10);
        if (msg != 0xffff) {
            if ((func_02166CD0(k, msg) == 0 ? 1 : 0)) {
                *(u32 *)(p + i * 8 + 0x1e0) = 1;
                *(u32 *)(p + i * 8 + 0x1e4) = 0;
            } else {
                kind = func_021BBB3C((char *)W(0x3c8), i, 0xb);
                pos.x = func_021BBB3C((char *)W(0x3c8), i, 2);
                pos.y = func_021BBB3C((char *)W(0x3c8), i, 3);
                pos.z = kind == 4 ? 0xe : 0x10;
                pos.pri = 5;
                pos.f7 = 2;
                *(u32 *)(p + i * 8 + 0x1e0) = 2;
                *(u32 *)(p + i * 8 + 0x1e4) = (u32)func_0204B294((void *)W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
                func_0204B92C((struct Obj *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
                func_0204B3DC((struct Obj *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
                func_0204B688((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
            }
        } else {
            *(u32 *)(p + i * 8 + 0x1e0) = 0;
            *(u32 *)(p + i * 8 + 0x1e4) = 0;
        }
    }
}


/*
 * Frees the second word of every entry whose first word is 2.
 */
void func_021C06A0(int unused, S *s)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++) {
        if (s->arr[i * 2] == 2)
            func_0204B3B4((struct Obj *)s->arr[i * 2 + 1]);
    }
}


void func_021C06C8(unsigned short *a, char *b, int a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = b + i * 4;
        ((struct Obj12126 *)e)->f34 = func_0201C440((void *)(*a));
        ((struct Obj12126 *)e)->f24 = 0;
    }
}


/*
 * Clears a word and releases two handles of each of four entries.
 */
void func_021C06EC(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = p + i * 4;
        ((struct Obj09204 *)e)->f24 = 0;
        func_0201C6EC((struct PrintSys *)(((struct Obj09204 *)e)->f34));
        func_0201C4C0((struct PrintSys *)(((struct Obj09204 *)e)->f34));
    }
}
