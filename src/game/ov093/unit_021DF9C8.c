/*
 * file:     unit_021DF9C8.c
 * unit:     yes
 * function: func_021DF9C8, func_021DFA14, func_021DFA20, func_021DFA3C, func_021DFA54, func_021DFA60, func_021DFA7C, func_021DFA88, func_021DFAB0
 * address:  0x021DF9C8
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
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D76BC   0x021D76BC  thumb
 *   d_021F166C     0x021F166C  data   ov093  a4
 *   d_021F1504     0x021F1504  data   ov093  a4
 *   func_021C818C  0x021C818C  thumb  ov093
 *   d_021F14FC     0x021F14FC  data   ov093  a4
 *   d_021F140C     0x021F140C  data   ov093  a4
 */
struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern void func_021D7704(int key, int m);
extern int func_021DD008(int a);
extern int func_021C818C(unsigned char *p, int v);
void func_021DF9C8(int self, int a, int b);
int *func_021DFA14(int *p);
void func_021DFA20(int a, int b, int c);
void func_021DFA3C(int a, int b, int c);
int *func_021DFA54(int *p);
void func_021DFA60(int a, int b, int c);
int *func_021DFA7C(int *p);
void func_021DFA88(int a, unsigned char *b, int c);
int *func_021DFAB0(int *p);
extern int d_021F166C[];
extern int d_021F1504[];
extern int d_021F14FC[];
extern int d_021F140C[];




void func_021DF9C8(int self, int a, int b)
{
    u8 v;

    if (b != func_021D775C(3))
        return;
    if (func_021D5444(func_021C7CF4((int *)a, b)) != 0x1e3)
        return;
    v = func_021D775C(0x16);
    if (v == 0xf || v == 8)
        func_021D7704(0x31, func_021DD008(self));
}




int *func_021DFA14(int *p)
{
    *p = 2;
    return d_021F166C;
}




void func_021DFA20(int a, int b, int c)
{
    int n = 2;

    if (c == func_021D775C(n))
        func_021D7704(53, n << 10);
}





/* 021DFA3C  shape F1: gate on func_021D775C(2) */
void func_021DFA3C(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x41, 1);
}



int *func_021DFA54(int *p)
{
    *p = 1;
    return d_021F1504;
}



void func_021DFA60(int a, int b, int c)
{
    int n = 2;

    if (c == func_021D775C(n))
        func_021D7704(53, n << 10);
}


int *func_021DFA7C(int *p)
{
    *p = 1;
    return d_021F14FC;
}


void func_021DFA88(int a, unsigned char *b, int c)
{
    if (c == func_021D775C(4) && func_021C818C(b, c))
        func_021D7704(53, 6 << 10);
}


int *func_021DFAB0(int *p)
{
    *p = 1;
    return d_021F140C;
}
