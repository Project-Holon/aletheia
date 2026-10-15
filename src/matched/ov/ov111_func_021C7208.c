/*
 * function: VIEWER_TEXT_InitVram
 * address:  0x021C7208
 * packet:   pkt_ov111_021C7208
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021C88FC  0x021C88FC  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

typedef enum { GX_DISP_SELECT_SUB_MAIN = 0, GX_DISP_SELECT_MAIN_SUB = 1 } GXDispSelect;

static inline void GX_SetDispSelect(GXDispSelect sel)
{
    *(volatile u16 *)0x04000304 = (u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel << 15));
}

struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern const unsigned char d_021C88FC[];

void VIEWER_TEXT_InitVram(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C88FC);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
}
