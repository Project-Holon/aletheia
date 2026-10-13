/*
 * file:     unit_021E10D8.c
 * unit:     yes
 * function: func_021E10D8, func_021E1120, func_021E112C, func_021E11B8, func_021E11DC
 * address:  0x021E10D8
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F286C     0x021F286C  data   ov093  a4
 *   func_021C8174  0x021C8174  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   data_021F253C 0x021F253C data a4
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   BTL_CALC_MakeSickContFromKind 0x021D7DC0 thumb ov093
 *   d_021F2908     0x021F2908  data   ov093  a4
 */
#include "../../matched/include/Obj03703.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Word_021E10D8 { u32 v; } Word_021E10D8;

typedef signed char s8;

typedef struct { u32 v; } Word_021E1120;

extern int BTL_EVENT_GetVar(int key);
extern u32 BTL_CALC_Random(u32 range);
extern Word_021E10D8 BTL_CALC_MakeDefaultSickCont(int x);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021C8174(int *p);
extern void func_021C83DC(char *p, int x);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void BTL_CALC_MakeSickContFromKind(int, int, Word_021E1120 *);
void func_021E10D8(int unused, void *q, int id);
int *func_021E1120(int *p);
u8 func_021E112C(int *a, u8 *p1, u8 *p2);
void func_021E11B8(int a, void *b, int c);
void func_021E11DC(int unused, void *q, int id);
u32 *func_021E1298(u32 *p);
extern u32 d_021F286C[];
extern u32 data_021F253C[];
extern int d_021F2908[];


void func_021E10D8(int unused, void *q, int id)
{
    u32 v;
    Word_021E10D8 w;
    int k;

    k = 3;
    if (id == BTL_EVENT_GetVar(3)) {
        v = d_021F286C[(u8)BTL_CALC_Random(k)];
        w = BTL_CALC_MakeDefaultSickCont(v);
        BTL_EVENT_OverwriteVar(0x1d, v);
        BTL_EVENT_OverwriteVar(0x1e, w.v);
        BTL_EVENT_OverwriteVar(0x26, 0x14);
    }
}


int *func_021E1120(int *p)
{
    *p = 2;
    return d_021F2908;
}


u8 func_021E112C(int *a, u8 *p1, u8 *p2)
{
    u8 r;
    u8 x;
    u8 y;
    int n;

    n = func_021C8174(a);
    switch (n) {
    case 1:
    case 2:
    case 3:
    case 8:
    case 15:
        x = 1;
        y = 6;
        r = 1;
        break;
    case 4:
    case 14:
    default:
        x = 0;
        y = 1;
        r = 0;
        break;
    case 10:
        x = 2;
        y = 0;
        r = 6;
        break;
    case 0:
    case 5:
        x = 0;
        y = 2;
        r = 7;
        break;
    case 6:
    case 11:
    case 12:
        x = 1;
        y = 1;
        r = 5;
        break;
    case 9:
        x = 1;
        y = 5;
        r = 2;
        break;
    case 7:
    case 13:
        x = 0;
        y = 3;
        r = (n == 7) ? y : 4;
        break;
    }
    if (p1)
        *p1 = x;
    if (p2)
        *p2 = y;
    return r;
}




void func_021E11B8(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
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
    if (id == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x47) == 0 && BTL_CALC_Random(100) < 30) {
        m = func_021C7CF4(q, id);
        target = BTL_EVENT_GetVar(6);
        func_021E112C(q, &kind, &value);
        switch (kind) {
        case 0:
            r = func_021C88A4(q, 12, id);
            r[15] = target;
            ((struct Obj03703 *)r)->f4 = value;
            BTL_CALC_MakeSickContFromKind(value, (int)m, (Word_021E1120 *)(r + 8));
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
