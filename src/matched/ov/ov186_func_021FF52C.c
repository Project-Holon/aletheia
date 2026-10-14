/*
 * function: BR_NET_Main
 * address: 0x021FF52C
 * packet: pkt_ov186_021FF52C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_NET_RunTask 0x021FFB58 thumb ov186
 *   GDS_RAP_Main 0x021D6A34 thumb ov125
 */
#include "../include/Obj14477.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {int(*fn)(void*,void*,int);char pad_04[4];int arg_08;} S;
extern void BR_NET_RunTask(S*);
extern int GDS_RAP_Main(char*);
void BR_NET_Main(char*p){if(((struct Obj14477 *)p)->f5A4){BR_NET_RunTask(*(S* *)&((struct Obj14477 *)p)->f5AC);GDS_RAP_Main(p);}}
