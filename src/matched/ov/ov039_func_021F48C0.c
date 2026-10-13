/*
 * function: FIELD_GIMMICK_CART_LANES_SampleJointTranslation
 * address:  0x021F48C0
 * packet:   pkt_ov039_021F48C0
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_GIMMICK_CART_LANES_SampleJointTranslation  0x021F48C0  thumb
 *   FIELD_GIMMICK_CART_LANES_SampleJointTrack  0x021F4928  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern void FIELD_GIMMICK_CART_LANES_SampleJointTrack(int *out, int frame, const u32 *data, const u8 *base);

void FIELD_GIMMICK_CART_LANES_SampleJointTranslation(u8 *a, int idx, int x, int *out)
{
    u16 off;
    u32 flags;
    u8 *p;
    int c;
    int b;
    int d;

    off = *(u16 *)(a + idx * 2 + 0x14);
    flags = *(u32 *)(a + off);
    p = a + off + 4;
    if (flags & 6) {
        return;
    }
    if (!(flags & 8)) {
        FIELD_GIMMICK_CART_LANES_SampleJointTrack(&c, x, (const u32 *)p, a);
        p += 8;
        out[0] = c;
    }
    if (!(flags & 0x10)) {
        FIELD_GIMMICK_CART_LANES_SampleJointTrack(&b, x, (const u32 *)p, a);
        p += 8;
        out[1] = b;
    }
    if (flags & 0x20) {
        return;
    }
    FIELD_GIMMICK_CART_LANES_SampleJointTrack(&d, x, (const u32 *)p, a);
    out[2] = d;
}
