/*
 * file:     gtsnego_disp_p06.c
 * unit:     yes
 * function: func_021D48F0, func_021D4930, func_021D4988, func_021D4A20, func_021D4B48
 * address:  0x021D48F0
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_020399EC 0x020399EC arm
 *   func_02039ACC 0x02039ACC arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4864 0x021D4864 thumb ov120
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_02039338 0x02039338 arm
 *   func_021D7C10  0x021D7C10  thumb  ov120
 *   func_021D8638  0x021D8638  thumb  ov120
 *   func_021D7B38  0x021D7B38  thumb  ov120
 *   func_021D7A74  0x021D7A74  thumb  ov120
 *   func_021D8648  0x021D8648  thumb  ov120
 *   func_020362DC  0x020362DC  arm
 *   func_0203C554  0x0203C554  arm
 *   func_020355D8  0x020355D8  arm
 *   func_0203C3EC  0x0203C3EC  arm
 *   func_0203D7B0  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0216CB30 0x0216CB30 arm ov009
 *   func_02009EC8 0x02009EC8 thumb
 *   func_02009E74 0x02009E74 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   func_021D8590 0x021D8590 thumb ov120
 *   func_021D505C 0x021D505C thumb ov120
 *   func_0203D644 0x0203D644 arm
 *   func_02009CA8 0x02009CA8 thumb
 *   func_021D4F70 0x021D4F70 thumb ov120
 *   func_02082D44 0x02082D44 arm
 *   func_0216C8DC 0x0216C8DC arm ov009
 *   func_0208D7E0 0x0208D7E0 arm
 *   func_0215580C 0x0215580C thumb ov009
 *   func_0203C35C 0x0203C35C arm
 *   func_02156BC4 0x02156BC4 thumb ov009
 *   func_0203C9AC 0x0203C9AC arm
 *   d_021D8B40 0x021D8B40 data a2
 *   d_021D8B50 0x021D8B50 data a1
 */
#include "../../matched/include/Obj05342.h"
#include "../../matched/include/Obj05343.h"
#include "../../matched/include/Obj10386.h"
#include "../../matched/include/Obj22828.h"
#include "../../matched/include/Obj01539.h"

#define I(k) (*(int *)(p + (k)))
struct Sub02009D9CObj;
struct Sub0200852CObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 value; u8 kind; u8 pad; u16 detail; u32 tail; } Record;

extern int func_0203CD98(void);
extern int func_020399EC(void);
extern int func_02039ACC(void);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4864(u8 *p);
extern int func_021D7AF4(char *p);
extern u16 func_02039338(void);
extern int func_021D7C10(char *p);
extern u32 func_020362DC(void);
extern void func_021D8638(unsigned char *p);
extern void func_0203C554(u32 a);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 a);
extern int func_0203C3EC(void);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_021D7B38(char *p);
extern void func_021D7A74(u8 *p, int n);
extern void func_021D8648(u8 *p);
extern int func_0216CB30(int, int, int);
extern void *func_02009EC8(void *);
extern u32 func_02009E74(struct Sub02009D9CObj *obj, u32 id);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_021D8590(u8 *, int, int);
extern void func_021D505C(int a, int b, int *p);
extern void func_0203D644(int);
extern void func_02009CA8(void *account, void *out);
extern void *func_021D4F70(void **p, int i);
extern void func_02082D44(const void *, void *, u32);
extern u8 func_0216C8DC(u8 keyID, char *keyString, int *valueSrc);
extern int func_0208D7E0(char *, const char *, ...);
extern int func_0215580C(int, int, int, int);
extern u32 func_0203C35C(void);
extern void func_02156BC4(int);
extern void func_0203C9AC(int, u32, u32, u32);
void func_021D48F0(int *a);
void func_021D4930(u8 *a);
void func_021D4988(int *a);
int func_021D4A20(int a, u8 *p);
void func_021D4B48(u8 *p);
extern const u16 d_021D8B40[];
extern const char d_021D8B50[];

void func_021D48F0(int *a)
{
    if (func_0203CD98() == 0) {
        func_021D4244(a, (int)((void (*)(int))func_021D4864), 0x31d);
        return;
    }
    if (func_020399EC() != 0 && func_02039ACC() != 0)
        func_021D4244(a, (int)((void (*)(int))func_021D4864), 0x322);
}

void func_021D4930(u8 *a)
{
    if (func_021D7AF4((char *)(((struct Obj05342 *)a)->f40)) != 0) {
        if (((struct Obj05342 *)a)->f14 > 0) {
            ((struct Obj05342 *)a)->f14 = ((struct Obj05342 *)a)->f14 - 1;
            return;
        }
        if (func_02039338() != 0) {
            if (func_02039ACC() != 0) {
                ((struct Obj05342 *)a)->f14 = 0xb4;
                func_021D4244((int *)a, (int)((void (*)(int))func_021D4864), 0x33f);
                return;
            }
        } else {
            ((struct Obj05342 *)a)->f14 = 0xb4;
            func_021D4244((int *)a, (int)func_021D48F0, 0x344);
        }
    }
}


/*
 * Blocker resolved: the call to func_0203C3EC (site +0050) was the only
 *          unresolved relocation.  It is an unlabelled ARM leaf in the ARM9
 *          image; it was matched in arm9 (src/matched/func_0203C3EC.c, shard
 *          pkt_0203C3EC) so `attest_matched` now resolves the BL field.  All
 *          17 relocations and all 152 bytes agree.
 */
