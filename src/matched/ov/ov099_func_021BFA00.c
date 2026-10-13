/*
 * function: func_021BFA00
 * address: 0x021BFA00
 * packet: pkt_ov099_021BFA00
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BFA26.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
#include "../include/Obj00008.h"
extern unsigned int KEY_GetTrg(void);
extern void func_021C2408(char *);
extern void func_021BA8EC(char *);
int func_021BFA00(char *p, int ret) {
 if (KEY_GetTrg()) { ((struct Obj00008 *)p)->f1CC=11; func_021C2408(p); func_021BA8EC(p); }
 return ret;
}
