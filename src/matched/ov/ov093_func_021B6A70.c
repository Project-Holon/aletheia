/*
 * function: BTL_MAIN_CreateViewCore
 * address: 0x021B6A70
 * packet: pkt_ov093_021B6A70
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   BTLV_CORE_Create 0x021E8F20 thumb ov093
 *   BTL_CLIENT_SetView 0x021CD95C thumb ov093
 */
#include "../include/Obj13268.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Scene;
extern struct Scene *BTLV_CORE_Create(void *,void *,u32,int,u16);
struct QA;
extern void BTL_CLIENT_SetView(struct QA *p, u32 v);
void BTL_MAIN_CreateViewCore(unsigned char *p,unsigned char *q,int r) { void *v; struct Scene *s; if(q[0x23]) v=*(void **)(p+0x10+q[0x21]*4); else v=((struct Obj13268 *)p)->f10; s=BTLV_CORE_Create(p,v,(u32)(p+0xc8),r,0x13); *(struct Scene * *)&((struct Obj13268 *)p)->f4=s; BTL_CLIENT_SetView(v,(u32)s); }
