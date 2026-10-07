/*
 * file:     union_oneself_p08.c
 * unit:     yes
 * function: func_0217E904, func_0217EAD8, func_0217EC04, func_0217EC1C, func_0217EC28, func_0217EC34, func_0217EC40, func_0217EC54, func_0217EC68, func_0217EC78, func_0217EC88, func_0217EC94, func_0217ECA0, func_0217ECAC, func_0217ECB8, func_0217ECD0, func_0217ECE8, func_0217ED04, func_0217ED10, func_0217ED2C, func_0217ED48, func_0217ED64, func_0217ED80, func_0217ED8C, func_0217ED98, func_0217EDA4, func_0217EDB0, func_0217EDBC, func_0217EDC8, func_0217EDD4, func_0217EDE0, func_0217EDEC, func_0217EDF8, func_0217EE04, func_0217EE10, func_0217EE1C
 * address:  0x0217E904
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217FEB8  0x0217FEB8  thumb  ov019
 *   func_0217AE20  0x0217AE20  thumb  ov019
 *   func_02174F34  0x02174F34  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_02173408  0x02173408  thumb  ov012
 *   func_02173524  0x02173524  thumb  ov012
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012124  0x02012124  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0203D378  0x0203D378  arm
 *   func_020392B8  0x020392B8  arm
 *   func_02039338  0x02039338  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0217F098  0x0217F098  thumb  ov019
 *   func_0217F188  0x0217F188  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0216F7F4  0x0216F7F4  thumb  ov010
 *   func_0200855C  0x0200855C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02008550 0x02008550 thumb
 *   d_0218031C 0x0218031C data a2
 *   d_0218034C  0x0218034C  data a2
 *   d_02180330  0x02180330  data a2
 *   d_02180348  0x02180348  data a2
 *   d_021805E4 0x021805E4 data a2
 *   d_02180648  0x02180648  data a2
 *   d_0218053C  0x0218053C  data a2
 *   d_02180570  0x02180570  data a2
 *   d_02180300  0x02180300  data a2
 *   d_0218032C  0x0218032C  data a2
 *   d_02180320  0x02180320  data a2
 *   d_02180318  0x02180318  data a2
 *   d_02180328 0x02180328 data a2
 *   d_02180324 0x02180324 data a2
 *   func_020056EC 0x020056EC thumb
 *   d_02180380 0x02180380 data a2
 *   d_0218033C  0x0218033C  data a2
 *   d_02180368 0x02180368 data a2
 *   d_02180370 0x02180370 data a2
 *   d_02180360 0x02180360 data a2
 *   d_02180390     0x02180390  data  a2
 *   d_02180314  0x02180314  data a2
 *   d_02180310  0x02180310  data a2
 *   d_02180340  0x02180340  data a2
 *   d_02180304  0x02180304  data a2
 *   d_02180308  0x02180308  data a2
 *   d_02180344  0x02180344  data a2
 *   d_02180350  0x02180350  data a2
 *   d_02180338  0x02180338  data a2
 *   d_0218035C  0x0218035C  data a2
 *   d_02180358  0x02180358  data a2
 *   d_02180354  0x02180354  data a2
 *   d_021802F8  0x021802F8  data a2
 *   d_021802F0  0x021802F0  data a2
 *   d_021802F4  0x021802F4  data a2
 */
#include "../../matched/include/Obj00033.h"
#include "../../matched/include/Obj05956.h"

struct Ctx;
struct Entry;
struct Link;
struct Sub0200852CObj;
struct WordSet;
typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys_0217E904;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Bits;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
    int f8;
} Sys_0217EAD8;

