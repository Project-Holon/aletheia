/*
 * function: func_021BFDA8
 * address: 0x021BFDA8
 * packet: pkt_ov099_021BFDA8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BFDCE.
 * symbols:
 *   func_021563EC 0x021563EC thumb ov009
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
#include "../include/Obj22052.h"
extern int func_021563EC(void);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
int func_021BFDA8(char *p, int ret) {
 if (!func_021563EC()) { func_02039C68((struct Link *)func_020399A8(),24,10); ((struct Obj22052 *)p)->f1CC=172; }
 return ret;
}
