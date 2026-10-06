/*
 * function: func_021B9BD4
 * address:  0x021B9BD4
 * packet:   pkt_ov088_021B9BD4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (52) runs 2 bytes past the compiled function (50);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_020111E8  0x020111E8  thumb
 */

typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern u32 func_020111E8(void);

void func_021B9BD4(int *p)
{
    func_02040588(5, 0);
    func_02041EE4(6, 0, p[10] / 2);
    if (func_020111E8() == 0x15) {
        p[10]++;
    } else {
        p[10]--;
    }
}
