/*
 * function: func_021FE4D8
 * address: 0x021FE4D8
 * packet: pkt_ov186_021FE4D8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
extern void func_02082BCC(void *, unsigned, unsigned);
void func_021FE4D8(int *p, int a, const int *values, int duration)
{
    float value;
    func_02082BCC(p, 0, 0x14);
    p[0] = a;
    if (values[0] > 0)
        value = 0.5f + (float)(values[0] << 12);
    else
        value = (float)(values[0] << 12) - 0.5f;
    p[1] = (int)value;
    if (values[1] > 0)
        value = 0.5f + (float)(values[1] << 12);
    else
        value = (float)(values[1] << 12) - 0.5f;
    p[2] = (int)value;
    p[3] = 0;
    p[4] = duration;
}
