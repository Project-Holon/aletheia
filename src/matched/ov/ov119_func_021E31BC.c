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
 *   func_02048AC4 0x02048AC4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021E3034 0x021E3034 thumb ov119
 *   func_021E2F2C 0x021E2F2C thumb ov119
 *   func_021E2B68 0x021E2B68 thumb ov119
 */
#include "../include/Obj03778.h"
extern void func_02048AC4(void *);
struct Rec;
extern void func_02047E54(struct Rec *p);
extern void func_020307B0(void *);
typedef unsigned int   u32;
extern void func_021E3034(u32 *p, int a1);
extern void func_021E2F2C(void *);
extern void func_021E2B68(void);
void func_021E31BC(char *p) {
    if (((struct Obj03778 *)p)->f83C) func_02048AC4(((struct Obj03778 *)p)->f83C);
    func_02047E54(((struct Obj03778 *)p)->f820);
    if (((struct Obj03778 *)p)->fC) {
        func_021E3034(((struct Obj03778 *)p)->fC,6);
        func_021E2F2C(((struct Obj03778 *)p)->fC);
        func_020307B0(((struct Obj03778 *)p)->fC);
        ((struct Obj03778 *)p)->fC=0;
    }
    func_021E2B68();
}
