/*
 * function: MUSICAL_SHOT_SYS_DeleteScene
 * address: 0x021F3BF0
 * packet: pkt_ov112_021F3BF0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte padding at 0x021F3C4E.
 * symbols:
 *   STA_ACT_LIGHT_DeleteUnit 0x021F6C7C thumb ov112
 *   STA_ACT_LIGHT_DeleteModel 0x021F6F4C thumb ov112
 *   STA_ACT_LIGHT_DeleteBillboardImage 0x021F7120 thumb ov112
 *   MUSICAL_MCSS_DeleteRenderObj 0x021F51B0 thumb ov112
 *   MUSICAL_MCSS_DeleteActorPool 0x021F4948 thumb ov112
 *   MUSICAL_SHOT_SYS_Exit3D 0x021F3ED0 thumb ov112
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 */
#include "../include/Obj03246.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void STA_ACT_LIGHT_DeleteUnit(char *p);
extern void STA_ACT_LIGHT_DeleteModel(u8 *p);
struct Descriptor;
extern void STA_ACT_LIGHT_DeleteBillboardImage(char *p);
extern void MUSICAL_MCSS_DeleteRenderObj(int a);
extern void MUSICAL_MCSS_DeleteActorPool(u8 *);
extern void MUSICAL_SHOT_SYS_Exit3D(u8 *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 func_020307B0(void *p);
void MUSICAL_SHOT_SYS_DeleteScene(u8 *p)
{
    u8 i;
    STA_ACT_LIGHT_DeleteUnit((char *)(((struct Obj03246 *)p)->f40));
    STA_ACT_LIGHT_DeleteModel((u8 *)(((struct Obj03246 *)p)->f28));
    STA_ACT_LIGHT_DeleteBillboardImage(((struct Obj03246 *)p)->f2C);
    MUSICAL_MCSS_DeleteRenderObj(((struct Obj03246 *)p)->f20);
    MUSICAL_MCSS_DeleteActorPool(*(u8 * *)&((struct Obj03246 *)p)->f24);
    BMP_WIN_Delete(((struct Obj03246 *)p)->f58);
    BMP_WIN_Delete(((struct Obj03246 *)p)->f54);
    GF_FONT_Delete(((struct Obj03246 *)p)->f60);
    GF_FONT_Delete(((struct Obj03246 *)p)->f5C);
    MUSICAL_SHOT_SYS_Exit3D(p);
    for(i=0;i<4;i++) func_020307B0(*(void **)(p+i*4+8));
    func_020307B0(p);
}
