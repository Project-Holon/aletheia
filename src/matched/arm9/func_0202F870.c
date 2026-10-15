/*
 * function: func_0202F870
 * address:  0x0202F870
 * packet:   pkt_0202F7C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G2_GetBG1CharPtr    0x0207E24C  arm
 *   func_02082A7C    0x02082A7C  arm
 *   ARC_UTIL_LoadMember    0x0204A1BC  arm
 *   NNS_G2dGetUnpackedCharacterDataEx    0x02062A4C  arm
 *   DWCi_ScreenDC_FlushRange    0x020862F0  arm
 *   MIi_CpuCopy16    0x02082A60  arm
 *   func_020307B0    0x020307B0  arm
 *   NNS_G2dGetUnpackedScreenData    0x02062B30  arm
 *   G2_GetBG1ScrPtr    0x0207DFB4  arm
 *   NNS_G2dGetUnpackedPaletteCompressInfo    0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData    0x02062A98  arm
 *
 * Three copies of one block: register a handle with ARC_UTIL_LoadMember(0x16, i, 0, 7),
 * probe it (NNS_G2dGetUnpackedCharacterDataEx / 02062B30 / 02062A98 with a stack out-pointer), and
 * on success clear 0x20 bytes of the record's buffer through DWCi_ScreenDC_FlushRange and
 * fill it back through MIi_CpuCopy16 with the current frame-tick from the
 * getter (G2_GetBG1CharPtr / G2_GetBG1ScrPtr).  The handle is released with
 * func_020307B0 after each block.
 *
 * The idiom that makes this EXACT: the word each block reads twice (p[4],
 * p[2]) is written as an ASSIGNMENT INSIDE the third argument of the second
 * call -- `MIi_CpuCopy16(p[5], getter(), v1 = p[4])`.  mwcc evaluates the
 * arguments of a call right-to-left, so the assignment's load lands before
 * the getter call, and the value it produces is live across that call, which
 * is what puts it in r5 and forces the original's
 * `push {r3, r4, r5, lr}` frame.  Spelling the same value as a statement
 * before the call puts the load one statement early; spelling it inline in
 * both calls leaves the load where it is scheduled and loses r5 (6 bytes
 * short).  See docs/idioms/
 * an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register.md
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F870.c \
 *       --func func_0202F870 --addr 0x0202F870 --cc 1.1p1 --thumb
 *   -> EXACT, 208 bytes, 20/20 relocation sites resolved (all `label`)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed int     s32;
struct NitroFileHeader;
extern void *G2_GetBG1CharPtr(void);
extern void func_02082A7C(u32 a, u32 b, u32 c);
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
extern void DWCi_ScreenDC_FlushRange(u32 a, u32 b);
extern void MIi_CpuCopy16(u32 a, u32 b, u32 c);
extern u32 func_020307B0(void *p);
extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);
extern void *G2_GetBG1ScrPtr(void);
extern s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);

void func_0202F870(void)
{
    u32 *p1;
    u32 *p2;
    u32 *p3;
    u32 *p4;
    u32 h;
    u32 v1;
    u32 v2;

    func_02082A7C(0, (u32)G2_GetBG1CharPtr(), 0x4000);
    h = ARC_UTIL_LoadMember(0x16, 1, 0, 7);
    if (NNS_G2dGetUnpackedCharacterDataEx((struct NitroFileHeader *)h, (void **)(&p1)) != 0) {
        DWCi_ScreenDC_FlushRange(p1[5], p1[4]);
        MIi_CpuCopy16(p1[5], (u32)G2_GetBG1CharPtr(), v1 = p1[4]);
    }
    func_020307B0((void *)h);
    h = ARC_UTIL_LoadMember(0x16, 2, 0, 7);
    if (NNS_G2dGetUnpackedScreenData((void *)h, (void **)(&p2)) != 0) {
        DWCi_ScreenDC_FlushRange((u32)p2 + 0xc, p2[2]);
        MIi_CpuCopy16((u32)p2 + 0xc, (u32)G2_GetBG1ScrPtr(), v2 = p2[2]);
    }
    func_020307B0((void *)h);
    h = ARC_UTIL_LoadMember(0x16, 0, 0, 7);
    NNS_G2dGetUnpackedPaletteCompressInfo((struct NitroFileHeader *)h, (void **)(&p4));
    if (NNS_G2dGetUnpackedPaletteData((struct NitroFileHeader *)h, (void **)(&p3)) != 0) {
        DWCi_ScreenDC_FlushRange(p3[3], 0x20);
        MIi_CpuCopy16(p3[3], 0x05000000, 0x20);
    }
    func_020307B0((void *)h);
}
