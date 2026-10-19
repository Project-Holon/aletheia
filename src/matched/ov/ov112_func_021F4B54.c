/*
 * function: MUSICAL_MCSS_FindFreeActorIndex
 * address: 0x021F4B54
 * packet: pkt_ov112_021F4B54
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj06407.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u16 used:1; u16 rest:15; } Bits;
u16 MUSICAL_MCSS_FindFreeActorIndex(u32 p) { u16 n; int i; n=((struct Obj06407 *)p)->f10; for (i=0;i<n;i++) { if (((Bits *)(((struct Obj06407 *)p)->f8+i*36))->used==0) break; } if (i==n) return 0; return i; }
