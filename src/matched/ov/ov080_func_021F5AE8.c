/*
 * function: func_021F5AE8
 * address:  0x021F5AE8
 * packet:   pkt_ov080_021F5AE8
 * region:   ov080
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_021F5AE8(u8 *w)
{
    int *c = (int *)(w + 0x3000);

    if (c[0] < *(u16 *)(w + 0x3008)) {
        if (c[1] == 0) {
            int i;

            for (i = 0; i < *(u16 *)(w + 0x300A); i++)
                *(int *)(w + (c[0] + i * *(u16 *)(w + 0x3008)) * 64 + 0x34) = 1;
            c[0]++;
            c[1] = 1;
        } else {
            c[1]--;
        }
    }
}
