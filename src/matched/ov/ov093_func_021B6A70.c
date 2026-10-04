/*
 * function: func_021B6A70
 * address: 0x021B6A70
 * packet: pkt_ov093_021B6A70
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   func_021E8F20 0x021E8F20 thumb ov093
 *   func_021CD95C 0x021CD95C thumb ov093
 */
#include "../include/Obj13268.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Scene;
extern struct Scene *func_021E8F20(void *,void *,u32,int,u16);
struct QA;
extern void func_021CD95C(struct QA *p, u32 v);
void func_021B6A70(unsigned char *p,unsigned char *q,int r) { void *v; struct Scene *s; if(q[0x23]) v=*(void **)(p+0x10+q[0x21]*4); else v=((struct Obj13268 *)p)->f10; s=func_021E8F20(p,v,(u32)(p+0xc8),r,0x13); *(struct Scene * *)&((struct Obj13268 *)p)->f4=s; func_021CD95C(v,(u32)s); }
