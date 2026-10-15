/*
 * function: BEACON_DETAIL_GRA_Exit
 * address: 0x021BBE18
 * packet: pkt_ov216_021BBE18
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_DeleteTouchBar 0x021BC3D4 thumb ov216
 *   BEACON_DETAIL_GRA_DeleteListWindows 0x021BC8A8 thumb ov216
 *   BEACON_DETAIL_GRA_DeleteDetailActors 0x021BC6B4 thumb ov216
 *   BEACON_DETAIL_GRA_FreeTrainerGfx 0x021BC56C thumb ov216
 *   BEACON_DETAIL_GRA_DeleteInfoWindow 0x021BC6FC thumb ov216
 *   BEACON_DETAIL_GRA_FreeBackground 0x021BC378 thumb ov216
 *   BEACON_DETAIL_GRA_DeleteObjects 0x021BC178 thumb ov216
 *   BEACON_DETAIL_GRA_Delete 0x021BC0B4 thumb ov216
 *   BEACON_DETAIL_GRA_Destroy 0x021BC9D0 thumb ov216
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov072_id 0x00000048 data
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj01437.h"
struct S021BC6B4; struct Proc;
extern unsigned char ov072_id[],ov067_id[];
extern void BEACON_DETAIL_GRA_DeleteTouchBar(unsigned char *p);
extern void BEACON_DETAIL_GRA_DeleteListWindows(char *);
extern void BEACON_DETAIL_GRA_DeleteDetailActors(struct S021BC6B4 *);
extern void BEACON_DETAIL_GRA_FreeTrainerGfx(char *);
extern unsigned BEACON_DETAIL_GRA_DeleteInfoWindow(unsigned *);
extern void BEACON_DETAIL_GRA_FreeBackground(char *);
extern void BEACON_DETAIL_GRA_DeleteObjects(char *);
extern void BEACON_DETAIL_GRA_Delete(char *);
extern void BEACON_DETAIL_GRA_Destroy(unsigned *);
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void func_02034A5C(int);
int BEACON_DETAIL_GRA_Exit(struct Proc *heap,int unused1,int unused2,char *p)
{
    BEACON_DETAIL_GRA_DeleteTouchBar(((struct Obj01437 *)p)->f124);
    BEACON_DETAIL_GRA_DeleteListWindows(p);
    BEACON_DETAIL_GRA_DeleteDetailActors((struct S021BC6B4 *)p);
    BEACON_DETAIL_GRA_FreeTrainerGfx(p);
    BEACON_DETAIL_GRA_DeleteInfoWindow((unsigned *)p);
    BEACON_DETAIL_GRA_FreeBackground(p);
    BEACON_DETAIL_GRA_DeleteObjects(p);
    BEACON_DETAIL_GRA_Delete(p);
    BEACON_DETAIL_GRA_Destroy(*(unsigned * *)&((struct Obj01437 *)p)->f50);
    func_020315D4(heap);
    GFL_HEAP_DeleteChecked(119);
    func_02034A5C((int)ov072_id);
    func_02034A5C((int)ov067_id);
    return 1;
}
