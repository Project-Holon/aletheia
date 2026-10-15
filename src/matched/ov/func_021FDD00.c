/*
 * function: WORLDTRADE_SEARCH_LoadBgGraphics
 * address:  0x021FDD00
 * packet:   pkt_021FDD00
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *
 * The parameterless member: handle open, the B68 and B40 window calls, two
 * F5BC text calls, three 49658/498F4 draws and the second B40 pair, then
 * the 49238 release.  Contents 166 of 168 bytes (pool pad).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *h);

void WORLDTRADE_SEARCH_LoadBgGraphics(void *p)
{
    void *h = func_020490F4(0x60, 0x48);

    func_02049B68(h, 2, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xb, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x17, 1, 0, 0, 1, 0x48);
    func_02049658(h, 0xc, 2, 0, 0, 1, 0x48);
    func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    ARC_TOOL_DeleteHandle(h);
}
