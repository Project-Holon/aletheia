/*
 * function: WIFIBATTLEMATCH_VIEW_DeleteWindow
 * address: 0x021E6EFC
 * packet: pkt_ov177_021E6EFC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 */
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void WIFIBATTLEMATCH_VIEW_DeleteWindow(unsigned *p)
{
    unsigned i;
    for (i = 0; i < p[0]; i++) {
        if ((void *)p[i + 1] != 0)
            BMP_WIN_Delete((void *)p[i + 1]);
    }
}
