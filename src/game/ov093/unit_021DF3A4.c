/*
 * file:     unit_021DF3A4.c
 * unit:     yes
 * function: func_021DF3A4, func_021DF3F8, func_021DF404, func_021DF420, func_021DF42C, func_021DF438, func_021DF480
 * address:  0x021DF3A4
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
 *   func_021E889C  0x021E889C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C888C  0x021C888C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8408  0x021C8408  thumb  ov093
 *   d_021F161C     0x021F161C  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F1534     0x021F1534  data   ov093  a4
 *   d_021F145C     0x021F145C  data   ov093  a4
 */
struct S;
struct QQ;
struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021E889C(int a, int b, int c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C888C(u8 *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021D775C(int);
extern void func_021C8408(u8 *, int);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern void func_021D7704(int key, int m);
void func_021DF3A4(int a, void *b, int c);
int *func_021DF3F8(int *p);
void func_021DF404(int a, u8 *b, int c);
void func_021DF420(int a, u8 *b, int c);
int *func_021DF42C(int *p);
void func_021DF438(int self, int a, int b);
int *func_021DF480(int *p);
extern int d_021F161C[];
extern int d_021F1534[];
extern int d_021F145C[];



void func_021DF3A4(int a, void *b, int c)
{
    u8 *r;

    if (func_021E889C(a, (int)b, c) != 0) {
        r = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(r + 4, 2, 0x3ec);
        func_021C8860((struct S *)(r + 4), c);
        func_021C8860((struct S *)(r + 4), func_021D70A8((void *)a));
        func_021C888C(r + 4, 0x56a);
        func_021C88C8(b, r);
    }
}



int *func_021DF3F8(int *p)
{
    *p = 2;
    return d_021F161C;
}



void func_021DF404(int a, u8 *b, int c)
{
    if (c == func_021D775C(2))
        func_021C8408(b, c);
}



/*
 * Sibling of func_021DF3B0 against the func_021DFE08 probe.
 */
void func_021DF420(int a, u8 *b, int c)
{
    func_021C8408(b, c);
}


int *func_021DF42C(int *p)
{
    *p = 1;
    return d_021F1534;
}


void func_021DF438(int self, int a, int b)
{
    u8 v;

    if (b != func_021D775C(3))
        return;
    if (func_021D5444(func_021C7CF4((int *)a, b)) != 0x1e7)
        return;
    v = func_021D775C(0x16);
    if (v == 0xf || v == 7)
        func_021D7704(0x31, 0x1333);
}


int *func_021DF480(int *p)
{
    *p = 1;
    return d_021F145C;
}
