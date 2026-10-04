/*
 * function: func_021DAF1C
 * address: 0x021DAF1C
 * packet: pkt_ov093_021DAF1C
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
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj13469.h"
extern int func_021D775C(int);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *,unsigned int);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *,int,int);
extern void func_021C88C8(void *,void *);
void func_021DAF1C(int a, int *b, int c) { char *p; if (c == func_021D775C(2) && func_021D5BDC(func_021C7CF4(b,c),13)) { p = func_021C88A4((char *)b,24,c); p[8] = c; ((struct Obj13469 *)p)->f4 = 13; func_021C88C8((char *)b,p); } }
