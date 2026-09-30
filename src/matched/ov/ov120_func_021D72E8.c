/*
 * function: func_021D72E8
 * address: 0x021D72E8
 * packet: pkt_ov120_021D72E8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: named float scale initialized before the guard keeps its pool load in r6.
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fgeq 0x0209BB54 arm
 *   _ffix 0x0209C494 arm
 */
int func_021D72E8(void *p, int n, int count)
{
    float f;
    float scale;
    f = (float)(n - 26);
    scale = 132.0f;
    if (count <= 3) return 0;
    f = f / (scale / (float)(count - 2));
    if (f >= (float)(count - 2)) f = (float)(count - 3);
    return (int)f;
}
