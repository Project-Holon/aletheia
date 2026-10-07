/*
 * file:     unit_021E3B64_p02.c
 * unit:     yes
 * function: func_021E3E00, func_021E3E30, func_021E3E64, func_021E3E84
 * address:  0x021E3E00
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
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E3F08  0x021E3F08  thumb  ov093
 *   func_021D6920  0x021D6920  thumb  ov093
 *   func_021D6940  0x021D6940  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D76BC(int key, u32 val);
extern void func_021E3F08(void *a, int c, int *w);
extern int func_021D6920(u8 *p, u32 n);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C8010(u8 *p, unsigned int v);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern u32 func_021D78AC(u32 range);
void func_021E3E00(int u, int a, int b, int *p);
void func_021E3E30(int u, void *a, int b, int *p);
void func_021E3E64(int u, void *a, int b, int *p);
int func_021E3E84(int u, void *a, int c, int *w);


void func_021E3E00(int u, int a, int b, int *p)
{
    if (b == func_021D775C(4)) {
        if (func_021D775C(0x46) == 0) {
            if (p[6] != 0)
                p[1] += func_021D775C(0x32);
        }
    }
}


void func_021E3E30(int u, void *a, int b, int *p)
{
    int x;

    if (b == func_021D775C(3)) {
        if (*p >= 2) {
            func_021C7CF4(a, b);
            x = p[1];
            if (x != 0)
                x *= 2;
            func_021D76BC(0x37, x);
            *p = 3;
        }
    }
}


void func_021E3E64(int u, void *a, int b, int *p)
{
    if (b == func_021D775C(2))
        func_021E3F08(a, b, p);
}


int func_021E3E84(int u, void *a, int c, int *w)
{
    u8 buf[16];
    void *q;
    unsigned i;
    int x;
    int t;
    int r;

    q = func_021C7CF4(a, c);
    for (i = 0; i < 3; i++) {
        if (func_021D6920(q, (u8)i) != 0) {
            func_021D6940(q, (u8)i, (int)0, (u16 *)(&buf[6]));
            x = buf[0xb];
            if (func_021C7D00(a, x) == 6) {
                t = func_021C8010(a, c);
                r = func_021C7F68(a, (u16)(0x100 | t), buf);
                if (r != 0)
                    x = buf[(u8)func_021D78AC(r)];
                else
                    x = 0x1f;
            }
            return x;
        }
    }
    return 0x1f;
}
