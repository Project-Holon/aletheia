/*
 * function: func_021D7374
 * address: 0x021D7374
 * packet: pkt_ov125_021D7374
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D85E8 0x021D85E8 arm ov125
 */
extern int func_021D85E8(void);
typedef struct { int count; char entries[1]; } List;
int func_021D7374(int a, void **out, int max)
{
    int p;
    char *base;
    int n;
    int i;
    p = func_021D85E8() + 4;
    n = *(int *)p;
    if (n > max) n = max;
    base = (char *)(p + 4);
    for (i = 0; i < n; i++) out[i] = base + i * 572 + 12;
    for (; i < max; i++) out[i] = 0;
    return n;
}
