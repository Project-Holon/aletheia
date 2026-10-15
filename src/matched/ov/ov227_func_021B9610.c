/*
 * function: EVENT_PDC_RETURN_Exit
 * address: 0x021B9610
 * packet: pkt_ov227_021B9610
 * region: ov227
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj08473.h"
struct S020314B8;struct U16Vec;struct S020315D4;
extern void func_0203133C(struct S020314B8 *p);
extern void STRBUF_Delete(struct U16Vec *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int EVENT_PDC_RETURN_Exit(struct S020315D4 *a,void *b,void *c,char *p){func_0203133C(*(struct S020314B8 * *)&((struct Obj08473 *)p)->f34);if(*(struct U16Vec * *)&((struct Obj08473 *)p)->f28)STRBUF_Delete(*(struct U16Vec * *)&((struct Obj08473 *)p)->f28);STRBUF_Delete(*(struct U16Vec * *)&((struct Obj08473 *)p)->f4);func_020315D4(a);func_020306F0(139);return 1;}
