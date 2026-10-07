/*
 * file:     guru2_main_p21.c
 * unit:     yes
 * function: func_021E1204, func_021E1210, func_021E121C, func_021E129C
 * address:  0x021E1204
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E203C 0x021E203C data a4
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   d_021E22B8 0x021E22B8 data a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_02030DA8 0x02030DA8 arm
 */
#include "../../matched/include/Obj23795.h"
#include "../../matched/include/Obj23796.h"
#include "../../matched/include/Obj02209.h"

struct Actor;
struct Node;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int v[4]; } Table;

extern void func_020061E4(u32 a);
extern void func_0204B8D4(struct Obj *p, u32 arg);
extern u32 func_0204B98C(struct Actor *);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_02030DA8(void *, void (*)(void *, int *), void *, int);
int func_021E1204(char *p);
int func_021E1210(char *p);
void func_021E121C(void *task, int *p);
void func_021E129C(char *p);
extern const Table d_021E203C;
extern const char d_021E22B8[];


int func_021E1204(char *p)
{
    return ((struct Obj23795 *)p)->fC78;
}


int func_021E1210(char *p)
{
    return ((struct Obj23796 *)p)->fC7C;
}

void func_021E121C(void *task, int *p)
{
    switch (p[0]) {
    case 0:
        if (p[3] < 4) {
            Table sounds = d_021E203C;
            p[1]--;
            if (p[1] <= 0) {
                p[1] = 30;
                func_020061E4(sounds.v[p[3]]);
                p[3]++;
            }
        }
        func_0204B8D4((struct Obj *)p[5], 0x1800);
        if (func_0204B98C((struct Actor *)p[5]) == 0) p[0]++;
        break;
    case 1:
        func_0204B3B4((struct Obj *)p[5]);
        func_020307B0(p);
        func_02030EAC(task);
        break;
    }
}

void func_021E129C(char *p)
{
    struct { u16 x, y, z; u8 a, b; } pos;
    int *q = func_02030734(0x8072, 24, 0, d_021E22B8, 5638);
    func_02082BCC(q, 0, 24);
    pos.x = 128;
    pos.y = 100;
    pos.z = 0;
    pos.b = 0;
    pos.a = 0;
    q[5] = (int)func_0204B294((void *)((struct Obj02209 *)p)->fD68, ((struct Obj02209 *)p)->fD6C, ((struct Obj02209 *)p)->fD70, ((struct Obj02209 *)p)->fD74, &pos, 0, 114);
    func_0204B8D4((struct Obj *)q[5], 4096);
    q[4] = (int)p;
    func_02030DA8(((struct Obj02209 *)p)->fD98, func_021E121C, q, 0);
}
