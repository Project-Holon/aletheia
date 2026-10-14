/*
 * function: ZUKAN_DETAIL_AREA_BeginHideOverlay
 * address: 0x021C1FE0
 * packet: pkt_ov208_021C1FE0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021C0C8C 0x021C0C8C thumb ov208
 *   ZUKAN_DETAIL_AREA_DrawTownName 0x021C1D30 thumb ov208
 *   ZUKAN_DETAIL_AREA_UpdateTerrainIcons 0x021C2238 thumb ov208
 */
#include "../include/Obj00081.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
struct PrintSys;
struct Descriptor;
struct CharBuf;
extern unsigned CLACT_GetActorDrawEnable(struct Obj *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned);
extern void func_021C0C8C(u16 *, u8 *, int, int);
extern void ZUKAN_DETAIL_AREA_DrawTownName(u16 *, u8 *, int);
extern void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *, u8 *, int);
void ZUKAN_DETAIL_AREA_BeginHideOverlay(u16 *heap, u8 *p, int key)
{
    u8 i;
    if (CLACT_GetActorDrawEnable(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        if (((struct Obj00081 *)p)->f90 == 1) {
            ((struct Obj00081 *)p)->f30 = 0;
            PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
            BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
            BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
        }
    } else {
        for (i = 0; i < 61; i++) CLACT_SetActorDrawEnable(*(struct Obj **)(p + i * 4 + 0xdc), 0);
        if (((struct Obj00081 *)p)->f90 == 0) {
            func_021C0C8C(heap, p, key, 0);
            p[0x79] = 255;
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00081 *)p)->fCC, 0);
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00081 *)p)->fD0, 0);
            ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
            ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        }
    }
}
