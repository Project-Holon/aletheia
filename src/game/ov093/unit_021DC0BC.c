/*
 * file:     unit_021DC0BC.c
 * unit:     yes
 * function: func_021DC0BC, func_021DC0F8, func_021DC104, func_021DC130
 * address:  0x021DC0BC
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F0690 0x021F0690 data a4
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   d_021F07A8     0x021F07A8  data   ov093  a4
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
extern u32 func_021D7B60(void *p, u32 d);
extern void func_021D7704(int a, int b);
extern int func_021D5B48(u8 *p);
void func_021DC0BC(int u, int a, int b);
int *func_021DC0F8(int *p);
void func_021DC104(int a,void *b,int c);
int *func_021DC130(int *p);
extern int d_021F0690;
extern int d_021F07A8[];


void func_021DC0BC(int u, int a, int b)
{
    void *m;
    u32 n;
    if (b == func_021D775C(3)) {
        m = func_021C7CF4((int *)a, b);
        n = func_021D59B4(m, 0xd);
        if (n <= func_021D7B60(m, 2)) {
            func_021D7704(0x35, 2 << 10);
        }
    }
}


int *func_021DC0F8(int *p)
{
    *p = 1;
    return d_021F07A8;
}


void func_021DC104(int a,void *b,int c) { int k=4; if(c==func_021D775C(k) && func_021D5B48(func_021C7CF4(b,c))) func_021D7704(0x35,k<<9); }

int *func_021DC130(int *p) { *p=1; return &d_021F0690; }
