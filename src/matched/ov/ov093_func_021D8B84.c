/*
 * unit: yes
 * function: func_021D8B84, func_021D8BA8
 * address: 0x021D8B84
 * packet: pkt_ov093_021D8B84
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F07B8 0x021F07B8 data a4
 */
extern int func_021D775C(int);
extern void func_021D7704(int, int);
extern unsigned int d_021F07B8;
void func_021D8B84(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(0x45)) func_021D7704(0x35, 3 << 11);
}
void *func_021D8BA8(int *p) { *p = 1; return &d_021F07B8; }
