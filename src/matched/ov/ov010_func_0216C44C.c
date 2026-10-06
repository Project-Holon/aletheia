/*
 * function: func_0216C44C
 * address: 0x0216C44C
 * packet: pkt_ov010_0216C44C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0216C2FC 0x0216C2FC thumb ov010
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C58 0x02188C58 thumb ov021
 */
#include "../include/Obj05905.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
typedef unsigned int u32;
typedef struct Work Work;
extern int func_0216C2FC(void *evt, u32 *state, struct Work *w);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *);
void *func_0216C44C(void *a,void *b) {
    void *t; u8 *p;
    t=func_020122C0(a,0,(void *)func_0216C2FC,0x14); p=func_020124E8(t);
    ((struct Obj05905 *)p)->f0=func_02188C84(b); ((struct Obj05905 *)p)->f4=a; ((struct Obj05905 *)p)->f8=b;
    ((struct Obj05905 *)p)->fC=func_02188C58(b); ((struct Obj05905 *)p)->f10=0; return t;
}
