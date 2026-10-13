/*
 * file:     unit_021E30F8.c
 * unit:     yes
 * function: func_021E30F8, func_021E311C, func_021E3128, func_021E314C
 * address:  0x021E30F8
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
 *   func_021C8288  0x021C8288  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   data_021F25F4  0x021F25F4  data   a4
 *   d_021F2A58     0x021F2A58  data   ov093  a4
 */
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C8288(u8 *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_EVENT_MultiplyVar(int key, s32 m);
void func_021E30F8(int u, void *a, int b);
int *func_021E311C(int *p);
void func_021E3128(int u, int a, int b);
void func_021E314C(int u, void *p, int key);
u8 *func_021E3184(u32 *out);
extern u8 data_021F25F4[];
extern int d_021F2A58[];


void func_021E30F8(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (func_021C8288(a) == 3)
            BTL_EVENT_OverwriteVar(0x51, 1);
    }
}


int *func_021E311C(int *p)
{
    *p = 2;
    return d_021F2A58;
}


void func_021E3128(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x21) == 5)
            BTL_EVENT_OverwriteVar(0x42, 0);
    }
}



void func_021E314C(int u, void *p, int key)
{
    int k = 4;
    if (key == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(p, (u8)BTL_EVENT_GetVar(k)), 5) != 0)
            BTL_EVENT_MultiplyVar(0x35, k << 11);
    }
}



u8 *func_021E3184(u32 *out)
{
    *out = 1;
    return data_021F25F4;
}
