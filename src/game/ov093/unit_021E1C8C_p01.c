/*
 * file:     unit_021E1C8C_p01.c
 * unit:     yes
 * function: func_021E1D20, func_021E1D78
 * address:  0x021E1D20
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
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C804C  0x021C804C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C8290  0x021C8290  thumb  ov093
 *   func_021C831C  0x021C831C  thumb  ov093
 *   func_021C830C  0x021C830C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021C804C(int a, int b, u32 *out);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C8290(u8 *p, int a, int b, void *item);
extern void func_021C831C(u8 *p, int v);
extern unsigned int func_021C830C(u8 *p);
extern int func_021D76BC(int key, u32 val);
void func_021E1D20(int u, int a, int b);
void func_021E1D78(int a, void *b, int c);


void func_021E1D20(int u, int a, int b)
{
    u32 x;
    u8 k;

    if (func_021C804C(a, b, &x) != 0) {
        k = func_021D775C(6);
        if (func_021B9A24(k, b) == 0) {
            func_021C8010((u8 *)a, k);
            func_021C8010((u8 *)a, b);
            if (func_021C8290((u8 *)a, b, k, 0) == 0)
                func_021C831C((u8 *)a, b);
        }
    }
}


void func_021E1D78(int a, void *b, int c)
{
    if (c == func_021D775C(3) && func_021C830C(b))
        func_021D76BC(81, 1);
}
