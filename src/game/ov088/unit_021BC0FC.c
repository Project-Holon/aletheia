/*
 * file:     unit_021BC0FC.c
 * unit:     yes
 * function: func_021BC0FC, func_021BC114, func_021BC12C, func_021BC230
 * address:  0x021BC0FC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020312F8  0x020312F8  arm
 *   d_021BD824     0x021BD824  data  a4
 *   ov088_id       0x00000058  data  a1
 *   func_020070A4  0x020070A4  thumb
 *   func_0203159C  0x0203159C  arm
 *   func_021BD25C  0x021BD25C  thumb  ov088
 *   func_02007220  0x02007220  thumb
 *   func_0200846C  0x0200846C  thumb
 *   func_020082EC  0x020082EC  thumb
 *   func_0216BFD4  0x0216BFD4  thumb  ov010
 *   func_02031324  0x02031324  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02005A98  0x02005A98  thumb
 *   func_020069D4  0x020069D4  thumb
 *   ov194_id       0x000000C2  data
 *   ov204_id       0x000000CC  data
 *   d_021F557C     0x021F557C  data  ov194  a4
 *   d_021F558C     0x021F558C  data  ov194  a4
 *   d_021BFD20     0x021BFD20  data  ov204  a4
 *   d_021BFD30     0x021BFD30  data  ov204  a4
 *   func_021BD2F4  0x021BD2F4  thumb  ov088
 *   func_02031330  0x02031330  arm
 *   func_02031348  0x02031348  arm
 *   func_02008550  0x02008550  thumb
 *   func_021BC4A4  0x021BC4A4  thumb  ov088
 *   d_021BFD24     0x021BFD24  data  ov204  a4
 *   d_021F5580     0x021F5580  data  ov194  a4
 */
#include "../../matched/include/Obj00964.h"
#include "../../matched/include/Obj01518.h"
#include "../../matched/include/Obj20826.h"
#include "../../matched/include/Obj20827.h"
#include "../../matched/include/Obj20828.h"

