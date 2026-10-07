/*
 * file:     c_gear_p05.c
 * unit:     yes
 * function: func_021F1010, func_021F1060, func_021F11B4, func_021F122C, func_021F1290, func_021F133C, func_021F13FC, func_021F1458, func_021F1574, func_021F15FC, func_021F1624, func_021F1740, func_021F1758, func_021F18F0, func_021F1910, func_021F1950, func_021F1A44, func_021F1A64, func_021F1B30, func_021F1B50, func_021F1BBC, func_021F1BE4, func_021F1C0C, func_021F1CD8, func_021F1DB0, func_021F1DE8, func_021F1E98
 * address:  0x021F1010
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020409B4  0x020409B4  arm
 *   d_021F3324     0x021F3324  data  a4
 *   func_021F0B00  0x021F0B00  thumb  ov029
 *   func_021F0A68  0x021F0A68  thumb  ov029
 *   func_021F0A38  0x021F0A38  thumb  ov029
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   func_021F0FB0  0x021F0FB0  thumb  ov029
 *   func_021F1000  0x021F1000  thumb  ov029
 *   d_021F331C     0x021F331C  data  a4
 *   d_021F3410     0x021F3410  data  a4
 *   d_021F31D4     0x021F31D4  data  a2
 *   d_021F348C     0x021F348C  data  a4
 *   func_021F0AE0  0x021F0AE0  thumb  ov029
 *   d_021F3334     0x021F3334  data  a4
 *   func_021F0D14  0x021F0D14  thumb  ov029
 *   func_021F0C70  0x021F0C70  thumb  ov029
 *   func_0204162C  0x0204162C  arm
 *   d_021F3354     0x021F3354  data  a4
 *   d_021F323C     0x021F323C  data  a1
 *   func_021F2BB8  0x021F2BB8  thumb  ov029
 *   func_021F2BD4  0x021F2BD4  thumb  ov029
 *   func_020091AC  0x020091AC  thumb
 *   d_021F332C     0x021F332C  data  a4
 *   func_02049F78  0x02049F78  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021F09B4  0x021F09B4  thumb  ov029
 *   func_0203FA08  0x0203FA08  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   d_021F31E0     0x021F31E0  data  a4
 *   d_021F31A8     0x021F31A8  data  ov029  a1
 *   d_021F32E0     0x021F32E0  data  a4
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0203D88C  0x0203D88C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_021F31C8     0x021F31C8  data  a4
 *   d_021F33CC     0x021F33CC  data  a4
 *   func_02040588  0x02040588  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02041300  0x02041300  arm
 *   d_021F338C     0x021F338C  data  ov029  a4
 *   d_021F33AC     0x021F33AC  data  a4
 *   d_021F336C     0x021F336C  data  ov029  a4
 *   func_0207D63C 0x0207D63C arm
 *   func_020355D8  0x020355D8  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021F020C  0x021F020C  thumb  ov029
 *   func_021F0D80  0x021F0D80  thumb  ov029
 *   func_021EFEC0  0x021EFEC0  thumb  ov029
 *   func_021F2AEC  0x021F2AEC  thumb  ov029
 *   func_020061E4  0x020061E4  thumb
 *   func_021F2DA8  0x021F2DA8  thumb  ov029
 *   func_0203FB44  0x0203FB44  arm
 *   func_020090E8  0x020090E8  thumb
 *   func_0204B908  0x0204B908  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02043598  0x02043598  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204BA20  0x0204BA20  arm
 *   func_021F1F80  0x021F1F80  thumb  ov029
 *   func_021F20AC  0x021F20AC  thumb  ov029
 *   d_021F3526     0x021F3526  data  ov029  a1
 *   d_021F3531     0x021F3531  data  ov029  a1
 *   d_021F353C     0x021F353C  data  ov029  a1
 *   d_021F3548     0x021F3548  data  ov029  a4
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021F05B4  0x021F05B4  thumb  ov029
 *   func_02026C8C  0x02026C8C  thumb
 *   func_02026CA0  0x02026CA0  thumb
 *   func_02026C78  0x02026C78  thumb
 *   func_02165CD8  0x02165CD8  thumb  ov010
 *   func_020215BC  0x020215BC  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020090F0  0x020090F0  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_02051B84  0x02051B84  arm
 *   d_021F3214     0x021F3214  data  a4
 *   d_021F3272     0x021F3272  data  a2
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 */
#include "../../matched/include/Obj00106.h"
#include "../../matched/include/Obj00042.h"
#include "../../matched/include/Obj04308.h"
#include "../../matched/include/Obj05116.h"
#include "../../matched/include/Obj02749.h"
#include "../../matched/include/Obj20392.h"
#include "../../matched/include/Obj13046.h"
#include "../../matched/include/Obj00811.h"
#include "../../matched/include/Obj06128.h"
#include "../../matched/include/Obj20395.h"
#include "../../matched/include/Obj00709.h"
#include "../../matched/include/Obj02111.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
struct Sub020090B0Obj;
struct Actor;
struct Obj;
struct PalAnmSlot;
struct S;
struct Bank;
struct Ctx;
struct Sub0200852CObj;
typedef struct { int a, b; } Pair;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { u8 key, row, col, v; } Ent;

