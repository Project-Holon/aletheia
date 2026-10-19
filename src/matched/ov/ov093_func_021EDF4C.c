/*
 * function: BTLV_SCU_HideNamePlate
 * address:  0x021EDF4C
 * packet:   pkt_ov093_021EDF4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm  arm9
 */
typedef unsigned char u8;
struct W {
    u8 pad[0xa];
    u8 fa;
    u8 fb;
    u8 pad2[0x16];
    u8 f22_0 : 1;
};
typedef unsigned int   u32;
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
void BTLV_SCU_HideNamePlate(struct W *w)
{
    if (w->fa == 0)
        BG_SYS_ChangeScrollImmediate(w->fb, 0, 0x90);
    else
        BG_SYS_ChangeScrollImmediate(w->fb, 0, -0x90);
    w->f22_0 = 0;
}
