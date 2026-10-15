/*
 * function: BR_CODEIN_RecordDeleteProfileScreen
 * address: 0x021DCE28
 * packet: pkt_ov183_021DCE28
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_DeleteProfileScreen 0x021FD640 thumb ov186
 */
#include "../include/Obj00050.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void BR_UTIL_DeleteProfileScreen(int *);
void BR_CODEIN_RecordDeleteProfileScreen(char *p,char *unused) { if(((struct Obj00050 *)p)->fDC && *(int * *)&((struct Obj00050 *)p)->f44) { BR_UTIL_DeleteProfileScreen(*(int * *)&((struct Obj00050 *)p)->f44); *(int *)&((struct Obj00050 *)p)->f44=0; ((struct Obj00050 *)p)->fDC=0; } }
