/*
 * file:     pokemontrade_3d_p14.c
 * unit:     yes
 * function: func_021E3E60, func_021E3E80, func_021E3F08, func_021E3F30, func_021E3F70, func_021E3F74, func_021E3FE4, func_021E4000, func_021E4068, func_021E40EC, func_021E4174, func_021E41A0, func_021E421C, func_021E42B4
 * address:  0x021E3E60
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
 *   func_0204A48C  0x0204A48C  arm
 *   d_021E7CC8     0x021E7CC8  data  ov119  a4
 *   d_021E7D40     0x021E7D40  data  ov119  a4
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_021E4324  0x021E4324  thumb  ov119
 *   func_0201F5DC  0x0201F5DC  thumb
 *   func_021E43DC 0x021E43DC thumb ov119
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02040618 0x02040618 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040588 0x02040588 arm
 *   d_021E7DD0 0x021E7DD0 data a4
 *   func_020414EC 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   func_02042FB0 0x02042FB0 arm
 */
#include "../../matched/include/Obj22800.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj10379.h"
#include "../../matched/include/Obj00908.h"
#include "../../matched/include/Obj13916.h"
#include "../../matched/include/Obj03780.h"
#include "../../matched/include/Obj13917.h"
#include "../../matched/include/Obj13918.h"

struct Cfg;
struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { unsigned int w[2]; } Tbl2;

extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_021D8AA8(void *);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_021E4324(char *p, int d);
extern void *func_0201F5DC(void *, unsigned, unsigned, unsigned);
extern void func_021E43DC(char *);
extern u32 func_020275E4(void);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021E6700(void *);
extern void func_020414EC(u32 i);
extern void func_02041B6C(u32 bit);
extern int func_021E4DBC(char *);
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
void func_021E3E60(void *p);
void func_021E3E80(char *p);
void func_021E3F08(char *p);
void func_021E3F30(char *p);
void func_021E3F70(void *p);
void func_021E3F74(char *p);
void func_021E3FE4(char *p);
void func_021E4000(char *p);
void func_021E4068(char *p);
void func_021E40EC(char *p, int a1, int a2);
void func_021E4174(char *p);
unsigned short func_021E41A0(int i, int row, char *p, int mode);
int func_021E421C(char *p, int x, int y);
void func_021E42B4(char *p);
extern int d_021E7CC8;
extern int d_021E7D40;
extern const Tbl2 d_021E7DD0;


/*
 * Tail call: forward the two ov119 data pointers and *(u16*)(p+0x5f4) to
 * the ARM helper. Non-SDK dep of func_021DFDA0's preamble.
 *
 * Addresses are Black-image addresses.
 */
void func_021E3E60(void *p)
{
    func_0204A48C((const struct Cfg *)(&d_021E7CC8), (u32)(&d_021E7D40), ((struct Obj22800 *)p)->f5F4);
}

void func_021E3E80(char *p)
{
    void *v;
    int kind;
    int mode;
    v = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    mode = func_021D8AA8(p);
    kind = 4;
    if (mode == 0)
        kind = 11;
    func_02049B68(v, 9, 0, 0, 0, ((struct Obj00001 *)p)->f5F4);
    if (*(int *)&((struct Obj00001 *)p)->f86C == 0)
        *(int *)&((struct Obj00001 *)p)->f86C = func_02049740(v, 10, 2, 0, 0, ((struct Obj00001 *)p)->f5F4);
    func_02049990(v, kind, (int)2, (int)0, (unsigned short)(((struct Obj00001 *)p)->f86C), (int)0, (int)0, (unsigned int)(((struct Obj00001 *)p)->f5F4));
    func_02049238(v);
}


void func_021E3F08(char *p)
{
    u32 v;

    v = ((struct Obj00001 *)p)->f86C;
    if (v != 0)
        func_0203FB44((int)2, (u16)v, (u16)(v >> 16));
    ((struct Obj00001 *)p)->f86C = 0;
}

void func_021E3F30(char *p)
{
    void *v;
    v = func_020490F4(0x66, ((struct Obj10379 *)p)->f5F4);
    func_02049990(v, 12, (int)4, (int)0, (unsigned short)(((struct Obj10379 *)p)->f870), (int)0, (int)0, (unsigned int)(((struct Obj10379 *)p)->f5F4));
    func_02049238(v);
}

/*
 * Empty stub.
 */
void func_021E3F70(void *p)
{
}


void func_021E3F74(char *p)
{
    void *v;

    v = func_020490F4(0x66, ((struct Obj00908 *)p)->f5F4);
    func_02049B68(v, 0x11, 4, 0, 0xC0, ((struct Obj00908 *)p)->f5F4);
    ((struct Obj00908 *)p)->f874 = (void *)func_02049740(v, 0xD, 7, 0, 0, ((struct Obj00908 *)p)->f5F4);
    ((struct Obj00908 *)p)->f870 = (void *)func_02049740(v, 0xD, 5, 0, 0, ((struct Obj00908 *)p)->f5F4);
    func_02049238(v);
    func_021E4324(p, (int)(((struct Obj00908 *)p)->f874));
}


