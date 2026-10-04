/*
 * function: func_021C16EC
 * address: 0x021C16EC
 * packet: pkt_ov099_021C16EC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(void *);
extern void func_021BA8EC(char *);
int func_021C16EC(char *p,int ret){if(!func_021BA928(p))return ret;if(--((struct Obj00008 *)p)->f1E0==0){((struct Obj00008 *)p)->f1D0=0;((struct Obj00008 *)p)->f1CC=26;func_021BA8EC(p);}return ret;}
