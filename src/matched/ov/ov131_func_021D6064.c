/*
 * function: P_STATUS_GetPokePara
 * address: 0x021D6064
 * packet: pkt_ov131_021D6064
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb

 */
#include "../include/Obj00112.h"
extern void *func_020185F0(void *);
typedef unsigned int   u32;
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetBoxParamSize(void);
void *P_STATUS_GetPokePara(unsigned char *p) {
 switch((*(unsigned char **)(p+8))[12]) {
 case 0: return func_020185F0(**(void ** *)&((struct Obj00112 *)p)->f8);
 case 1: return func_020185F0(func_0201AB28(**(void ** *)&((struct Obj00112 *)p)->f8,((struct Obj00112 *)p)->f18));
 case 2: return (unsigned char *)**(void ** *)&((struct Obj00112 *)p)->f8+POKE_TOOL_GetBoxParamSize()* ((struct Obj00112 *)p)->f18;
 default: return 0;
 }
}
