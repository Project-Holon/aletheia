/*
 * unit: yes
 * function: func_06899D2C, func_06899D30
 * address: 0x06899D2C
 * packet: pkt_ov095_06899D2C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: veneer follower unit; function_starts seeds 06899D2C, 06899D30.
 * symbols:
 *   func_06899D38 0x06899D38 thumb ov095
 */
extern void func_06899D38(void);
void func_06899D2C(void) {}
void func_06899D30(void) { func_06899D38(); }
