/*
 * function: UNION_SUBDISP_DeleteLineWindows
 * address: 0x021F0478
 * packet: pkt_ov031_021F0478
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void UNION_SUBDISP_DeleteLineWindows(char *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        BMP_WIN_Delete(*(void **)(p + 0x4c + i * 4));
    }
}
