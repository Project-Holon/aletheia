/*
 * function: REPORT_LoadBgGraphics
 * address:  0x021F0228
 * packet:   pkt_ov034_021F0228
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   REPORT_LoadBgGraphics 0x021F0228 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *, int, int, int, int, int);
typedef unsigned int   u32;
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);
extern void func_02049658(void *, int, int, int, int, int, int);
extern void func_020498F4(void *, int, int, int, int, int, int);
extern void ARC_TOOL_DeleteHandle(void *);

void REPORT_LoadBgGraphics(int a)
{
    void *h = func_020490F4(0xC4, a);

    func_02049B68(h, 2, 4, 0, 0x60, a);
    BG_SYS_LoadPlttEntry(4, 0);
    func_02049658(h, 1, 4, 0, 0, 1, a);
    func_020498F4(h, 0, 4, 0, 0, 1, a);
    ARC_TOOL_DeleteHandle(h);
}
