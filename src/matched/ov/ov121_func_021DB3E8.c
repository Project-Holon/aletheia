/*
 * function: MYSTERY_ALBUM_Cleanup
 * address: 0x021DB3E8
 * packet: pkt_ov121_021DB3E8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MYSTERY_UTIL_DeleteWindow 0x021D9A40 thumb ov121
 */
#include "../include/Obj01058.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct Obj;
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void MYSTERY_UTIL_DeleteWindow(u8 *p);
void MYSTERY_ALBUM_Cleanup(char *p)
{
    int i;
    BG_SYS_SetTileUnit(2,1,0);
    BG_SYS_SetTileUnit(1,1,0);
    for(i=0;i<2;i++) CLACT_DeleteActor(*(void **)(p+0xaf4+i*4));
    CLACT_DeleteActor(((struct Obj01058 *)p)->fAF0);
    CLACT_DeleteActor(((struct Obj01058 *)p)->fAEC);
    CLACT_ReleaseCharacter((u32)(((struct Obj01058 *)p)->fAFC));
    CLACT_ReleaseCellAnim((u32)(((struct Obj01058 *)p)->fB00));
    CLACT_ReleasePalette((u32)(((struct Obj01058 *)p)->fB04));
    MYSTERY_UTIL_DeleteWindow(((struct Obj01058 *)p)->fAB4);
    ((struct Obj01058 *)p)->fAB4=0;
    CLACT_ReleasePalette((u32)(((struct Obj01058 *)p)->fBA8));
    for(i=0;i<8;i++) BMP_WIN_Delete(*(void **)(p+0xb08+i*4));
}
