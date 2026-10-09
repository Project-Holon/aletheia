/*
 * file:     unit_021DE3D4.c
 * unit:     yes
 * function: func_021DE3D4, func_021DE3FC, func_021DE440, func_021DE494
 * address:  0x021DE3D4
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
 *   d_021F1394     0x021F1394  data   ov093  a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F163C 0x021F163C data a4
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021DCFD0  0x021DCFD0  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
struct QQ;
struct S;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_021DCFF8(int a, int b);
extern int func_021DCFD0(int *a, unsigned int b);
extern int func_021D76BC(int key, u32 val);
extern void func_021DD044(void *a, void *b, int c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
void func_021DE3D4(int a, int b, int c);
void *func_021DE3F0(int *p);
void func_021DE3FC(int a, void *b, int c);
void func_021DE440(void *a, void *b, int c, int *d);
extern u8 d_021F163C[];

void func_021DE3D4(int a, int b, int c) { int k=2; if(c == func_021D775C(k)) func_021D7704(0x35,k<<10); }

void *func_021DE3F0(int *p) { *p=2; return d_021F163C; }


void func_021DE3FC(int a, void *b, int c)
{
    u8 j;

    if (c == func_021D775C(2)) {
        j = func_021DCFF8(a, 2);
        if (func_021DCFD0(b, j) != 0 && func_021D76BC(0x11, 2) != 0)
            func_021DD044((void *)a, b, c);
    }
}


void func_021DE440(void *a, void *b, int c, int *d)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 2, 0x401);
        func_021C8860((struct S *)(m + 4), c);
        func_021C8860((struct S *)(m + 4), func_021D70A8(a));
        func_021C88C8(b, m);
        *d = 0;
    }
}


extern int d_021F1394[];
int *func_021DE494(int *p);

int *func_021DE494(int *p)
{
    *p = 1;
    return d_021F1394;
}
