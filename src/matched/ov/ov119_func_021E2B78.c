/*
 * function: func_021E2B78
 * address: 0x021E2B78
 * packet: pkt_ov119_021E2B78
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02048B20 0x02048B20 arm
 */
#include "../include/Obj08066.h"
typedef struct {int x,y,z;} Vec;
extern void func_02048AFC(void *,Vec *);
extern void func_02048B44(void *,Vec *);
extern void func_02048B6C(void *,int *);
extern void func_02048B20(void *,Vec *);
void func_021E2B78(char *p) {
    Vec a;
    Vec b;
    a.x=0; a.y=0x2b000; a.z=0xf1000;
    b.x=0; b.y=0x2b000; b.z=0;
    func_02048AFC(((struct Obj08066 *)p)->f83C,&a);
    func_02048B44(((struct Obj08066 *)p)->f83C,&b);
    a.z-=0x1000;
    func_02048B6C(((struct Obj08066 *)p)->f83C,&a.z);
    b.x=0; b.y=0x1000; b.z=0;
    func_02048B20(((struct Obj08066 *)p)->f83C,&b);
}
