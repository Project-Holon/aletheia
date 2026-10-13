/*
 * unit: yes
 * function: func_021D9118, func_021D9148
 * address: 0x021D9118
 * packet: pkt_ov093_021D9118
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   d_021F0758 0x021F0758 data a4
 */
extern int func_021D775C(int);
extern void func_021D7704(int, int);
extern unsigned int WAZA_TOOL_GetFlag(unsigned short, unsigned int);
extern unsigned int d_021F0758;
void func_021D9118(int a, int b, int c)
{
    if (c == func_021D775C(3) && WAZA_TOOL_GetFlag(func_021D775C(0x12), 7)) func_021D7704(0x31, 0x1333);
}
void *func_021D9148(int *p) { *p = 1; return &d_021F0758; }
