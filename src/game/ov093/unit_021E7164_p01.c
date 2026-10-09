/*
 * file:     unit_021E7164_p01.c
 * unit:     yes
 * function: func_021E7164, func_021E71D8, func_021E71E4
 * address:  0x021E7164
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
 *   func_021C81C8  0x021C81C8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F24EC     0x021F24EC  data   ov093  a4
 *   func_021C812C  0x021C812C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   func_021E7260  0x021E7260  thumb  ov093
 */
struct Q7;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021C81C8(u8 *p, u8 *x, int flag);
extern int func_021D76BC(int key, u32 val);
extern u8 *func_021C812C(u8 *p);
extern u16 func_021D70A8(struct QQ *p);
extern u16 func_021C8138(struct Q7 *p);
extern int func_021E7260(int a, int b, int c);
void func_021E7164(int u, int a, int b);
int *func_021E71D8(int *p);
void func_021E71E4(int a, int b, int c);
extern int d_021F24EC[];


void func_021E7164(int u, int a, int b)
{
    int x, y, q, v;

    if (b == func_021D775C(3)) {
        x = (int)func_021C7CF4((int *)a, b);
        y = (int)func_021C7CF4((int *)a, (u8)func_021D775C(4));
        x = func_021C81C8((u8 *)a, (u8 *)x, 0);
        y = func_021C81C8((u8 *)a, (u8 *)y, 0);
        q = x / y;
        if (q >= 4)
            v = 150;
        else if (q >= 3)
            v = 120;
        else if (q >= 2)
            v = 80;
        else {
            v = 60;
            if (q < 1)
                v = 40;
        }
        func_021D76BC(0x30, v);
    }
}


int *func_021E71D8(int *p)
{
    *p = 1;
    return d_021F24EC;
}


/*
 * The decrement inside the call argument (`i--`) is what puts the `subs`
 * before the result test; a `for (...; i--)` step lands it after the branch.
 */
void func_021E71E4(int a, int b, int c)
{
    int x, y, i, v;
    u32 n;

    if (c == func_021D775C(3)) {
        x = (int)func_021C812C((u8 *)b);
        y = func_021D70A8((void *)a);
        i = func_021C8138((struct Q7 *)b) - 1;
        n = 0;
        for (; i >= 0;) {
            if (func_021E7260(x, y, i--) == 0)
                break;
            n++;
        }
        switch (n) {
        case 0: v = 0x28; break;
        case 1: v = 0x50; break;
        case 2: v = 0x78; break;
        case 3: v = 0xa0; break;
        default: v = 0xc8; break;
        }
        func_021D76BC(0x30, v);
    }
}
