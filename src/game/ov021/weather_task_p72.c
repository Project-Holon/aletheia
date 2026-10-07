/*
 * file:     weather_task_p72.c
 * unit:     yes
 * function: func_021A6200, func_021A6278, func_021A627C, func_021A62B4
 * address:  0x021A6200
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
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_021A607C  0x021A607C  thumb  ov021
 *   func_021A60DC  0x021A60DC  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_021A3964  0x021A3964  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S;

extern int func_0216D3CC(int a0);
extern u16 func_0216D5F8(void *p);
extern void *func_0216D4B4(char *p);
extern int func_021A607C(void *a, void *b, int c, int d, int e, int f);
extern int func_021A60DC(void *a, void *b, int c, int d, int e, int f);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *p, int a);
extern void func_021A3964(u8 *p, u32 v);
int func_021A6200(void *a, void *b, int c, int d, int e, int f);
void func_021A6278(void *a, void *b, int c, int d, int e, int f);
void func_021A627C(S *a, void *b, int c, int d, u16 e);
void func_021A62B4(S *a, void *b, int c, int d, u16 e);


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


void func_021A627C(S *a, void *b, int c, int d, u16 e)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410(b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}


void func_021A62B4(S *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x14));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}
