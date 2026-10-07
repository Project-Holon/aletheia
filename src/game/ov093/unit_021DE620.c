/*
 * file:     unit_021DE620.c
 * unit:     yes
 * function: func_021DE620, func_021DE668
 * address:  0x021DE620
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F1474     0x021F1474  data   ov093  a4
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F13E4     0x021F13E4  data   a4
 */
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021DD008(int a);
extern void func_021D7704(int key, int m);
extern int func_021DCFF8(int a, int b);
void func_021DE620(int a, int b, int c);
int *func_021DE65C(int *p);
void func_021DE668(int a, int b, int c);
int *func_021DE6C0(int *p);
extern int d_021F1474;
extern int d_021F13E4;


void func_021DE620(int a, int b, int c)
{
    u8 v;
    if (c == func_021D775C(3)) {
        v = func_021D775C(4);
        if (func_021D5BB0(func_021C7CF4((int *)b, v), 1) != 0)
            func_021D7704(0x35, func_021DD008(a));
    }
}


int *func_021DE65C(int *p)
{
    *p = 1;
    return &d_021F1474;
}


void func_021DE668(int a, int b, int c)
{
    u16 v;
    float x;

    if (c == func_021D775C(4)) {
        v = 100 - func_021DCFF8(a, 2);
        if (v != 0)
            x = 0.5f + (float)(v << 12);
        else
            x = (float)(v << 12) - 0.5f;
        func_021D7704(0x35, (int)x / 100);
    }
}


int *func_021DE6C0(int *p)
{
    *p = 1;
    return &d_021F13E4;
}
