/*
 * function: func_021BA7B8
 * address: 0x021BA7B8
 * packet: pkt_ov213_021BA7B8
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA9C0 0x021BA9C0 thumb ov213
 *   func_021BA8D4 0x021BA8D4 thumb ov213
 *   G3D_UTIL_Delete 0x02047E54 arm
 */
#include "../include/Obj10931.h"
struct Rec;
extern void func_021BA9C0(void *);
extern void func_021BA8D4(char *p);
extern void G3D_UTIL_Delete(struct Rec *p);
void func_021BA7B8(char *p){func_021BA9C0(p);func_021BA8D4(p);G3D_UTIL_Delete(((struct Obj10931 *)p)->f8);}
