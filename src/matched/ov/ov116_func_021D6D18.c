/*
 * function: func_021D6D18
 * address: 0x021D6D18
 * packet: pkt_ov116_021D6D18
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two bytes zero alignment padding follow the compiled function.
 * symbols:
 *   func_021D70EC 0x021D70EC thumb ov116
 *   func_021D7158 0x021D7158 thumb ov116
 */
#include "../include/Obj22621.h"
extern int func_021D70EC(unsigned char *,int *);
typedef unsigned char  u8;
extern int func_021D7158(u8 *p);
int func_021D6D18(unsigned char *a,unsigned char *b) { int result; if(func_021D70EC(b,&result) && func_021D7158(b)==0) { ((struct Obj22621 *)a)->f0=1; return 1; } return 0; }
