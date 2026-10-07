/*
 * file:     script_work_p04.c
 * unit:     yes
 * function: func_02157AF0, func_02157B88, func_02157C48, func_02157D0C, func_02157D68, func_02157D98, func_02157DB8, func_02157DD8, func_02157E08
 * address:  0x02157AF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02157960  0x02157960  thumb
 *   func_02157AC8  0x02157AC8  thumb
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02039C68  0x02039C68  arm
 *   func_0203F328  0x0203F328  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203D0DC 0x0203D0DC arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   d_02172878 0x02172878 data a1
 *   func_0203CBAC 0x0203CBAC arm
 *   d_02172868 0x02172868 data a1
 *   d_02172808 0x02172808 data a1
 */
#include "../../matched/include/Obj02664.h"
#include "../../matched/include/Obj01831.h"
#include "../../matched/include/Obj04915.h"
#include "../../matched/include/Obj18743.h"
#include "../../matched/include/Obj18744.h"

struct Entry;
struct Link;
struct Object;
struct Req;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int a; u16 b; } Loc;

typedef struct Object {
    u32 f00;
    u8 pad04[0x74];
    u32 n;
} Object;

extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_02157960(int a, int b, int c);
extern void func_02157AC8(int *p);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
extern void func_0203F328(u16 *, u32, u32);
extern u32 func_020056EC(u32 range);
extern int func_0203D1B4(void);
extern int func_0203D0DC(int a0);
extern int func_0203CD98(void);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082D44(void *, void *, u32);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
void func_02157AF0(int *p);
void func_02157B88(int *p);
void func_02157C48(Object *p);
void func_02157D0C(int *p);
void func_02157D68(int *p);
void func_02157D98(int p);
void func_02157DB8(int p);
void *func_02157DD8(u8 *p);
int func_02157E08(void *p);
extern const char d_02172878[];
extern u8 d_02172868[];
extern u8 d_02172808[];


void func_02157AF0(int *p)
{
    u8 *b = (u8 *)p;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x18, (u8)p[0]) == 0)
        return;
    if (b[0x675] != 0) {
        if (b[0x676] == 1) {
            int *e = (int *)(b + 8 + b[0x677] * 16);
            int k = 0xFF;
            if (func_0203D3F8((u32)func_020399A8(), 0xFF, (unsigned)(p[0] << 24) >> 16, e[0], e[1], 0, 0, 1) == 0)
                return;
            func_02157960((int)p, (int)((void *)func_02157AC8), k + 0x2F);
            return;
        }
        func_02157960((int)p, (int)((void *)func_02157AC8), 0x133);
        return;
    }
    func_02157960((int)p, (int)((void *)func_02157AC8), 0x137);
}


void func_02157B88(int *p)
{
    u8 *b = (u8 *)p;
    if (b[0x676] == 1) {
        Loc l;
        int *s = *(int * *)&((struct Obj02664 *)b)->f664;
        l.b = func_0203F1FC((const u8 *)s[1], s[0]);
        l.a = ((struct Obj02664 *)b)->f668;
        if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 1), (u16)8, (u32)(&l)) == 0)
            return;
        func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p[0]);
        ((struct Obj02664 *)b)->f670 = 0;
        func_02157960((int)p, (int)((void *)func_02157AF0), 0x152);
        return;
    }
    ((struct Obj02664 *)b)->f66C = 1;
    if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 3), (u16)4, (u32)(b + 0x66C)) == 0)
        return;
    func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p[0]);
    ((struct Obj02664 *)b)->f670 = 0;
    func_02157960((int)p, (int)((void *)func_02157AF0), 0x162);
}


/*
 * levers: the RNG result is the third argument to func_0203F328, kept live
 *   in r2 across its preceding store. The bound is read as p->n in the for
 *   condition rather than through n; expanding that one use changes the
 *   hoisted bound/far-word allocation from r7/r6 to the original r6/r7.
 */
void func_02157C48(Object *p)
{
    u8 *b = (u8 *)p;
    int *e;
    u32 i;
    unsigned long n;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x17, (u8)p->f00) == 0)
        return;
    if (b[0x675] != 0) {
        e = 0;
        b[0x676] = 0;
        n = p->n;
        for (i = 0; i < p->n; i++) {
            e = (int *)(b + 8 + i * 16);
            if (e[2] == ((struct Obj01831 *)b)->f67C && (e[3] & ((struct Obj01831 *)b)->f680)) {
                b[0x677] = i;
                b[0x676] = 1;
                break;
            }
        }
        func_02157960((int)p, (int)func_02157B88, 0x188);
        if (b[0x676] == 1) {
            u32 t = func_020056EC(0);
            ((struct Obj01831 *)b)->f668 = t;
            func_0203F328((u16 *)e[1], e[0], t);
            *(int * *)&((struct Obj01831 *)b)->f664 = e;
        }
        return;
    }
    func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p->f00);
    func_02157960((int)p, (int)func_02157AF0, 0x193);
}


void func_02157D0C(int *p)
{
    if (*((u8 *)p + 0x675) == 0) {
        ((struct Obj04915 *)p)->f67C = p[4];
        ((struct Obj04915 *)p)->f680 = p[5];
        if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 2), (u16)8, (u32)((u8 *)p + 0x67C)) == 0)
            return;
        func_02157960((int)p, (int)((void *)func_02157C48), 0x1A2);
        return;
    }
    func_02157960((int)p, (int)((void *)func_02157C48), 0x1A6);
}

void func_02157D68(int *p) { if (func_0203D1B4() > 1) { func_02039C68((struct Link *)func_020399A8(), 0x17, (u8)p[0]); func_02157960((int)p, (int)func_02157D0C, 0x1af); } }

void func_02157D98(int p)
{
    func_0203D0DC(0);
    func_02157960(p, (int)func_02157D68, 0x1B7);
}

void func_02157DB8(int p)
{
    if (func_0203CD98() == 1)
        func_02157960(p, (int)func_02157D98, 0x1BE);
}

void *func_02157DD8(u8 *p)
{
    void *q = func_02030734(((struct Obj18743 *)p)->f6, 0x684, 1, d_02172878, 0x1CD);
    func_02082D44(p, q, 0x7C);
    return q;
}

int func_02157E08(void *p)
{
    if (func_0203CD98() != 0)
        return 0;
    d_02172868[7] = ((struct Obj18744 *)p)->f0;
    func_0203CBAC((struct Req *)d_02172808, 0, (u32)p);
    return 1;
}
