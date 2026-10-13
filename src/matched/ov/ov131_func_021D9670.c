/*
 * function: P_STA_RIBBON_HideDetail
 * address: 0x021D9670
 * packet: pkt_ov131_021D9670
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_02041570 0x02041570 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040AE0 0x02040AE0 arm
 */
#include "../include/Obj06485.h"
#include "../include/Obj23158.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_ReleaseCharacter(u32 i);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_02041570(int,u16);
extern void func_02041B6C(u32 bit);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
void P_STA_RIBBON_HideDetail(u8 *a,u8 *p)
{
    u8 *q;
    if(((struct Obj06485 *)p)->f4==1) {
        CLACT_ReleaseCharacter((u32)(((struct Obj06485 *)p)->f18));
        CLACT_DeleteActor(((struct Obj06485 *)p)->f1C);
        func_02041570(4,0);
        func_02041B6C(4);
        ((struct Obj06485 *)p)->f4=0;
        q=*(u8 * *)&((struct Obj06485 *)p)->f30;
        func_02040AE0(6,q+0xc,((struct Obj23158 *)q)->f8);
        func_02041B6C(6);
    }
}
