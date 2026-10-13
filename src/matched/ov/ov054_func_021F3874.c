/*
 * function: FIELD_GIMMICK_SOUND_OBJS_B_LoadWaitLimits
 * address: 0x021F3874
 * packet: pkt_ov054_021F3874
 * region: ov054
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_020307B0 0x020307B0 arm
 *   sGimmick54WaitMembers 0x021F394C data a4
 */
#include "../include/Obj03165.h"

typedef struct { int v[2]; } Pair;
extern Pair sGimmick54WaitMembers;
extern void *ARC_TOOL_LoadMember(unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void FIELD_GIMMICK_SOUND_OBJS_B_LoadWaitLimits(char *p) { Pair t=sGimmick54WaitMembers; int i; for(i=0;i<2;i++){ int *q=ARC_TOOL_LoadMember(0x7f,t.v[i],((struct Obj03165 *)p)->f0); ((int *)(p+0x18))[i]=q[0]; ((int *)(p+0x20))[i]=q[1]; func_020307B0(q); } }
