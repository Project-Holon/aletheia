/*
 * function: func_021D580C
 * address: 0x021D580C
 * packet: pkt_ov115_021D580C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 */
#include "../include/Obj03765.h"
typedef unsigned char u8;
typedef short s16;
extern void CLACT_DrawSystem(void);
void func_021D580C(u8 *p) {
    ++((struct Obj03765 *)p)->f9C8;
    if (((struct Obj03765 *)p)->f9C8 >= 192) ((struct Obj03765 *)p)->f9C8 = 0;
    if (((struct Obj03765 *)p)->fB4A) {
        ++((struct Obj03765 *)p)->fB4A;
        if (((struct Obj03765 *)p)->fB4A >= 257) ((struct Obj03765 *)p)->fB4A = 1;
    }
    CLACT_DrawSystem();
}
