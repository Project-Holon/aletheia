/*
 * function: BTL_POKEPARAM_GetHitRecord
 * address:  0x021D6940
 * packet:   pkt_ov093_021D6940
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out)
{
    int k;
    u32 n;
    u16 *e;

    if ((u32)i < 3) {
        k = p[0x1ef] - i;
        if (k < 0) k += 3;
        n = (p + k)[0x1ec];
        if (j < n) {
            e = (u16 *)(p + k * 0x30 + (u8)(n - j - 1) * 8);
            out[0] = e[0x15c / 2];
            out[1] = e[0x15e / 2];
            out[2] = e[0x160 / 2];
            out[3] = e[0x162 / 2];
            return 1;
        }
    }
    return 0;
}
