/*
 * function: OEKAKI_LoadBgGraphics
 * address:  0x02184B78
 * packet:   pkt_ov023_02184B78
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 */

typedef unsigned char u8;

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

void OEKAKI_LoadBgGraphics(u8 *p, void *h)
{
    func_02049B68(h, 0, 0, 0, 0x180, 0x28);
    func_02049B68(h, 1, 4, 0, 0x180, 0x28);
    func_02049B40(0x17, 5, 0, 0x1A0, 0x20, 0x28);
    func_02049B40(0x17, 5, 4, 0x1A0, 0x20, 0x28);
    func_02049658(h, 2, 2, 0, 0x2000, 0, 0x28);
    func_020498F4(h, 6, 2, 0, 0x600, 0, 0x28);
    func_02049658(h, 4, 5, 0, 0x2000, 0, 0x28);
    func_020498F4(h, 7, 5, 0, 0x600, 0, 0x28);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 10, 0, 0x28);
    BMP_MENUWORK_LoadCharAndPltt(0, 0x1F, 11, 0, 0x28);
}
