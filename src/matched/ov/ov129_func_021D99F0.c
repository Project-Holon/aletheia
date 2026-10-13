/*
 * function: func_021D99F0
 * address: 0x021D99F0
 * packet: pkt_ov129_021D99F0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DA3D0 0x021DA3D0 thumb ov129
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 * Extent ends with two bytes of zero alignment padding.
 */
#include "../include/Obj06480.h"
#include "../include/Obj10500.h"

struct Bank;
struct Descriptor;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned char  u8;
extern void func_021DA3D0(u8 *p);
extern unsigned int func_020452E8(struct Descriptor *d);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
void func_021D99F0(char *p)  {
    int i;
    char *q;
    for(i=0;i<((struct Obj10500 *)p)->f23C;i++) CLACT_DeleteActor((struct Obj *)(*(int *)(p+i*28+12)));
    for(i=0;i<2;i++)  {
        q=p+i*28;
        CLACT_DeleteActor((struct Obj *)(((struct Obj06480 *)q)->f15C));
        CLACT_DeleteActor((struct Obj *)(((struct Obj06480 *)q)->f1E8));
    }
    for(i=0;i<3;i++) CLACT_DeleteActor((struct Obj *)(*(int *)(p+i*28+0x194)));
    func_021DA3D0((u8 *)p);
    func_020452E8((struct Descriptor *)(((struct Obj10500 *)p)->f310));
    for(i=0;i<3;i++)  {
        q=p+i*4;
        CLACT_ReleasePalette(((struct Obj06480 *)q)->f260);
        CLACT_ReleaseCharacter(((struct Obj06480 *)q)->f26C);
        CLACT_ReleaseCellAnim(((struct Obj06480 *)q)->f284);
    }
    CLACT_DeleteUnit((struct Bank *)(((struct Obj10500 *)p)->f25C));
    CLACT_ExitSystem();
}
