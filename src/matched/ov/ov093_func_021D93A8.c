/*
 * unit: yes
 * function: func_021D93A8, func_021D93CC
 * address: 0x021D93A8
 * packet: pkt_ov093_021D93A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F0A40 0x021F0A40 data a4
 */
extern int func_021D775C(int);
typedef unsigned char  u8;
extern int func_021C8288(u8 *p);
extern int func_021D76BC(int, unsigned int);
extern unsigned int d_021F0A40;
void func_021D93A8(int a, void *b, int c)
{
    if (c == func_021D775C(2) && func_021C8288(b) == 1) func_021D76BC(0x41, 1);
}
void *func_021D93CC(int *p) { *p = 3; return &d_021F0A40; }
