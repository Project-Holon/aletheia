/*
 * function: MB_SEQ_DrawSelectedMail
 * address:  0x021C5C64
 * packet:   pkt_ov136_021C5C64
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MB_SEQ_DrawSelectedMail 0x021C5C64 thumb
 *   MB_SEQ_DrawMailEntry 0x021C6028 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 */
#include "../include/Obj00127.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void MB_SEQ_DrawMailEntry(u8 *p, u32 a1, int idx, int sel);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
void MB_SEQ_DrawSelectedMail(u8 *p)
{
    MB_SEQ_DrawMailEntry(p, 10, 0x16, p[0x1f]);
    BGWINFRM_PutFrame(**(struct WinMgr ** *)&((struct Obj00127 *)p)->f8, 10, 4, 7);
}
