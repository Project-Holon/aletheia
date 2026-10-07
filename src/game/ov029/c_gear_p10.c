/*
 * file:     c_gear_p10.c
 * unit:     yes
 * function: func_021F29D8, func_021F2AB8, func_021F2AD4, func_021F2AEC, func_021F2B9C, func_021F2BB8, func_021F2BD4
 * address:  0x021F29D8
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
 *   func_02012138  0x02012138  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021F05B4  0x021F05B4  thumb  ov029
 *   func_020061E4  0x020061E4  thumb
 *   func_021F3098  0x021F3098  thumb  ov029
 *   func_021F3118  0x021F3118  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F2EEC  0x021F2EEC  thumb  ov029
 *   func_021F2CD4  0x021F2CD4  thumb  ov029
 *   func_021F06B8 0x021F06B8 thumb ov029
 *   func_021F1290  0x021F1290  thumb  ov029
 *   func_020091AC  0x020091AC  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_021F20AC  0x021F20AC  thumb  ov029
 *   func_02009110 0x02009110 thumb
 *   func_02009134 0x02009134 thumb
 *   func_02009160 0x02009160 thumb
 */
#include "../../matched/include/Obj00042.h"
#include "../../matched/include/Obj20398.h"

struct Ctx;
struct Sub020090B0Obj;
typedef unsigned char  u8;

typedef unsigned int   u32;

extern unsigned int func_02012138(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021F05B4(unsigned char *p);
extern void func_020061E4(unsigned int id);
extern void func_021F3098(u8 *p);
extern void func_021F3118(void *p);
extern void func_021EFEF8(char *p, void (*f)(void), int a);
extern int func_021F2EEC(char *p, int k);
extern void func_021F2CD4(void);
extern void func_021F06B8(u8 *p, int a, int b);
extern void func_021F1290(void *q, int a, int b, int c);
extern void func_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind, int marked, int flagged);
extern void func_020409B4(u32 index);
extern void func_021F20AC(char *p);
extern u32 func_02009110(const struct Sub020090B0Obj *obj, int row, int col);
extern int func_02009134(const struct Sub020090B0Obj *obj, int row, int col);
extern u32 func_02009160(const struct Sub020090B0Obj *obj, int row, int col, int kind);
int func_021F29D8(char *p, int a);
int func_021F2AB8(char *p);
void func_021F2AD4(u8 *p);
void func_021F2AEC(unsigned char *p, int a1, int a2, int a3, int k);
u32 func_021F2B9C(u8 *p, int row, int col);
int func_021F2BB8(u8 *p, int row, int col);
int func_021F2BD4(u8 *p, int row, int col, int kind);


/*
 * The listing extent (252 B) runs over the matched follower 0x021F2AB8;
 * the function is 224 B.  Case order 1/6, 5, 12/13, 7/11 is the table's
 * code order; the shared "sound; r = func_021F2EEC" tails are cross-jumped.
 */
int func_021F29D8(char *p, int a)
{
    int r = 0;
    void *b;

    func_02012138((const struct Ctx *)*(int *)&((struct Obj00042 *)p)->f1C);
    b = func_0201210C(((struct Obj00042 *)p)->f1C);
    if (a == 0 || b == 0)
        return 0;

    switch (((struct Obj00042 *)p)->f214) {
    case 1:
    case 6:
        if (func_021F05B4((unsigned char *)p) == 0) {
            func_020061E4(0x54E);
            r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        } else {
            func_020061E4(0x7E3);
            func_021F3098((u8 *)p);
            func_021EFEF8(p, (void (*)(void))func_021F3118, 0x1238);
        }
        break;
    case 5:
        func_020061E4(0x54E);
        r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        break;
    case 12:
    case 13:
        func_020061E4(0x628);
        r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        break;
    case 7:
    case 11:
        if (func_021F05B4((unsigned char *)p) == 0) {
            func_020061E4(0x628);
            r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        } else {
            func_020061E4(0x7E3);
        }
        break;
    }

    if (r != 0) {
        ((struct Obj00042 *)p)->f218 = ((struct Obj00042 *)p)->f214;
        func_021EFEF8(p, func_021F2CD4, 0x1256);
    }
    ((struct Obj00042 *)p)->f214 = 0;
    return r;
}


/*
 * Unlabelled leaf, sole blocker of ov021 func_0218A6E8.
 */
int func_021F2AB8(char *p)
{
    if (p == 0)
        return 0;
    if (((struct Obj20398 *)p)->f218 == 5)
        return 1;
    return 0;
}

void func_021F2AD4(u8 *p)
{
    if (p != 0) {
        p[0x462] = 0;
        func_021F06B8(p, 0, 0);
    }
}


void func_021F2AEC(unsigned char *p, int a1, int a2, int a3, int k)
{
    int j;
    int i;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (k == func_021F2B9C(p, i, j)) {
                if (func_021F2BB8((u8 *)p, i, j) != 0) {
                    func_020091AC((struct Sub020090B0Obj *)a1, i, j, k, 0, 1);
                    func_021F1290((void *)p, i, j, k);
                } else if (func_021F2BD4((u8 *)p, i, j, k) != 0) {
                    func_020091AC((struct Sub020090B0Obj *)a1, i, j, k, 0, 0);
                }
            }
        }
    }
    func_020091AC((struct Sub020090B0Obj *)a1, a2, a3, k, 1, 0);
    func_021F1290((void *)p, a2, a3, k);
    func_020409B4(4);
    func_021F20AC((char *)p);
}

u32 func_021F2B9C(u8 *p, int row, int col)
{
    if (p[0x45a] != 0)
        return func_02009110(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col);
    return 0;
}

int func_021F2BB8(u8 *p, int row, int col)
{
    if (p[0x45a] != 0)
        return func_02009134(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col);
    return 0;
}

int func_021F2BD4(u8 *p, int row, int col, int kind)
{
    if (p[0x45a] != 0)
        return func_02009160(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col, kind);
    return 0;
}
