/*
 * file:     weather_task_p20.c
 * unit:     yes
 * function: func_021A5D04, func_021A5DD8, func_021A5E28, func_021A5EA0, func_021A5EA4, func_021A5EDC, func_021A5F14, func_021A5F38, func_021A5F74, func_021A5F98, func_021A6014
 * address:  0x021A5D04
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
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5CA4  0x021A5CA4  thumb  ov021
 *   func_021A5B6C  0x021A5B6C  thumb  ov021
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_0219D724  0x0219D724  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB158  0x021AB158  thumb  ov021
 *   func_021AB164  0x021AB164  thumb  ov021
 *   func_021AB170  0x021AB170  thumb  ov021
 *   func_021AB17C  0x021AB17C  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_021A3964  0x021A3964  thumb
 *   func_021A6C6C  0x021A6C6C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021A6278  0x021A6278  thumb  ov021
 *   func_021A627C  0x021A627C  thumb  ov021
 *   func_021A62B4  0x021A62B4  thumb  ov021
 *   func_021A62D8  0x021A62D8  thumb  ov021
 *   func_021A62FC  0x021A62FC  thumb  ov021
 *   func_021A6338  0x021A6338  thumb  ov021
 *   func_021A607C  0x021A607C  thumb  ov021
 *   func_021A60DC  0x021A60DC  thumb  ov021
 *   func_021A61B0  0x021A61B0  thumb  ov021
 *   func_021A6200  0x021A6200  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S_021A5EA4;

extern int func_0216D3CC(int a0);
extern int func_021A5CA4(void *a, void *b, int c, int d, int e, int f);
extern int func_021A5B6C(u32 a, u32 b, u32 c, u32 d);
extern int func_0219E664(void *o, u32 k, void *buf);
extern int func_0219D724(u32 a, char *b);
extern u16 func_021AB0F0(u32);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB158(u16);
extern int func_021AB164(u16);
extern int func_021AB170(u16);
extern int func_021AB17C(u16);
extern u16 func_0216D5F8(void *p);
extern void *func_0216D4B4(char *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *p, int a);
extern void func_021A3964(u8 *p, u32 v);
extern int func_021A6C6C(u8 *p, u32 k);
extern void func_020061E4(u32 a);
extern void func_021A6278(void *a, void *b, int c, int d, int e, int f);
extern void func_021A627C(void *a, void *b, int c, int d, int e, int f);
extern void func_021A62B4(void *a, void *b, int c, int d, int e, int f);
extern void func_021A62D8(void *a, void *b, int c, int d, int e, int f);
extern void func_021A62FC(void *a, void *b, int c, int d, int e, int f);
extern void func_021A6338(void *a, void *b, int c, int d, int e, int f);
extern int func_021A607C(void *a, void *b, int c, int d, int e, int f);
extern int func_021A60DC(void *a, void *b, int c, int d, int e, int f);
extern int func_021A61B0(void *a, void *b, int c, int d, int e, int f);
extern int func_021A6200(void *a, void *b, int c, int d, int e, int f);
int func_021A5D04(void *a, void *b, int c, int d, int e, int f);
int func_021A5DD8(void *a, void *b, int c, int d, u16 e, int f);
int func_021A5E28(void *a, void *b, int c, int d, int e, int f);
void func_021A5EA0(void *p, void *a, int b, int c, int d, int e);
void func_021A5EA4(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A5EDC(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A5F14(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A5F38(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A5F74(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A5F98(int *a, u32 sel, u32 c, u32 d, u32 e, u32 f);
int func_021A6014(int *a, int b, int c, int d, int e);



/*
 * Same body as ov021_func_021A60DC with func_021A5CA4 as the e == 9 path.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5D04(void *a, void *b, int c, int d, int e, int f)
{
    u8 buf[8];
    u32 r;
    u32 t;
    u16 k;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A5CA4(a, b, c, d, e, f);
    }
    r = func_021A5B6C((u32)a, (u32)b, e, 0);
    if (f == 1 && (r & 2)) {
        r = 0;
    }
    if (r == 0) {
        return 2;
    }
    if (r & 2) {
        func_0219E664(b, e, buf);
        t = func_0219D724((u32)b, (char *)buf);
        cls = 9;
        k = func_021AB0F0(t);
        func_021AB0F8(t);
        if (func_021AB158(k)) {
            cls = 0;
        } else if (func_021AB164(k)) {
            cls = 1;
        } else if (func_021AB170(k)) {
            cls = 2;
        } else if (func_021AB17C(k)) {
            cls = 3;
        }
        if (cls != 9 && cls == e) {
            return 5;
        }
    }
    return 4;
}



int func_021A5DD8(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A5CA4(a, b, c, d, e, f);
    }
    return func_021A5D04(a, b, c, d, e, f);
}



int func_021A5E28(void *a, void *b, int c, int d, int e, int f)
{
    int t = func_0216D5F8(b);
    if (e != 9 && e != t) {
        func_0216D4B4(b);
        return func_021A5D04(a, b, c, d, e, f);
    }
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A5CA4(a, b, c, d, e, f);
    }
    return func_021A5D04(a, b, c, d, e, f);
}


/*
 * Unlabelled leaf (a bare `bx lr` in a .word run): the empty arm-0 handler
 * called from func_021A5BC0's dispatch.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5EA0(void *p, void *a, int b, int c, int d, int e)
{
}



void func_021A5EA4(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410(b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}



void func_021A5EDC(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    int k;
    if (f == 1) {
        k = 0x14;
    } else if (d & 2) {
        k = 0x58;
    } else {
        k = 0xc;
    }
    func_0216D410(b, func_02197E7C(e, k));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}



void func_021A5F14(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x28));
    a->f0 = 2;
    func_021A3964(a->f14, 2);
}



void func_021A5F38(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x1c));
    a->f0 = 3;
    func_021A3964(a->f14, 0);
    if (func_021A6C6C((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}



void func_021A5F74(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x38));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}



void func_021A5F98(int *a, u32 sel, u32 c, u32 d, u32 e, u32 f)
{
    void *p = ((void **)a)[7];
    switch (sel) {
    case 0: func_021A6278(a, p, c, d, e, f); break;
    case 1: func_021A627C(a, p, c, d, e, f); break;
    case 2: func_021A62B4(a, p, c, d, e, f); break;
    case 3: func_021A62D8(a, p, c, d, e, f); break;
    case 4: func_021A62FC(a, p, c, d, e, f); break;
    case 5: func_021A6338(a, p, c, d, e, f); break;
    }
}



int func_021A6014(int *a, int b, int c, int d, int e)
{
    int sw = a[0];
    int r = 0;
    void *p = ((void **)a)[7];
    switch (sw) {
    case 0: r = func_021A607C(a, p, b, c, d, e); break;
    case 1: r = func_021A60DC(a, p, b, c, d, e); break;
    case 2: r = func_021A61B0(a, p, b, c, d, e); break;
    case 3: r = func_021A6200(a, p, b, c, d, e); break;
    }
    return r;
}
