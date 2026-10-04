/*
 * function: func_021B9F8C
 * address: 0x021B9F8C
 * packet: pkt_ov225_021B9F8C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA4D8 0x021BA4D8 thumb ov225
 *   func_021BA218 0x021BA218 thumb ov225
 *   func_021B639C 0x021B639C thumb ov067
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 */
#include "../include/Obj14802.h"
extern void func_02030EAC(void *),func_021BA4D8(char *),func_021BA218(char *),func_021B639C(unsigned char *),func_020307B0(void *),func_02034A5C(int);
extern const char ov067_id[];
void func_021B9F8C(char *p){func_02030EAC(((struct Obj14802 *)p)->f48);func_021BA4D8(p);func_021BA218(p);func_021B639C(*(unsigned char * *)&((struct Obj14802 *)p)->f4);func_020307B0(p);func_02034A5C((int)ov067_id);}
