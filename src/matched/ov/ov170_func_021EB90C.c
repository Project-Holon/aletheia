/*
 * function: BOX2_SEQ_ChangeFramePalette
 * address: 0x021EB90C
 * packet: pkt_ov170_021EB90C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021EB95A.
 * symbols:
 *   BOX2_SEQ_DrawFrameColor 0x021EB6D8 thumb ov170
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 */
#include "../include/Obj01558.h"
#include "../include/Obj23984.h"
#include "../include/Obj23985.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct WinMgr;
extern void BOX2_SEQ_DrawFrameColor(int a, int b, int c, int d);
extern void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
void BOX2_SEQ_ChangeFramePalette(char *p)
{
    BOX2_SEQ_DrawFrameColor((int)p, 20, 84, 0);
    BOX2_SEQ_DrawFrameColor((int)p, 21, 85, 1);
    BGWINFRM_ChangePalette(*(struct WinMgr * *)&((struct Obj23984 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74, 7, 0, 9, 11, 3, 12);
    BGWINFRM_ChangePalette(*(struct WinMgr * *)&((struct Obj23985 *)(*(char * *)&((struct Obj01558 *)p)->f2C))->f74, 7, 0, 12, 11, 3, 12);
}