u32 func_0217F1EC(u8 *p);
void func_0217F210(u8 *p, u8 *a, u32 b);
void func_0217F074(void *p);
void func_0217BAF0(char *p, int x, unsigned int v);
int func_0217FEB8(u8 *p);
void func_0217AE20(u8 *w);
int func_02174F34(void);
int func_02172D68(u8 *w);
void func_02172D38(u8 *w);
void func_02172D50(u8 *w);
void func_02173408(u8 *w);
void func_02173524(u8 *w, u8 *q);
void func_0217422C(u8 *p, int a, int b);
int func_02174268(u8 *w);
void func_0217505C(int *p, int x);
u32 func_0200FB24(void);
void func_02012124(struct Ctx *p, u32 v);
struct Entry *func_020399A8(void);
void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
void func_0203D7BC(u8 a0);
u32 func_0203D378(void);
int func_020392B8(void);
u16 func_02039338(void);
u32 func_0203D1C0(u32 index);
void func_0217F098(unsigned char *base, u8 *x);
void func_0217F188(char *p, u32 arg);
int func_0217B8E4(char *p, int v);
void *func_0216F7F4(int a, u8 *e, int b);
u8 func_0200855C(const struct Sub0200852CObj *obj);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
u32 func_020362DC(void);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_020056EC(u32 v);
int func_0217E904(u8 *w, u8 *obj, u8 *a2, u8 *state);
int func_0217EAD8(u8 *w, void *obj, u8 *a2, u8 *state);
u16 func_0217EC04(void ***ctx);
u16 func_0217EC1C(int i);
u16 func_0217EC28(int i);
u16 func_0217EC34(int i);
u16 func_0217EC40(int i, int j);
u16 func_0217EC54(int i, int j);
u16 func_0217EC68(int i);
u16 func_0217EC78(int i);
u16 func_0217EC88(int i);
u16 func_0217EC94(int i);
u16 func_0217ECA0(int i);
u16 func_0217ECAC(int i);
u16 func_0217ECB8(void ***ctx);
u16 func_0217ECD0(void ***ctx);
u16 func_0217ECE8(int i);
u16 func_0217ED04(int i);
u16 func_0217ED10(int i);
u16 func_0217ED2C(int i);
u16 func_0217ED48(int i);
u16 func_0217ED64(int i);
u16 func_0217ED80(int i);
u16 func_0217ED8C(int i);
u16 func_0217ED98(int i);
u16 func_0217EDA4(int i);
u16 func_0217EDB0(int i);
u16 func_0217EDBC(int i);
u16 func_0217EDC8(int i);
u16 func_0217EDD4(int i);
u16 func_0217EDE0(int i);
u16 func_0217EDEC(int i);
u16 func_0217EDF8(int i);
u16 func_0217EE04(int i);
u16 func_0217EE10(int i);
u16 func_0217EE1C(int i);
extern const u16 d_0218031C[];
extern const u16 d_0218034C[];
extern const u16 d_02180330[];
extern const u16 d_02180348[];
extern const u16 d_021805E4[][2];
extern const u16 d_02180648[][2];
extern const u16 d_0218053C[];
extern const u16 d_02180570[];
extern const u16 d_02180300[];
extern const u16 d_0218032C[];
extern const u16 d_02180320[];
extern const u16 d_02180318[];
extern const u16 d_02180328[];
extern const u16 d_02180324[];
extern const u16 d_02180380[][2];
extern const u16 d_0218033C[];
extern const u16 d_02180368[][2];
extern const u16 d_02180370[][2];
extern const u16 d_02180360[][2];
extern const u16 d_02180390[][2];
extern const u16 d_02180314[];
extern const u16 d_02180310[];
extern const u16 d_02180340[];
extern const u16 d_02180304[];
extern const u16 d_02180308[];
extern const u16 d_02180344[];
extern const u16 d_02180350[];
extern const u16 d_02180338[];
extern const u16 d_0218035C[];
extern const u16 d_02180358[];
extern const u16 d_02180354[];
extern const u16 d_021802F8[];
extern const u16 d_021802F0[];
extern const u16 d_021802F4[];


