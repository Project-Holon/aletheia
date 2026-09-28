/*
 * function: func_021C5F64
 * address:  0x021C5F64
 * packet:   pkt_ov111_021C5F64
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5DB8  0x021C5DB8  thumb  ov111
 *   func_021C5F50  0x021C5F50  thumb  ov111
 *   func_02040B1C  0x02040B1C  arm
 *   d_021C86A8     0x021C86A8  data  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} TouchPos;

extern int func_021C5DB8(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side);
extern void func_021C5F50(TouchPos *src, TouchPos *dst);
extern void func_02040B1C(u8 index, const void *src, u32 size, u32 tile);
extern const u8 d_021C86A8[2][2][16];

int func_021C5F64(u8 *pix, TouchPos *cur, TouchPos *prev, int flush, const void *src, u8 clip, u8 side)
{
    int drew = 0;
    int n = 0;
    int ofs;
    int px, py;

    if (clip == 0) {
        ofs = 4;
    } else {
        ofs = 2;
    }
    if (cur->active) {
        if (prev->active) {
            px = prev->x - 0x20 - ofs;
            py = prev->y - 0x5A;
        }
        n = func_021C5DB8(pix, d_021C86A8[clip][cur->size], cur->x - 0x20 - ofs, cur->y - 0x5A, &px, &py, 0, prev->active, clip, side);
        drew = 1;
    }
    if (drew && flush) {
        func_02040B1C(7, src, 0x3000, 1);
    }
    func_021C5F50(cur, prev);
    cur->active = 0;
    return n;
}
