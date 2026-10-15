/*
 * function: APP_POWER_ResetDisplay
 * address:  0x0202F7C4
 * packet:   pkt_0202F7C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * The two calls to this packet's own followers (0x0202F870 at +0x7A and
 * 0x0202F940 at +0x80) are the only sites that need the `matched` class:
 * their compared range was their only `label` witness until those two files
 * existed, and they resolve the moment this shard carries them
 * (`manifest --verify --shard pkt_0202F7C4`, then re-run `one`).  Everything
 * else is `label`.
 *
 * A display/VCOUNT init: two GXx_SetMasterBrightness_ writes of 0xFFFFFFF0 to the
 * 0x0400006C and 0x0400106C registers, the engine setup calls, then three
 * read-modify-write pairs on the hardware registers at 0x04000000 (clear bits
 * 8-12, set bit 9; then clear 0xE000), 0x0400000A (clear all but 0x43, set 2),
 * 0x04000014 and 0x04000050 (both zeroed), the two packet-local sub-inits, and
 * the two registers released again.
 *
 * Note the compiler derives 0x0400000A and 0x04000014 from the pooled
 * 0x0400006C with `subs r0, #0x62` / `#0x58`, and reuses the value 4 in r6 as
 * `lsls r0, r6, #0x18` for the 0x04000000 base; both fall out of writing the
 * plain literals, so no symbol for the registers is needed.
 *
 * symbols:
 *   GXx_SetMasterBrightness_    0x0207D534  arm
 *   GX_HBlankIntr    0x0207D3AC  arm
 *   GX_VBlankIntr    0x0207D3E4  arm
 *   func_020808F4    0x020808F4  arm
 *   func_020809A0    0x020809A0  arm
 *   func_0207FDCC    0x0207FDCC  arm
 *   GX_SetGraphicsMode    0x0207D4B0  arm
 *   APP_POWER_LoadShutdownScreen    0x0202F870  thumb
 *   APP_POWER_DrawShutdownScreen    0x0202F940  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern long GX_HBlankIntr(int enable);
extern long GX_VBlankIntr(int enable);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void func_0207FDCC(u32 a);
extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
extern void APP_POWER_LoadShutdownScreen(void);
extern void APP_POWER_DrawShutdownScreen(u32 a);

void APP_POWER_ResetDisplay(u32 a0)
{
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, 0xFFFFFFF0);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, 0xFFFFFFF0);
    GX_HBlankIntr(0);
    GX_VBlankIntr(0);
    func_020808F4();
    func_020809A0();
    func_0207FDCC(4);
    GX_SetGraphicsMode(1, 0, 0);
    REG32(0x04000000) = (REG32(0x04000000) & 0xFFFFE0FF) | 0x200;
    REG32(0x04000000) = REG32(0x04000000) & 0xFFFF1FFF;
    REG16(0x0400000A) = (REG16(0x0400000A) & 0x43) | 4;
    REG16(0x0400000A) = REG16(0x0400000A) & 0xFFBF;
    REG32(0x04000014) = 0;
    REG16(0x04000050) = 0;
    APP_POWER_LoadShutdownScreen();
    APP_POWER_DrawShutdownScreen(a0);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, 0);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, 0x10);
}
