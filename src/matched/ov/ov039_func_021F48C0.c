/*
 * function: func_021F48C0
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
 *   func_021F48C0  0x021F48C0  thumb
 *   func_021F4928  0x021F4928  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021F4928(int *out, int frame, const u32 *data, const u8 *base);

void func_021F48C0(u8 *a, int idx, int x, int *out)
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
        func_021F4928(&c, x, (const u32 *)p, a);
        p += 8;
        out[0] = c;
    }
    if (!(flags & 0x10)) {
        func_021F4928(&b, x, (const u32 *)p, a);
        p += 8;
        out[1] = b;
    }
    if (flags & 0x20) {
        return;
    }
    func_021F4928(&d, x, (const u32 *)p, a);
    out[2] = d;
}