int func_0217E904(u8 *w, u8 *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int m;
    int i;

    p = *(u8 * *)&((struct Obj00033 *)w)->f355C;
    if (*state < 7 && func_0200FB24() != 0 && func_0217F1EC(w) == 1) {
        func_0217BAF0((char *)w, (int)a2, (int)1);
        *state = 7;
    }
    switch (*state) {
    case 0:
        func_0217BAF0((char *)w, (int)a2, (int)1);
        if (p[0xde] == 2) {
            if (func_0217F1EC(w) == 1)
                *state = 6;
        } else {
            func_0217F210(w, a2, 0x14c);
            (*state)++;
        }
        break;
    case 1:
        if (func_02174F34() == 1)
            (*state)++;
        break;
    case 2:
        if (func_0217FEB8(p) == 1)
            (*state)++;
        break;
    case 3:
        if (func_0217F1EC(w) == 1)
            (*state)++;
        break;
    case 4:
        func_02039C68((struct Link *)func_020399A8(), 0x13, 0x14);
        (*state)++;
        break;
    case 5:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x13, 0x14) == 1) {
            func_0203D7BC(0);
            (*state)++;
        }
        break;
    case 6:
        if (func_0203D378() == 1) {
            m = p[0x16e];
            if (func_020392B8() <= 1) {
                (*state)++;
                break;
            }
            for (i = 0; i < 5; i++) {
                if (i != func_02039338() && ((1 << i) & m)) {
                    if ((int)func_0203D1C0((u8)i) == 1)
                        break;
                }
            }
            if (i == 5)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 7:
        if (((Bits *)(p + 0xc8))->b1 == 1 && func_02172D68(w) == 1)
            return 0;
        if (func_0200FB24() != 0) {
            func_0217F074(w);
            func_02012124((struct Ctx *)((*(Sys_0217E904 * *)&((struct Obj00033 *)w)->f0)->fc), 1);
            return 0;
        }
        func_02172D38(w);
        (*state)++;
        break;
    case 8:
        if (func_02172D68(w) == 0)
            (*state)++;
        break;
    case 9:
        p[0xc9] = 1;
        func_02173408(w);
        func_0217AE20(w);
        func_02173524(w, obj + 0x14);
        func_0217422C(w, 0x19, 0);
        (*state)++;
        break;
    case 10:
        if (func_02174268(w) == 0) {
            if (*(u8 **)(w + 0x355C) != 0) {
                func_0217505C((int *)(*(u8 **)(w + 0x355C)), (*(Sys_0217E904 * *)&((struct Obj00033 *)w)->f0)->fc);
                *(u8 **)(w + 0x355C) = 0;
            }
            func_02172D50(w);
            (*state)++;
        }
        break;
    case 11:
        if (func_02172D68(w) == 0)
            return 1;
        break;
    }
    return 0;
}


int func_0217EAD8(u8 *w, void *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int t;
    int v;
    int msg;
    void *q;

    p = *(u8 * *)&((struct Obj05956 *)w)->f355C;
    switch (*state) {
    case 0:
        func_0217BAF0((char *)w, (int)a2, 1);
        t = func_0200855C((const struct Sub0200852CObj *)(p + 0x18 + p[0x16c] * 0x2c));
        if (t == 0x14 || t == 0x15) {
            v = (*(u8 **)(p + 0x134 + p[0x16c] * 4))[3];
            if (v < 5) {
                msg = 0x156 + v;
            } else if (v == 5) {
                switch (t) {
                case 0x15:
                    msg = 0x15c;
                    break;
                case 0x14:
                    msg = 0x15b;
                    break;
                default:
                    msg = 0x15d;
                    break;
                }
            } else {
                msg = 0x15d;
            }
        } else {
            msg = 0x15d;
        }
        func_0217F098(w, a2);
        func_0201F02C((struct WordSet *)(((struct Obj05956 *)w)->f2804), 0, p + 0x18 + p[0x16c] * 0x2c);
        func_0217F188((char *)w, msg);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 3)) {
            func_0217F074(w);
            (*(u8 **)(p + 0x134 + p[0x16c] * 4))[4] |= 0x20;
            q = func_0216F7F4((*(Sys_0217EAD8 * *)&((struct Obj05956 *)w)->f0)->f8, *(u8 **)(p + 0x134 + p[0x16c] * 4), 0x41);
            ((struct Obj05956 *)w)->f3558 = q;
            func_0217422C(w, 0x1c, (int)q);
            (*state)++;
        }
        break;
    case 2:
        if (func_02174268(w) == 0) {
            ((struct Obj05956 *)w)->f3558 = 0;
            (*state)++;
        }
        break;
    case 3:
        func_0217B8E4((char *)w, 0x2a);
        return 1;
    }
    return 0;
}

