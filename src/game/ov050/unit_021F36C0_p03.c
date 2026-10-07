/*
 * file:     unit_021F36C0_p03.c
 * unit:     yes
 * function: func_021F383C, func_021F3890
 * address:  0x021F383C
 * region:   ov050
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb
 *   func_021BE760  0x021BE760  thumb
 *   func_021BE480  0x021BE480  thumb
 *   func_021F3744  0x021F3744  thumb  ov050
 *   func_021F3788  0x021F3788  thumb  ov050
 *   d_021F38A4     0x021F38A4  data  a4
 *   d_021F38B4     0x021F38B4  data  a4
 */
typedef struct { int a; int b; int c; } T12;

extern int func_02188D2C(int a);
extern void func_021BE760(int a, void *b, int c);
extern T12 *func_021BE480(int a, int b, unsigned short c);
extern void func_021F3744(int *p);
extern void func_021F3788(int *p);
void func_021F383C(int unused, int b);
void func_021F3890(void);
extern int d_021F38A4;
extern const T12 d_021F38B4[];


void func_021F383C(int unused, int b)
{
    int r4;
    int i;
    T12 *p;
    const T12 *s;

    r4 = func_02188D2C(b);
    func_021BE760(r4, &d_021F38A4, 0);
    for (i = 0; i < 2; i++) {
        p = func_021BE480(r4, 0, i);
        s = &d_021F38B4[i];
        p->a = s->a;
        p->b = s->b;
        p->c = s->c;
    }
    func_021F3744((int *)b);
    func_021F3788((int *)b);
}

void func_021F3890(void)
{
}
