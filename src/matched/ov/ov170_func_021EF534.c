/*
 * function: func_021EF534
 * address:  0x021EF534
 * packet:   pkt_ov170_021EF534
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);

void func_021EF534(struct WinMgr *mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    BGWINFRM_GetPos(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x15)
        return;
    for (; i < 6; i++)
        BGWINFRM_StartMove(mgr, i, -1, 0, buf[1] - 0x15);
}
