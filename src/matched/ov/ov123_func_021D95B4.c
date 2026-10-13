/*
 * function: func_021D95B4
 * address: 0x021D95B4
 * packet: pkt_ov123_021D95B4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 58 compiled bytes followed by 2 bytes of zero alignment padding.
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 */
#include "../include/Obj04501.h"
typedef unsigned char  u8;
extern void TIME_ICON_Delete(u8 *p);
extern unsigned char *TIME_ICON_CreateNode(unsigned int,void *,unsigned char,unsigned char,unsigned short);
void func_021D95B4(char *p) { if(((struct Obj04501 *)p)->f90) { TIME_ICON_Delete(((struct Obj04501 *)p)->f90); ((struct Obj04501 *)p)->f90=0; } ((struct Obj04501 *)p)->f90=TIME_ICON_CreateNode(((struct Obj04501 *)p)->f88,((struct Obj04501 *)p)->f48,15,16,((struct Obj04501 *)p)->fB0); }
