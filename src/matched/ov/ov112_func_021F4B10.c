/*
 * function: MUSICAL_MCSS_IsElemModeSupportedC
 * address: 0x021F4B10
 * packet: pkt_ov112_021F4B10
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_IsModeSupportedC 0x021F5064 thumb ov112
 */
#include "../include/Obj22520.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *MUSICAL_MCSS_GetElemPtr(u8 *,int);
extern int MUSICAL_MCSS_IsModeSupportedC(u8 *,int);
int MUSICAL_MCSS_IsElemModeSupportedC(u8 *p,int index,int mode) { return MUSICAL_MCSS_IsModeSupportedC(MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((struct Obj22520 *)p)->fC,index),mode); }
