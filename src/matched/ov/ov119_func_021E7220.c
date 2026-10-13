/*
 * function: func_021E7220
 * address: 0x021E7220
 * packet: pkt_ov119_021E7220
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned int   u32;
struct Node;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void func_02030EAC(struct Node *n);

void func_021E7220(void *p, int a)
{
    BG_SYS_SetMainVisiblePlanes(a);
    func_02030EAC(p);
}
