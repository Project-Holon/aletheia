/*
 * function: GURU2_RECEIPT_VBlank
 * address:  0x021DD1A4
 * packet:   pkt_021DD1A4
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GURU2_RECEIPT_AnimatePalette  0x021DD14C  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_Update  0x020419E4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void GURU2_RECEIPT_AnimatePalette(void *unused, u8 *p);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_Update(void);

void GURU2_RECEIPT_VBlank(void *a0, void *work)
{
    GURU2_RECEIPT_AnimatePalette(a0, work);
    CLACT_VBlankSystem();
    BG_SYS_Update();
}
