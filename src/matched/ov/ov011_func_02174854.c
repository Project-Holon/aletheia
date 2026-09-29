/*
 * function: func_02174854
 * address:  0x02174854
 * packet:   pkt_ov011_02174854
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_020399A8(void);
int func_0203D3F8(int a, int b, int c, int d, int e, int f, int g, int h);

typedef struct { unsigned char a : 1; unsigned char b : 1; unsigned char c : 1; } F8;

int func_02174854(unsigned char *p, int b, int c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    ((F8 *)(p + 0x8F8))->b = 0;
    return func_0203D3F8(func_020399A8(), b, 0x228, 4, c, 0, 0, 0);
}
