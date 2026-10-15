/*
 * function: BEACON_VIEW_DeleteWindows
 * address: 0x021F30B4
 * packet: pkt_ov032_021F30B4
 * region: ov032
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
void BEACON_VIEW_DeleteWindows(char *p)
{
    int i;
    for (i = 0; i < 3; i++)
        BMP_WIN_Delete(*(struct Descriptor **)(p + i * 20 + 0x17c));
}
