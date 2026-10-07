/*
 * file:     mb_seq_p02.c
 * unit:     yes
 * function: func_021C6BD8, func_021C6BF0, func_021C6C34
 * address:  0x021C6BD8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C7D78 0x021C7D78 data a4
 *   func_02031330 0x02031330 arm
 *   d_021C7D7C 0x021C7D7C data a4
 *   func_021C714C 0x021C714C thumb ov136
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021C7648 0x021C7648 thumb
 *   func_021C7250 0x021C7250 thumb
 *   func_021C71D0 0x021C71D0 thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C7738 0x021C7738 thumb
 */
#include "../../matched/include/Obj14194.h"
#include "../../matched/include/Obj00412.h"
#include "../../matched/include/Obj23618.h"
#include "../../matched/include/Obj23619.h"
#include "../../matched/include/Obj23620.h"
#include "../../matched/include/Obj23621.h"
#include "../../matched/include/Obj23622.h"
#include "../../matched/include/Obj23623.h"

struct PrintSys;
struct Sound;
typedef unsigned char u8;

typedef unsigned int u32;

struct StateEnt {
    void (*fn)(u8 *);
    u32 a;
    u32 b;
};

struct Row { int (*call)(u8 *); int result; int other; };

typedef unsigned short u16;

extern unsigned int func_02031330(void *p);
extern int func_021C714C(u8 *p, u32 v);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_021C7648(u8 *p);
extern void func_020061E4(u32);
extern int func_021C7250(u8 *p, int v, int w);
extern int func_021C71D0(u8 *p, int v, int w);
extern void func_021C66A0(u8 *p, int i, u32 v);
extern int func_02025DE8(struct Sound *obj);
extern u8 func_020260E0(struct Sound *obj);
extern int func_021C7738(void);
int func_021C6BD8(u8 *p);
int func_021C6BF0(u8 *p);
int func_021C6C28(u8 *p);
int func_021C6C34(u8 *p);
extern const struct StateEnt d_021C7D78[];
extern const struct Row d_021C7D7C[];

int func_021C6BD8(u8 *p)
{
    d_021C7D78[*(u32 *)(p + 0x14)].fn(p);
    return 7;
}

int func_021C6BF0(u8 *p)
{
    if (func_02031330(((struct Obj14194 *)p)->f30) == 1) return 7;
    ((struct Obj14194 *)p)->f28 = d_021C7D7C[*(int *)(p + 0x14)].call(p);
    return d_021C7D7C[*(int *)(p + 0x14)].result;
}

int func_021C6C28(u8 *p)
{
    return func_021C714C(p, 9);
}


int func_021C6C34(u8 *p)
{
    u32 k;
    u8 *r;

    if (func_0201C6B4(((struct Obj23618 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f1C4) == 0) {
        return 9;
    }
    switch (func_021C7648(p)) {
    case 0:
        if (((struct Obj00412 *)p)->f1C != 0) {
            ((struct Obj00412 *)p)->f1C -= 1;
            func_020061E4(0x548);
            return func_021C7250(p, 0, 0xB);
        }
        return 9;
    case 1:
        if (((struct Obj00412 *)p)->f1C != ((struct Obj23619 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f2FE) {
            ((struct Obj00412 *)p)->f1C += 1;
            func_020061E4(0x548);
            return func_021C7250(p, 1, 0xB);
        }
        return 9;
    case 2:
        func_020061E4(0x551);
        func_021C66A0(((struct Obj00412 *)p)->f8, 3, 9);
        ((struct Obj00412 *)p)->f28 = 10;
        return 0x18;
    case 3:
        func_020061E4(0x556);
        func_021C66A0(((struct Obj00412 *)p)->f8, 7, 8);
        ((struct Obj00412 *)p)->f28 = 10;
        return 0x19;
    }
    k = func_02025DE8(((struct Obj23620 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f294);
    switch (k) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        r = *(u8 * *)&((struct Obj00412 *)p)->f8 + k + ((struct Obj00412 *)p)->f1C * 10;
        if (r[0x2E8] == 0xFF) {
            break;
        }
        p[0x1E] = k;
        p[0x1F] = r[0x2E8];
        func_020061E4(0x54C);
        return func_021C71D0(p, k, 0xC);
    case (u32)-2:
        func_020061E4(0x551);
        func_021C66A0(((struct Obj00412 *)p)->f8, 3, 9);
        ((struct Obj00412 *)p)->f28 = 10;
        return 0x18;
    case (u32)-5:
        func_020260E0(((struct Obj23621 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f294);
        if (((struct Obj00412 *)p)->f1C != ((struct Obj23622 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f2FE) {
            ((struct Obj00412 *)p)->f1C += 1;
            func_020061E4(0x548);
            return func_021C7250(p, 1, 0xB);
        }
        break;
    case (u32)-6:
        func_020260E0(((struct Obj23623 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f294);
        if (((struct Obj00412 *)p)->f1C != 0) {
            ((struct Obj00412 *)p)->f1C -= 1;
            func_020061E4(0x548);
            return func_021C7250(p, 0, 0xB);
        }
        break;
    case (u32)-3:
        func_020061E4(0x548);
        break;
    case (u32)-4:
        break;
    default:
        if (func_021C7738()) {
            func_020061E4(0x556);
            func_021C66A0(((struct Obj00412 *)p)->f8, 7, 8);
            ((struct Obj00412 *)p)->f28 = 10;
            return 0x19;
        }
        break;
    }
    return 9;
}
