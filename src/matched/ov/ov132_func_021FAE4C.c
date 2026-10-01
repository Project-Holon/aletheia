/*
 * function: func_021FAE4C
 * address: 0x021FAE4C
 * packet: pkt_ov132_021FAE4C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0207CEE4 0x0207CEE4 arm
 */
typedef unsigned short u16;
extern void func_0207CEE4(int, void *, void *, void *);
int func_021FAE4C(char *p, int *out)
{
    int v;
    (*(u16 *)(p + 0x2a))++;
    if (*(u16 *)(p + 0x2a) >= *(u16 *)(p + 0x28)) {
        out[0] = *(int *)(p + 0x10);
        out[1] = *(int *)(p + 0x14);
        out[2] = *(int *)(p + 0x18);
        return 1;
    }
    if (*(u16 *)(p + 0x2a) != 0) v = (int)(0.5f + (float)(*(u16 *)(p + 0x2a) << 12));
    else v = (int)((float)(*(u16 *)(p + 0x2a) << 12) - 0.5f);
    func_0207CEE4(v, p + 0x1c, p + 4, out);
    return 0;
}
