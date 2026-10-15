/*
 * function: func_021845A4
 * address:  0x021845A4
 * packet:   pkt_021845A4
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Exit  0x020450C8  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *
 * Addresses are Black-image addresses.
 */

extern int BMP_WIN_Exit(int);
extern int G3D_SYSTEM_Exit(int);
extern int BG_SYS_Delete(int);

void func_021845A4(int a)
{
    BG_SYS_Delete(G3D_SYSTEM_Exit(BMP_WIN_Exit(a)));
}
