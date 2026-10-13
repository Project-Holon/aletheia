/*
 * file:     unit_021E396C.c
 * unit:     yes
 * function: func_021E396C, func_021E3990, func_021E399C, func_021E39C0, func_021E3A04
 * address:  0x021E396C
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F2804     0x021F2804  data   a4
 *   d_021F27FC     0x021F27FC  data   a4
 *   d_021F2AB8     0x021F2AB8  data   ov093  a4
 */
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_EVENT_MultiplyVar(int a, int b);
void func_021E396C(int u, int a, int b, int *p);
int *func_021E3990(int *p);
void func_021E399C(int u, int a, int b);
void func_021E39C0(int u, void *a, int c);
int *func_021E39F8(int *p);
void func_021E3A04(int u, void *a, int c);
int *func_021E3A3C(int *p);
extern int d_021F2804[];
extern int d_021F27FC[];
extern int d_021F2AB8[];


void func_021E396C(int u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (*p == 0)
            *p = 10;
        BTL_EVENT_OverwriteVar(0x30, *p);
    }
}


int *func_021E3990(int *p)
{
    *p = 2;
    return d_021F2AB8;
}


void func_021E399C(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x21) == 4)
            BTL_EVENT_OverwriteVar(0x42, 0);
    }
}




void func_021E39C0(int u, void *a, int c)
{
    int n;

    if (c == BTL_EVENT_GetVar(3)) {
        n = 4;
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(a, (u8)BTL_EVENT_GetVar(4)), 4) != 0)
            BTL_EVENT_MultiplyVar(0x35, n << 11);
    }
}




int *func_021E39F8(int *p)
{
    *p = 1;
    return d_021F2804;
}




void func_021E3A04(int u, void *a, int c)
{
    int n;

    if (c == BTL_EVENT_GetVar(3)) {
        n = 8;
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(a, (u8)BTL_EVENT_GetVar(4)), 8) != 0)
            BTL_EVENT_MultiplyVar(0x35, n << 10);
    }
}




int *func_021E3A3C(int *p)
{
    *p = 1;
    return d_021F27FC;
}
