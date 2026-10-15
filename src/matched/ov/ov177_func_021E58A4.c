/*
 * function: WIFIBATTLEMATCH_VIEW_LoadBgPalette
 * address: 0x021E58A4
 * packet: pkt_ov177_021E58A4
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   BG_SYS_FillScrollArea  0x02040618  arm  arm9
 */
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned short u16;
extern void func_020498F4(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
typedef unsigned int   u32;
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void ARC_TOOL_DeleteHandle(int);
void WIFIBATTLEMATCH_VIEW_LoadBgPalette(int unused, int mode, unsigned color)
{
    int h;
    unsigned c = (color & 0x7fff) | 0x8000;
    h = (int)func_020490F4((int)0x85, (unsigned short)c);
    func_020498F4((void *)h, 5, 3, 0, 0, 0, c);
    func_020498F4((void *)h, 6, 7, 0, 0, 0, c);
    switch (mode) {
    case 2:
        func_020498F4((void *)h, 8, 6, 0, 0, 0, c);
        break;
    case 3:
        func_020498F4((void *)h, 10, 2, 0, 0, 0, c);
        break;
    case 0:
    case 1:
        func_020498F4((void *)h, 10, 6, 0, 0, 0, c);
        break;
    }
    BG_SYS_FillScrollArea(2, 0, -256);
    BG_SYS_FillScrollArea(1, 0, -256);
    BG_SYS_FillScrollArea(6, 0, -256);
    BG_SYS_FillScrollArea(5, 0, -256);
    ARC_TOOL_DeleteHandle(h);
}
