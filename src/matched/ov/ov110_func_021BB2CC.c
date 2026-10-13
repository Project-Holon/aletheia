/*
 * function: PMSIV_CATEGORY_Delete
 * address: 0x021BB2CC
 * packet: pkt_ov110_021BB2CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03752.h"
typedef unsigned char u8;
struct Descriptor;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void PMSIV_CATEGORY_Delete(u8 *p) {
    u8 i;
    if(((struct Obj03752 *)p)->f54) CLACT_DeleteActor(((struct Obj03752 *)p)->f54);
    for(i=0;i<12;i++) if(*(void **)(p+0x60+i*4)) BMP_WIN_Delete(*(void **)(p+0x60+i*4));
    if(((struct Obj03752 *)p)->f90) BMP_WIN_Delete(((struct Obj03752 *)p)->f90);
    if(((struct Obj03752 *)p)->f94) BMP_WIN_Delete(((struct Obj03752 *)p)->f94);
    if(((struct Obj03752 *)p)->f98) BMP_WIN_Delete(((struct Obj03752 *)p)->f98);
    func_020307B0(p);
}
