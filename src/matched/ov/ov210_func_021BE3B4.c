/*
 * function: func_021BE3B4
 * address:  0x021BE3B4
 * packet:   pkt_021BE3B4
 * region:   ov210
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */

struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);

void func_021BE3B4(char *p)
{
    unsigned int i;
    for (i = 0; i < 0x10; i++)
    {
        BMP_WIN_Delete(*(void **)(p + 0x14c + i * 8));
    }
    BMP_WIN_Exit();
}
