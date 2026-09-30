/*
 * function: func_021D5CAC
 * address: 0x021D5CAC
 * packet: pkt_ov123_021D5CAC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5DB4 0x021C5DB4 arm ov114
 */
extern int func_021C5DB4(void);
int func_021D5CAC(char *p)
{
    if (*(int *)(p+0xd0)) return 0;
    if (*(int *)(p+0xcc)) {
        if (++*(int *)(p+0xcc)>3600) {
            *(int *)(p+0xd0)=1;
            if (!func_021C5DB4()) *(int *)(p+0xc8)=1;
            return 0;
        }
    }
    return 1;
}
