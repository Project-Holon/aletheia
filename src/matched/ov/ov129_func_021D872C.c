/*
 * function: WF2DMAP_SCENE_Delete
 * address: 0x021D872C
 * packet: pkt_ov129_021D872C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * The caller supplies the pointer through the legacy argless 02021540 thunk.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   WF2DMAP_SCENE_DeleteActors 0x021D99F0 thumb ov129
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj04506.h"
typedef unsigned int   u32;
struct Node;
struct PalAnmSlot;
struct Proc;
struct U16Vec;
extern void func_02030EAC(struct Node *n);
extern u32 GF_FONT_Delete(void *ptr);
extern void WF2DMAP_SCENE_DeleteActors(char *);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
extern void BG_SYS_FreeLayerBuf(unsigned);
extern void BG_SYS_Delete(void);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BUTTON_MAN_Delete(void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
int WF2DMAP_SCENE_Delete(void *a,int b,int c,char *p)
{
    func_02030EAC(((struct Obj04506 *)p)->f318);
    GF_FONT_Delete(((struct Obj04506 *)p)->f314);
    WF2DMAP_SCENE_DeleteActors(p);
    BMP_WIN_Exit();
    BG_SYS_SetMainPlaneVisible(1,0); BG_SYS_SetMainPlaneVisible(2,0); BG_SYS_SetMainPlaneVisible(4,0); BG_SYS_SetMainPlaneVisible(8,0);
    BG_SYS_SetSubPlaneVisible(1,0); BG_SYS_SetSubPlaneVisible(2,0); BG_SYS_SetSubPlaneVisible(4,0); BG_SYS_SetSubPlaneVisible(8,0);
    BG_SYS_FreeLayerBuf(1); BG_SYS_FreeLayerBuf(2); BG_SYS_FreeLayerBuf(3); BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(6); BG_SYS_FreeLayerBuf(7);
    BG_SYS_Delete();
    PALANM_FreeSlotBuffers(((struct Obj04506 *)p)->f290,0);
    PALANM_Delete(((struct Obj04506 *)p)->f290);
    ARC_TOOL_DeleteHandle(((struct Obj04506 *)p)->f258);
    BUTTON_MAN_Delete(((struct Obj04506 *)p)->f294);
    if(c==0) STRBUF_Delete(((struct Obj04506 *)p)->f348);
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(50);
    return 1;
}
