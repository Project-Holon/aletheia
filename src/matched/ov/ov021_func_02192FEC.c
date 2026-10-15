/*
 * function: FIELD_MSGBG_LoadWindowGraphicsStepFn
 * address:  0x02192FEC
 * packet:   pkt_ov021_02192FEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049B40  0x02049B40  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   FIELD_MSGBG_LoadSysWindowFrameGraphics  0x021929E8  thumb  ov021
 */

extern void func_02049B40(int, int, int, int, int, int);
extern void BMP_MENUWORK_LoadCharAndPltt(int, int, int, int, int);
typedef unsigned int   u32;
extern void FIELD_MSGBG_LoadSysWindowFrameGraphics(u32 heap);

void FIELD_MSGBG_LoadWindowGraphicsStepFn(int a, int b, int c)
{
    if (c == 0) {
        func_02049B40(0x17, 5, 0, 0x160, 0x20, b);
        func_02049B40(0x17, 7, 0, 0x1c0, 0x20, b);
    } else if (c == 1) {
        BMP_MENUWORK_LoadCharAndPltt(a & 0xff, 1, 0xd, 0, b);
    } else if (c == 2) {
        FIELD_MSGBG_LoadSysWindowFrameGraphics(b);
    }
}
