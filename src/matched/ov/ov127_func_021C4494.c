/*
 * function: WIFI_2DCHAR_RegisterBmpHandles
 * address: 0x021C4494
 * packet: pkt_ov127_021C4494
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021C4512 follow the return.
 * symbols:
 *   WIFI_2DCHAR_IsCellUsed 0x021C447C thumb ov127
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 */
#include "../include/Obj03277.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFI_2DCHAR_IsCellUsed(char *p, int i);
extern signed int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
void WIFI_2DCHAR_RegisterBmpHandles(u8 *p, u32 a, u32 heap)
{
    int i;
    i = 16;
    if (WIFI_2DCHAR_IsCellUsed((char *)p, 16) == 1) {
        ((struct Obj03277 *)p)->f330 = i;
    } else {
        i = 17;
        if (WIFI_2DCHAR_IsCellUsed((char *)p, 17) == 1)
        ((struct Obj03277 *)p)->f330 = i;
    }
    ((struct Obj03277 *)p)->f2E8 = (u32)CLACT_RegisterCellAnim((void *)(((struct Obj03277 *)p)->f2F8), 9, 8, (u16)heap);
    ((struct Obj03277 *)p)->f2E0 = CLACT_RegisterCharacter((void *)(((struct Obj03277 *)p)->f2F8), 11, 0, a, heap);
    ((struct Obj03277 *)p)->f2E4 = CLACT_RegisterPaletteEx((void *)(((struct Obj03277 *)p)->f2F8), 10, a, 320, 0, 1, heap);
}
