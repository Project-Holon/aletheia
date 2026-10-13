/*
 * function: BTL_REC_AddRecord
 * address:  0x021EE8F4
 * packet:   pkt_ov093_021EE8F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_02082D44(const void *src, void *dst, int n);

void BTL_REC_AddRecord(u8 *p, u8 idx, const void *src, u32 n)
{
    u8 m;
    int len;
    u32 end;

    if (p[0] == 0) {
        p[3] = (p[3] & ~0x3f) | 1;
        p[0] = 2;
    }
    m = p[1];
    if (!(m & (1 << idx))) {
        len = n * 4;
        end = p[0] + (len + 1);
        if (end <= 0x3c) {
            p[1] = m | (u8)(1 << idx);
            p[2]++;
            (p + p[0])[4] = (idx << 5) | n;
            func_02082D44(src, p + 4 + (p[0] + 1), len);
            p[0] = end;
        } else {
            p[3] |= 0x80;
        }
    }
}
