/*
 * unit: yes
 * function: func_021D9340, func_021D9360
 * address: 0x021D9340
 * packet: pkt_ov093_021D9340
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F06B8 0x021F06B8 data a4
 */
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);
extern unsigned int d_021F06B8;
void func_021D9340(int a, int b, int c)
{
    if (c == func_021D775C(2)) func_021D76BC(0x20, func_021D775C(0x20) << 1);
}
void *func_021D9360(int *p) { *p = 1; return &d_021F06B8; }
