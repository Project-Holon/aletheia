/*
 * function: func_021F0674
 * address: 0x021F0674
 * packet: pkt_ov033_021F0674
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021D50 0x02021D50 thumb
 */
struct S02021D50;
extern void func_02021D50(struct S02021D50 *);
void func_021F0674(int a, unsigned char *p)
{
    func_02021D50(*(struct S02021D50 **)(p + 0xbc));
    if (*(int *)(p + 0xb0) != 0) {
        if (p[0xac] >= 4)
            p[0xac] = 0;
        p[0xac]++;
    }
}
