/*
 * file:     unit_021E10D8_p01.c
 * unit:     yes
 * function: func_021E11B8, func_021E11DC
 * address:  0x021E11B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E112C  0x021E112C  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   data_021F253C 0x021F253C data a4
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021D7DC0 0x021D7DC0 thumb ov093
 */
#include "../../matched/include/Obj03703.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned int u32;

typedef struct { u32 v; } Word;

extern int func_021D775C(int key);
extern u8 func_021E112C(int *a, u8 *p1, u8 *p2);
extern void func_021C83DC(char *p, int x);
extern u32 func_021D78AC(u32);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021D7DC0(int, int, Word *);
void func_021E11B8(int a, void *b, int c);
void func_021E11DC(int unused, void *q, int id);
u32 *func_021E1298(u32 *p);
extern u32 data_021F253C[];


void func_021E11B8(int a, void *b, int c)
{
    if (c == func_021D775C(2))
        func_021C83DC(b, func_021E112C(b, 0, 0));
}

/*
 * follower: 021E1298 store-return stub included; lead sentinel at +12 is signed byte.
 */
void func_021E11DC(int unused, void *q, int id)
{
    void *m;
    u8 target;
    u8 kind;
    u8 value;
    u8 *r;
    if (id == func_021D775C(3) && func_021D775C(0x47) == 0 && func_021D78AC(100) < 30) {
        m = func_021C7CF4(q, id);
        target = func_021D775C(6);
        func_021E112C(q, &kind, &value);
        switch (kind) {
        case 0:
            r = func_021C88A4(q, 12, id);
            r[15] = target;
            ((struct Obj03703 *)r)->f4 = value;
            func_021D7DC0(value, (int)m, (Word *)(r + 8));
            func_021C88C8(q, r);
            break;
        case 1:
            r = func_021C88A4(q, 14, id);
            r[15] = 1;
            r[16] = target;
            ((struct Obj03703 *)r)->f4 = value;
            ((struct Obj03703 *)r)->fC = -1;
            func_021C88C8(q, r);
            break;
        case 2:
            r = func_021C88A4(q, 43, id);
            r[4] = target;
            r[5] = 100;
            func_021C88C8(q, r);
            break;
        }
    }
}

u32 *func_021E1298(u32 *p)
{
    *p = 1;
    return data_021F253C;
}
