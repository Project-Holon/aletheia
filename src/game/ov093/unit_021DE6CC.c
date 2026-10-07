/*
 * file:     unit_021DE6CC.c
 * unit:     yes
 * function: func_021DE6CC, func_021DE70C, func_021DE74C
 * address:  0x021DE6CC
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
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F148C     0x021F148C  data   ov093  a4
 *   d_021F13EC     0x021F13EC  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   d_021F139C     0x021F139C  data   a4
 */
struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int k);
extern int func_0201C1E8(int a);
extern int func_021DD008(int a);
extern void func_021D7704(int key, int m);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
void func_021DE6CC(int a, int b, int c);
int *func_021DE700(int *p);
void func_021DE70C(int a, int b, int c);
int *func_021DE740(int *p);
void func_021DE74C(int u, int a, int b);
int *func_021DE790(int *p);
extern int d_021F148C;
extern int d_021F13EC;
extern int d_021F139C;


void func_021DE6CC(int a, int b, int c)
{
    if (c == func_021D775C(3)) {
        if (func_0201C1E8((u16)func_021D775C(0x12)) == 1)
            func_021D7704(0x31, func_021DD008(a));
    }
}


int *func_021DE700(int *p)
{
    *p = 1;
    return &d_021F148C;
}


void func_021DE70C(int a, int b, int c)
{
    if (c == func_021D775C(3)) {
        if (func_0201C1E8((u16)func_021D775C(0x12)) == 2)
            func_021D7704(0x31, func_021DD008(a));
    }
}


int *func_021DE740(int *p)
{
    *p = 1;
    return &d_021F13EC;
}


void func_021DE74C(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021D5444(func_021C7CF4((int *)a, b)) == 0x16e) {
            if (func_0201C1E8((u16)func_021D775C(0x12)) == 2)
                func_021D7704(0x35, 2 << 12);
        }
    }
}


int *func_021DE790(int *p)
{
    *p = 1;
    return &d_021F139C;
}
