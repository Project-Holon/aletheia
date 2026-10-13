/*
 * function: ENCEFF_StartScreenTexEffect
 * address: 0x021F529C
 * packet: pkt_ov075_021F529C
 * region: ov075
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   ENCEFF_ScreenTexEventMain 0x021F5518 thumb ov075
 */
#include "../include/Obj13214.h"
typedef unsigned int u32;
typedef struct Vec { int x,y,z; } Vec;
struct Desc;
struct Obj;
struct Work;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *,int,int);
extern int ENCEFF_ScreenTexEventMain(void *task, int *st, struct Work *w);
void *ENCEFF_StartScreenTexEffect(void *a,Vec *src,u32 b,u32 c) {
    void *h;
    char *w;
    h=func_020122C0(a,0,(void *)ENCEFF_ScreenTexEventMain,0x30);
    w=func_020124E8(h);
    MI_CpuFill8(w,0,0x30);
    *(Vec *)(w+24)=*src;
    ((struct Obj13214 *)w)->f28=b;
    ((struct Obj13214 *)w)->f2C=c;
    return h;
}
