/*
 * function: func_021E31BC
 * address: 0x021E31BC
 * packet: pkt_ov119_021E31BC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021E3034 0x021E3034 thumb ov119
 *   func_021E2F2C 0x021E2F2C thumb ov119
 *   func_021E2B68 0x021E2B68 thumb ov119
 */
#include "../include/Obj03778.h"
extern unsigned int G3D_CAMERA_Delete(void *ptr);
struct Rec;
extern void G3D_UTIL_Delete(struct Rec *p);
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
extern void func_021E3034(u32 *p, int a1);
extern void func_021E2F2C(void *);
extern void func_021E2B68(void);
void func_021E31BC(char *p) {
    if (((struct Obj03778 *)p)->f83C) G3D_CAMERA_Delete(((struct Obj03778 *)p)->f83C);
    G3D_UTIL_Delete(((struct Obj03778 *)p)->f820);
    if (((struct Obj03778 *)p)->fC) {
        func_021E3034(((struct Obj03778 *)p)->fC,6);
        func_021E2F2C(((struct Obj03778 *)p)->fC);
        func_020307B0(((struct Obj03778 *)p)->fC);
        ((struct Obj03778 *)p)->fC=0;
    }
    func_021E2B68();
}
