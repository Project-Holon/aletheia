/*
 * function: BEACON_VIEW_SetFadeState
 * address:  0x021F0208
 * packet:   pkt_ov032_021F0208
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   FLD_VREQ_SetSubBlendAlpha  0x021D3294  thumb  ov021
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct Chan02021FD8;
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void FLD_VREQ_SetSubBlendAlpha(u32 p, u32 a, u32 b, u32 c, u32 d);

void BEACON_VIEW_SetFadeState(u8 *p, int flag)
{
    if (flag) {
        PALANM_BlendChannel((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 1, 0, 0xe0, 6, 0);
        PALANM_BlendChannel((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 3, 0, 0xe0, 6, 0);
        FLD_VREQ_SetSubBlendAlpha(((struct Obj00007 *)p)->f10, 5, 0x1e, 0xa, 6);
    } else {
        PALANM_BlendChannel((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 1, 0, 0xe0, 0, 0);
        PALANM_BlendChannel((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 3, 0, 0xe0, 0, 0);
        FLD_VREQ_SetSubBlendAlpha(((struct Obj00007 *)p)->f10, 4, 0x1e, 0xd, 3);
    }
}
