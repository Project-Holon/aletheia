/*
 * file:     unit_021E324C.c
 * unit:     yes
 * function: func_021E324C, func_021E32CC, func_021E32F8, func_021E3324, func_021E3330, func_021E338C, func_021E33BC, func_021E33EC, func_021E3414
 * address:  0x021E324C
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
 *   d_021F2844     0x021F2844  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C824C  0x021C824C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   data_021F2A78  0x021F2A78  data   a4
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetHiddenPowerType  0x02018790  thumb
 *   POKE_TOOL_GetHiddenPowerPower  0x02018820  thumb
 *   d_021F2E18 0x021F2E18 data a4
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj21473.h"

struct QI;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C824C(u8 *p, int v);
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void func_021C83DC(char *p, int x);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern u32 POKE_TOOL_GetHiddenPowerType(void *p);
extern u32 POKE_TOOL_GetHiddenPowerPower(void *p);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
void func_021E324C(int u, void *p, int key);
u8 *func_021E32C0(u32 *out);
void func_021E32CC(int u, void *a, int b);
void func_021E32F8(int u, void *a, int b);
int *func_021E3324(int *p);
void func_021E3330(int u, void *p, int key);
void func_021E338C(int u, void *a, int b);
void func_021E33BC(int u, void *a, int b);
void func_021E33EC(int u, int a, int b);
extern u8 data_021F2A78[];
extern int d_021F2E18;



void func_021E324C(int u, void *p, int key)
{
    int two = 2;
    if (key == BTL_EVENT_GetVar(two)) {
        if (func_021C824C(p, key) != 0) {
            u16 x = (u16)(int)BTL_POKEPARAM_GetItem(func_021C7CF4(p, key));
            int v = 0;
            int r = 0;
            switch (x) {
            case 0x74: v = 10; r = 1; break;
            case 0x75: v = 12; r = two; break;
            case 0x76: v = 9; r = 3; break;
            case 0x77: v = 14; r = 4; break;
            }
            BTL_EVENT_OverwriteVar(0x16, v);
            func_021C83DC(p, r);
        }
    }
}



u8 *func_021E32C0(u32 *out)
{
    *out = 2;
    return data_021F2A78;
}



void func_021E32CC(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(2))
        BTL_EVENT_OverwriteVar(0x16, POKE_TOOL_GetHiddenPowerType(BTL_POKEPARAM_GetMon(func_021C7CF4(a, b))));
}



void func_021E32F8(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x30, POKE_TOOL_GetHiddenPowerPower(BTL_POKEPARAM_GetMon(func_021C7CF4(a, b))));
}



int *func_021E3324(int *p)
{
    *p = 4;
    return &d_021F2E18;
}


void func_021E3330(int u, void *p, int key)
{
    u16 x;
    int k;
    if (key == BTL_EVENT_GetVar(2)) {
        if (func_021C824C(p, key) == 0) {
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
            return;
        }
        x = (u16)(int)BTL_POKEPARAM_GetItem(func_021C7CF4(p, key));
        k = 11;
        BTL_CALC_GetMonParamWithHeap((void *)x, k);
        if (x == 0 || BTL_CALC_GetMonParamWithHeap((void *)x, k) == 0)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}



void func_021E338C(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(2))
        BTL_EVENT_OverwriteVar(0x16, BTL_CALC_GetMonParamWithHeap((void *)((u16)(int)BTL_POKEPARAM_GetItem(func_021C7CF4(a, b))), 0xc));
}



void func_021E33BC(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x30, BTL_CALC_GetMonParamWithHeap((void *)((u16)(int)BTL_POKEPARAM_GetItem(func_021C7CF4(a, b))), 0xb));
}



void func_021E33EC(int u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        s = func_021C88A4((char *)a, 0x23, b);
        ((struct Obj21473 *)s)->f4 = 1;
        func_021C88C8((void *)a, s);
    }
}


extern int d_021F2844[];
int *func_021E3414(int *p);

int *func_021E3414(int *p)
{
    *p = 1;
    return d_021F2844;
}
