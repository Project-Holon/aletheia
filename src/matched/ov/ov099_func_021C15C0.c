/*
 * function: func_021C15C0
 * address: 0x021C15C0
 * packet: pkt_ov099_021C15C0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BF03C 0x021BF03C thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(void *);
extern int func_021BF03C(char *);
extern u32 KEY_GetTrg(void);
int func_021C15C0(char *p,int ret){if(!func_021BA928(p))return ret;if(func_021BF03C(p))((struct Obj00008 *)p)->f1CC=48;if(KEY_GetTrg()&3)((struct Obj00008 *)p)->f1CC=48;return ret;}
