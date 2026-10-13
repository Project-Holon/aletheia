/*
 * file:     unit_021E0518.c
 * unit:     yes
 * function: func_021E0518, func_021E05A4, func_021E05B0, func_021E061C
 * address:  0x021E0518
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
 *   func_021C8174  0x021C8174  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F26F4     0x021F26F4  data   ov093  a4
 *   d_021F2424     0x021F2424  data   ov093  a4
 */
#include "../../matched/include/Obj13504.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C8174(int *p);
extern u16 BTLV_CORE_PackByteTwice(int c);
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetTypePair(void *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int BTL_FIELD_GetStaticSlotObject(int k);
extern int BTLV_CORE_MakeSlotKind2Index(u32 a);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
void func_021E0518(int a, int *b, int c);
int *func_021E05A4(int *p);
void func_021E05B0(int a, void *b, int c);
int *func_021E061C(int *p);
extern int d_021F26F4[];
extern int d_021F2424[];


void func_021E0518(int a, int *b, int c)
{
    int t;
    u16 v;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        switch (func_021C8174(b)) {
        case 1: case 2: case 3: case 8: case 9: case 15:
            t = 4;
            break;
        case 4: case 14:
        default:
            t = 0;
            break;
        case 10:
            t = 5;
            break;
        case 0: case 5:
            t = 0xb;
            break;
        case 6: case 11: case 12:
            t = 0xa;
            break;
        case 7: case 13:
            t = 0xe;
            break;
        }
        v = BTLV_CORE_PackByteTwice(t);
        if (v != BTL_POKEPARAM_GetTypePair(func_021C7CF4(b, c))) {
            p = func_021C88A4((char *)b, 0x14, c);
            ((struct Obj13504 *)p)->f4 = v;
            ((struct Obj13504 *)p)->f6 = c;
            func_021C88C8(b, p);
        }
    }
}


int *func_021E05A4(int *p)
{
    *p = 1;
    return d_021F26F4;
}


void func_021E05B0(int a, void *b, int c)
{
    int *p;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_FIELD_GetStaticSlotObject(1) == 0) {
            p = func_021C88A4(b, 0x1b, c);
            p[1] = 1;
            p[2] = BTLV_CORE_MakeSlotKind2Index(5);
            func_021C8838(p + 4, 2, 0x359);
            func_021C8860((struct S *)(p + 4), c);
            func_021C88C8(b, p);
        } else {
            p = func_021C88A4(b, 0x1c, c);
            p[1] = 1;
            func_021C88C8(b, p);
        }
    }
}


int *func_021E061C(int *p)
{
    *p = 1;
    return d_021F2424;
}
