/*
 * file:     box2_seq_p39.c
 * unit:     yes
 * function: func_021EC768, func_021EC7B8, func_021EC804, func_021EC8E4, func_021EC94C, func_021EC994, func_021EC9D8, func_021ECA24, func_021ECA38, func_021ECA6C
 * address:  0x021EC768
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EC030 0x021EC030 thumb
 *   func_021EC048 0x021EC048 thumb
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC428 0x021EC428 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ECB74 0x021ECB74 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_0202CF98 0x0202CF98 thumb
 *   d_021EFCE0 0x021EFCE0 data a1
 *   _ffix 0x0209C494 arm
 *   func_0204B570 0x0204B570 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B588 0x0204B588 arm
 *   _fsub 0x0209CB8C arm
 *   _fadd 0x0209C95C arm
 *   func_021DD908 0x021DD908 thumb ov170
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021EC060 0x021EC060 thumb ov170
 */
#include "../../matched/include/Obj24013.h"
#include "../../matched/include/Obj24014.h"
#include "../../matched/include/Obj24015.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj24016.h"
#include "../../matched/include/Obj04546.h"
#include "../../matched/include/Obj05439.h"
#include "../../matched/include/Obj04547.h"
#include "../../matched/include/Obj06551.h"
#include "../../matched/include/Obj24017.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
struct WinMgr;
struct Actor;
struct Obj;
struct Pair;
struct Pt;
typedef struct { unsigned char a; unsigned char b; } Off;

typedef unsigned int u32;

typedef signed char s8;

extern void func_021EC030(char *p, int i, int c);
extern void func_021EC048(char *p, int i, int c);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC428(char *p, int a, int i, int b);
extern void func_021EC000(char *p, int i, int v);
extern void func_021ECB74(char *a, int b);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_0204B588(struct Actor *actor, const struct Pt *src);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern int func_021DD908(char *p, u32 a);
extern unsigned func_021DD25C(void ***, unsigned short, int, unsigned, unsigned);
extern void func_021EC060(char *p, unsigned i, int b);
void func_021EC768(char *p, unsigned i, int flag);
void func_021EC7B8(char *p, int i, unsigned j, int flag);
void func_021EC804(char **p, short dx);
void func_021EC8E4(char *p);
void func_021EC94C(char *p);
int func_021EC994(char *p);
int func_021EC9D8(char *p);
void func_021ECA24(int *p);
void func_021ECA38(int *p);
void func_021ECA6C(unsigned char *p, int flag, int i, unsigned end, int mode);
extern const Off d_021EFCE0[];


void func_021EC768(char *p, unsigned i, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        func_021EC030(p, c, 0);
        func_021EC048(p, c, 0x14);
        return;
    }
    if (i < 0x1E || i == 0x24)
        func_021EC030(p, c, 3);
    else
        func_021EC030(p, c, 1);
    func_021EC048(p, c, 0x75 - i * 2);
}


void func_021EC7B8(char *p, int i, unsigned j, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        func_021EC030(p, c, 0);
        func_021EC048(p, c, 0x14);
        return;
    }
    if (j < 0x1E)
        func_021EC030(p, c, 3);
    else
        func_021EC030(p, c, 1);
    func_021EC048(p, c, 0x75 - j * 2);
}


void func_021EC804(char **p, short dx)
{
    short t[2];
    short reset;
    short lim;
    unsigned short i;
    unsigned char k;
    if (dx >= 0) {
        lim = 0xB0;
        reset = -8;
    } else {
        lim = -8;
        reset = 0xB0;
    }
    for (i = 0; i < 0x1E; i++) {
        k = *(unsigned char *)(p[11] + i + 0x3DD2);
        func_021EC0B0(p[11], k, &t[1], &t[0], 0);
        t[1] += dx;
        if (t[1] == lim) {
            t[1] = reset;
            func_021EC428(p[11], (int)(p[11] + 0x1B4 + i * 0x200), k, *(unsigned char *)(p[11] + i + 0x3DB4));
            func_021EC000(p[11], k, *(int *)(p[11] + i * 4 + 0x3DF8));
            if (((struct Obj24013 *)(p[11]))->fA17A == 0 && (((struct Obj24014 *)(p[0]))->f24 == 3 || ((struct Obj24015 *)(p[0]))->f24 == 5))
                func_021ECB74((char *)p, i);
        }
        func_021EC08C(p[11], k, t[1], t[0], 0);
    }
}


