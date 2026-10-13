/*
 * function: func_021BFAD0
 * address: 0x021BFAD0
 * packet: pkt_ov099_021BFAD0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BFB02.
 * symbols:
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 */
#include "../include/Obj22051.h"
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void func_021BA874(void *,int);
extern void func_021BAAB8(char *,int,int);
extern void func_021C18C8(char *,int,int);
int func_021BFAD0(char *p,int ret) {
 func_021BA874(p,DWC_RAP_GetTargetFriendIndex());
 func_021BAAB8(p,11,0);
 func_021C18C8(p,4,4);
 ((struct Obj22051 *)p)->f1CC=15;
 return ret;
}
