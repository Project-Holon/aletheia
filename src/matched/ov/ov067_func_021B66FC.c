/*
 * function: TOUCHBAR_FreeGfx
 * address: 0x021B66FC
 * packet: pkt_ov067_021B66FC
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0203FB44's low/high halfword arguments preserve the explicit
 * caller narrowing; the first argument follows its own u32 definition.
 * symbols:
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void MI_CpuFill8(void *, u32, u32);
void TOUCHBAR_FreeGfx(u32 *p)
{
    CLACT_ReleaseCellAnim(p[2]);
    CLACT_ReleaseCharacter(p[1]);
    CLACT_ReleasePalette(p[0]);
    BG_SYS_DeleteHalf(p[3], (u16)p[4], (u16)(p[4] >> 16));
    MI_CpuFill8(p, 0, 0x14);
}