typedef struct { int w[6]; } Tab;

struct W {
    u8 pad0[0x230];
    u16 unk_230[3][5];
};

typedef signed int     s32;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

extern void func_020409B4(u32 index);
extern void func_021F0B00(void *q, void *p, u8 a, int b, int c, u16 d);
extern int func_021F0A68(char *p);
extern void func_021F0A38(unsigned char *p);
extern u32 func_021F2B9C(u8 *p, int row, int col);
extern void func_021F0FB0(char *p);
extern int func_021F1000(char *p);
extern void func_021F0AE0(void *q, void *p, int k);
extern void func_021F0D14(int a, int b, int *x, int *y);
extern int func_021F0C70(void *p, int i, int j, int k);
extern u32 func_0204162C(int channel);
extern int func_021F2BB8(unsigned char *p, int row, int col);
extern int func_021F2BD4(u8 *p, int row, int col, int kind);
extern void func_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind, int marked, int flagged);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E468(void *a, u32 b, u32 c);
extern u32 func_020307B0(void *p);
extern void func_021F09B4(unsigned char *p, unsigned char *q, int n);
extern u32 func_0203FA08(u32 a, u32 b, u32 c);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 func_0204ABF0(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
extern s32 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void func_0203D88C(u32 a, u32 b);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_0207D63C(u32, int, int, int, int);
extern void func_020355D8(u8 v);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_021F020C(const void *p, int a, int b, int *c, int *d);
extern int func_021F0D80(void *p, int k);
extern int func_021EFEC0(int a, int b);
extern void func_021F2AEC(unsigned char *p, int a1, int a2, int a3, int k);
extern void func_020061E4(u32 id);
extern int func_021F2DA8(u8 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020090E8(struct Sub020090B0Obj *obj, u8 value);
extern void func_0204B908(int, int);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_02043598(u32 mask, u32 enable);
extern int func_02085D3C(void);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_021F1F80(char *p);
extern void func_021F20AC(char *p);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern int func_021F05B4(unsigned char *p);
extern u32 func_02026C8C(void);
extern int func_02026CA0(int *p);
extern void *func_02026C78(int n);
extern u8 func_02165CD8(struct S *p);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void *func_020120F4(const struct Ctx *p);
extern unsigned char *func_02012944(void *p);
extern unsigned char func_02008550(const struct Sub0200852CObj *obj);
extern unsigned char func_020090F0(const struct Sub020090B0Obj *obj);
extern struct Bank *func_0204B100(int count, unsigned char flag, u32 heapId);
extern struct Obj *func_0204B034(unsigned char *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
void func_021F1010(void *p);
int func_021F1060(u8 *p);
int func_021F11B4(char *p);
void func_021F122C(char *p);
void func_021F1290(void *q, int a, int b, int c);
int func_021F133C(char *p, int v, int *o1, int *o2);
void func_021F13FC(void *p);
u32 func_021F1458(u8 *p, int a, int b, int c);
void func_021F1574(char *p, int idx);
void func_021F15FC(char *p, int flag);
void func_021F1624(void *p);
void func_021F1740(void *p);
void func_021F1758(u8 *p, int key);
void func_021F18F0(int key, int flag, u8 *p);
void func_021F1910(char *p, int on);
void func_021F1950(char *p);
void func_021F1A44(char *p, int flag);
void func_021F1A64(char *p, int flag);
void func_021F1B30(char *p, int flag);
void func_021F1B50(char *p);
void func_021F1BBC(char *p);
int func_021F1BE4(char *p);
void func_021F1C0C(char *p);
void func_021F1CD8(char *p);
void func_021F1DB0(char *p);
void func_021F1DE8(char *p, int flag);
void func_021F1E98(char *p);
extern const Pair d_021F3324;
extern const Pair d_021F331C;
extern const Ent d_021F3410[];
extern const u16 d_021F31D4[];
extern const Ent d_021F348C[];
extern const Pair d_021F3334;
extern const Tab d_021F3354;
extern const u8 d_021F323C[];
extern const int d_021F332C[2];
extern const int d_021F31E0[];
extern const u8 d_021F31A8[];
extern const int d_021F32E0[][3];
extern const int d_021F31C8[];
extern const int d_021F33CC[];
extern struct BgTemplate d_021F338C;
extern struct BgTemplate d_021F33AC;
extern struct BgTemplate d_021F336C;
extern const u8 d_021F3526[];
extern const u8 d_021F3531[];
extern const u8 d_021F353C[];
extern const int d_021F3548[];
extern char d_021F3214[];
extern char d_021F3272[];


void func_021F1010(void *p)
{
    Pair t = d_021F3324;
    int i, j, n;

    for (i = 0; i < 9; i++) {
        n = ((int *)&t)[i % 2];
        for (j = 0; j < n; j++)
            func_021F1290(p, i, j, 0);
    }
    func_020409B4(4);
}


int func_021F1060(u8 *p)
{
    Pair t = d_021F331C;
    int i, j, n;
    unsigned int k;
    const Ent *e;
    int v;
    int col;
    int row;

    switch (p[0x455]) {
    case 0:
        for (i = 0; i < 9; i++) {
            n = ((int *)&t)[i % 2];
            for (j = 0; j < n; j++)
                func_021F0B00(p + 0x2D0 + i * 0x20 + j * 8, p, 4, 1, 4, 2);
        }
        p[0x455]++;
        break;
    case 1:
        if (func_021F0A68((char *)p) == 0)
            p[0x455]++;
        break;
    case 2:
        for (k = 0; k < 0x1F; k++) {
            e = &d_021F3410[k];
            if (p[0x456] == d_021F3410[k].key) {
                col = e->col;
                row = e->row;
                v = func_021F2B9C(p, row, col);
                func_021F0B00(p + 0x2D0 + row * 0x20 + col * 8, p, d_021F31D4[v], 2, v, e->v);
            }
        }
        if (p[0x456] >= 4) {
            func_021F0FB0((char *)p);
            func_021F1A44((char *)p, 1);
            p[0x455]++;
        }
        p[0x456]++;
        break;
    case 3:
        if (func_021F0A68((char *)p) == 0 && func_021F1000((char *)p) == 0)
            return 1;
        break;
    }
    func_021F0A38(p);
    return 0;
}


/*
 * The byte at +0x456 must be spelled out at each use (no cached pointer
 * local): a local pointer makes the increment reload the pool constant.
 */
int func_021F11B4(char *p)
{
    unsigned int i;

    if (((struct Obj00106 *)p)->f456 <= 0x7E) {
        for (i = 0; i < 0x24; i++) {
            if (((struct Obj00106 *)p)->f456 == d_021F348C[i].key)
                func_021F0B00(p + 0x2D0 + d_021F348C[i].row * 0x20 + d_021F348C[i].col * 8,
                              p, 4, 0, 4, d_021F348C[i].v);
        }
        ((struct Obj00106 *)p)->f456 = ((struct Obj00106 *)p)->f456 + 1;
    } else {
        if (func_021F0A68(p) == 0)
            return 1;
    }
    func_021F0A38((unsigned char *)p);
    return 0;
}


void func_021F122C(char *p)
{
    Pair t = d_021F3334;
    char *base;
    int i, j, n;

    i = 0;
    base = p + 0x2D0;
    for (; i < 9; i++) {
        n = ((int *)&t)[i % 2];
        for (j = 0; j < n; j++)
            func_021F0AE0(base + i * 0x20 + j * 8, p, 4);
    }
}


/*
 * note 2026-10-05 (wD7 lane15): closed. The table entry is a named block local (w = t.w[c]) in the
 *   store block. mwcc puts a named local first in `w + o` (adds r0,r0,r4); the plain t.w[c] load
 *   is a temp and goes second, which was the last 2-byte residue.
 */
void func_021F1290(void *q, int a, int b, int c)
{
    Tab t = d_021F3354;
    int y, x, xx, v, pal, i, yy, j;
    u16 *buf;

    buf = (u16 *)func_0204162C(4);
    func_021F0D14(a, b, &y, &x);
    v = d_021F31D4[c];
    pal = func_021F0C70(q, v, a, b);
    xx = x;
    for (i = 0; i < 4; i++) {
        int o = i * 32;
        u16 *row = buf + xx * 32;
        yy = y;
        for (j = 0; j < 4; j++) {
            if (yy >= 0 && yy < 0x20) {
                int w = t.w[c];
                row[yy] = (w + o + j) | ((d_021F323C + v * 5)[pal] << 12);
            }
            yy++;
        }
        xx++;
    }
}


int func_021F133C(char *p, int v, int *o1, int *o2)
{
    int a = 0;
    int b = 0;
    int found = 0;
    int i;
    int j;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (v == func_021F2B9C((unsigned char *)p, i, j)) {
                if (found == 0) {
                    a = i;
                    b = j;
                    found = 1;
                }
                if (func_021F2BB8((unsigned char *)p, i, j)) {
                    func_021F0D14(i, j, o1, o2);
                    return 1;
                }
                if (func_021F2BD4((u8 *)p, i, j, v)) {
                    a = i;
                    b = j;
                    found = 1;
                }
            }
        }
    }
    if (found) {
        func_021F0D14(a, b, o1, o2);
        func_020091AC((struct Sub020090B0Obj *)(*(int *)&((struct Obj00042 *)p)->f20), a, b, v, 1, 0);
        func_021F1290(p, a, b, v);
        func_020409B4(4);
        return 1;
    }
    return 0;
}


void func_021F13FC(void *p)
{
    int t[2];
    int i;
    int j;
    int n;

    t[0] = d_021F332C[0];
    t[1] = d_021F332C[1];
    for (i = 0; i < 9; i++) {
        n = t[i % 2];
        for (j = 0; j < n; j++)
            func_021F1290(p, i, j, func_021F2B9C(p, i, j));
    }
    func_020409B4(4);
}


/*
 * The 0x230 table must be a struct member (u16 [3][5]); a raw cast keeps
 * p + 0x230 in ip and spills the source pointer instead. `n` is declared
 * before `r` so the counter lands at [sp,#0x20] and the handle at [sp,#0x1c].
 */
u32 func_021F1458(u8 *p, int a, int b, int c)
{
    int n;
    int r;
    char *loc;
    u8 *src;
    int m;
    int k;
    u32 size;
    u32 v;

    if (c) {
        r = (int)func_02049F78((void *)(((struct Obj04308 *)p)->f24), d_021F31E0[a], (u32)(&loc), 0x8070);
        func_020862F0(((struct Obj05116 *)loc)->fC, ((struct Obj05116 *)loc)->f8);
        func_0207E468(((struct Obj05116 *)loc)->fC, 0, ((struct Obj05116 *)loc)->f8);
        src = *(u8 * *)&((struct Obj05116 *)loc)->fC;
        for (n = 0; n < 5; n++) {
            for (m = 0; m < 3; m++) {
                ((struct W *)p)->unk_230[m][n] = ((u16 *)(src + (n + 1) * 0x20))[d_021F31A8[m]];
            }
        }
        func_020307B0((void *)r);
        r = (int)func_02049F78((void *)(((struct Obj04308 *)p)->f24), 0x17, (u32)(&loc), 0x8070);
        for (k = 0; k < 9; k++) {
            func_021F09B4(p, ((struct Obj05116 *)loc)->fC, k);
        }
        func_020307B0((void *)r);
    }
    size = 0x5000;
    v = func_0203FA08(6, size, 0);
    ((struct Obj04308 *)p)->f14 = (u16)v | (size << 16);
    func_02049658((void *)(((struct Obj04308 *)p)->f24), d_021F32E0[b][a], 6, v, 0, 0, 0x70);
    return func_02049990((void *)(((struct Obj04308 *)p)->f24), 2, 6, 0, (u16)((struct Obj04308 *)p)->f14, 0, 0, 0x70);
}


/*
 * note:     the two tables are `const`: non-const, the copy of p lands after the first
 *           stack-argument store (4 bytes out). The loop needs i = 0 hoisted first, the
 *           base hoisted and q = p + i*4 with q[0x6e].
 */
void func_021F1574(char *p, int idx)
{
    int i;
    int r;
    char *loc;
    int *base;
    int *q;

    i = 0;
    ((struct Obj02749 *)p)->f28 = func_0204ABF0((void *)(((struct Obj02749 *)p)->f24), d_021F31C8[idx], 1, 0, 0x70);
    ((struct Obj02749 *)p)->f2C = func_0204A6C8((void *)(((struct Obj02749 *)p)->f24), 0x16, 0, 1, 0x70);
    ((struct Obj02749 *)p)->f30 = func_0204AF28((void *)(((struct Obj02749 *)p)->f24), 0x15, 0x14, ((struct Obj02749 *)p)->fC);
    r = (int)func_02049F78((void *)(((struct Obj02749 *)p)->f24), 0x18, (unsigned int)(&loc), ((struct Obj02749 *)p)->fC);
    base = *(int * *)&((struct Obj20392 *)loc)->fC;
    for (; i < 17; i++) {
        q = (int *)(p + i * 4);
        q[0x6e] = base[d_021F33CC[i]];
    }
    func_020307B0((void *)r);
    func_0203D88C(0xda, 0xe);
    func_0203D34C(0, ((struct Obj02749 *)p)->fC);
}

void func_021F15FC(char *p, int flag)
{
    if (flag == 0)
        func_02049990((void *)(((struct Obj13046 *)p)->f24), 1, 5, 0, (u16)((struct Obj13046 *)p)->f14, 0, 0, 0x70);
}


/*
 * volatile: 0x021F1722 ldr / 0x021F1726 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write, hardware register)
 *
 * Twin of ov030 func_021EFF54 (same three BgTemplate blocks), plus the
 * func_021F1740 call and the sub-screen window-mask clear. d_021F33AC's
 * ov029 hint is contested by another overlay, so its line carries only a4.
 */
void func_021F1624(void *p)
{
    int i;

    for (i = 4; i <= 7; i++) {
        func_02040588((u8)i, 0);
    }
    {
        struct BgTemplate t = d_021F338C;
        func_0203FCA0(6, &t, 0);
        func_02040588((u8)6, 1);
        func_0204047C(6, 3);
        func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(6);
    }
    {
        struct BgTemplate t = d_021F33AC;
        func_0203FCA0(5, &t, 0);
        func_02040588((u8)5, 1);
        func_0204047C(5, 1);
        func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(5);
    }
    {
        struct BgTemplate t = d_021F336C;
        func_0203FCA0(4, &t, 0);
        func_02040588((u8)4, 1);
        func_0204047C(4, 2);
        func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(4);
    }
    func_021F1740(p);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}

void func_021F1740(void *p)
{
    func_0207D63C(0x04001050, 2, 0x15, 9, 0x10);
}


/*
 * Stack order: c, d, x, y declared in that order ([sp,#0x10], #0xc, #8, #4).
 * The inner switch lists case 3 before case 2 (bodies 1, 6, 5 in the image).
 * func_021EFEC0 is the unlabelled ov029 leaf filed as ov029_func_021EFEC0.c.
 */
void func_021F1758(u8 *p, int key)
{
    int c;
    int d;
    int x;
    int y;
    int r;
    u32 v;

    if (p[0x45A] == 0 && key != 6 && key != 0)
        return;
    if (((struct Obj00042 *)p)->f214 != 0)
        return;
    func_020355D8(1);
    switch (key) {
    case 0:
        (int)func_02035CB8((u32 *)(&x), (u32 *)(&y));
        r = func_021F020C(p, x, y, &c, &d);
        if (p[0x457] != 0) {
            ((struct Obj00042 *)p)->f2CC = x;
            ((struct Obj00042 *)p)->f2CE = y;
            if ((func_021F0D80(p, r) > 1 || r == 4) && func_021EFEC0(c, d) != 0) {
                func_021F2AEC((unsigned char *)p, *(int *)&((struct Obj00042 *)p)->f20, c, d, (r + 1) % 5);
                func_020409B4(4);
                func_020061E4(0x628);
            }
        } else if (func_021F2DA8(p) == 0) {
            p[0x452] = c;
            p[0x453] = d;
            switch (r) {
            case 1:
                ((struct Obj00042 *)p)->f214 = 1;
                break;
            case 3:
                ((struct Obj00042 *)p)->f214 = 6;
                break;
            case 2:
                ((struct Obj00042 *)p)->f214 = 5;
                break;
            }
        }
        break;
    case 1:
        func_020061E4(0x628);
        p[0x457] ^= 1;
        func_021F1910((char *)p, p[0x457]);
        break;
    case 2:
        ((struct Obj00042 *)p)->f214 = 0xC;
        break;
    case 3:
        ((struct Obj00042 *)p)->f214 = 7;
        break;
    case 4:
        ((struct Obj00042 *)p)->f214 = 0xB;
        break;
    case 5:
        func_020061E4(0x628);
        v = ((struct Obj00042 *)p)->f14;
        func_0203FB44((int)6, (u16)v, (u16)(v >> 16));
        p[0x458]++;
        p[0x458] = p[0x458] % 5;
        func_020090E8((struct Sub020090B0Obj *)(*(int *)&((struct Obj00042 *)p)->f20), p[0x458]);
        func_021F1458(p, p[0x459], p[0x458], 0);
        func_021F13FC(p);
        func_021F1A44((char *)p, 1);
        break;
    case 6:
        ((struct Obj00042 *)p)->f214 = 0xD;
        break;
    }
}

void func_021F18F0(int key, int flag, u8 *p)
{
    if (func_021F2DA8(p) == 0 && flag == 0)
        func_021F1758(p, key);
}


void func_021F1910(char *p, int on)
{
    if (on) {
        func_0204B908(((struct Obj00811 *)p)->f150, 0);
        func_0204B954((struct Actor *)(((struct Obj00811 *)p)->f150), 0x2000);
        func_0204B92C((struct Obj *)((struct Obj00811 *)p)->f150, 1);
    } else {
        func_0204B92C((struct Obj *)((struct Obj00811 *)p)->f150, 0);
        func_0204B908(((struct Obj00811 *)p)->f150, 1);
    }
}


void func_021F1950(char *p)
{
    int i;
    int j;
    S13Rec s;
    int *q;

    func_02043598(0x10, 1);
    j = 0;
    for (i = 0; i < 11; i++) {
        s.x = d_021F3531[i];
        s.y = d_021F353C[i];
        s.z = d_021F3526[i];
        if (s.z == 6 && func_02085D3C()) {
            s.z = 7;
        }
        s.a = 0;
        s.b = 2;
        q = (int *)(p + i * 4);
        q[0x4b] = (int)func_0204B294((void *)((struct Obj00811 *)p)->f34, ((struct Obj00811 *)p)->f2C, ((struct Obj00811 *)p)->f28,
                                ((struct Obj00811 *)p)->f30, &s, 0, ((struct Obj00811 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x4b], 0);
        func_0204BA20((struct Actor *)q[0x4b], 0);
    }
    func_021F1910(p, 0);
    for (j = 0; j < 3; j++) {
        s.x = 8;
        s.y = 8;
        s.z = d_021F3548[j];
        s.a = 0;
        s.b = 2;
        q = (int *)(p + j * 4);
        q[0x56] = (int)func_0204B294((void *)((struct Obj00811 *)p)->f34, ((struct Obj00811 *)p)->f2C, ((struct Obj00811 *)p)->f28,
                                ((struct Obj00811 *)p)->f30, &s, 0, ((struct Obj00811 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x56], 0);
        func_0204BA20((struct Actor *)q[0x56], 0);
    }
    func_021F1F80(p);
    func_021F20AC(p);
}

void func_021F1A44(char *p, int flag)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x158), flag);
}


