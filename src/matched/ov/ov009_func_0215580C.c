/*
 * function: func_0215580C
 * address:  0x0215580C
 * packet:   pkt_ov009_0215580C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * In state 6 of the ov009 work block: resets n slots, enters state 7 and
 * hands func_0216B284 and three registrars the ov009 callbacks.
 *
 * The two callback leaves it passes were unlabelled; their own EXACT
 * shards (wave 2) witness them.
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02156C60  0x02156C60  thumb  ov009
 *   func_02156C00  0x02156C00  thumb  ov009
 *   func_02155374  0x02155374  thumb  ov009
 *   func_0216B284  0x0216B284  arm
 *   func_02177138  0x02177138  arm
 *   func_02177160  0x02177160  arm
 *   func_0216B634  0x0216B634  arm
 *   func_02177188  0x02177188  arm
 *   func_02155674  0x02155674  thumb  ov009
 *   func_02155D3C  0x02155D3C  thumb  ov009
 *   func_02155D80  0x02155D80  thumb  ov009
 *   func_02155DCC  0x02155DCC  thumb  ov009
 *   func_02155E9C  0x02155E9C  thumb  ov009
 *   func_02155BDC  0x02155BDC  thumb  ov009
 */

typedef unsigned char  u8;

typedef struct {
    char pad0[0x754];
    int state;
    int w758;
    int w75C;
    int w760;
    int n;
    char pad768[0x7A1 - 0x768];
    u8 b7A1;
} G;

typedef void (*Fn)(void);

extern G *d_021A8264;
extern char d_021A1C5C[];
void func_02034714(char *a, int b, char *c);
void func_02156C60(void);
void func_02156C00(int i);
void func_02155374(int v);
int func_0216B284(int a, u8 n, int b, Fn c, int d, Fn e, int f, int g,
                  int h, int i, int j, int k);
void func_02177138(Fn f, int a);
void func_02177160(Fn f, int a);
void func_0216B634(Fn f, int a);
void func_02177188(Fn f, int a);
void func_02155674(void);
void func_02155D3C(void);
void func_02155D80(void);
void func_02155DCC(void);
void func_02155E9C(void);
void func_02155BDC(void);

int func_0215580C(int a0, int n, int a2, int a3)
{
    int i;

    if (d_021A8264 == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (d_021A8264->state != 6)
        return 0;
    func_02156C60();
    for (i = 0; i < n; i++)
        func_02156C00(i);
    func_02155374(7);
    d_021A8264->n = n;
    if (func_0216B284(1, n, a0, func_02155D3C, 0, func_02155674, 0, a2, a3,
                      0, 0, 0) == 0)
        return 0;
    d_021A8264->w75C = 0;
    func_02177138(func_02155D80, 0);
    func_02177160(func_02155DCC, 0);
    func_0216B634(func_02155E9C, 0);
    func_02177188(func_02155BDC, 0);
    d_021A8264->w760 = 0;
    d_021A8264->b7A1 = 1;
    d_021A8264->w758 = 0x3EF;
    return 1;
}
