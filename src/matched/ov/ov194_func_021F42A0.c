/*
 * function: NAMEIN_GRAPHIC_DeleteIconActor
 * address: 0x021F42A0
 * packet: pkt_ov194_021F42A0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj03342.h"
typedef unsigned int   u32;
struct Grid;
struct Obj;
struct Obj020437AC;
struct U16Vec;
extern void CLACT_ReleasePalette(u32 i);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_OAM_Delete(struct Grid *g);
extern void BMP_Delete(struct Obj020437AC *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_DeleteActor(struct Obj *p);
extern void MI_CpuFill8(unsigned char *,unsigned,unsigned);
void NAMEIN_GRAPHIC_DeleteIconActor(unsigned char *p) {
    if (((struct Obj03342 *)p)->f2C) {
        CLACT_ReleasePalette(((struct Obj03342 *)p)->f24);
        STRBUF_Delete(((struct Obj03342 *)p)->f28);
        BMP_OAM_Delete(((struct Obj03342 *)p)->f2C);
        BMP_Delete(((struct Obj03342 *)p)->f30);
    }
    CLACT_ReleasePalette(((struct Obj03342 *)p)->f8);
    CLACT_ReleaseCharacter((u32)(((struct Obj03342 *)p)->fC));
    CLACT_ReleaseCellAnim(((struct Obj03342 *)p)->f10);
    CLACT_DeleteActor(((struct Obj03342 *)p)->f0);
    MI_CpuFill8(p,0,0x3c);
}
