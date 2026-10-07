/*
 * file:     unit_021EE740.c
 * unit:     yes
 * function: func_021EE740, func_021EE770, func_021EE7C0, func_021EE7EC, func_021EE7F0, func_021EE800, func_021EE84C, func_021EE868, func_021EE8B0, func_021EE8F8, func_021EE940, func_021EE988, func_021EE9D8, func_021EEA04, func_021EEA08, func_021EEA18
 * address:  0x021EE740
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2148  0x021A2148  thumb  ov021
 *   d_021EEA80     0x021EEA80  data  ov028  a1
 *   d_021EEAA4     0x021EEAA4  data  ov028  a4
 */
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern int *func_021A21B8(int *);
extern void func_021A22E0(u32 *, int, int, int);
void func_021A232C(u8 *p, int a, int b, int c, int d);
u16 func_02014A10(u32 i);
int func_021A2108(u32 a, int b, int c);
int func_021A23B0(u32 a);
extern int func_021A2114(u32 a, int b, u32 c);
void func_021A2390(u32 *p, int a, int b, int c);
int func_021A21BC(unsigned char *o);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
int func_021A2148(unsigned char *o);
int func_021EE740(u32 *a, int b);
int func_021EE770(int a, int b);
int func_021EE7C0(u32 *a, int b);
int func_021EE7EC(void);
int func_021EE7F0(int *a);
int func_021EE800(int a, int b);
int func_021EE84C(u32 *a, int b);
void func_021EE864(void);
int func_021EE868(int a, int b);
int func_021EE8B0(int a, int b);
int func_021EE8F8(int a, int b);
int func_021EE940(int a, int b);
int func_021EE988(int a, int b);
int func_021EE9D8(u32 *a, int b);
int func_021EEA04(void);
int func_021EEA08(int *a);
int func_021EEA18(int a, int b);
extern unsigned char d_021EEA80[];
extern int d_021EEAA4[];

int func_021EE740(u32 *a, int b)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A22E0(a, 9, 0x7FDF, b);
    p[0] = 0;
    p[10] = 9;
    p[11] = 0x7F78;
    return 1;
}


int func_021EE770(int a, int b)
{
    int *p = func_021A21B8((int *)a);

    if (*p == 0) {
        func_021A232C((u8 *)a, p[10], p[11], 0x5a, b);
        func_021A2108(a, 0x3e, func_02014A10(9));
        *p = *p - 1;
    } else if (func_021A23B0(a) != 0) {
        return 1;
    }
    return 0;
}

int func_021EE7C0(u32 *a, int b)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A22E0(a, p[10], p[11], b);
    func_021A2114((u32)a, 62, func_02014A10(9));
    return 1;
}

/*
 * Unlabelled 4-byte Thumb leaf (`movs r0,#0; bx lr`), emitted as a data word
 * by disasm.py because it saves no lr. A standalone slot: it follows the
 * `pop {r3,r4,r5,pc}` end of func_021EE7E8 and precedes func_021EE7F0.
 */
int func_021EE7EC(void)
{
    return 0;
}

int func_021EE7F0(int *a)
{
    int *p;
    p = func_021A21B8(a);
    p[0] = 0;
    return 1;
}


int func_021EE800(int a, int b)
{
    int *p = func_021A21B8((int *)a);
    int v = *p;
    int r;

    if (v == 0) {
        *p = v - 1;
        func_021A2390((u32 *)a, 0x7fdf, 0x3c, b);
    } else {
        if (b != 0)
            r = func_021A23B0(a);
        else
            r = 1;
        if (r != 0) {
            if (func_021A21BC((unsigned char *)a) == 0)
                return 1;
        }
    }
    return 0;
}

int func_021EE84C(u32 *a, int b)
{
    func_021A231C(a, b);
    func_021A2120(a, b);
    return 1;
}


void func_021EE864(void)
{
}


int func_021EE868(int a, int b)
{
    int i = func_021A2148((unsigned char *)a);
    int *p = func_021A21B8((int *)a);

    p[1] = 0;
    p[0] = 10;
    p[11] = d_021EEA80[i];
    p[12] = d_021EEAA4[i];
    func_021A22E0((u32 *)a, p[11], 0x7fdf, b);
    return 1;
}


int func_021EE8B0(int a, int b)
{
    int i = func_021A2148((unsigned char *)a);
    int *p = func_021A21B8((int *)a);

    p[1] = 0;
    p[0] = 11;
    p[11] = d_021EEA80[i];
    p[12] = d_021EEAA4[i];
    func_021A22E0((u32 *)a, p[11], 0x7fdf, b);
    return 1;
}


int func_021EE8F8(int a, int b)
{
    int i = func_021A2148((unsigned char *)a);
    int *p = func_021A21B8((int *)a);

    p[1] = 0;
    p[0] = 13;
    p[11] = d_021EEA80[i];
    p[12] = d_021EEAA4[i];
    func_021A22E0((u32 *)a, p[11], 0x7fdf, b);
    return 1;
}


int func_021EE940(int a, int b)
{
    int i = func_021A2148((unsigned char *)a);
    int *p = func_021A21B8((int *)a);

    p[1] = 0;
    p[0] = 14;
    p[11] = d_021EEA80[i];
    p[12] = d_021EEAA4[i];
    func_021A22E0((u32 *)a, p[11], 0x7fdf, b);
    return 1;
}


int func_021EE988(int a, int b)
{
    int *p = func_021A21B8((int *)a);

    if (p[1] == 0) {
        func_021A232C((u8 *)a, p[11], p[12], 0x5A, b);
        func_021A2108(a, 0x3E, func_02014A10(p[0]));
        p[1] = p[1] - 1;
    } else if (func_021A23B0(a) != 0) {
        return 1;
    }
    return 0;
}

int func_021EE9D8(u32 *a, int b)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A22E0(a, p[11], p[12], b);
    func_021A2114((u32)a, 62, func_02014A10(p[0]));
    return 1;
}

int func_021EEA04(void)
{
    return 0;
}

int func_021EEA08(int *a)
{
    int *p;
    p = func_021A21B8(a);
    p[1] = 0;
    return 1;
}


int func_021EEA18(int a, int b)
{
    int *p = func_021A21B8((int *)a);
    int ok;

    if (p[1] == 0) {
        p[1] = p[1] - 1;
        func_021A2390((u32 *)a, 0x7FDF, 0x3C, b);
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && func_021A21BC((unsigned char *)a) == 0) {
            return 1;
        }
    }
    return 0;
}
