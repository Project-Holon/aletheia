/*
 * function: func_021B64DC
 * address: 0x021B64DC
 * packet: pkt_ov180_021B64DC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_DecodePartyParam 0x02017D30 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_EncodePartyParam 0x02017D70 thumb
 */
#include "../include/Obj02515.h"
extern unsigned POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *,unsigned);
typedef unsigned int   u32;
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
void func_021B64DC(unsigned char *p) {
 unsigned i; void *mon; unsigned saved;
 p[0x915E]=0;
 for(i=0;i<POKEPARTY_GetCount(**(void ** *)&((struct Obj02515 *)p)->f0);i++) {
  mon=POKEPARTY_GetMember(**(void ** *)&((struct Obj02515 *)p)->f0,i); saved=POKE_TOOL_DecodePartyParam(mon);
  if(POKE_TOOL_GetPartyValue(mon,76,0)==0) { *(void **)(p+(unsigned char)p[0x915E]*4+0x9140)=mon; p[0x915E]++; }
  POKE_TOOL_EncodePartyParam(mon,saved);
 }
}
