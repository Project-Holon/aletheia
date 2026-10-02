/*
 * unit: yes
 * function: func_021DC630,func_021DC658
 * address: 0x021DC630
 * packet: pkt_ov093_021DC630
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F06D0 0x021F06D0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern unsigned char d_021F06D0[];
extern int func_021D775C(int);
extern int func_021C8288(void *);
extern void func_021D7704(int,int);
void func_021DC630(int a, void *b, int c) { if (c == func_021D775C(2) && func_021C8288(b) == 4) func_021D7704(53,8192); }
void *func_021DC658(int *p) { *p = 1; return d_021F06D0; }
