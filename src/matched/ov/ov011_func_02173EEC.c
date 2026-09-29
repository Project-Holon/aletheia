/*
 * function: func_02173EEC
 * address:  0x02173EEC
 * packet:   pkt_ov011_02173EEC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D578  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_020399A8(void);
int func_0203D578(int a, int b);
void func_02082D44(char *d, char *s, int n);
int func_0203D3F8(int a, int b, int c, int d, char *e, int f, int g, int h);

int func_02173EEC(char *a, char *b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578(func_020399A8(), 0x212) == 1) {
        return 0;
    }
    func_02082D44(b + 0x78, a + 0x3F0, 0x34);
    return func_0203D3F8(func_020399A8(), 0xFF, 0x212, 0x34, a + 0x3F0, 0, 0, 1);
}