void func_021E3FE4(char *p)
{
    ((struct Obj13916 *)p)->f644 = func_0201F5DC((void *)6, 15, 0, ((struct Obj13916 *)p)->f5F4);
}

void func_021E4000(char *p)
{
    func_021E43DC(p);
    if (((struct Obj00001 *)p)->f870) {
        func_0203FB44((int)5, (unsigned short)(((struct Obj00001 *)p)->f870), (unsigned short)(((struct Obj00001 *)p)->f870 >> 16));
        *(int *)&((struct Obj00001 *)p)->f870 = 0;
    }
    if (((struct Obj00001 *)p)->f874) {
        func_0203FB44((int)7, (unsigned short)(((struct Obj00001 *)p)->f874), (unsigned short)(((struct Obj00001 *)p)->f874 >> 16));
        *(int *)&((struct Obj00001 *)p)->f874 = 0;
    }
    if (*(unsigned int *)&((struct Obj00001 *)p)->f644) {
        func_0203FB44((int)6, (unsigned short)(*(unsigned int *)&((struct Obj00001 *)p)->f644), (unsigned short)(*(unsigned int *)&((struct Obj00001 *)p)->f644 >> 16));
        *(int *)&((struct Obj00001 *)p)->f644 = 0;
    }
}

void func_021E4068(char *p)
{
    void *v;
    int a;
    if (((struct Obj03780 *)p)->f888 == 0) {
        v = func_020490F4(func_020275E4(), ((struct Obj03780 *)p)->f5F4);
        ((struct Obj03780 *)p)->f8A4 = func_0204A6C8(v, func_02027618(), 0, 1, ((struct Obj03780 *)p)->f5F4);
        ((struct Obj03780 *)p)->f888 = func_0204AC18(v, func_02027614(), 1, 0, 0, 3, ((struct Obj03780 *)p)->f5F4);
        a = func_0202761C(2);
        ((struct Obj03780 *)p)->f8B8 = func_0204AF28(v, a, func_02027620(2), ((struct Obj03780 *)p)->f5F4);
        func_02049238(v);
    }
}

void func_021E40EC(char *p, int a1, int a2)
{
    Tbl2 tbl = d_021E7DD0;
    void *v;
    v = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    func_02049990(v, tbl.w[a2], 4, 0, (unsigned short)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    if (a1 != 0) {
        func_02040618(4, 0, 0x80);
    } else {
        func_02040618(4, 0, 0);
    }
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04, 0);
    func_02049238(v);
    func_02040588(4, 1);
}

void func_021E4174(char *p)
{
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    func_021E6700(p);
    func_020414EC(4);
    func_02041B6C(4);
}

unsigned short func_021E41A0(int i, int row, char *p, int mode)
{
    if (i >= ((struct Obj13917 *)p)->f638)
        i -= ((struct Obj13917 *)p)->f638;
    if (i < 12) {
        if (mode)
            return (*(unsigned short **)(p + 0x1180))[i + (row * 32 + 18)];
        else
            return (*(unsigned short **)(p + 0x1178))[i + (row * 32 + 18)];
    } else {
        i = (i - 12) % 20;
        if (mode)
            return (*(unsigned short **)(p + 0x117C))[i + (row * 32 + 18)];
        else
            return (*(unsigned short **)(p + 0x1174))[i + (row * 32 + 18)];
    }
}

/*
 * lever: initialize the inner counter before calculating the two outer cursors.
 */
int func_021E421C(char *p, int x, int y)
{
    int i, j, a, b;
    char *q, *r, *s;
    for (i = 0; i < 12; i++) {
        j = 0;
        q = p + i * 5;
        s = p + i * 20;
        for (; j < 5; j++) {
            if (*(unsigned char *)(q + j + 0xebc)) {
                r = s + j * 4;
                a = ((struct Obj13918 *)r)->fDCC - 5;
                b = ((struct Obj13918 *)r)->fDCE - 8;
                if (a < 0) a -= 8;
                a /= 8;
                b /= 8;
                if (a <= x && a + 3 > x && b <= y && b + 3 > y) return 1;
            }
        }
    }
    return 0;
}

void func_021E42B4(char *p)
{
    int x, y, n, mode;
    n = ((struct Obj00001 *)p)->f107C / 8;
    func_021E4DBC(p);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            mode = func_021E421C(p, x, y);
            func_02042FB0(7, x, y, func_021E41A0(n + x, y, p, mode));
        }
    }
    ((struct Obj00001 *)p)->f108C = ((struct Obj00001 *)p)->f107C % 8;
    ((struct Obj00001 *)p)->f1084 = 1;
    func_02041B6C(7);
}
