/*
 * function: func_021DD018
 * address: 0x021DD018
 * packet: pkt_ov119_021DD018
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   d_021E7FE0 0x021E7FE0 data ov119 a4
 */
extern int func_021E4DBC(char *);
extern const int d_021E7FE0[];
void func_021DD018(char *p, int flag)
{
    int n;
    if (flag) {
        n = func_021E4DBC(p) + 2;
        if (n >= *(int *)(p + 0x634)) n -= *(int *)(p + 0x634);
        if (*(short *)(p + 0x107c) == d_021E7FE0[0]) n = 2;
        else if (*(short *)(p + 0x107c) == d_021E7FE0[*(int *)(p + 0x630)]) {
            n = 0;
            if (*(int *)(p + 0xf78) >= 3) *(int *)(p + 0xf78) = 2;
        }
        *(int *)(p + 0xf74) = n;
        *(short *)(p + 0x1080) = -1;
    }
}
