/*
 * file:     weather_task_p70.c
 * unit:     yes
 * function: func_021A5EA4, func_021A5EDC, func_021A5F14, func_021A5F38, func_021A5F74, func_021A5F98, func_021A6014
 * address:  0x021A5EA4
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
 *   func_0216D5F8  0x0216D5F8  thumb
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
typedef unsigned short u16;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern u16 func_0216D5F8(void *p);
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
void func_021A5EA4(S *a, void *b, int c, int d, u16 e);
void func_021A5EDC(S *a, void *b, int c, int d, u16 e, int f);
void func_021A5F14(S *a, void *b, int c, int d, u16 e);
void func_021A5F38(S *a, void *b, int c, int d, u16 e);
void func_021A5F74(S *a, void *b, int c, int d, u16 e);
void func_021A5F98(int *a, u32 sel, u32 c, u32 d, u32 e, u32 f);
int func_021A6014(int *a, int b, int c, int d, int e);


void func_021A5EA4(S *a, void *b, int c, int d, u16 e)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410(b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}


void func_021A5EDC(S *a, void *b, int c, int d, u16 e, int f)
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


void func_021A5F14(S *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x28));
    a->f0 = 2;
    func_021A3964(a->f14, 2);
}


void func_021A5F38(S *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x1c));
    a->f0 = 3;
    func_021A3964(a->f14, 0);
    if (func_021A6C6C((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}


void func_021A5F74(S *a, void *b, int c, int d, u16 e)
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
