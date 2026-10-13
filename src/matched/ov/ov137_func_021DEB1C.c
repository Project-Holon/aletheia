/*
 * function: func_021DEB1C
 * address: 0x021DEB1C
 * packet: pkt_ov137_021DEB1C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E170C 0x021E170C thumb ov137
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 */
#include "../include/Obj01753.h"
typedef unsigned short u16;
extern int func_021E170C(char *);
extern void *func_021DEB10(char *);
extern int UNION_APP_GetMemberCount(unsigned char *p);
int func_021DEB1C(char *p) {unsigned v;v=func_021E170C(p)+1;if(v!=UNION_APP_GetMemberCount(func_021DEB10(p)))return 0;((struct Obj01753 *)p)->f0=5;return 1;}
