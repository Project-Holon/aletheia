/*
 * function: BOX2_UI_DrawSlot
 * address: 0x021EDAB0
 * packet: pkt_ov170_021EDAB0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   BOX2_MAIN_GetBoxWallpaper 0x021DEDCC thumb ov170
 *   BOX2_UI_ReplaceColorIndex 0x021EDBE8 thumb ov170
 *   BOX2_UI_LoadMonIcon 0x021EDC0C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj24024.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void MI_CpuCopy8(const void *, void *, unsigned);
extern u32 func_020307B0(void *p);
extern int BOX2_MAIN_GetBoxWallpaper(char *p, int box);
extern void BOX2_UI_ReplaceColorIndex(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n);
typedef unsigned char  u8;
extern void BOX2_UI_LoadMonIcon(int **a, int box, u8 *dest);
void BOX2_UI_DrawSlot(char *p, int i)
{
    void *t;
    void *q = ARC_UTIL_LoadScreenDataFromArchive(0x74, 0x47, 1, (u32)(&t), 0x4c);
    MI_CpuCopy8(((struct Obj24024 *)t)->f14, *(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400, 0x400);
    func_020307B0(q);
    BOX2_UI_ReplaceColorIndex((int)p, (unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400), BOX2_MAIN_GetBoxWallpaper((char *)p, i), 8, 0x400);
    BOX2_UI_LoadMonIcon((int **)p, i, (unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400));
}
