/*
 * file:     unit_021E56E0.c
 * unit:     yes
 * function: func_021E56E0, func_021E5720, func_021E5748, func_021E5784, func_021E5800, func_021E5828, func_021E5870, func_021E58D8
 * address:  0x021E56E0
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
 *   func_0689C91C  0x0689C91C  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F29D8     0x021F29D8  data   ov093  a4
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   BTL_MAIN_GetEnemyLanePos  0x021B8C20  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   d_021F29E8     0x021F29E8  data   ov093  a4
 *   d_021F2674     0x021F2674  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   d_021F24F4     0x021F24F4  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
#include "../../matched/include/Obj13527.h"
#include "../../matched/include/Obj06273.h"
#include "../../matched/include/Obj13528.h"
#include "../../matched/include/Obj10096.h"

struct S;
struct Q7;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C8010(u8 *p, unsigned int v);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021C815C(int *p);
extern u8 BTL_MAIN_GetEnemyLanePos(int kind, u32 flags, u32 v);
extern u16 func_021C8138(struct Q7 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern Word BTLV_CORE_MakeSlotKind1Empty(void);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_0689C91C(u16 v);
void func_021E56E0(int a, void *b, int c);
int *func_021E5714(int *p);
void func_021E5720(void *a, void *b, int c);
void func_021E5748(int a, void *b, int c);
void func_021E5784(void *a, void *b, int c, int d);
int *func_021E57F4(int *p);
void func_021E5800(void *a, void *b, int c);
void func_021E5828(int a, void *b, int c);
int *func_021E5864(int *p);
void func_021E5870(int a, void *b, int c);
int *func_021E58CC(int *p);
void func_021E58D8(int a, int b, int c);
extern int d_021F29D8[];
extern int d_021F29E8[];
extern int d_021F2674[];
extern int d_021F24F4[];


void func_021E56E0(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj13527 *)m)->f4 = 0;
        m[8] = func_021C8010(b, c);
        func_021C88C8(b, m);
    }
}


int *func_021E5714(int *p)
{
    *p = 2;
    return d_021F29D8;
}


void func_021E5720(void *a, void *b, int c)
{
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(0xd);
        func_021E5784(a, b, c, k);
    }
}


void func_021E5748(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 2, 0x432);
        func_021C8860((struct S *)(m + 4), c);
        func_021C88C8(b, m);
    }
}


void func_021E5784(void *a, void *b, int c, int d)
{
    u8 *m;
    int n;

    if (c == BTL_EVENT_GetVar(3) && BTL_EVENT_OverwriteVar(0x51, 1) != 0) {
        if (d == 6) {
            n = func_021C8010(b, c);
            d = BTL_MAIN_GetEnemyLanePos(func_021C815C(b), n, 0);
        }
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj06273 *)m)->f4 = 3;
        m[8] = d;
        ((struct Obj06273 *)m)->fC = func_021C8138(b) + 2;
        ((struct Obj06273 *)m)->f10 = BTL_EVENT_GetFactorKey(a);
        m[0x1c] = 2;
        func_021C88C8(b, m);
    }
}


int *func_021E57F4(int *p)
{
    *p = 2;
    return d_021F29E8;
}


void func_021E5800(void *a, void *b, int c)
{
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(0xd);
        func_021E5784(a, b, c, k);
    }
}


void func_021E5828(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 2, 0x435);
        func_021C8860((struct S *)(m + 4), c);
        func_021C88C8(b, m);
    }
}


int *func_021E5864(int *p)
{
    *p = 1;
    return d_021F2674;
}


void func_021E5870(int a, void *b, int c)
{
    u8 *m;
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        m = (u8 *)func_021C88A4(b, 0xc, c);
        m[0xf] = k;
        ((struct Obj13528 *)m)->f4 = 0x10;
        *(Word *)(m + 8) = BTLV_CORE_MakeSlotKind1Empty();
        func_021C8838(m + 0x14, 2, 0x235);
        func_021C8860((struct S *)(m + 0x14), k);
        func_021C88C8(b, m);
    }
}


int *func_021E58CC(int *p)
{
    *p = 1;
    return d_021F24F4;
}


void func_021E58D8(int a, int b, int c)
{
    u8 *m;
    u8 k;
    int n;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        n = func_021D59B4(func_021C7CF4((int *)b, k), 0x10);
        if (func_0689C91C(n) == 0) {
            m = (u8 *)func_021C88A4((void *)b, 0x1f, c);
            m[6] = c;
            ((struct Obj10096 *)m)->f4 = n;
            func_021C8838(m + 0xc, 2, 0x26b);
            func_021C8860((struct S *)(m + 0xc), c);
            func_021C8860((struct S *)(m + 0xc), k);
            func_021C8860((struct S *)(m + 0xc), ((struct Obj10096 *)m)->f4);
            func_021C88C8((void *)b, m);
        }
    }
}
