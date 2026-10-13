/*
 * function: FIELD_MSGBG_LoadWindowGraphicsAll
 * address:  0x02192FA4
 * packet:   pkt_ov021_02192FA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   FIELD_MSGBG_LoadSysWindowFrameGraphics  0x021929E8  thumb  ov021
 */

extern void func_02049B40(int, int, int, int, int, int);
extern void func_0201F5BC(int, int, int, int, int);
typedef unsigned int   u32;
extern void FIELD_MSGBG_LoadSysWindowFrameGraphics(u32 heap);

void FIELD_MSGBG_LoadWindowGraphicsAll(int a, int b)
{
    func_02049B40(0x17, 5, 0, 0x160, 0x20, b);
    func_02049B40(0x17, 7, 0, 0x1c0, 0x20, b);
    func_0201F5BC(a & 0xff, 1, 0xd, 0, b);
    FIELD_MSGBG_LoadSysWindowFrameGraphics(b);
}
