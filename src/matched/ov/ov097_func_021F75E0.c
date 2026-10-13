/*
 * function: VS_MULTI_LIST_DeleteBgFrames
 * address:  0x021F75E0
 * packet:   pkt_ov097_021F75E0
 * region:   ov097
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 */

struct WinMgr;
extern void BGWINFRM_Delete(struct WinMgr *mgr);

void VS_MULTI_LIST_DeleteBgFrames(int *p)
{
    BGWINFRM_Delete((struct WinMgr *)p[2]);
}