void func_021EC8E4(char *p)
{
    signed char buf[2];
    unsigned short i;
    short x, y;
    func_0202CF98(*(struct WinMgr * *)&((struct Obj24016 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74, 8, &buf[1], &buf[0]);
    x = buf[0] * 8;
    y = buf[1] * 8;
    for (i = 0; i < 6; i++)
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + i + 0x3DF0),
                      (short)(y + d_021EFCE0[i].a), (short)(x + d_021EFCE0[i].b), (short)0);
}

void func_021EC94C(char *p)
{
    int pair[2];
    unsigned short shape[2];
    *(float *)(p + 8) = 4096.0f;
    p[7] = 0;
    func_0204B570(((struct Obj04546 *)p)->f0, 1);
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    func_0204B5AC(((struct Obj04546 *)p)->f0, (struct Pair *)pair);
    shape[0] = 0;
    shape[1] = 8;
    func_0204B588(((struct Obj04546 *)p)->f0, (const struct Pt *)shape);
}

int func_021EC994(char *p)
{
    int pair[2];
    (((struct Obj05439 *)p)->f7)++;
    *(float *)(p + 8) -= 102.0f;
    if ((unsigned char)p[7] == 40)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    func_0204B5AC(((struct Obj05439 *)p)->f0, (struct Pair *)pair);
    return 1;
}

int func_021EC9D8(char *p)
{
    int pair[2];
    ((struct Obj04547 *)p)->f7 -= 2;
    *(float *)(p + 8) += 102.0f;
    *(float *)(p + 8) += 102.0f;
    if ((unsigned char)p[7] == 0)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    func_0204B5AC(((struct Obj04547 *)p)->f0, (struct Pair *)pair);
    return 1;
}

/*
 * Zero*p through the pool, then run the sibling teardown.
 */
void func_021ECA24(int *p)
{
    func_0204B3DC((struct Obj *)*p, 0);
    func_021ECA38(p);
}

/*
 * Program the two 0x1000 spans of the frame handle and zero its head.
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * func_0204B5AC.c, shard pkt_0204B5AC), so the call at +0022 attests as
 * `matched`.  Every concrete byte matches; the extent ran long because the
 * follower has no func_ label.
 */
void func_021ECA38(int *p)
{
    struct { unsigned short a[2]; int b[2]; } s;
    s.a[0] = 0;
    s.a[1] = 0;
    func_0204B588((struct Actor *)(*p), (const struct Pt *)s.a);
    s.b[0] = 0x1000;
    s.b[1] = 0x1000;
    func_0204B5AC((struct Obj *)(*p), (struct Pair *)s.b);
    func_0204B570((struct Actor *)(*p), 0);
}

void func_021ECA6C(unsigned char *p, int flag, int i, unsigned end, int mode)
{
    if (mode == 1) {
        if (((struct Obj24017 *)(*(char * *)&((struct Obj06551 *)p)->f0))->f24 == 5) {
            for (; i < end; i++) {
                if (func_021DD908((char *)p, i) == 1 && func_021DD25C((void ***)p, i, p[0x14], 0x4C, 0) == 0)
                    func_021EC060(WORK(p), WIN(p, i), 0);
                else
                    func_021EC060(WORK(p), WIN(p, i), 1);
            }
        } else {
            for (; i < end; i++) {
                if (func_021DD25C((void ***)p, i, p[0x14], 6, 0) == 0)
                    func_021EC060(WORK(p), WIN(p, i), 1);
                else
                    func_021EC060(WORK(p), WIN(p, i), 0);
            }
        }
    } else {
        for (; i < end; i++)
            func_021EC060(WORK(p), WIN(p, i), flag);
    }
}
