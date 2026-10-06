/*
 * function: func_021C8FF4
 * address: 0x021C8FF4
 * packet: pkt_ov212_021C8FF4
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj08417.h"
#include "../include/Obj25654.h"
#include "../include/Obj25655.h"
#include "../include/Obj25656.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
int func_021C8FF4(u8 *p) {
    int result;
    switch (((struct Obj25654 *)(*(u8 * *)&((struct Obj08417 *)p)->f28))->f8) {
    case 0:
        ((struct Obj25655 *)(*(u8 * *)&((struct Obj08417 *)p)->f0))->fE = 0;
        result = 9;
        break;
    case 1:
        ((struct Obj25656 *)(*(u8 * *)&((struct Obj08417 *)p)->f0))->fE = 1;
        result = 9;
        break;
    case 2: result = 3; break;
    }
    func_020307B0(((struct Obj08417 *)p)->f28);
    return result;
}
