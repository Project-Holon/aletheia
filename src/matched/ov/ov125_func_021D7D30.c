/*
 * function: func_021D7D30
 * address: 0x021D7D30
 * packet: pkt_ov125_021D7D30
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021DA0B4 0x021DA0B4 data a4
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021D9640 0x021D9640 data a4
 *   func_021D7D24 0x021D7D24 arm ov125
 */
extern char d_021DA0B4[], d_021D9640[];
extern unsigned d_021D9E40[];
extern void func_021D7D24(void *);
extern void func_020853C0(void *, void (*)(void *), int, void *, int, unsigned);
extern void func_02085868(void *);
int func_021D7D30(void) {
 func_020853C0(d_021DA0B4, func_021D7D24, 0, d_021D9640, 0x800, d_021D9E40[0x270/4]);
 func_02085868(d_021DA0B4);
 return 1;
}
