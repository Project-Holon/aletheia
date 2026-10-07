/*
 * file:     unit_021E396C_p01.c
 * unit:     yes
 * function: func_021E39C0, func_021E3A04
 * address:  0x021E39C0
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
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F2804     0x021F2804  data   a4
 *   d_021F27FC     0x021F27FC  data   a4
 */
struct UtilWork;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D7704(int a, int b);
void func_021E39C0(int u, void *a, int c);
int *func_021E39F8(int *p);
void func_021E3A04(int u, void *a, int c);
int *func_021E3A3C(int *p);
extern int d_021F2804[];
extern int d_021F27FC[];


void func_021E39C0(int u, void *a, int c)
{
    int n;

    if (c == func_021D775C(3)) {
        n = 4;
        if (func_021D5BDC(func_021C7CF4(a, (u8)func_021D775C(4)), 4) != 0)
            func_021D7704(0x35, n << 11);
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

    if (c == func_021D775C(3)) {
        n = 8;
        if (func_021D5BDC(func_021C7CF4(a, (u8)func_021D775C(4)), 8) != 0)
            func_021D7704(0x35, n << 10);
    }
}


int *func_021E3A3C(int *p)
{
    *p = 1;
    return d_021F27FC;
}
