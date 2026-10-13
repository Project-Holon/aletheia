/*
 * function: TR_AI_InitScriptCache
 * address: 0x0218A41C
 * packet: pkt_ov096_0218A41C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   gTrAiScriptCache 0x0218A7C0 data a4
 *   gTrAiAllocSite 0x0218A7A0 data
 */

#include "../include/G_Slot.h"

typedef unsigned char u8;
typedef struct { u8 id[4]; u8 ref[4]; void *obj[4]; } Slot;
extern struct Slot *gTrAiScriptCache;
extern const char gTrAiAllocSite[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
void TR_AI_InitScriptCache(unsigned int a) { int i; if(gTrAiScriptCache==0) { gTrAiScriptCache=func_02030734(a,24,1,gTrAiAllocSite,3999); for(i=0;i<4;i++) gTrAiScriptCache->id[i]=255; } }