void func_021F1A64(char *p, int flag)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (*(int *)(p + i * 12 + 0x3c) != 0) {
            func_0204B3DC((struct Obj *)*(int *)(p + i * 12 + 0x3c), flag);
        }
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 4 + 0x158) != 0 && ((struct Obj00106 *)p)->f45A != 0) {
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x158), flag);
        }
    }
    for (i = 0; i < 11; i++) {
        if (*(int *)(p + i * 4 + 0x12c) != 0) {
            if ((unsigned)(i - 8) <= 1) {
                if (((struct Obj00106 *)p)->f45A != 0) {
                    func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x12c), flag);
                }
            } else {
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x12c), flag);
            }
        }
    }
    if (((struct Obj00106 *)p)->f164 != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f164, flag);
    }
    if (((struct Obj00106 *)p)->f168 != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f168, flag);
    }
    if (((struct Obj00106 *)p)->f16C != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f16C, flag);
    }
    if (flag == 1) {
        func_021F1F80(p);
    }
}

void func_021F1B30(char *p, int flag)
{
    int i;
    for (i = 0; i < 18; i++)
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x170), flag);
}


void func_021F1B50(char *p)
{
    int i;
    S13Rec s;
    int *q;

    for (i = 0; i < 18; i++) {
        s.x = 0x80;
        s.y = 0x60;
        s.z = i + 0x12;
        s.a = 0;
        s.b = 2;
        q = (int *)(p + i * 4);
        q[0x5c] = (int)func_0204B294((void *)((struct Obj06128 *)p)->f34, ((struct Obj06128 *)p)->f2C, ((struct Obj06128 *)p)->f28,
                                ((struct Obj06128 *)p)->f30, &s, 0, ((struct Obj06128 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x5c], 0);
        func_0204B954((struct Actor *)q[0x5c], 0x2000);
        func_0204B9A0((struct Actor *)q[0x5c]);
        func_0204B92C((struct Obj *)q[0x5c], 1);
    }
}

void func_021F1BBC(char *p)
{
    int i;
    if (((struct Obj20395 *)p)->f170 != 0) {
        for (i = 0; i < 18; i++) {
            func_0204B3B4((struct Obj *)(*(int *)(p + i * 4 + 0x170)));
            *(int *)(p + i * 4 + 0x170) = 0;
        }
    }
}

int func_021F1BE4(char *p)
{
    int i;
    for (i = 0; i < 18; i++) {
        if (func_0204B98C((struct Actor *)(*(int *)(p + i * 4 + 0x170))) == 1)
            return 0;
    }
    return 1;
}


void func_021F1C0C(char *p)
{
    S13Rec s;

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x28;
    s.a = 0;
    s.b = 2;
    ((struct Obj00709 *)p)->f164 = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f164, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f164), 0);

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x27;
    s.a = 0x14;
    s.b = 2;
    ((struct Obj00709 *)p)->f168 = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f168, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f168), 0);

    s.x = 0x22;
    s.y = 0xaa;
    s.z = 0x10;
    s.a = 0;
    s.b = 2;
    ((struct Obj00709 *)p)->f16C = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f16C, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f16C), 0);
}


