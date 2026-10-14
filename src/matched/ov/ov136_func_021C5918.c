/*
 * function: MB_SEQ_DeleteFrames
 * address:  0x021C5918
 * packet:   pkt_ov136_021C5918
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_DeleteFrames 0x021C5918 thumb
 *   BGWINFRM_Delete 0x0202CA0C thumb
 */
#include "../include/Obj23511.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void BGWINFRM_Delete(struct WinMgr *mgr);
void MB_SEQ_DeleteFrames(u8 *p)
{
    BGWINFRM_Delete(**(struct WinMgr ** *)&((struct Obj23511 *)p)->f8);
}
