/*
 * file:     weather_task_p74.c
 * unit:     yes
 * function: func_021A635C, func_021A63EC
 * address:  0x021A635C
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
} S;

extern void *func_021A3960(unsigned char *p);
extern void func_021A63F0(void *a, void *b, int c, int d, int e, int f);
extern void func_021A6428(void *a, void *b, int c, int d, int e, int f);
extern void func_021A6454(void *a, void *b, int c, int d, int e, int f);
extern void func_021A6478(void *a, void *b, int c, int d, int e, int f);
void func_021A635C(S *a, int sel, int c, int d, int e, int f);
void func_021A63EC(void *a, void *b, int c, int d, int e, int f);


void func_021A635C(S *a, int sel, int c, int d, int e, int f)
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

/*
 * Empty leaf (bx lr) that saves nothing, so disasm.py does not label it.
 */
void func_021A63EC(void *a, void *b, int c, int d, int e, int f)
{
}
