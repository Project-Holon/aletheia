/*
 * file:     unit_021E30F8_p01.c
 * unit:     yes
 * function: func_021E3128, func_021E314C
 * address:  0x021E3128
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
 *   func_021D7704  0x021D7704  thumb  ov093
 *   data_021F25F4  0x021F25F4  data   a4
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
extern void func_021D7704(int key, s32 m);
void func_021E3128(int u, int a, int b);
void func_021E314C(int u, void *p, int key);
u8 *func_021E3184(u32 *out);
extern u8 data_021F25F4[];


void func_021E3128(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021D775C(0x21) == 5)
            func_021D76BC(0x42, 0);
    }
}


void func_021E314C(int u, void *p, int key)
{
    int k = 4;
    if (key == func_021D775C(3)) {
        if (func_021D5BDC(func_021C7CF4(p, (u8)func_021D775C(k)), 5) != 0)
            func_021D7704(0x35, k << 11);
    }
}


u8 *func_021E3184(u32 *out)
{
    *out = 1;
    return data_021F25F4;
}
