/*
 * file:     unit_021D8D40.c
 * unit:     yes
 * function: func_021D8D40, func_021D8D90, func_021D8D9C, func_021D8E00, func_021D8E1C, func_021D8E58, func_021D8E7C, func_021D8EDC, func_021D8F1C, func_021D8F54, func_021D8F84, func_021D8FCC, func_021D901C, func_021D9064, func_021D9070, func_021D90DC, func_021D90E8, func_021D910C
 * address:  0x021D8D40
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
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   d_021F06A0     0x021F06A0  data   ov093  a4
 *   d_021F0E1C     0x021F0E1C  data   ov093  a4
 *   d_021F0608 0x021F0608 data a4
 *   d_021F07E0     0x021F07E0  data   ov093  a4
 */
struct QF;
struct S;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Hd { u32 lo : 23; u32 flag : 1; u32 hi : 8; };

extern int func_021D775C(int key);
extern int func_0201C1E8(int a);
extern void func_021D7704(int a, int b);
extern int func_021C8010(u8 *p, unsigned int v);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u16 func_021D5444(struct QF *p);
extern int func_021C8288(u8 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021B9A24(unsigned int a, unsigned int b);
void func_021D8D40(int u, int a, int b, int c);
int *func_021D8D90(int *p);
int func_021D8D9C(void *a, int k, u8 *buf, int v);
int func_021D8E00(void *a, int b);
void func_021D8E1C(int a, void *b, int c, int *d);
void func_021D8E58(int a, void *b, int c, int *d);
void func_021D8E7C(int u, void *a, u32 b, u32 c, u8 d);
void func_021D8EDC(int u, int a, int b, int *p);
void func_021D8F1C(int a, void *b, int c, int *d);
void func_021D8F54(int a, void *b, int c, int *d);
void func_021D8F84(int u, int a, int b, int *p);
void func_021D8FCC(int u, int a, int b);
void func_021D901C(int u, int a, int b);
int *func_021D9064(int *p);
void func_021D9070(int u, int a, int b);
int *func_021D90DC(int *p);
void func_021D90E8(int a, int b, int c);
void *func_021D910C(int *p);
/*
 * lever: func_021C7F68 returns a u8 count, so n is a u8 and the count is spilled and reloaded.
 */
extern int d_021F06A0[];
extern int d_021F0E1C[];
extern unsigned int d_021F0608;
extern int d_021F07E0[];




void func_021D8D40(int u, int a, int b, int c)
{
    if (b == func_021D775C(3)) {
        if (func_021D8D9C((void *)a, b, (u8 *)c, 0x39) != 0 || func_021D8D9C((void *)a, b, (u8 *)c, 0x3a) != 0) {
            if (func_0201C1E8((u16)func_021D775C(0x12)) == 2)
                func_021D7704(0x35, 6 << 10);
        }
    }
}




int *func_021D8D90(int *p)
{
    *p = 1;
    return d_021F06A0;
}




int func_021D8D9C(void *a, int k, u8 *buf, int v)
{
    int t;
    u8 n;
    u8 i;

    t = func_021C8010(a, k);
    if (t != 6) {
        n = func_021C7F68(a, (u16)((7 << 8) | t), buf);
        for (i = 0; i < n; i++) {
            if (k != buf[i]) {
                if (v == func_021D59B4(func_021C7CF4(a, buf[i]), 0x11))
                    return 1;
            }
        }
    }
    return 0;
}







/*
 * Caller uses the forwarder's live pointer return and forwards r1.
 */
int func_021D8E00(void *a, int b)
{
    if (func_021D5444(func_021C7CF4(a, b)) == 0x1a5) return 1;
    return 0;
}







/*
 * The thunk's caller supplies r0 and consumes its forwarded return.
 */
void func_021D8E1C(int a, void *b, int c, int *d)
{
    if (func_021D8E00(b, c)) {
        func_021D8E7C(a, b, c, (unsigned char)(func_021C8288(b) == 1), 1);
        *d = 1;
    }
}







void func_021D8E58(int a, void *b, int c, int *d)
{
    if (c == func_021D775C(2)) func_021D8E1C(a, b, c, d);
}








void func_021D8E7C(int u, void *a, u32 b, u32 c, u8 d)
{
    u8 *r;

    if (c != func_021D59B4(func_021C7CF4((int *)((int)a), b), 0x13)) {
        r = func_021C88A4(a, 0x39, b);
        r[4] = b;
        r[5] = c;
        ((struct Hd *)r)->flag = d;
        func_021C8838(r + 8, 2, 0xde);
        func_021C8860((struct S *)(r + 8), b);
        func_021C88C8(a, r);
    }
}








void func_021D8EDC(int u, int a, int b, int *p)
{
    if (*p != 0 && func_021D8E00((void *)a, b) != 0)
        func_021D8E7C(u, (void *)a, (int)b, (u8)(func_021C8288((u8 *)a) == 1), 1);
}






void func_021D8F1C(int a, void *b, int c, int *d)
{
    if (*d && c == func_021D775C(2) && func_021D8E00(b, c))
        func_021D8E7C(a, b, c, 0, 0);
}






void func_021D8F54(int a, void *b, int c, int *d)
{
    if (*d && func_021D8E00(b, c)) func_021D8E7C(a, b, c, 0, 0);
}







void func_021D8F84(int u, int a, int b, int *p)
{
    int t;

    if (*p != 0 && func_021D8E00((void *)a, b) != 0) {
        if (b == func_021D775C(2)) {
            t = func_021D775C(0x10);
            if (t != func_021D70A8((void *)u))
                func_021D8E7C(u, (void *)a, b, 0, 0);
        }
    }
}






void func_021D8FCC(int u, int a, int b)
{
    u8 k;

    if (func_021D8E00((void *)a, b) != 0 && func_021C8288((u8 *)a) == 1) {
        k = func_021D775C(3);
        if (func_021B9A24(b, k) != 0) {
            if (func_0201C1E8((u16)func_021D775C(0x12)) == 1)
                func_021D7704(0x35, 3 << 11);
        }
    }
}






void func_021D901C(int u, int a, int b)
{
    u8 k;

    if (func_021D8E00((void *)a, b) != 0 && func_021C8288((u8 *)a) == 1) {
        k = func_021D775C(4);
        if (func_021B9A24(b, k) != 0) {
            if (func_021D775C(0x1a) == 2)
                func_021D7704(0x35, 6 << 10);
        }
    }
}



int *func_021D9064(int *p)
{
    *p = 11;
    return d_021F0E1C;
}



void func_021D9070(int u, int a, int b)
{
    void *p;
    void *q;
    u8 x;
    u8 y;

    if (b == func_021D775C(3)) {
        p = func_021C7CF4((int *)a, b);
        q = func_021C7CF4((int *)a, (u8)func_021D775C(4));
        x = func_021D59B4(p, 0x12);
        y = func_021D59B4(q, 0x12);
        if (x != 2 && y != 2) {
            if (x == y) {
                func_021D7704(0x31, 5 << 10);
                return;
            }
            func_021D7704(0x31, 3 << 10);
        }
    }
}


int *func_021D90DC(int *p)
{
    *p = 1;
    return d_021F07E0;
}


void func_021D90E8(int a, int b, int c)
{
    if (c == func_021D775C(3) && (unsigned int)func_021D775C(0x30) <= 0x3c) func_021D7704(0x31, 0x30 << 7);
}

void *func_021D910C(int *p) { *p = 1; return &d_021F0608; }
