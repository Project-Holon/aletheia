/*
 * function: func_021DE1F8
 * address:  0x021DE1F8
 * packet:   pkt_021DE1F8
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 */
typedef unsigned int u32;

extern void CLACT_ReleaseCharacter(u32 v);

void func_021DE1F8(char *p, int i)
{
    if (*(u32 *)(p + 0xbb4 + i * 4) != 0xffffffffu) {
        CLACT_ReleaseCharacter(*(u32 *)(p + 0xbb4 + i * 4));
        *(u32 *)(p + 0xbb4 + i * 4) = 0xffffffffu;
    }
}
