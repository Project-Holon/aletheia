/*
 * function: BOX2_UI_UpdateTopBarMove
 * address: 0x021EF6E0
 * packet: pkt_ov170_021EF6E0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021EF736.
 * symbols:
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   BGWINFRM_UpdateMove 0x0202CDD4 thumb
 *   BOX2_UI_LayoutPartySlots 0x021ED8A4 thumb ov170
 */
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern u32 BGWINFRM_UpdateMove(struct WinMgr *mgr, u32 idx);
extern void BOX2_UI_LayoutPartySlots(char *);
#define MGR(p) (*(struct WinMgr **)(*(char **)((p)+0x2c)+0x74))
unsigned BOX2_UI_UpdateTopBarMove(char *p)
{
    signed char a[2], b[2];
    unsigned r;
    BGWINFRM_GetPos(MGR(p),7,&a[1],&a[0]);
    r=BGWINFRM_UpdateMove(MGR(p),7);
    BGWINFRM_GetPos(MGR(p),7,&b[1],&b[0]);
    if(a[1]!=b[1] || a[0]!=b[0]) BOX2_UI_LayoutPartySlots(p);
    return r;
}
