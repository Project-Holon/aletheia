/*
 * function: BTL_REC_NextRecord
 * address:  0x021EE9E4
 * packet:   pkt_ov093_021EE9E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_02082D44(const void *src, void *dst, int n);

int BTL_REC_NextRecord(u8 *p, u32 *pos, u8 *a, u8 *b, u32 *dst)
{
    u8 h;
    int len;

    if (*pos == 0) {
        *pos = 2;
    }
    if (*pos < p[0]) {
        h = (p + *pos)[4];
        *a = (h >> 5) & 7;
        *b = h & 0x1f;
        len = *b * 4;
        *pos = *pos + 1;
        func_02082D44(p + 4 + *pos, dst, len);
        *pos = *pos + len;
        return 1;
    }
    return 0;
}
