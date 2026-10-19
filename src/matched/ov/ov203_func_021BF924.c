/*
 * function: DEMO3D_CMDSYS_Release
 * address: 0x021BF924
 * packet: pkt_ov203_021BF924
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   DEMO3D_DATA_DeleteCapture 0x021BE9E8 thumb ov203
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 */
#include "../include/Obj02250.h"
typedef unsigned int   u32;
struct S02031140;
struct Tcbl;
extern void DEMO3D_DATA_DeleteCapture(int);
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void GFL_USE_SetBgmPaused(void *);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern int GFL_USE_PopBgm(void);
void DEMO3D_CMDSYS_Release(char *p)
{
    if(((struct Obj02250 *)p)->f2C) DEMO3D_DATA_DeleteCapture(((struct Obj02250 *)p)->f2C);
    TCBL_DeleteAllTasks(((struct Obj02250 *)p)->f20);
    if(((struct Obj02250 *)p)->f19) {
        GFL_USE_PopBgm();GFL_USE_SetBgmPaused(0);GFL_USE_FadeInBgmFull(60);
    }
    ARC_TOOL_DeleteHandle(((struct Obj02250 *)p)->f28);GF_FONT_Delete(((struct Obj02250 *)p)->f24);TCBL_Destroy(((struct Obj02250 *)p)->f20);
}
