/*
 * file:     unit_021DE4A0.c
 * unit:     yes
 * function: func_021DE4A0, func_021DE4B8, func_021DE4C4, func_021DE4F4, func_021DE520, func_021DE52C, func_021DE538, func_021DE564, func_021DE598, func_021DE5DC
 * address:  0x021DE4A0
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
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F164C     0x021F164C  data   ov093  a4
 *   func_021DD008 0x021DD008 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F158C 0x021F158C data a4
 *   d_021F146C 0x021F146C data a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   d_021F13DC     0x021F13DC  data   ov093  a4
 *   d_021F13D4     0x021F13D4  data   ov093  a4
 *   d_021F165C     0x021F165C  data   ov093  a4
 *   d_021F1584     0x021F1584  data   ov093  a4
 */
struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021DCFF8(int,int);
extern int func_021D76BC(int,u32);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021DD008(int);
extern void func_021D7704(int,int);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
void func_021DE4A0(int a, int b, int c);
int *func_021DE4B8(int *p);
void func_021DE4C4(int a, int b, int c);
void func_021DE4F4(int a, void *b, int c);
int *func_021DE520(int *p);
int *func_021DE52C(int *p);
void func_021DE538(int a, int b, int c);
void *func_021DE558(int *p);
void func_021DE564(int a, int b, int c);
void *func_021DE58C(int *p);
void func_021DE598(int u, int a, int b);
int *func_021DE5D0(int *p);
void func_021DE5DC(int u, int a, int b);
int *func_021DE614(int *p);
/*
 * extent: two-byte alignment padding at 021DE4F2.
 * lever: u8 result local narrows in r0 before copying to r1; twin 021DE3FC.
 */
extern int d_021F164C[];
extern u8 d_021F158C[];
extern u8 d_021F146C[];
extern int d_021F13DC;
extern int d_021F13D4;
extern int d_021F165C[];
extern int d_021F1584[];



/* 021DE4A0  shape F1: gate on func_021D775C(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DE4B6; movs r0, #0x11; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DE4A0(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x11, 0);
}



int *func_021DE4B8(int *p)
{
    *p = 2;
    return d_021F164C;
}



void func_021DE4C4(int a, int b, int c) { u8 j; if(c == func_021D775C(3) && func_021D775C(0x25)==0) { j=func_021DCFF8(a,2); func_021D76BC(0x26,j); } }




void func_021DE4F4(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        m = (u8 *)func_021C88A4(b, 0x2b, c);
        m[4] = c;
        m[5] = 100;
        func_021C88C8(b, m);
    }
}


int *func_021DE520(int *p)
{
    *p = 2;
    return d_021F165C;
}


int *func_021DE52C(int *p)
{
    *p = 1;
    return d_021F1584;
}


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
