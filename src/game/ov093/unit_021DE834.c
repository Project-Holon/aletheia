/*
 * file:     unit_021DE834.c
 * unit:     yes
 * function: func_021DE834, func_021DE878, func_021DE8B4
 * address:  0x021DE834
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
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F16AC     0x021F16AC  data   a4
 *   d_021F13A4     0x021F13A4  data   a4
 */
struct QF;
struct R5;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern int func_021D6D54(struct R5 *p);
extern void func_021D7704(int key, int m);
void func_021DE834(int u, int a, int b);
int *func_021DE86C(int *p);
void func_021DE878(int a,int *b,int c);
void func_021DE8B4(int u, int a, int b);
int *func_021DE8F0(int *p);
extern int d_021F16AC;
extern int d_021F13A4;


void func_021DE834(int u, int a, int b)
{
    void *m;
    if (b == func_021D775C(2)) {
        m = func_021C7CF4((int *)a, b);
        if (func_021D5444(m) == 0x84 && func_021D6D54(m) == 0)
            func_021D7704(0x35, 2 << 12);
    }
}


int *func_021DE86C(int *p)
{
    *p = 2;
    return &d_021F16AC;
}

/*
 * interface: func_021C7CF4 returns its live r0 here (the matched
 * tail forwarder is declared void); r1 is visibly loaded with c before
 * the call and is retained as an argument, per canonical exceptions.
 */
void func_021DE878(int a,int *b,int c) { if(c==func_021D775C(3)) { if((unsigned int)func_021D5444(func_021C7CF4(b,c))-380<=1) { if(func_021D775C(26)==2) func_021D7704(53,6144); } } }


void func_021DE8B4(int u, int a, int b)
{
    if (b == func_021D775C(4)) {
        if ((u32)func_021D5444(func_021C7CF4((int *)a, b)) - 0x17c <= 1) {
            if (func_021D775C(0x1a) == 2)
                func_021D7704(0x35, 6 << 10);
        }
    }
}


int *func_021DE8F0(int *p)
{
    *p = 1;
    return &d_021F13A4;
}
