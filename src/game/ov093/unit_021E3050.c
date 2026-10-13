/*
 * file:     unit_021E3050.c
 * unit:     yes
 * function: func_021E3050, func_021E3074, func_021E3080, func_021E30A4, func_021E30C8, func_021E30EC
 * address:  0x021E3050
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   d_021F2D08     0x021F2D08  data   ov093  a4
 *   d_021F246C     0x021F246C  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021C8288(u8 *p);
void func_021E3050(int u, int a, int b);
int *func_021E3074(int *p);
void func_021E3080(int u, int a, int b);
void func_021E30A4(int u, void *a, int b);
void func_021E30C8(int u, void *a, int b);
int *func_021E30EC(int *p);
extern int d_021F2D08[];
extern int d_021F246C[];


void func_021E3050(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x21) == 3)
            BTL_EVENT_OverwriteVar(0x42, 0);
    }
}


int *func_021E3074(int *p)
{
    *p = 3;
    return d_021F2D08;
}


void func_021E3080(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x21) == 3)
            BTL_EVENT_OverwriteVar(0x42, 0);
    }
}




void func_021E30A4(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (func_021C8288(a) == 2)
            BTL_EVENT_OverwriteVar(0x51, 1);
    }
}




void func_021E30C8(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (func_021C8288(a) == 1)
            BTL_EVENT_OverwriteVar(0x2b, 0x32);
    }
}


int *func_021E30EC(int *p)
{
    *p = 1;
    return d_021F246C;
}
