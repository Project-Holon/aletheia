/*
 * function: func_020248D8
 * address:  0x020248D8
 * packet:   pkt_02024838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   g_0209F792  0x0209F792  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 g_0209F792[];


int func_020248D8(u32 v, u32 *a1, u32 *a2)
{
    u32 i;
    u32 sum;

    v &= 0x7ff;
    sum = 0;
    for (i = 0; i < 0xd; i++) {
        u16 n = g_0209F792[i];

        sum += n;
        if (v < sum) {
            *a1 = i;
            *a2 = v - (sum - n);
            return 1;
        }
    }
    return 0;
}