void func_021F1CD8(char *p)
{
    int n;
    int cnt;
    int k;
    int tmp;
    void *e;

    cnt = 0;
    if (((struct Obj00042 *)p)->f45A == 0) {
        return;
    }
    if (func_021F05B4((unsigned char *)p) != 0) {
        return;
    }
    n = func_02026C8C();
    if (((struct Obj00042 *)p)->f450 == 0) {
        tmp = 0;
        if (func_02026CA0(&tmp) != 30) {
            ((struct Obj00042 *)p)->f450 = 1;
        }
    }
    n--;
    for (k = 0; k < 30; k++) {
        if (cnt >= 10) {
            break;
        }
        if (n < 0) {
            func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00042 *)p)->f210), p + 0x1f8, (int)3, (u16)(d_021F33CC[cnt] * 2 + 0x60), 4);
            cnt++;
        } else {
            e = func_02026C78(n);
            if (e != 0) {
                func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00042 *)p)->f210), (u32 *)(p + 0x1b8) + func_02165CD8(e), (int)3,
                              (u16)(d_021F33CC[cnt] * 2 + 0x60), 4);
                cnt++;
            }
            n--;
        }
    }
}

void func_021F1DB0(char *p)
{
    if (((struct Obj02111 *)p)->f164 != 0) {
        func_0204B3B4((struct Obj *)(((struct Obj02111 *)p)->f164));
        ((struct Obj02111 *)p)->f164 = 0;
    }
    if (((struct Obj02111 *)p)->f168 != 0)
        func_0204B3B4((struct Obj *)(((struct Obj02111 *)p)->f168));
    if (((struct Obj02111 *)p)->f16C != 0) {
        func_0204B3B4((struct Obj *)(((struct Obj02111 *)p)->f16C));
        ((struct Obj02111 *)p)->f16C = 0;
    }
}


