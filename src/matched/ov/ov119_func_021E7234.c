/*
 * function: POKETRADE_2D_TaskSetSubPlaneVisible
 * address: 0x021E7234
 * packet: pkt_ov119_021E7234
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned int   u32;
struct Node;
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_02030EAC(struct Node *n);

void POKETRADE_2D_TaskSetSubPlaneVisible(void *p, int a)
{
    BG_SYS_SetSubVisiblePlanes(a);
    func_02030EAC(p);
}
