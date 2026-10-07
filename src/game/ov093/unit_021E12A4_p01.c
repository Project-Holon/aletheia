/*
 * file:     unit_021E12A4_p01.c
 * unit:     yes
 * function: func_021E1410, func_021E1434
 * address:  0x021E1410
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
 */
struct UtilWork;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D7704(int key, s32 m);
void func_021E1410(int a, int b, int c);
void func_021E1434(int a, void *p, int id);


void func_021E1410(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(33) == 4)
        func_021D76BC(66, 0);
}


void func_021E1434(int a, void *p, int id)
{
    int k;
    if (id == func_021D775C(3)) {
        k = 4;
        if (func_021D5BDC(func_021C7CF4(p, (u8)func_021D775C(4)), 4)) {
            func_021D7704(0x35, k << 11);
        }
    }
}
