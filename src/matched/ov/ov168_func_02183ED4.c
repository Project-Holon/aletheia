/*
 * function: func_02183ED4
 * address:  0x02183ED4
 * packet:   pkt_02183ED4
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_ResetWndMask  0x02022224  thumb
 */
typedef unsigned int u32;

extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern u32 WIPE_ResetWndMask(void *win);

void func_02183ED4(int a0)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FFu;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FFu;
    WIPE_ResetWndMask((void *)0);
    WIPE_ResetWndMask((void *)1);
}
