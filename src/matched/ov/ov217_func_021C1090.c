/*
 * function: func_021C1090
 * address:  0x021C1090
 * packet:   pkt_ov217_021C1090
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _fflt  0x0209BDBC  arm
 *   _fmul  0x0209C77C  arm
 *   _ffix  0x0209C494  arm
 *   func_02045738  0x02045738  arm
 *   func_0201D304  0x0201D304  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int func_02045738(int a);
extern int func_0201D304(int a, int b, int c);

int func_021C1090(u8 *p, int a1)
{
    int r;
    int x;
    x = func_02045738(*(int *)(p + 0x18)) * 8;
    x = x - func_0201D304(a1, *(int *)(p + 0x10), 0);
    r = (int)(0.5f * (float)x);
    if (r < 0) {
        r = 0;
    }
    return r;
}
