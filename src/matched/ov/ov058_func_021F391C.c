/*
 * function: func_021F391C
 * address:  0x021F391C
 * packet:   pkt_ov058_021F391C
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     places four entries (i, j, i + 2, j + 2) and rotates each by a
 *           (sin, cos) pair of the arm9 table at 0x020A1B38: pair 0x400 for
 *           the first two, pair 0xC00 for the last two (the pool words
 *           0x020A2B38 / 0x020A4B38 are that table plus 0x1000 / 0x3000).
 *           The cos values are separate locals y and y2 (two stack slots)
 *           while the sin value reuses x in r7; y declared before x puts x
 *           in r7 (x first swaps them). The function is 264 bytes, the rest
 *           of the handed 612 is data.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   d_020A1B38     0x020A1B38  data  a2
 */

typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern s16 d_020A1B38[];

typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern char *func_021BE480(void *p, int i, u16 j);
extern void  func_021BE4A4(void *p, int i, u16 j, int v);
extern void  func_0207AF1C(void *m, int a, int b);

void func_021F391C(void *unused, void *a, int i, int j)
{
    void *s;
    V *e;
    int y;
    int x;
    int y2;

    func_02188C84(a);
    s = (void *)func_02188D2C(a);

    e = (V *)func_021BE480(s, 0, i);
    e->a = 0x1770000;
    e->b = 0x50000;
    e->c = 0x2100000;
    x = d_020A1B38[0x800];
    y = d_020A1B38[0x801];
    func_0207AF1C((char *)e + 0x18, x, y);
    func_021BE4A4(s, 0, i, 1);

    e = (V *)func_021BE480(s, 0, j);
    e->a = 0x1710000;
    e->b = 0x50000;
    e->c = 0x2100000;
    func_0207AF1C((char *)e + 0x18, x, y);
    func_021BE4A4(s, 0, j, 1);

    e = (V *)func_021BE480(s, 0, i + 2);
    e->a = 0x1C60000;
    e->b = 0x50000;
    e->c = 0x20B0000;
    x = d_020A1B38[0x1800];
    y2 = d_020A1B38[0x1801];
    func_0207AF1C((char *)e + 0x18, x, y2);
    func_021BE4A4(s, 0, i + 2, 1);

    e = (V *)func_021BE480(s, 0, j + 2);
    e->a = 0x1CC0000;
    e->b = 0x50000;
    e->c = 0x20B0000;
    func_0207AF1C((char *)e + 0x18, x, y2);
    func_021BE4A4(s, 0, j + 2, 1);
}
