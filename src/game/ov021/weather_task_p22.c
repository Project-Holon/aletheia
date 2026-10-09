/*
 * file:     weather_task_p22.c
 * unit:     yes
 * function: func_021A60DC, func_021A61B0, func_021A6200, func_021A6278, func_021A627C, func_021A62B4, func_021A62D8, func_021A62FC, func_021A6338, func_021A635C, func_021A63EC
 * address:  0x021A60DC
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
 *   func_021A607C  0x021A607C  thumb  ov021
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
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A63F0  0x021A63F0  thumb  ov021
 *   func_021A6428  0x021A6428  thumb  ov021
 *   func_021A6454  0x021A6454  thumb  ov021
 *   func_021A6478  0x021A6478  thumb  ov021
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
extern int func_021A607C(void *a, void *b, int c, int d, int e, int f);
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
extern void *func_021A3960(unsigned char *p);
extern void func_021A63F0(void *a, void *b, int c, int d, int e, int f);
extern void func_021A6428(void *a, void *b, int c, int d, int e, int f);
extern void func_021A6454(void *a, void *b, int c, int d, int e, int f);
extern void func_021A6478(void *a, void *b, int c, int d, int e, int f);
int func_021A60DC(void *a, void *b, int c, int d, int e, int f);
int func_021A61B0(void *a, void *b, int c, int d, u16 e, int f);
int func_021A6200(void *a, void *b, int c, int d, int e, int f);
void func_021A6278(void *a, void *b, int c, int d, int e, int f);
void func_021A627C(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A62B4(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A62D8(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A62FC(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A6338(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A635C(S_021A5EA4 *a, int sel, int c, int d, int e, int f);
void func_021A63EC(void *a, void *b, int c, int d, int e, int f);





/*
 * Same body as ov021_func_021A5D04 with func_021A607C as the e == 9 path.
 *
 * Addresses are Black-image addresses.
 */
int func_021A60DC(void *a, void *b, int c, int d, int e, int f)
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
        return func_021A607C(a, b, c, d, e, f);
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





int func_021A61B0(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A607C(a, b, c, d, e, f);
    }
    return func_021A60DC(a, b, c, d, e, f);
}





int func_021A6200(void *a, void *b, int c, int d, int e, int f)
{
    int t = func_0216D5F8(b);
    if (e != 9 && e != t) {
        func_0216D4B4(b);
        return func_021A60DC(a, b, c, d, e, f);
    }
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A607C(a, b, c, d, e, f);
    }
    return func_021A60DC(a, b, c, d, e, f);
}




/*
 * Empty leaf (bx lr) that saves nothing, so disasm.py does not label it.
 */
void func_021A6278(void *a, void *b, int c, int d, int e, int f)
{
}





void func_021A627C(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410(b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}





void func_021A62B4(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x14));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}




void func_021A62D8(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x28));
    a->f0 = 2;
    func_021A3964(a->f14, 2);
}




void func_021A62FC(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x1c));
    a->f0 = 3;
    func_021A3964(a->f14, 0);
    if (func_021A6C6C((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}




void func_021A6338(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x38));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}



void func_021A635C(S_021A5EA4 *a, int sel, int c, int d, int e, int f)
{
    void *x = func_021A3960(a->f14);
    switch (sel) {
    case 0: func_021A63EC(a, x, c, d, e, f); break;
    case 1: func_021A63F0(a, x, c, d, e, f); break;
    case 2: func_021A6428(a, x, c, d, e, f); break;
    case 3: func_021A6454(a, x, c, d, e, f); break;
    case 4: func_021A6478(a, x, c, d, e, f); break;
    }
}


void func_021A63EC(void *a, void *b, int c, int d, int e, int f)
{
}
