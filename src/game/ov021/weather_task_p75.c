/*
 * file:     weather_task_p75.c
 * unit:     yes
 * function: func_021A63F0, func_021A6428
 * address:  0x021A63F0
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
void func_021A63F0(S *a, void *b, int c, int d, u16 e);
void func_021A6428(S *a, void *b, int c, int d, u16 e, int f);


void func_021A63F0(S *a, void *b, int c, int d, u16 e)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410(b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}


void func_021A6428(S *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410(b, func_02197E7C(e, (f == 1) ? 0x14 : 0x10));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}
