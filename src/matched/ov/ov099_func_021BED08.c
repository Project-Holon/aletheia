/*
 * function: func_021BED08
 * address: 0x021BED08
 * packet: pkt_ov099_021BED08
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BED3A.
 * symbols:
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021BAB04 0x021BAB04 thumb ov099
 */
#include "../include/Obj13699.h"
extern void func_021BA8EC(char *);
extern unsigned int func_0202EB0C(void);
extern void func_021BAB04(void *p, int message);
int func_021BED08(char *p,int ret) {
 func_021BA8EC(p);
 if (func_0202EB0C()) func_021BAB04(p,44);
 else func_021BAB04(p,19);
 ((struct Obj13699 *)p)->f1CC=8;
 ((struct Obj13699 *)p)->f1E8=0;
 return ret;
}