void func_021D4988(int *a)
{
    func_021D7C10((char *)(((struct Obj05343 *)a)->f40));
    if (func_020362DC() == 2) {
        func_021D8638((unsigned char *)(((struct Obj05343 *)a)->f40));
        if (func_0203CD98() != 0)
            func_0203C554(1);
        func_020355D8(0);
        func_020061E4(0x551);
        func_021D4244(a, 0x021D4FF5, 0x360);
    }
    if (func_0203CD98() == 0) {
        if (func_020362DC() != 1)
            return;
    } else {
        if (func_0203C3EC() != 1)
            return;
        func_0203D7B0(1);
        func_0203D7BC(1);
    }
    func_021D7B38((char *)(((struct Obj05343 *)a)->f40));
    func_021D7A74((u8 *)(((struct Obj05343 *)a)->f40), 0x10);
    ((struct Obj05343 *)a)->f14 = 0xb4;
    func_021D8648((u8 *)(((struct Obj05343 *)a)->f40));
    func_021D4244(a, 0x021D4931, 0x377);
}

int func_021D4A20(int a, u8 *p)
{
    int mode;
    int x;
    int y;
    int score = -1;
    int id;
    int group;
    int i;
    u8 *q = *(u8 * *)&((struct Obj10386 *)p)->f48;
    mode = func_0216CB30(a, (int)(p + 0x76), -1);
    x = func_0216CB30(a, (int)(p + 0x8e), -1);
    y = func_0216CB30(a, (int)(p + 0x82), -1);
    id = func_0216CB30(a, (int)(p + 0x5e), 0);
    group = func_0216CB30(a, (int)(p + 0xb2), 0);
    if (I(0x138) == 1) {
        if (mode == 4) {
            if (I(0x148) == -1) {
                if (func_02009E74(func_02009EC8(((struct Obj10386 *)p)->f30), id) != 0)
                    score = 100;
            } else {
                if (I(0x18) == id) score = 100;
            }
        } else {
            if (group == func_02008530((const struct Sub0200852CObj *)func_02012944((void *)(((struct Obj22828 *)q)->f0)))) {
                if (I(0x148) == -1) {
                    if (func_02009E74(func_02009EC8(((struct Obj10386 *)p)->f30), id) != 0)
                        score = 100;
                } else {
                    if (I(0x18) == id) score = 100;
                }
            }
        }
    } else {
        if (I(0x144) == mode) {
            if (I(0x13c) == x) score += 20;
            else if (I(0x13c) == 0 || x == 0) score += 10;
            else score -= 40;
            if (I(0x140) == y) score += 20;
            else if (y == 0 || I(0x140) == 0) score += 10;
            else score -= 40;
            for (i = 0; i < 100; i++) {
                if (id == *(int *)(q + i * 4 + 0x1c) && id != 0) {
                    score = 0;
                    break;
                }
            }
        }
    }
    return score;
}

void func_021D4B48(u8 *p)
{
    u32 values[8];
    void *q;
    int i;
    Record *r;
    if (func_021D7AF4(((struct Obj01539 *)p)->f40)) {
        if (func_0203CD98() == 0) {
            func_021D8590(*(u8 * *)&((struct Obj01539 *)p)->f40, (int)func_021D505C, (int)p);
            func_021D4244((int *)p, (int)func_021D4988, 0x3ea);
            return;
        }
        func_0203D644(0);
        func_02009CA8((void *)(((struct Obj01539 *)p)->f44), values);
        values[0] = ((struct Obj01539 *)p)->f14C;
        values[1] = ((struct Obj01539 *)p)->f138;
        values[2] = ((struct Obj01539 *)p)->f144;
        values[3] = ((struct Obj01539 *)p)->f13C;
        values[4] = ((struct Obj01539 *)p)->f140;
        values[5] = 0x20015;
        values[6] = 1;
        values[7] = 0;
        if (((struct Obj01539 *)p)->f138 == 1) {
            if (((struct Obj01539 *)p)->f148 == -1)
                values[2] = 4;
            else {
                q = func_021D4F70(((struct Obj01539 *)p)->f2C, ((struct Obj01539 *)p)->f148);
                values[7] = func_02008530(q);
                ((struct Obj01539 *)p)->f18 = func_02008530(q);
            }
        }
        for (i = 0; i < 8; i++) {
            r = (Record *)(p + 0x58) + i;
            func_02082D44(d_021D8B40 + i, &r->detail, 2);
            r->value = values[i];
            r->kind = func_0216C8DC(r->kind, (char *)(&r->detail), (int *)r);
        }
        func_0208D7E0((char *)p + 0xb8, d_021D8B50, ((struct Obj01539 *)p)->f138, 1);
        if (func_0215580C((int)p + 0xb8, 2, (int)func_021D4A20, (int)p)) {
            func_0203C35C();
            func_02156BC4(0);
            func_021D8590(*(u8 * *)&((struct Obj01539 *)p)->f40, (int)func_021D505C, (int)p);
            func_021D4244((int *)p, (int)func_021D4988, 0x41d);
            return;
        }
        func_0203C9AC(0, 0, 0, 0x3f1);
    }
}
