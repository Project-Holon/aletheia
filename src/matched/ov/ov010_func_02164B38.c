/*
 * function: func_02164B38
 * address: 0x02164B38
 * packet: pkt_ov010_02164B38
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02164A2C 0x02164A2C thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 */
#include "../include/Obj07302.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc;
struct SeqWork2;
extern struct Desc *func_020122C0(void *,void *,void *,u32);
struct Big;
struct Ctx;
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int func_02164A2C(void *,u32 *,struct SeqWork2 *);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
void *func_02164B38(void *a,void *b,u32 c){void *t=func_020122C0(a,0,(void *)func_02164A2C,0x1c);u8 *p=func_020124E8(t);void *v=func_020120F4(a);((struct Obj07302 *)p)->f4=v;((struct Obj07302 *)p)->f8=func_02012EBC(v);((struct Obj07302 *)p)->f0=a; p[0x18]=c;return t;}
