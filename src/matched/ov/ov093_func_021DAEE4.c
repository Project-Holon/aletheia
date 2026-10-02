/*
 * function: func_021DAEE4
 * address: 0x021DAEE4
 * packet: pkt_ov093_021DAEE4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: func_021C7CF4 uses its live r0 result and visibly loaded r1;
 * its own legacy file declares void and one parameter. Preserve this
 * caller's observed result and two-argument setup without editing callee.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int func_021D775C(int);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *,unsigned int);
extern struct UtilWork *func_021C7CF4(int *,int);
extern void func_021D7704(int,int);
void func_021DAEE4(int a, int *b, int c) { if (c == func_021D775C(3) && func_021D5BDC(func_021C7CF4(b,c),13) && func_021D775C(22) == 9) func_021D7704(53,6144); }
