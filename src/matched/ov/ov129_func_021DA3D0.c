/*
 * function: WF2DMAP_SCENE_DeleteOam
 * address: 0x021DA3D0
 * packet: pkt_ov129_021DA3D0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 */
#include "../include/Obj08140.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Grid;
extern void CLACT_ReleasePalette(u32);
extern void BMP_OAM_Delete(struct Grid *);
extern void BMP_OAM_DeleteSys(void *);
void WF2DMAP_SCENE_DeleteOam(u8 *p) { CLACT_ReleasePalette(((struct Obj08140 *)p)->f30C); BMP_OAM_Delete(*(struct Grid * *)&((struct Obj08140 *)p)->f304); BMP_OAM_Delete(*(struct Grid * *)&((struct Obj08140 *)p)->f308); BMP_OAM_DeleteSys(((struct Obj08140 *)p)->f300); }
