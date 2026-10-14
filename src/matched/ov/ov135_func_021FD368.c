/*
 * function: WORLDTRADE_LIST_SelectCursorEntry
 * address: 0x021FD368
 * packet: pkt_ov135_021FD368
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_SUBLCD_MoveArrowToSlot 0x021FFD1C thumb ov135
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj01063.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef unsigned char  u8;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_SUBLCD_MoveArrowToSlot(void *, int, int);
extern void GFL_USE_PlaySeDefaultVolume(u32);
void WORLDTRADE_LIST_SelectCursorEntry(unsigned char *p, int i)
{
    if (i != ((struct Obj01063 *)p)->fD4 && i >= 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p + (i + 1) * 4 + 0xd0c)), i * 4 + 16);
        ((struct Obj01063 *)p)->f28 = 2;
        WORLDTRADE_SetStateAndReturn(p, 3, 17);
        ((struct Obj01063 *)p)->fD4 = i;
        WORLDTRADE_SUBLCD_MoveArrowToSlot(p, i, 0);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ((struct Obj01063 *)p)->f12E4 = 1;
        ((struct Obj01063 *)p)->f12FC = 1;
    }
}
