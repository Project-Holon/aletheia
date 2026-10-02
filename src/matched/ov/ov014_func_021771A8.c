/*
 * unit: yes
 * function: func_021771A8, func_021771DC
 * address: 0x021771A8
 * packet: pkt_ov014_021771A8
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_021779F4 0x021779F4 thumb ov014
 */
extern int func_02178E4C(void);
int func_021771A8(void)
{
    switch (func_02178E4C()) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: return 1;
    case 0: default: return 0;
    }
}
extern int func_021779F4(void);
int func_021771DC(void) { return func_021779F4(); }
