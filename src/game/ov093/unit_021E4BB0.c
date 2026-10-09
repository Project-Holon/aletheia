/*
 * file:     unit_021E4BB0.c
 * unit:     yes
 * function: func_021E4BB0, func_021E4C68, func_021E4C74, func_021E4D98
 * address:  0x021E4BB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   d_021F2724 0x021F2724 data a4
 *   d_021F2544 0x021F2544 data a4
 *   d_021F275C     0x021F275C  data   ov093  a4
 */
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
extern u8 *func_021C8120(u8 *p, int b);
void func_021E4BB0(int a, void *b, int c);
int *func_021E4C68(int *p);
void func_021E4C74(int unused, void *s, int k);
int *func_021E4D8C(int *p);
void func_021E4D98(int unused, void *s, int k);
int *func_021E4EB8(int *p);
extern int d_021F2724[];
extern int d_021F2544[];
extern int d_021F275C[];


void func_021E4BB0(int a, void *b, int c)
{
    void *q;
    u8 *w;
    u8 k;

    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        q = func_021C7CF4(b, k);
        w = func_021C88A4(b, 0xf, c);
        w[4] = c;
        w[5] = func_021D59B4(q, 1);
        w[6] = func_021D59B4(q, 2);
        w[7] = func_021D59B4(q, 3);
        w[8] = func_021D59B4(q, 4);
        w[9] = func_021D59B4(q, 5);
        w[10] = func_021D59B4(q, 6);
        w[11] = func_021D59B4(q, 7);
        func_021C88C8(b, w);
        w = func_021C88A4(b, 4, c);
        func_021C8838(w + 4, 2, 0x417);
        func_021C8860((struct S *)(w + 4), c);
        func_021C8860((struct S *)(w + 4), k);
        func_021C88C8(b, w);
    }
}


int *func_021E4C68(int *p)
{
    *p = 1;
    return d_021F275C;
}


void func_021E4C74(int unused, void *s, int k)
{
    u8 v;
    void *a;
    void *b;
    u32 *t;
    int i;
    u8 *p;
    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        a = func_021C7CF4(s, v);
        b = func_021C7CF4(s, k);
        t = (u32 *)func_021C8120(s, 28);
        for (i = 1; i <= 7; i++) {
            t[i - 1] = func_021D59B4(b, i);
        }
        p = func_021C88A4(s, 15, k);
        p[4] = k;
        p[5] = func_021D59B4(a, 1);
        p[6] = func_021D59B4(a, 2);
        p[7] = func_021D59B4(a, 3);
        p[8] = func_021D59B4(a, 4);
        p[9] = func_021D59B4(a, 5);
        p[10] = func_021D59B4(a, 6);
        p[11] = func_021D59B4(a, 7);
        func_021C88C8(s, p);
        p = func_021C88A4(s, 15, k);
        p[4] = v;
        p[5] = t[0];
        p[6] = t[1];
        p[7] = t[2];
        p[8] = t[3];
        p[9] = t[4];
        p[10] = t[5];
        p[11] = t[6];
        func_021C88C8(s, p);
        p = func_021C88A4(s, 4, k);
        func_021C8838(p + 4, 2, 673);
        func_021C8860((struct S *)(p + 4), k);
        func_021C88C8(s, p);
    }
}



int *func_021E4D8C(int *p)
{
    *p = 1;
    return d_021F2724;
}



void func_021E4D98(int unused, void *s, int k)
{
    u8 v;
    void *a;
    void *b;
    u32 x;
    u32 y;
    u8 *p;
    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        a = func_021C7CF4(s, v);
        b = func_021C7CF4(s, k);
        x = func_021D59B4(b, 1);
        y = func_021D59B4(b, 3);
        p = func_021C88A4(s, 15, k);
        p[4] = k;
        p[5] = func_021D59B4(a, 1);
        p[7] = func_021D59B4(a, 3);
        p[6] = func_021D59B4(b, 2);
        p[8] = func_021D59B4(b, 4);
        p[9] = func_021D59B4(b, 5);
        p[10] = func_021D59B4(b, 6);
        p[11] = func_021D59B4(b, 7);
        func_021C88C8(s, p);
        p = func_021C88A4(s, 15, k);
        p[4] = v;
        p[5] = x;
        p[7] = y;
        p[6] = func_021D59B4(a, 2);
        p[8] = func_021D59B4(a, 4);
        p[9] = func_021D59B4(a, 5);
        p[10] = func_021D59B4(a, 6);
        p[11] = func_021D59B4(a, 7);
        func_021C88C8(s, p);
        p = func_021C88A4(s, 4, k);
        func_021C8838(p + 4, 2, 676);
        func_021C8860((struct S *)(p + 4), k);
        func_021C88C8(s, p);
    }
}



int *func_021E4EB8(int *p)
{
    *p = 1;
    return d_021F2544;
}
