/*
 * file:     unit_021EE740.c
 * unit:     yes
 * function: func_021EE740, func_021EE788, func_021EE7F0, func_021EE838, func_021EE83C
 * address:  0x021EE740
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A23D4  0x021A23D4  thumb  ov021
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A23E8  0x021A23E8  thumb  ov021
 *   func_021A2400  0x021A2400  thumb  ov021
 *   func_021A240C  0x021A240C  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A23F4  0x021A23F4  thumb  ov021
 *   func_021A2418  0x021A2418  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

int func_021A23D4(int *p);
int *func_021A21B8(int *p);
int func_021A23E8(int *p);
int func_021A2400(int *p);
int func_021A240C(int *p);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A232C(u8 *p, int a, int b, int c, int d);
int func_021A23F4(int *p);
int func_021A2418(int *p);
int func_021A2108(u32 a, int b, int c);
int func_021A23B0(u32 a);
int func_021A2114(u32 a, int b, u32 c);
void func_021A2390(u32 *p, int a, int b, int c);
int func_021EE740(int *p, int v);
int func_021EE788(int *p, int v);
int func_021EE7F0(int p, int v);
int func_021EE838(void);
int func_021EE83C(int p, int v);


int func_021EE740(int *p, int v)
{
    if (func_021A23D4(p)) {
        return 0;
    }
    *func_021A21B8(p) = 0;
    if (func_021A23E8(p)) {
        func_021A2400(p);
        func_021A22E0((u32 *)p, func_021A240C(p), 0x7FFF, v);
    }
    return 1;
}


int func_021EE788(int *p, int v)
{
    int *s = func_021A21B8(p);
    int t;

    if (*s == 0) {
        if (func_021A23E8(p)) {
            t = func_021A2400(p);
            func_021A232C((u8 *)p, func_021A240C(p), t, 0xA0, v);
        }
        if (func_021A23F4(p)) {
            func_021A2108((u32)p, 0x52, func_021A2418(p));
        }
        *s = 1;
    }
    if (func_021A23B0((u32)p)) {
        return 1;
    }
    return 0;
}


int func_021EE7F0(int p, int v)
{
    int t;

    if (func_021A23E8((int *)p)) {
        t = func_021A2400((int *)p);
        func_021A22E0((u32 *)p, func_021A240C((int *)p), t, v);
    }
    if (func_021A23F4((int *)p)) {
        func_021A2114(p, 0x52, func_021A2418((int *)p));
    }
    return 1;
}

/*
 * Unlabelled 4-byte Thumb leaf (`movs r0,#0; bx lr`), emitted as a data word
 * by disasm.py because it saves no lr. Sits alone between func_021EE82x and
 * func_021EE83C, extent 4.
 */
int func_021EE838(void)
{
    return 0;
}


int func_021EE83C(int p, int v)
{
    if (func_021A23E8((int *)p)) {
        func_021A2390((u32 *)p, 0x7FFF, 0x50, v);
    }
    return 1;
}
