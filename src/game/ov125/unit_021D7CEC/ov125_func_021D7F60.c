/*
 * function: func_021D7F60
 * address: 0x021D7F60
 * packet: pkt_ov125_021D7F60
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021DA258 0x021DA258 data a4
 *   func_021D8C5C 0x021D8C5C arm ov125
 *   func_0215F638 0x0215F638 arm ov009
 *   func_0215F644 0x0215F644 arm ov009
 */

#include "../../../matched/include/G_Clear.h"

extern struct Clear d_021D9E40;
extern char d_021DA258[];
extern int func_0215F638(int s, int how);
extern int func_0215F644(int s);
extern void func_021D8C5C(void *);
void func_021D7F60(void) {
 if (((unsigned *)&d_021D9E40)[0x26c/4] == -1u) return;
 func_0215F638(((unsigned *)&d_021D9E40)[0x26c/4], 2);
 func_0215F644(((unsigned *)&d_021D9E40)[0x26c/4]);
 ((unsigned *)&d_021D9E40)[0x26c/4] = -1u;
 func_021D8C5C(d_021DA258);
}
