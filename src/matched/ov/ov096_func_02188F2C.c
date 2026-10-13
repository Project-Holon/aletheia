/*
 * unit: yes
 * function: TR_AI_CmdLoadAbility, TR_AI_CmdNop
 * address: 0x02188F2C
 * packet: pkt_ov096_02188F2C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   TR_AI_GetPosition 0x0218A160 thumb ov096
 *   TR_AI_GetAbility 0x0218A220 thumb ov096
 */
#include "../include/Obj13655.h"
#include "../include/Obj21945.h"
struct Cursor; extern unsigned int VM_GetU32(struct Cursor *); extern unsigned char TR_AI_GetPosition(unsigned char *,int); extern int TR_AI_GetAbility(int,int,int);
int TR_AI_CmdLoadAbility(struct Cursor *a,unsigned char *b) { int k; k=VM_GetU32(a); ((struct Obj13655 *)b)->f38=TR_AI_GetAbility((int)b,k,TR_AI_GetPosition(b,k)); return ((struct Obj13655 *)b)->fC4; }
int TR_AI_CmdNop(int a, unsigned char *b) { return ((struct Obj21945 *)b)->fC4; }
