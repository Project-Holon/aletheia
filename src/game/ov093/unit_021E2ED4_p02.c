/*
 * file:     unit_021E2ED4_p02.c
 * unit:     yes
 * function: func_021E2FE8, func_021E300C
 * address:  0x021E2FE8
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
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   data_021F2464  0x021F2464  data   ov093  a4
 */
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021E8860(int n);
void func_021E2FE8(int u, int a, int b);
void func_021E300C(int u, void *p, int key);
u8 *func_021E3044(u32 *out);
extern u8 data_021F2464[];


void func_021E2FE8(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021D775C(0x21) == 3)
            func_021D76BC(0x42, 0);
    }
}


void func_021E300C(int u, void *p, int key)
{
    int k = 3;
    if (key == func_021D775C(k)) {
        if (func_021D5BDC(func_021C7CF4(p, (u8)func_021D775C(4)), k) != 0)
            func_021E8860(2);
    }
}


u8 *func_021E3044(u32 *out)
{
    *out = 1;
    return data_021F2464;
}
