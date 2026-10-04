/*
 * function: func_021E2EA0
 * address: 0x021E2EA0
 * packet: pkt_ov119_021E2EA0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two-byte zero alignment padding at 0x021E2EFA.
 * symbols:
 *   func_02011558 0x02011558 thumb
 */
#include "../include/Obj02173.h"
struct IcaAnime;
extern void func_02011558(struct IcaAnime *p);
void func_021E2EA0(char *p) {
    if (((struct Obj02173 *)p)->f90) {func_02011558(((struct Obj02173 *)p)->f90); ((struct Obj02173 *)p)->f90=0;}
    if (((struct Obj02173 *)p)->f94) {func_02011558(((struct Obj02173 *)p)->f94); ((struct Obj02173 *)p)->f94=0;}
    if (((struct Obj02173 *)p)->f98) {func_02011558(((struct Obj02173 *)p)->f98); ((struct Obj02173 *)p)->f98=0;}
    if (((struct Obj02173 *)p)->f9C) {func_02011558(((struct Obj02173 *)p)->f9C); ((struct Obj02173 *)p)->f9C=0;}
}