/*
 * Followers EC1C, EC28 and EC34 are already filed separately.
 */
u16 func_0217EC04(void ***ctx)
{
    return d_0218031C[func_02008550(**ctx)];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C2AC.
 */
u16 func_0217EC1C(int i)
{
    return d_0218034C[i];
}


u16 func_0217EC28(int i)
{
    return d_02180330[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C5A8.
 */
u16 func_0217EC34(int i)
{
    return d_02180348[i];
}

u16 func_0217EC40(int i, int j)
{
    return d_021805E4[i - 2][j];
}


u16 func_0217EC54(int i, int j)
{
    return d_02180648[i - 2][j];
}


u16 func_0217EC68(int i)
{
    return d_0218053C[i - 2];
}


u16 func_0217EC78(int i)
{
    return d_02180570[i - 2];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C2AC and func_0217C88C.
 */
u16 func_0217EC88(int i)
{
    return d_02180300[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217D7A4 / func_0217D890.
 */
u16 func_0217EC94(int i)
{
    return d_0218032C[i];
}


u16 func_0217ECA0(int i)
{
    return d_02180320[i];
}


u16 func_0217ECAC(int i)
{
    return d_02180318[i];
}

u16 func_0217ECB8(void ***ctx)
{
    return d_02180328[func_02008550(**ctx)];
}

u16 func_0217ECD0(void ***ctx)
{
    return d_02180324[func_02008550(**ctx)];
}

/*
 * Extent follower func_0217ED04 is already filed separately.
 */
u16 func_0217ECE8(int i)
{
    return d_02180380[func_020056EC(4)][i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217CEB8.
 */
u16 func_0217ED04(int i)
{
    return d_0218033C[i];
}

u16 func_0217ED10(int i)
{
    return d_02180368[func_020056EC(2)][i];
}

u16 func_0217ED2C(int i)
{
    return d_02180370[func_020056EC(4)][i];
}

u16 func_0217ED48(int i)
{
    return d_02180360[func_020056EC(2)][i];
}


u16 func_0217ED64(int i)
{
    return d_02180390[func_020056EC(4)][i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of func_0217ED64.
 */
u16 func_0217ED80(int i)
{
    return d_02180314[i];
}


u16 func_0217ED8C(int i)
{
    return d_02180310[i];
}


u16 func_0217ED98(int i)
{
    return d_02180340[i];
}


u16 func_0217EDA4(int i)
{
    return d_02180304[i];
}


u16 func_0217EDB0(int i)
{
    return d_02180308[i];
}


u16 func_0217EDBC(int i)
{
    return d_02180344[i];
}


u16 func_0217EDC8(int i)
{
    return d_02180350[i];
}


u16 func_0217EDD4(int i)
{
    return d_02180338[i];
}


u16 func_0217EDE0(int i)
{
    return d_0218035C[i];
}


u16 func_0217EDEC(int i)
{
    return d_02180358[i];
}


u16 func_0217EDF8(int i)
{
    return d_02180354[i];
}


u16 func_0217EE04(int i)
{
    return d_021802F8[i];
}


u16 func_0217EE10(int i)
{
    return d_021802F0[i];
}


u16 func_0217EE1C(int i)
{
    return d_021802F4[i];
}
