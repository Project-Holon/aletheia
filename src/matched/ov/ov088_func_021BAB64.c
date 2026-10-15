/*
 * function: STARTMENU_LoadGraphics
 * address:  0x021BAB64
 * packet:   pkt_ov088_021BAB64
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 */

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void STARTMENU_LoadGraphics(void)
{
    void *h;
    h = func_020490F4(0x23, 0x800B);
    func_02049B68(h, 4, 0, 0, 0xc0, 0xb);
    func_02049658(h, 3, 2, 0, 0, 1, 0xb);
    func_020498F4(h, 2, 3, 0, 0, 1, 0xb);
    func_02049B68(h, 5, 4, 0, 0xc0, 0xb);
    func_02049658(h, 1, 5, 0, 0, 1, 0xb);
    func_020498F4(h, 0, 6, 0, 0, 1, 0xb);
    ARC_TOOL_DeleteHandle(h);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, 0xb);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0xb);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0xb);
}
