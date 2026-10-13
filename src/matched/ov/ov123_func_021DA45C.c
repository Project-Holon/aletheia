/*
 * function: func_021DA45C
 * address: 0x021DA45C
 * packet: pkt_ov123_021DA45C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 */
#include "../include/Obj08119.h"
typedef unsigned char u8;
extern void NHTTP_RAP_DeleteConnection(u8 *);
extern void NHTTP_RAP_Destroy(u8 *);
void func_021DA45C(char *p) { if(*(u8 * *)&((struct Obj08119 *)p)->f8) { NHTTP_RAP_DeleteConnection(*(u8 * *)&((struct Obj08119 *)p)->f8); NHTTP_RAP_Destroy(*(u8 * *)&((struct Obj08119 *)p)->f8); *(u8 * *)&((struct Obj08119 *)p)->f8=0; } }
