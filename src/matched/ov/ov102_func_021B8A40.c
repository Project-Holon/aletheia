/*
 * function: func_021B8A40
 * address: 0x021B8A40
 * packet: pkt_ov102_021B8A40
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 021B8A8E.
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
void func_021B8A40(int *p, int a, int b, int n)
{
    int d;
    float f;
    p[0] = a;
    p[1] = a;
    p[2] = b;
    p[5] = n;
    if (n) {
        d = b - a;
        if (d > 0)
            f = 0.5f + (float)(d << 12);
        else
            f = (float)(d << 12) - 0.5f;
        p[3] = (int)f / n;
        p[4] = 0;
    } else {
        p[4] = n - 2;
    }
}
