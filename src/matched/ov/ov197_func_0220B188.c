/*
 * function: func_0220B188
 * address:  0x0220B188
 * packet:   pkt_0220B188
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */

struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void func_0220B188(char *a)
{
    unsigned int i;

    for (i = 0; i < 0x23; i++)
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(a + i * 8 + 0x28)));
}