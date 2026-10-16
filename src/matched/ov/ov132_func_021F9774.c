/*
 * function: STA_ACTING_GetActionByIndex
 * address: 0x021F9774
 * packet: pkt_ov132_021F9774
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: returning (u32)p+0xfc+i*4 keeps base and scaled index apart across the call; p+i*4+0xfc hoists their common base and is four bytes short.
 * symbols:
 *   STA_ACT_LIGHT_IsElemActive 0x021F7A80 thumb ov112
 */
#include "../include/Obj08155.h"
typedef unsigned int u32;
extern int STA_ACT_LIGHT_IsElemActive(char *,char *);
int STA_ACTING_GetActionByIndex(char *p,u32 i){if(STA_ACT_LIGHT_IsElemActive(*(char * *)&((struct Obj08155 *)p)->f40,*(char **)((u32)p+i*4+0x44))==1)return 1;return *(int *)((u32)p+0xfc+i*4);}
