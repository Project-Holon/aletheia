/*
 * unit: yes
 * function: func_021D90E8, func_021D910C
 * address: 0x021D90E8
 * packet: pkt_ov093_021D90E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F0608 0x021F0608 data a4
 */
extern int func_021D775C(int);
extern void func_021D7704(int, int);
extern unsigned int d_021F0608;
void func_021D90E8(int a, int b, int c)
{
    if (c == func_021D775C(3) && (unsigned int)func_021D775C(0x30) <= 0x3c) func_021D7704(0x31, 0x30 << 7);
}
void *func_021D910C(int *p) { *p = 1; return &d_021F0608; }
