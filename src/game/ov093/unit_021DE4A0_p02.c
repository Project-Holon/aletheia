/*
 * file:     unit_021DE4A0_p02.c
 * unit:     yes
 * function: func_021DE538, func_021DE564, func_021DE598, func_021DE5DC
 * address:  0x021DE538
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DD008 0x021DD008 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F158C 0x021F158C data a4
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F146C 0x021F146C data a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   d_021F13DC     0x021F13DC  data   ov093  a4
 *   d_021F13D4     0x021F13D4  data   ov093  a4
 */
struct QF;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern int func_021D775C(int);
extern int func_021DD008(int);
extern void func_021D7704(int,int);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
void func_021DE538(int a, int b, int c);
void *func_021DE558(int *p);
void func_021DE564(int a, int b, int c);
void *func_021DE58C(int *p);
void func_021DE598(int u, int a, int b);
int *func_021DE5D0(int *p);
void func_021DE5DC(int u, int a, int b);
int *func_021DE614(int *p);
extern u8 d_021F158C[];
extern u8 d_021F146C[];
extern int d_021F13DC;
extern int d_021F13D4;

void func_021DE538(int a, int b, int c) { if(c == func_021D775C(3)) func_021D7704(0x35,func_021DD008(a)); }

void *func_021DE558(int *p) { *p=1; return d_021F158C; }

/*
 * lever: u8 local holds getter result before increment; narrow callee argument.
 */
void func_021DE564(int a, int b, int c) { u8 j; if(c == func_021D775C(3)) { j=func_021D775C(0x2c); func_021D76BC(0x2c,(u8)(j+1)); } }

void *func_021DE58C(int *p) { *p=1; return d_021F146C; }


void func_021DE598(int u, int a, int b)
{
    u8 v;
    if (b == func_021D775C(3)) {
        if (func_021D5444(func_021C7CF4((int *)a, b)) == 0x71) {
            v = func_021D775C(0x2c);
            func_021D76BC(0x2c, (u8)(v + 2));
        }
    }
}


int *func_021DE5D0(int *p)
{
    *p = 1;
    return &d_021F13DC;
}


void func_021DE5DC(int u, int a, int b)
{
    u8 v;
    if (b == func_021D775C(3)) {
        if (func_021D5444(func_021C7CF4((int *)a, b)) == 0x53) {
            v = func_021D775C(0x2c);
            func_021D76BC(0x2c, (u8)(v + 2));
        }
    }
}


int *func_021DE614(int *p)
{
    *p = 1;
    return &d_021F13D4;
}
