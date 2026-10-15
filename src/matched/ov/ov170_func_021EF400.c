/*
 * function: BOX2_UI_UpdateBarMove
 * address:  0x021EF400
 * packet:   pkt_ov170_021EF400
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   BGWINFRM_UpdateMove 0x0202CDD4 thumb
 *   BOX2_SEQ_MoveActorToWindow 0x021EC8E4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj24043.h"
#include "../include/Obj24044.h"
#include "../include/Obj24045.h"

typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern u32 BGWINFRM_UpdateMove(struct WinMgr *mgr, u32 idx);
extern void BOX2_SEQ_MoveActorToWindow(char *p);

int BOX2_UI_UpdateBarMove(unsigned char *p)
{
    signed char a[2];
    signed char b[2];
    unsigned r;
    BGWINFRM_GetPos(*(struct WinMgr * *)&((struct Obj24043 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74, 8, &a[1], &a[0]);
    r = BGWINFRM_UpdateMove(*(struct WinMgr * *)&((struct Obj24044 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74, 8);
    BGWINFRM_GetPos(*(struct WinMgr * *)&((struct Obj24045 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74, 8, &b[1], &b[0]);
    if (a[1] != b[1] || a[0] != b[0])
        BOX2_SEQ_MoveActorToWindow((char *)p);
    {
        int ret = 0;
        if (r != 0)
            ret = 1;
        return ret;
    }
}
