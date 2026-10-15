/*
 * function: NAMEIN_GRAPHIC_PickTableE
 * address:  0x021F4E58
 * packet:   pkt_021F4E58
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORDSET_CopyString 0x0201F41C thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);

int NAMEIN_GRAPHIC_PickTableE(int p, int idx, unsigned short *tab, int val, unsigned char *out)
{
    unsigned char i;

    WORDSET_CopyString((const u16 *)(p + 0xe + 0x18 * idx), (u16 *)((int)tab), val);
    i = 0;
    while (i < 3 && tab[i] != 0x3000) {
        i++;
    }
    if (out != 0) {
        *out = (unsigned char)i;
    }
    return i != 0;
}
