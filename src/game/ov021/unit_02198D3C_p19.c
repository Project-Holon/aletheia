/*
 * file:     unit_02198D3C_p19.c
 * unit:     yes
 * function: func_0219A7DC, func_0219A87C
 * address:  0x0219A7DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D504C     0x021D504C  data  a4
 *   d_021D5060     0x021D5060  data  a4
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D5D4  0x0216D5D4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0219B374  0x0219B374  thumb  ov021
 */
typedef signed char s8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int v[5]; } Arr;

typedef unsigned char  u8;

typedef signed short   s16;

extern u16 func_0216D5F8(void *p);
extern void func_0216D5E0(int a0, int a1);
extern int func_0216D5D4(void *p);
extern u16 func_021642A4(int i);
extern u8 *func_0216D684(u32, u32);
extern int func_0219B358(u32);
extern void func_0219B374(u32 a, u8 *s);
int func_0219A7DC(u32 a, s8 *b);
void func_0219A87C(u32 a);
extern const Arr d_021D504C;
extern const Arr d_021D5060;


int func_0219A7DC(u32 a, s8 *b)
{
    Arr ta = d_021D504C;
    Arr tb = d_021D5060;
    int *t;
    int i;
    int cur;
    t = ta.v;
    if (b[0] != 2)
        t = tb.v;
    cur = func_0216D5F8((void *)a);
    i = 0;
    if (t[0] != 9) {
        do {
            if (cur == t[i])
                break;
            i++;
        } while (t[i] != 9);
    }
    i++;
    if (t[i] == 9)
        i = 0;
    func_0216D5E0((u32)a, (u16)t[i]);
    if (func_0216D5F8((void *)a) == func_0216D5D4((void *)a))
        b[0] = func_021642A4(b[0]);
    b[2] = 0;
    return 1;
}


void func_0219A87C(u32 a)
{
    u8 *p = func_0216D684(a, 8);
    if (func_0219B358(a) == 1) {
        func_0219B374(a, p + 4);
    }
}
