/*
 * file:     unit_021E14E4.c
 * unit:     yes
 * function: func_021E14E4, func_021E14FC, func_021E1508, func_021E1558, func_021E15A4, func_021E15B0, func_021E15DC
 * address:  0x021E14E4
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_021F2938     0x021F2938  data   ov093  a4
 *   d_021F2554     0x021F2554  data   ov093  a4
 *   d_021F2494     0x021F2494  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int key, u32 val);
void func_021E14E4(int a, int b, int c);
int *func_021E14FC(int *p);
void func_021E1508(int a, void *p, int id);
void func_021E1558(int a, void *p, int id);
int *func_021E15A4(int *p);
void func_021E15B0(int a, int b, int c);
int *func_021E15DC(int *p);
extern int d_021F2938[];
extern int d_021F2554[];
extern int d_021F2494[];



/* 021E14E4  shape F1: gate on func_021D775C(3) */
void func_021E14E4(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x37, 0x14);
}



int *func_021E14FC(int *p)
{
    *p = 2;
    return d_021F2938;
}



void func_021E1508(int a, void *p, int id)
{
    void *x;
    void *y;
    u8 t;
    if (id == func_021D775C(3)) {
        t = func_021D775C(4);
        x = func_021C7CF4(p, t);
        y = func_021C7CF4(p, id);
        if (func_021D59B4(x, 13) - func_021D59B4(y, 13) <= 0) {
            func_021D76BC(0x40, 1);
        }
    }
}




void func_021E1558(int a, void *p, int id)
{
    void *x;
    int d;
    if (id == func_021D775C(3)) {
        x = func_021C7CF4(p, id);
        d = func_021D59B4(func_021C7CF4(p, (u8)func_021D775C(4)), 13) - func_021D59B4(x, 13);
        if (d < 0) d = 1;
        func_021D76BC(0x37, d);
    }
}


int *func_021E15A4(int *p)
{
    *p = 1;
    return d_021F2554;
}


void func_021E15B0(int a, int b, int c)
{
    int n;

    if (c != func_021D775C(3))
        return;
    n = (unsigned char)func_021D59B4(func_021C7CF4((int *)b, c), 15);
    func_021D76BC(55, n);
}


int *func_021E15DC(int *p)
{
    *p = 1;
    return d_021F2494;
}
