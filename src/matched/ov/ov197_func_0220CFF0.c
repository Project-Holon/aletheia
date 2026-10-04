/*
 * function: func_0220CFF0
 * address: 0x0220CFF0
 * packet: pkt_ov197_0220CFF0
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0220B990 0x0220B990 thumb ov197
 *   func_0220C4EC 0x0220C4EC thumb ov197
 *   func_0220BD24 0x0220BD24 thumb ov197
 */
#include "../include/Obj10837.h"
struct PrintSys;
extern unsigned func_0201C6B4(const struct PrintSys *),func_0220B990(unsigned char *);
extern void func_0220C4EC(char *,int),func_0220BD24(char *,int);
int func_0220CFF0(char *p){if(func_0201C6B4(*(struct PrintSys * *)&((struct Obj10837 *)p)->f18)==1){func_0220B990((unsigned char *)p);func_0220C4EC(p,((struct Obj10837 *)p)->f532);func_0220BD24(p,((struct Obj10837 *)p)->f532);return 5;}return 12;}
