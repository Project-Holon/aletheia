/*
 * file:     unit_021EE740.c
 * unit:     yes
 * function: func_021EE740, func_021EE7A4, func_021EE814, func_021EE888, func_021EE8D4, func_021EE908, func_021EE970, func_021EE990, func_021EEA04
 * address:  0x021EE740
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021EEAF4  0x021EEAF4  thumb  ov027
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_021A2248  0x021A2248  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   d_021EEB48     0x021EEB48  data  ov027  a4
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_0204B908  0x0204B908  arm
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   d_021EEB68     0x021EEB68  data  a4
 */
struct PtS;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short s16;

int *func_021A21B8(int *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A2424(u8 *p);
void func_021A25BC(unsigned char *o, int arg);
int func_021A223C(unsigned char *o, int arg);
void func_021A232C(u8 *p, int a, int b, int c, int d);
u16 func_02014A10(u32 i);
int func_021A2108(u32 a, int b, int c);
int func_021A23B0(u32 a);
void func_021A2160(unsigned char *o, unsigned int v, int i);
void func_021EEAF4(int a, int *p);
void func_021A2254(int a, void (*b)(int, int, int), int c, int d, int e, int f);
int func_021A2114(u32 a, int b, u32 c);
int func_021A2248(unsigned char *o, int arg);
int func_0209C0A4(int a, int b);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021A25CC(u8 *);
void func_021A2390(u32 *p, int a, int b, int c);
int func_021A21BC(unsigned char *o);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
unsigned char *func_021A2630(unsigned char *o);
unsigned int func_021A2638(unsigned char *o);
void func_021A2640(unsigned char *a, struct PtS *pt);
void func_021A2654(int obj, unsigned short *src);
void func_021A21E0(u32 *p);
extern u32 func_020056EC(u32 range);
extern void func_0204B908(int a0, int a1);
extern void *func_021A21C8(void *p, int a1);
int func_021EE740(int a, int b);
int func_021EE7A4(int a, int b, int c);
int func_021EE814(unsigned int *a, int b, int c);
int func_021EE888(int a, int b, int c);
int func_021EE8D4(u8 *a);
int func_021EE908(int a, int b, int c);
int func_021EE970(u32 *a, int b);
void func_021EE990(int a);
void func_021EEA04(int a, int n, int idx);
extern const int d_021EEB48[];
extern const int d_021EEB68[];



int func_021EE740(int a, int b)
{
    int *p = func_021A21B8((int *)a);

    func_021A21F8((u8 *)a, 1, 15, 1, 2, -2, 4, 1, (int)func_021EEA04);
    func_021A22E0((u32 *)a, 8, 0x7fdf, b);
    p[0] = 1;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    func_021A2424((u8 *)a);
    func_021A25BC((unsigned char *)a, 0x6e3);
    return 1;
}



int func_021EE7A4(int a, int b, int c)
{
    int *p = func_021A21B8((int *)a);
    int t = func_021A223C((unsigned char *)a, c);

    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A232C((u8 *)a, 8, 0x7f5e, 0x5a, b);
            func_021A2108(a, 0x3e, func_02014A10(3));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        func_021A2160((unsigned char *)a, 1, 0);
        return 1;
    }
    func_021EEAF4(a, p);
    return 0;
}



int func_021EE814(unsigned int *a, int b, int c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 2, 1, 2, -2, 4, 1, (int)func_021EEA04);
    func_021A22E0(a, 8, 0x7f5e, b);
    func_021A2254((int)a, func_021EEA04, 24, 2, 2, c);
    func_021A2160((unsigned char *)a, 1, 0);
    func_021A2114((u32)a, 0x3e, func_02014A10(3));
    return 1;
}



int func_021EE888(int a, int b, int c)
{
    int *p = func_021A21B8((int *)a);

    if (func_021A2248((unsigned char *)a, c) != 0) {
        int v = d_021EEB48[func_0209C0A4(p[1], 40)];
        p[3] = v;
        if (v <= -6)
            func_021EEA04(a, 1, c);
    }
    func_021EEAF4(a, p);
    return 0;
}


int func_021EE8D4(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 15, 2, -1);
    *p = 31;
    func_021A2160(a, 0, 0);
    func_021A25CC(a);
    return 1;
}



int func_021EE908(int a, int b, int c)
{
    int *p = func_021A21B8((int *)a);
    int t = func_021A223C((unsigned char *)a, c);
    int r;

    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0)
            func_021A2390((u32 *)a, 0x7fdf, 0x5a, b);
    } else {
        if (b != 0)
            r = func_021A23B0(a);
        else
            r = 1;
        if (r != 0 && t != 0) {
            if (func_021A21BC((unsigned char *)a) == 0)
                return 1;
        }
    }
    func_021EEAF4(a, p);
    return 0;
}


int func_021EE970(u32 *a, int b)
{
    func_021A21B8((int *)a);
    func_021A231C(a, b);
    func_021A2120(a, b);
    return 1;
}



/*
 * The 2 trailing bytes (0x021EEA02) are alignment padding before
 * func_021EEA04, which is why the verdict is EXACT*.
 */
void func_021EE990(int a)
{
    int *o = (int *)func_021A2630((unsigned char *)a);
    short pt[2];

    func_021A2638((unsigned char *)a);
    func_021A2640((unsigned char *)a, (struct PtS *)pt);
    if (o[3] == 0) {
        pt[0] = pt[0] + (short)o[4];
        pt[1] = pt[1] + (short)o[2];
        if (o[0] % 5 == 0)
            o[4] = o[4] + o[5];
        if (o[0]++ > o[1])
            o[3] = 1;
        func_021A2654(a, (short unsigned int *)pt);
    } else {
        func_021A21E0((u32 *)a);
    }
}



void func_021EEA04(int a, int n, int idx)
{
    int *w;
    int k;
    int i;
    int q;
    int obj;
    int *e;
    int s;
    s16 pt[2];

    w = func_021A21B8((int *)a);
    w[1] = (w[1] + 1) % 320;
    k = w[1] / 40;
    for (i = 0; i < n; i++) {
        obj = (int)func_021A21C8((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        q = func_021A2638((unsigned char *)obj);
        e[0] = 0;
        e[1] = func_020056EC(20) + 15;
        s = 3 - (e[1] - 15) / 6;
        e[2] = (s + 1) * d_021EEB68[k];
        e[4] = (s + 1) * d_021EEB48[k];
        e[3] = 0;
        e[5] = d_021EEB48[k];
        if (func_020056EC(1000) == 777) {
            s = 4;
            e[2] = e[2] + e[2] / 2;
        }
        func_0204B908(q, (u16)s);
        pt[0] = -6 - func_020056EC(24);
        pt[1] = func_020056EC(192) - 64;
        func_021A2654(obj, (short unsigned int *)pt);
    }
}
