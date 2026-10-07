/*
 * file:     trial_house_p19.c
 * unit:     yes
 * function: func_021D0A74, func_021D0AB8, func_021D0AC0, func_021D0AE4, func_021D0B58, func_021D0BCC, func_021D0BD8, func_021D0BE4
 * address:  0x021D0A74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201A954  0x0201A954  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_02168878  0x02168878  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200E5F8  0x0200E5F8  thumb
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021DE674     0x021DE674  data  a4
 *   func_02168AEC  0x02168AEC  thumb  ov010
 *   func_021680C8  0x021680C8  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0200E588  0x0200E588  thumb
 *   func_021D0C58  0x021D0C58  thumb  ov021
 *   d_0209DF0C     0x0209DF0C  data  a1
 */
#include "../../matched/include/Obj18370.h"
#include "../../matched/include/Obj20292.h"
#include "../../matched/include/Obj13002.h"
#include "../../matched/include/Obj20293.h"
#include "../../matched/include/Obj20294.h"

struct Party;
struct Big;
struct Ctx;
struct Sub020073D8Ctrl;
struct Sub02007324Ctrl;
struct Desc;
struct Obj;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Big {
    int w[72];
} Big;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Work {
    int f00;
    u8 f04;
    u8 pad05;
    u16 f06;
    int f08;
    int f0C;
    int f10;
    int f14;
    u8 pad18[0x78 - 0x18];
    int f78;
    u8 pad7C[0x80 - 0x7C];
    int f80;
    u8 *f84;
    u16 *f88;
    int f8C;
} Work;

void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_020056EC(u32 range);
extern int func_02168878(u8 *a, int b, int c, int d, int e, int f, u16 g);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern int func_020072CC(int a, int b, int c, void *d, int e);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern Big *func_0200E5F8(int a, int b);
extern void func_0200734C(struct Sub02007324Ctrl *a, unsigned int b);
extern u32 func_020307B0(void *p);
u16 func_02168AEC(u16 a0);
extern u32 func_021680C8(u32, u32, u32, u32);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_0200E588(void);
extern void func_021D0C58(void);
void func_021D0A74(int *p, u32 mode);
void func_021D0AB8(int *p, int v);
void func_021D0AC0(void *a, u8 *p, u32 c);
void func_021D0AE4(char *p, u32 mode);
void func_021D0B58(int a, Big *dst, int idx);
void func_021D0BCC(char *p);
int func_021D0BD8(u32 a, u32 b, u32 c, u32 d);
void *func_021D0BE4(void *a, u8 *b, u16 *c);
extern int d_021DE674;
extern u8 d_0209DF0C;


/*
 * The 0x124 store is written in each arm of the mode test (cross-jumped
 * into one tail) and the 0x12C store after it: that puts the two stores in
 * different blocks when constants are derived, so the second offset is
 * rematerialised (`movs #0x4b; lsls`) instead of `adds r0,#8`.
 * Extent runs into func_021D0AB8 (filed separately).
 */
void func_021D0A74(int *p, u32 mode)
{
    if (p == 0) {
        return;
    }
    if (mode <= 1) {
        int y;
        if (mode == 0) {
            y = 0;
            p[0x49] = 3;
        } else {
            y = 1;
            p[0x49] = 4;
        }
        p[0x4B] = y;
    } else {
        p[0x4B] = 0;
        p[0x49] = 3;
    }
    func_0201A954((struct Party *)p[0x4A], p[0x49]);
}


/*
 * Unlabelled ov021 leaf hidden in a word run: stores the second argument at
 * +0x130 of the first.  Matched to supply the `matched` witness for the
 * pending ov010 caller func_0216A594.
 */
void func_021D0AB8(int *p, int v)
{
    ((struct Obj18370 *)p)->f130 = v;
}


void func_021D0AC0(void *a, u8 *p, u32 c)
{
    if (((struct Obj20292 *)p)->f130 != 0) {
        func_021D0B58((int)a, (struct Big *)p, c);
    } else {
        func_021D0AE4((char *)p, c);
    }
    func_021D0BCC((char *)p);
}


void func_021D0AE4(char *p, u32 mode)
{
    int a;
    int b;
    int s;
    u16 v;

    switch (mode) {
    case 0:
        a = 0x32;
        b = 0x14;
        break;
    case 1:
        a = 0x6E;
        b = 0x32;
        break;
    case 2:
        a = 0xA0;
        b = 0x14;
        break;
    case 3:
        a = 0xF0;
        b = 0x1E;
        break;
    case 4:
        a = 0x10E;
        b = 0x1E;
        break;
    default:
        a = 0x32;
        b = 0x14;
        break;
    }
    s = a + func_020056EC(b);
    v = ((struct Obj13002 *)p)->f120;
    func_02168878((u8 *)p, (u16)s, ((struct Obj13002 *)p)->f124, 0, 0, 0, (v & 0x7FFF) | 0x8000);
}


/*
 * Callee witnesses filed in wave A1 (witness lane).
 */
void func_021D0B58(int a, Big *dst, int idx)
{
    int h;
    void *buf;
    int v;

    h = (int)func_02012EBC(func_020120F4((const struct Ctx *)a));
    buf = func_02030734(0x8004, 0x8004 >> 3, 1, (const char *)&d_021DE674, 0x14C);
    v = 0x8004 >> 3;
    if (func_020072CC(h, 5, 0x8004, buf, v) == 1) {
        *dst = *func_0200E5F8((int)func_020073D8((struct Sub020073D8Ctrl *)h, 5, 0), idx);
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 5);
    func_020307B0(buf);
}


/*
 * Unblocked by matching func_02168AEC (ov010, EXACT): the +0008 ABS32 site now
 * attests as `matched`.
 */
void func_021D0BCC(char *p)
{
    func_02168AEC(((struct Obj20293 *)p)->f4);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021D0BD8(u32 a, u32 b, u32 c, u32 d)
{
return func_021680C8(a, b, c, ((d << 16) >> 16));
}


void *func_021D0BE4(void *a, u8 *b, u16 *c)
{
    void *task;
    Work *w;

    task = func_020122C0(a, 0, func_021D0C58, 0x90);
    w = func_020124E8(task);
    w->f80 = (int)a;
    w->f88 = c;
    w->f84 = b;
    w->f8C = 0;
    w->f00 = 0x2E;
    w->f08 = func_0200E588();
    w->f0C = ((struct Obj20294 *)b)->f14C;
    w->f10 = d_0209DF0C;
    w->f14 = 0x200000;
    w->f78 = 1;
    w->f04 = 0;
    w->f06 = 0x8015;
    return task;
}
