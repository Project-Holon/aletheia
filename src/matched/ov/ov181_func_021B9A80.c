/*
 * function: func_021B9A80
 * address: 0x021B9A80
 * packet: pkt_ov181_021B9A80
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02040EBC 0x02040EBC arm
 */
typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void ARC_TOOL_DeleteHandle(unsigned char *);
extern void func_02040EBC(u32 a0, u32 a1);
void func_021B9A80(void *unused, int mode)
{
    unsigned char *h;
    if (mode == 1) {
        h = func_020490F4(0x1A, 0x808E);
        func_02049B68(h, 2, 0, 0, 0, 0x8E);
    } else {
        h = func_020490F4(0xDC, 0x808E);
        func_02049B68(h, 0xC, 0, 0x1E0, 0x20, 0x8E);
    }
    ARC_TOOL_DeleteHandle(h);
    func_02040EBC(1, 0);
}
