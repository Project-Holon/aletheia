/*
 * function: func_021F37B8
 * address:  0x021F37B8
 * packet:   pkt_ov050_021F37B8
 * region:   ov050
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   func_021BE700  0x021BE700  thumb
 *   func_021BE674  0x021BE674  thumb
 *   func_021BE6B8  0x021BE6B8  thumb
 */

extern int func_02188D2C(void);
extern void func_021BE4B4(int a, int b, int c, int d);
extern void func_021BE700(int a, int b, int c, unsigned short d, int e);
extern int func_021BE674(int a, int b, int c, unsigned short d);
extern void func_021BE6B8(int a, int b);

void func_021F37B8(void)
{
    int r6;
    int i;
    int j;

    r6 = func_02188D2C();
    func_021BE4B4(r6, 0, 1, 0);
    for (i = 0; i < 2; i++)
        func_021BE700(r6, 0, 1, i, 1);
    for (j = 0; j < 2; j++)
        func_021BE6B8(func_021BE674(r6, 0, 1, j), 0);
}
