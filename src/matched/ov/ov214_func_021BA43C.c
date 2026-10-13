/*
 * function: func_021BA43C
 * address:  0x021BA43C
 * packet:   pkt_021BA43C
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */

struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void func_021BA43C(int unused, char *p)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
    {
        BMP_WIN_Delete(*(void **)(p + 0x8c + i * 4));
    }
}
