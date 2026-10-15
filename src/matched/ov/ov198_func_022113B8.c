/*
 * function: B_PLIST_MAIN_CopyFrame
 * address: 0x022113B8
 * packet: pkt_ov198_022113B8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing 022113FA halfword is zero alignment padding, not a follower.
 * symbols:
 *   BG_SYS_GetBuf 0x0204162C arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   B_PLIST_MAIN_GetFramePos 0x0221139C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 BG_SYS_GetBuf(int channel);
extern void MIi_CpuCopy16(const void *, void *, unsigned);
extern void B_PLIST_MAIN_GetFramePos(u8 *, u8 *, unsigned);
void B_PLIST_MAIN_CopyFrame(u8 *dst, unsigned bg, unsigned which)
{
    u8 xy[2];
    u8 *src = (u8 *)BG_SYS_GetBuf(bg);
    u8 i;
    B_PLIST_MAIN_GetFramePos(&xy[1], &xy[0], which);
    for (i = 0; i < 6; i++) {
        MIi_CpuCopy16(src + 2 * (xy[1] + ((xy[0] + i) << 5)), dst + (i << 5), 32);
    }
}
