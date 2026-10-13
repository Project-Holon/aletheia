/*
 * function: func_021E4570
 * address: 0x021E4570
 * packet: pkt_ov119_021E4570
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void func_021E4570(char *p)
{
    int i;
    for (i = 0; i < 25; i++) {
        if (*(void **)(p + i * 4 + 0x6B8)) {
            BMP_WIN_Delete(*(void **)(p + i * 4 + 0x6B8));
            *(void **)(p + i * 4 + 0x6B8) = 0;
        }
    }
}
