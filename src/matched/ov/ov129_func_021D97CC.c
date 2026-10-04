/*
 * function: func_021D97CC
 * address: 0x021D97CC
 * packet: pkt_ov129_021D97CC
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:

 */
#include "../include/Obj23117.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
int func_021D97CC(u8 *p,int value) { int i; int count; count=((struct Obj23117 *)p)->f23C; for(i=0;i<count;i++) if(value==*(int *)(p+i*28+4)) return i; return 0; }
