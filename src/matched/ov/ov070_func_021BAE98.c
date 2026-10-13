/*
 * function: ITEMMENU_PrintPocketName
 * address:  0x021BAE98
 * packet:   pkt_ov070_021BAE98
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   ITEMMENU_PrintPocketCount  0x021BAF38  thumb  ov070
 *   ITEMMENU_SelectTab  0x021BA96C  thumb  ov070
 */
#include "../include/Obj06178.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void ITEMMENU_PrintPocketCount(int, int);
extern void ITEMMENU_SelectTab(int, unsigned);

void ITEMMENU_PrintPocketName(int p)
{
    ((struct Obj06178 *)p)->f504 = BMP_WIN_Create(2, 3, 0x15, 0xC, 3, 0xC, 1);
    ((struct Obj06178 *)p)->f75C = BMP_WIN_Create(2, 1, 0x15, 8, 3, 0xC, 1);
    ((struct Obj06178 *)p)->f764 = BMP_WIN_Create(2, 9, 0x15, 9, 3, 0xC, 1);
    ITEMMENU_PrintPocketCount(p, ((struct Obj06178 *)p)->f80C);
    ITEMMENU_SelectTab(p, ((struct Obj06178 *)p)->f80C);
}