struct Sub02005A98Hdr;
struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
struct Obj0203159C;
struct Sub0200852CObj;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_020312F8(u32 a1, u32 a2, u32 a3);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_021BD25C(int a, int b);
extern void *func_02007220(struct Sub020071E4Ctrl *ctrl);
extern void *func_0200846C(int a0);
extern void *func_020082EC(int a0);
extern int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
extern void *func_02031324(int a0);
extern int func_02034AC4(signed int id);
extern void func_02034A5C(int handle);
extern struct Sub02005A98Hdr *func_02005A98(const u32 *a0, u32 a1);
extern int func_020069D4(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
extern u32 func_021BD2F4(void *p);
extern unsigned int func_02031330(void *p);
extern void func_02031348(u32 h, void *id, void *proc, void *arg);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_021BC4A4(int a, int b, int c);
void func_021BC0FC(void);
void func_021BC114(void);
int func_021BC12C(struct Obj0203159C *a0);
int func_021BC230(void *a0, int *seq, void *a2, char *w);
extern char d_021BD824[];
extern char ov088_id[];
extern u8 ov194_id[];
extern u8 ov204_id[];
extern u32 d_021F557C;
extern u32 d_021F558C[];
extern u32 d_021BFD20;
extern u32 d_021BFD30[];
extern char d_021BFD24[];
extern char d_021F5580[];


void func_021BC0FC(void)
{
    func_020312F8((u32)ov088_id, (u32)d_021BD824, 1);
}


void func_021BC114(void)
{
    func_020312F8((u32)ov088_id, (u32)d_021BD824, 2);
}


/*
 * The ov194 id is held in a local (the original keeps it in r7 across the
 * copy loop and reuses it for the unload); the ov204 id is spelled
 * directly and reloaded from the pool for each call.
 */
int func_021BC12C(struct Obj0203159C *a0)
{
    u32 buf[30];
    void *sys;
    char *w;
    u32 n1, n2, i;
    u32 r;
    void *id;

    sys = func_020070A4();
    w = func_0203159C(a0, 0x5c, 1);
    ((struct Obj00964 *)w)->f2C = (u32)func_021BD25C(1, (int)sys);
    func_02007220(sys);
    ((struct Obj00964 *)w)->f54 = (u32)func_0200846C(1);
    ((struct Obj00964 *)w)->f58 = (u32)func_020082EC(1);
    ((struct Obj00964 *)w)->f0 = 0;
    ((struct Obj00964 *)w)->f4 = ((struct Obj00964 *)w)->f58;
    ((struct Obj00964 *)w)->f8 = ((struct Obj00964 *)w)->f54;
    ((struct Obj00964 *)w)->f28 = (u32)func_0216BFD4(1, 0, 0, 0, 7, 0, 0);
    ((struct Obj00964 *)w)->f30 = (unsigned int)func_02031324(1);

    id = ov194_id;
    func_02034AC4((int)id);
    n1 = d_021F557C;
    for (i = 0; i < n1; i++)
        buf[i] = d_021F558C[i];
    func_02034A5C((int)id);

    func_02034AC4((int)ov204_id);
    n2 = d_021BFD20;
    for (i = 0; i < n2; i++)
        buf[n1 + i] = d_021BFD30[i];
    func_02034A5C((int)ov204_id);

    ((struct Obj00964 *)w)->f34 = (u32)func_02005A98(buf, n1 + n2);
    r = func_020069D4(0x23c, 0, 0x40, 0, 0, 0, 0, 0);
    ((struct Obj00964 *)w)->f50 = r;
    ((struct Obj00964 *)w)->f10 = ((struct Obj00964 *)w)->f54;
    ((struct Obj00964 *)w)->f14 = ((struct Obj00964 *)w)->f58;
    ((struct Obj00964 *)w)->f18 = 1;
    ((struct Obj00964 *)w)->f1C = ((struct Obj00964 *)w)->f2C;
    ((struct Obj00964 *)w)->f20 = r;
    return 1;
}


/*
 * Case bodies are laid out in source order, and the original places
 * case 6 before case 5 (jump table at 0x021BC254).
 */
int func_021BC230(void *a0, int *seq, void *a2, char *w)
{
    int busy;

    func_021BD2F4(((struct Obj01518 *)w)->f2C);
    busy = func_02031330((void *)((struct Obj01518 *)w)->f30);
    switch (*seq) {
    case 0:
        func_02031348(((struct Obj01518 *)w)->f30, ov204_id, d_021BFD24, w + 0x10);
        *seq = 1;
        break;
    case 1:
        if (busy != 1)
            *seq = 2;
        break;
    case 2:
        ((struct Obj20826 *)(*(char * *)&((struct Obj01518 *)w)->f28))->f4 = func_02008550((const struct Sub0200852CObj *)(((struct Obj01518 *)w)->f8));
        ((struct Obj20827 *)(*(char * *)&((struct Obj01518 *)w)->f28))->f24 = *(u32 *)&((struct Obj01518 *)w)->f2C;
        func_02031348(((struct Obj01518 *)w)->f30, ov194_id, d_021F5580, ((struct Obj01518 *)w)->f28);
        *seq = 3;
        break;
    case 3:
        if (busy != 1)
            *seq = 4;
        break;
    case 4:
        func_021BC4A4(((struct Obj01518 *)w)->f54, ((struct Obj20828 *)(*(char * *)&((struct Obj01518 *)w)->f28))->f20,
                      func_02008550((const struct Sub0200852CObj *)(((struct Obj01518 *)w)->f54)));
        ((struct Obj01518 *)w)->f18 = 7;
        func_02031348(((struct Obj01518 *)w)->f30, ov204_id, d_021BFD24, w + 0x10);
        *seq = 6;
        break;
    case 6:
        if (busy != 1)
            *seq = 5;
        break;
    case 5:
        if (((struct Obj01518 *)w)->f24 == 0)
            *seq = 7;
        else
            *seq = 2;
        break;
    case 7:
        return 1;
    }
    return 0;
}