void func_021F1DE8(char *p, int flag)
{
    int z;

    ((struct Obj00106 *)p)->f459 = func_02008550((const struct Sub0200852CObj *)func_02012944((void *)func_020120F4((const struct Ctx *)(((struct Obj00106 *)p)->f1C))));
    ((struct Obj00106 *)p)->f458 = func_020090F0((const struct Sub020090B0Obj *)(((struct Obj00106 *)p)->f20));
    z = 0;
    ((struct Obj00106 *)p)->f34 = (int)func_0204B100(0x44, 0, ((struct Obj00106 *)p)->fC);
    ((struct Obj00106 *)p)->f38 = func_0204B034((unsigned char *)d_021F3214, 1, ((struct Obj00106 *)p)->fC);
    func_0204B258((struct Bank *)(((struct Obj00106 *)p)->f34), ((struct Obj00106 *)p)->f38);
    func_021F1458((unsigned char *)p, ((struct Obj00106 *)p)->f459, ((struct Obj00106 *)p)->f458, 1);
    func_021F1574(p, ((struct Obj00106 *)p)->f459);
    func_021F1950(p);
    func_021F1C0C(p);
    ((struct Obj00106 *)p)->f10 = (int)func_02051B84((u8 *)d_021F3272, (int)((void *)func_021F18F0), (int)p, ((struct Obj00106 *)p)->fC);
    if (flag) {
        func_021F1010(p);
        func_021F1A64(p, z);
    } else {
        func_021F13FC(p);
        func_021F1A64(p, 1);
        func_021F1A44(p, 1);
    }
}


void func_021F1E98(char *p)
{
    int i;
    int *q;
    unsigned int v;

    func_021F1DB0(p);
    func_021F1BBC(p);
    for (i = 0; i < 11; i++) {
        q = (int *)(p + i * 4);
        if (q[0x4b] != 0) {
            func_0204B3B4((struct Obj *)q[0x4b]);
            q[0x4b] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        q = (int *)(p + i * 4);
        if (q[0x56] != 0) {
            func_0204B3B4((struct Obj *)q[0x56]);
            q[0x56] = 0;
        }
    }
    for (i = 0; i < 20; i++) {
        q = (int *)(p + i * 12);
        if (q[0xf] != 0) {
            func_0204B3B4((struct Obj *)q[0xf]);
            q[0xf] = 0;
        }
    }
    func_0204AFD8(((struct Obj02111 *)p)->f30);
    func_0204A8D4(((struct Obj02111 *)p)->f2C);
    func_0204ADA4(((struct Obj02111 *)p)->f28);
    v = ((struct Obj02111 *)p)->f14;
    func_0203FB44((int)6, (unsigned short)v, (unsigned short)(v >> 16));
}
