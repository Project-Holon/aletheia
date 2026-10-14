/*
 * function: GURU2_MAIN_StateWaitRoleMessage
 * address: 0x021DEFB4
 * packet: pkt_ov137_021DEFB4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   GURU2_MAIN_IsMemberFlagSet 0x021E16C4 thumb ov137
 */
#include "../include/Obj01753.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GURU2_MAIN_IsMemberFlagSet(char *,int);
int GURU2_MAIN_StateWaitRoleMessage(char *p) { if(GURU2_MAIN_IsMemberFlagSet(p,4)==1) { ((struct Obj01753 *)p)->f0=22; return 1; } return 0; }
