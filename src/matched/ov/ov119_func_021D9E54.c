/*
 * function: func_021D9E54
 * address: 0x021D9E54
 * packet: pkt_ov119_021D9E54
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6558 0x021B6558 thumb ov067
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021D8C6C 0x021D8C6C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9E0C 0x021D9E0C thumb ov119
 */
#include "../include/Obj04474.h"

extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void func_021D8C6C(void *);
extern void func_021D8E84(void *,int);
extern void func_021D9E0C(char *p);
void func_021D9E54(char *p) {
    func_021B6558((unsigned char *)(((struct Obj04474 *)p)->f9C0),7,0);
    func_021B6558((unsigned char *)(((struct Obj04474 *)p)->f9C0),8,0);
    func_021B6558((unsigned char *)(((struct Obj04474 *)p)->f9C0),9,0);
    func_021B6558((unsigned char *)(((struct Obj04474 *)p)->f9C0),1,0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj04474 *)p)->fF04,0);
    func_021D8C6C(p);
    func_021D8E84(p,(int)func_021D9E0C);
}
