/*
 * function: func_021F0D5C
 * address:  0x021F0D5C
 * packet:   pkt_ov032_021F0D5C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0D5C  0x021F0D5C  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02028230  0x02028230  thumb
 *   func_02028148  0x02028148  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02028178(u32 w);
extern u32 func_02028230(u8 *p);
extern void func_02028148(u32 w);

int func_021F0D5C(char *p, int i)
{
    char *q;
    int j;

    q = p + 0xf0;
    func_02028178(*(u32 *)(q + i * 16));
    if (func_02028230(*(u8 **)(q + i * 16)) != 0) {
        for (j = 0; j < 2; j++) {
            func_02028148(*(u32 *)(p + j * 16 + 0xf0));
            *(u32 *)(p + j * 16 + 0xf0) = 0;
        }
        return 1;
    }
    return 0;
}
